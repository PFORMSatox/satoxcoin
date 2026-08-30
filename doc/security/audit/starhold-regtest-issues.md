# STARHOLD Regtest/Testnet Findings — Satoxcoin 4.0 (BTC 31.1 rebase)

**Date:** 2026-08-30 | **Tester:** STARHOLD (SATOVERSE: STARHOLD, Vite+Phaser TD, bloons2 lineage) | **Bin:** `build/bin/satoxcoind v4.0.3` | **Branch:** `main` @ `src/wallet/asset_tx.cpp:191` | **Datadirs:** `/tmp/starhold-regtest` (regtest 19443), `nebula-main/.satoxcoin-nebula/regtest` (nebula) | **Status:** FIXED 2026-08-30 10:45 UTC — see Section 1

This doc records **what didn't work** on regtest/testnet as found while building STARHOLD, and **how it should work** (industry expectation + fix guidance). All repros are clean-room, no Ninja Kiwi code.

---

## 1. CRITICAL — Deadlock in asset RPC (kills regtest node)

**Symptom:** `issue`/`transfer`/`reissue` on regtest intermittently triggers `POTENTIAL DEADLOCK DETECTED` then node becomes unresponsive on RPC port 19443 (`timeout on transient error: Could not connect to 127.0.0.1:19443`, `EOF reached`), requires `rm .lock` + `reindex` or wipe.

**Log:** `/tmp/starhold-regtest/regtest/debug.log:30`
```
[error] POTENTIAL DEADLOCK DETECTED
[error] Previous lock order was:
[error]  (2) 'walletInstance->cs_wallet' in ./wallet/wallet.cpp:3107 (in thread 'http_pool_14')
[error]  (1) '::cs_main' in ./node/interfaces.cpp:551 (in thread 'http_pool_14')
[error] Current lock order is:
[error]  (1) 'cs_main' in ./wallet/asset_tx.cpp:191 (in thread 'http_pool_5')
[error]  (2) 'wallet.cs_wallet' in ./wallet/asset_tx.cpp:191 (in thread 'http_pool_5')
# second instance:
[error]  (2) 'cs_wallet' in ./wallet/wallet.cpp:2369
[error]  (2) 'pwallet->cs_wallet' in ./wallet/walletdb.cpp:1108
[error]  (1) 'cs_main' in ./node/interfaces.cpp:589
[error] Current lock order is:
[error]  (1) 'cs_main' in ./wallet/asset_tx.cpp:191
[error]  (2) 'wallet.cs_wallet' in ./wallet/asset_tx.cpp:191
```

**Repro (100% on 2nd issue under load):**
```bash
satoxcoind -regtest -datadir=/tmp/starhold-regtest -daemon -fallbackfee=0.0001
satoxcoin-cli -regtest -datadir=/tmp/starhold-regtest createwallet starhold
ADDR_LEGACY=$(satoxcoin-cli -regtest -datadir=/tmp/starhold-regtest -rpcwallet=starhold getnewaddress "" legacy)
satoxcoin-cli -regtest -datadir=/tmp/starhold-regtest generatetoaddress 100 "$ADDR_LEGACY"  # fund
satoxcoin-cli -regtest -datadir=/tmp/starhold-regtest -rpcwallet=starhold issue "STARHOLD/VOID" 1000000000 "$ADDR_LEGACY" "" 8 false true QmTqu3Lk3gmTsQVtjU7rYYM37EAW4xNmbuEAp2Mjr4AV7E  # 1st often OK
satoxcoin-cli -regtest -datadir=/tmp/starhold-regtest generatetoaddress 1 "$ADDR_LEGACY"
satoxcoin-cli -regtest -datadir=/tmp/starhold-regtest -rpcwallet=starhold issue "STARHOLD/CANNON#001" 1 "$ADDR_LEGACY" "" 0 false true Qm...  # 2nd → deadlock, node hangs
```

**Root cause:** `src/wallet/asset_tx.cpp:191` locks `cs_main` then `cs_wallet`, while `wallet.cpp:3107`/`walletdb.cpp:1108` + `node/interfaces.cpp:551` lock in opposite order. Classic lock inversion. Under `http_pool_*` concurrency (parallel RPC), races to deadlock. Pre-existing, unrelated to STARHOLD — same pattern as `ci-known-failures.md:54` asset flush failures.

**How it should work:**
- No deadlock on any `issue`/`transfer` sequence, even with parallel RPC. Lock order must be consistent (always `cs_main` → `cs_wallet` or always opposite, documented in `doc/developer-notes.md`). Fix is to reorder locks in `asset_tx.cpp:191` (or introduce `LOCK2` ordering macro) and add `LOCKS_EXCLUDED` annotations, then verify with `-DDEBUG_LOCKORDER`.
- `ctest` gate: `test_satoxcoin --run_test=assets` + `validation_block_tests` must pass without `Flush: Couldn't find passets pointer`.

**FIX APPLIED 2026-08-30:**
- Changed `LOCK2(cs_main, wallet.cs_wallet)` → `LOCK2(wallet.cs_wallet, cs_main)` at 3 sites (`asset_tx.cpp:191,380,680`) to match wallet's `cs_wallet → cs_main` order (`wallet.cpp:3107` + `node/interfaces.cpp:551`). Rebuilt `satoxcoind`/`satoxcoin_wallet`.
- Verified: `rm -rf /tmp/starhold-regtest && satoxcoind -regtest -datadir=/tmp/starhold-regtest -daemon -fallbackfee=0.0001 -reindex`, `createwallet starhold`, `generatetoaddress 110` (3870000000 SATOX), `issue "STARHOLD" 1000000` + `issue "STARHOLD/VOID" 1B` + 6× `STARHOLD#TURRET001` etc (UNIQUE) + parallel `transfer` → all confirm, `grep -c "POTENTIAL DEADLOCK" debug.log` = **0**, `listassets` shows 8 STARHOLD assets, `listmyassets` correct. Previously 100% hang on 2nd `issue` with 19443 `EOF reached`.
- No workaround needed now; `apps/api` can parallelize `transfer` (forge burn) safely. Keep `fallbackfee` on for `issue`.

**Workaround for STARHOLD dev (historical, pre-fix):**
- Serialize all asset RPC: one at a time, `sleep 1` + `generatetoaddress 1` between issues. Never parallelize `issue` from `apps/api`. This avoided triggering the race but did not fix it.

---

## 2. HIGH — Address index flag requires reindex after fresh regtest

**Symptom:** After clean `rm -rf /tmp/starhold-regtest`, second start logs:
```
[error] Address index flag changed since last run. Rebuild the database using -reindex.
http_pool_* thread exit ... Shutdown done
```
Node restarts only with `-reindex`.

**How it should work:** Fresh regtest datadir should start without `-reindex`. The flag (`-addressindex`/`-assetindex` default vs persisted settings) must be coherent on first run. For STARHOLD, `satoxcoind -regtest -datadir=/tmp/starhold-regtest -reindex -daemon` is current workaround.

---

## 3. MEDIUM — Asset `issue` requires legacy P2PKH, bech32 rejected

**Symptom:**
```
satoxcoin-cli -rpcwallet=starhold issue "STARHOLD/VOID" 1000 "bcrt1qqal..." ...
error: Asset addresses must use legacy (P2PKH) format. SegWit and bech32 addresses are not supported.
```

**Repro:** Use `getnewaddress` (defaults to bech32 `bcrt1q...`) as `to_address`.

**How it should work:** Either document the requirement in `help issue` (currently missing) or allow bech32 (BTC 31.1 descriptors support it). STARHOLD workaround: always `getnewaddress "" legacy` → `J5NALs...` for `issue` (see `scripts/regtest-init.sh`). The chain should either auto-convert or error with hint: “use getnewaddress \"\" legacy”.

---

## 4. MEDIUM — Insufficient funds if wallet not funded before issue

**Symptom:** `issue "STARHOLD/VOID" 1_000_000_000 ...` → `Insufficient funds` when `getbalance` is 0.

**How it should work:** Document that `issue` burns a SATOX fee and needs coinbase maturity. STARHOLD flow must be `generatetoaddress 100 <legacy>` (≈ 774M SATOX after 100 blocks) before any `issue`. `doc/security/audit/testnet-bootstrap-runbook.md` should call this out for regtest game dev.

---

## 5. LOW — RPC port / datadir / wallet confusion

**Symptom:** `satoxcoin-cli -regtest -datadir=/tmp/starhold-regtest` without `-rpcwallet=starhold` → `No wallet is loaded` or timeout on 19443 if mainnet `satoxcoind` (port 60777) is also running with `~/.satoxcoin/satoxcoin.conf`. STARHOLD `satoxRpc.ts` must set `RPC_URL=http://127.0.0.1:19443` + cookie auth per datadir.

**How it should work:** `doc/security/audit/testnet-bootstrap-runbook.md` already lists ports (regtest 19444/19443, mainnet 60777) but should add a one-liner for game dev: `satoxcoin-cli -regtest -datadir=/tmp/starhold-regtest -rpcwallet=starhold <cmd>`.

---

## Impact on STARHOLD

Web greybox (`apps/web` Vite+Phaser) builds and runs (`npm run build` ✓ 1.6MB) without chain. Chain integration (`apps/api` → `transfer` VOID, `forge` UNIQUE, `generatetoaddress 1`) is blocked by #1 until lock order is fixed. Mock mode in `apps/api/src/starhold.ts:8` (`mocked:true`) keeps game playable.

## Verification

- Re-verify after fix: `bash scripts/regtest-init.sh` should `issue STARHOLD/VOID` + 6 `STARHOLD/*#001` + `transfer` 20 VOID + `listassets "STARHOLD*"` without deadlock, in parallel (2 concurrent `issue`).
- Add to CI: `test_satoxcoin --run_test=assets` must not log `POTENTIAL DEADLOCK`.

## References

- `src/wallet/asset_tx.cpp:191`, `src/wallet/wallet.cpp:3107`, `src/wallet/walletdb.cpp:1108`, `src/node/interfaces.cpp:551`
- `doc/security/audit/ci-known-failures.md:54` (asset flush)
- `doc/security/audit/testnet-bootstrap-runbook.md` (ports)
- `/tmp/starhold-regtest/regtest/debug.log` (repro logs retained)
