# Phase 5 — Rebase Satoxcoin onto Bitcoin Core v31.1

**Date:** 2026-08-13
**Status:** APPROVED — plan (code starts at M0 on approval)
**Supersedes:** `phase4-btc31-plan.md` (was DEFER; now flipped to GO)
**Base:** satoxcoin `3.0.0-rebase` (Ravencoin 4.6.1 = Bitcoin Core 0.21-era)
**Target:** Bitcoin Core **v31.1** (`9be056a` lineage, released 2026-07-08)
**Feature source:** Ravencoin **develop** (`408e372` = v4.6.2snapshot)

## Why we are doing this

1. **Security:** BTC 31.1 natively carries ~10 years of upstream fixes (2024/2025
   CVE waves) that we currently backport by hand. A modern base stops the
   backport treadmill.
2. **Alignment:** our sibling fork Meowcoin already rebased to BTC 30.2.0
   (2026-03). Staying on 0.21 leaves us ~9 majors behind the ecosystem.
3. **Clean lineage:** satoxcoin forks directly from Ravencoin (Bitcoin 0.15 →
   Ravencoin → satoxcoin). Meowcoin is **ignored entirely** — no code, no
   reference, no lineage. The old meowcoin-derived `main`/`2.4.0` branches are
   deprecated.

## Non-negotiable constraints

- **Consensus must be byte-identical.** A re-port must not change validation
  results on mainnet. The golden manifest + full sync parity (M6) is the gate.
- **KAWPOW security fixes carried forward** (commits 0e99ad487, c613eaaf2,
  b121f3b6f): mix_hash forgery, nHeight forgery, forged-epoch DoS,
  DAG-context race, index-load PoW gap. Meowcoin re-hit the nHeight bug class
  *after* its rebase (patched v30.2.5) — we port the fix, not the bug.
- **Asset-overflow soft-fork re-implemented with identical BIP9 params**
  (bit 11, start 1789862400 = 2026-09-20, timeout 1821398400 = 2027-09-20,
  1411/2016 threshold). `security/kawpow-hardening` stays **frozen** as the
  3.0.x activation line; activation per runbook happens only after 4.0 is out.
- **No meowcoin code** enters the tree.

## Branch structure

```
security/kawpow-hardening   FROZEN (3.0.x consensus/activation line, keep as-is)
3.0.0-rebase                FROZEN (release base)
rebase/ph4-btc31            CURRENT (this doc + lineage fix) [plan mode]
   └─ M0   BTC 31.1 baseline import (upstream remote)
   └─ M1   kawpow/x16r-port        (from security/kawpow-hardening)
   └─ M2   assets-port             (from ravencoin develop)
   └─ M3   community-fund+subsidy
   └─ M4   asset-overflow-softfork
   └─ M5   rpc/qt/wallet
   └─ M6   golden+sync-parity
   └─ M7   release 4.0.0
```

## Milestones (M0–M7)

### M0 — BTC 31.1 baseline
- Add `bitcoin` upstream remote; import `v31.1` release tree.
- Confirm build: `cmake -B build && cmake --build build` (CMake, C++20) + `make check`.
- Result: unmodified BTC 31.1 tree builds and tests green on our toolchain.

### M1 — Port KAWPOW + X16R/X16RV2 PoW
- Carry `src/crypto/ethash/`, `src/algo/`, `src/pow.cpp/h`, consensus PoW path.
- Adapt to 31.1 `CBlockHeader`/validation split (`src/kernel/`, `src/node/`).
- **Re-apply all 3 KAWPOW security fixes** (mix_hash, nHeight, epoch-DoS) +
  index-load gap.
- Gate: `test_satoxcoin --run_test=kawpow_tests,pow_tests` ported & passing.

### M2 — Port asset system from ravencoin develop
- `src/assets/*` (18 files), `src/assetstx.cpp/h`, RPC, validation hooks.
- From **ravencoin develop** (`408e372`) — the current source (includes #1287
  overflow, qualifier-memory fix, `transferwithmessage` fix).
- 353 asset hooks in old `validation.cpp` re-map to new kernel/node structure.
- Gate: `feature_assets.py`, `feature_raw_restricted_assets.py`,
  `feature_assets_mempool.py`, `rpc_assettransfer.py`.

### M3 — Community autonomous fund + satoxcoin subsidy
- Coinbase rule (10% community fund), halving interval 2100000 (~4 yr @1min),
  block subsidy 5000·COIN, `COINBASE_FLAGS`.
- Genesis/chainparams parity with `3.0.0-rebase` golden values.
- Gate: consensus/block tests + genesis hash check.

### M4 — Re-implement asset-overflow BIP9 soft-fork
- Re-apply the gated `CAmount +=` overflow checks
  (`bad-txns-input-asset-amount-negative`, etc.) via
  `IsTransferOverflowCheckDeployed()` on the new base.
- **Identical params:** bit 11, start 1789862400, timeout 1821398400,
  1411/2016, regtest 400/500. Window must not be invalidated.
- Gate: deployment asserts + `feature_assets.py` overflow cases.

### M5 — RPC + Qt GUI + BIP39/descriptor wallet
- Port asset/messaging RPC, restricted-asset UI, BIP39 wallet flow.
- Migrate legacy `CWallet` (BDB) to descriptor wallets on 31.1.
- Gate: RPC + functional wallet tests.

### M6 — Golden consensus manifest + full mainnet sync parity (THE hard gate)
- Regenerate golden manifest from `3.0.0-rebase`; port `consensus_golden_tests`.
- Full mainnet sync from genesis to tip on the 4.0 node; every header/block
  must match the 3.0.x node (`getblockhash` at checkpoints 100–5000+).
- Gate: golden + kawpow + pow + transaction + net + DoS suites + sync parity.

### M7 — Release 4.0.0
- Bump version, rebrand binaries (`satoxcoind`, `satoxcoin-cli`, `satoxcoin-qt`).
- Activation runbook (`asset-overflow-activation-runbook.md`) re-verified
  against 4.0; activation gated on pool signalling (pools → exchanges →
  explorers → nodes/wallets → solo miners).

## Per-module port mapping (old 0.21 → new 31.1)

| Subsystem | Old (0.21) | New (31.1) | Effort |
|---|---|---|---|
| Build | autotools `configure.ac` | **CMake** | Full rewrite |
| C++ | C++17 | **C++20** | Migration |
| Validation | `validation.cpp` (6441 lines) | `kernel/` + `node/` + `interfaces/` | Structural |
| Mempool | legacy `CTxMemPool` | cluster-mempool, `txorphanage` | Large |
| Wallet | legacy `CWallet` (BDB) | descriptor wallets | Major |
| Consensus lib | `libsatoxcoinconsensus` | `kernel` library | Re-arch |
| RPC | old registration | `RPCHelpMan` | Mechanical |
| Assets | `src/assets/*` + hooks | re-port onto kernel | High |
| Messaging/restricted | ravencoin-only | re-port | High |
| KAWPOW/X16R | `crypto/ethash/`, `algo/` | re-port + 3 fixes | High |
| Community fund | coinbase rule | re-apply | Low |

## Risk register

| Risk | Mitigation |
|---|---|
| Consensus drift breaks mainnet | M6 golden manifest + full sync parity is non-negotiable gate |
| Asset mempool behavior changes (cluster mempool) | Port ravencoin's mempool-asset indexes (Meowcoin precedent: `1b02ef2b5`) |
| Soft-fork window expires during port (2027-09-20 timeout) | Re-implement in M4 early; params byte-identical; activation deferred but ready |
| Descriptor-wallet migration breaks BIP39 wallets | M5 has dedicated migration tests; keep legacy import path where possible |
| 0.21→31.1 too large for one pass | Staged M0–M7; each milestone merges and is independently verifiable |

## Effort benchmark

Meowcoin did the equivalent (30.2, solo dev) as a single 1M-line graft in
**~7 weeks** (graft 2026-03-28 → v30.2.0 release 2026-05-14), then fixed
forward (v30.2.1→v30.2.6, incl. re-hitting the nHeight bug).

Our staged + verified approach is expected **longer (12–16 weeks of focused
work)** but consensus-safe: every milestone has a test gate, and the KAWPOW +
asset-overflow fixes are ported as known-good patches rather than discovered
post-release.

## Decision record

- [x] Target = BTC v31.1 (latest stable release, not master)
- [x] Feature source = Ravencoin **develop** (not master) — carries #1287
      asset-overflow, qualifier fix, P2SH, build updates
- [x] Meowcoin ignored entirely (no code, no reference)
- [x] Method = staged M0–M7 with gates (rejects meowcoin's graft approach)
- [x] kawpow-hardening stays frozen; soft-fork re-implemented on 4.0
- [ ] M0 baseline build (next action)
