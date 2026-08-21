# Plan: doc/ Rebrand — BTC/Bitcoin → SATOX/Satoxcoin (Codebase is Truth)

**Status:** DRAFT for review — no edits applied yet
**Scope:** `doc/` and subfolders only (excluding `doc/release-notes/` archives unless noted). The C++ codebase (`src/`, `CMakeLists.txt`, `contrib/`) is the single source of truth.
**Ticker:** `SATOX` (mainnet subsidy `300 SATOX`, see `README.md:73`). Case mapping: `BTC→SATOX`, `btc→satox`, `Bitcoin→Satoxcoin`, `bitcoin→satoxcoin`.
**Date:** 2026-08-21 | Branch: `main` | Base: `4.0.3` (BTC 31.1 rebase, `CMakeLists.txt:15`)

---

## 1. Objective

Bring every user-facing sentence, example command, port number, and file reference in `doc/` in line with the live codebase so that a new operator copying from the docs gets a working Satoxcoin node. Remove contradictory Bitcoin branding while explicitly preserving historical/upstream references that must stay `bitcoin`.

Do NOT rename files that are truth in the codebase (`contrib/devtools/gen-bitcoin-conf.sh` stays that name); update only the prose around them.

## 2. Inventory (how hits were found)

```bash
grep -R -n --include="*.md" --include="*.txt" --include="*.in" --include="*.1" \
  -E "BTC|btc|Bitcoin|bitcoin" doc/ | wc -l  # → 3127
grep -R -l --include="*.md" -E "BTC|btc|Bitcoin|bitcoin" doc/ | sort
# → 154 files, ~90% concentrated in doc/release-notes/ (archival)
# Non-archival hits (≈180 lines) summarized in §4 below.
```

Full raw log: `/home/pform/.lean-ctx/tee/2026-08-21_120523_grep...` / `...120524_grep...`. Next pass must use:

```bash
grep -R -n --include="*.md" --include="*.txt" --include="*.in" --include="*.1" \
  -E "bitcoind|bitcoin-cli|bitcoin-qt|bitcoin-tx|bitcoin-wallet|bitcoin-util|bitcoin\.conf|~/.bitcoin|\.bitcoin/|bitcoin-.*\.1|BTC|Bitcoin|bitcoin" doc/
```

## 3. Decision Matrix — Change vs Keep

| Rule | Pattern | Action | Rationale / Example |
|------|---------|--------|---------------------|
| **C1** | `bitcoind` / `bitcoin-cli` / `bitcoin-qt` / `bitcoin-tx` / `bitcoin-wallet` / `bitcoin-util` / `bitcoin-node` / `bitcoin-gui` | **REPLACE** → `satoxcoind` / `satoxcoin-cli` / `satoxcoin-qt` / `satoxcoin-tx` / `satoxcoin-wallet` / `satoxcoin-util` / `satoxcoin-node` / `satoxcoin-gui` | Live binaries are `satoxcoin*` (`CMakeLists.txt`, `src/clientversion.cpp:UA_NAME="Satoxcoin"`). Exception: release-notes archives keep original names. |
| **C2** | Generic `Bitcoin Core` referring to *this* software | **REPLACE** → `Satoxcoin Core` | Codebase `CLIENT_NAME="Satoxcoin Core"` (`CMakeLists.txt:30`) |
| **C3** | `Bitcoin network` / `Bitcoin payments` / `play bitcoins` when describing *this* network | **REPLACE** → `Satoxcoin network` / `Satoxcoin payments` | Operator confusion; lineage doc already uses `Satoxcoin network` |
| **C4** | Standalone ticker `BTC` / `btc` / `₿` meaning currency unit | **REPLACE** → `SATOX` / `satox` | Ticker is `$SATOX` (`README.md:45,73`) |
| **C5** | `~/.bitcoin`, `.bitcoin/`, `/var/lib/.../bitcoin`, `bitcoin.conf` file refs | **REPLACE** → `~/.satoxcoin`, `satoxcoin.conf` | Truth data dir `doc/files.md: Linux $HOME/.satoxcoin/` |
| **C6** | Example ports `8333/8332/18333/18332/18444/18443/48333` | **REPLACE** → P2P `60777/7060/38333/19444`, RPC `7777/19766/38332/19443` | `src/kernel/chainparams.cpp:232,400,596,719` + `src/chainparamsbase.cpp:43-49` |
| **C7** | URL `github.com/bitcoin/bips` / `github.com/bitcoin/bitcoin` / `bitcoincore.org` / `en.bitcoin.it` / `bitcoin-seeder` / `bitcoin-core/libmultiprocess` / `Transifex bitcoin` when **citing upstream** | **KEEP** | External historical authority; changing breaks links. Add parenthetical ` (upstream Bitcoin)` where ambiguity arises |
| **C8** | `doc/release-notes/release-notes-*.md` (all 120 files) | **KEEP** (frozen archive) | Historical record of Bitcoin-era releases; do not rewrite |
| **C9** | `doc/lineage.md` sentence `Bitcoin Core (0.15 → 0.21) → Ravencoin → Satoxcoin` | **KEEP** | Lineage intentionally documents ancestry |
| **C10** | `Bitcoin Core v31.1` / `BTC 31.1` when attributing rebase source (`doc/security/audit/phase*-btc31*`, `doc/README.md:6`, `doc/bips.md:1`) | **KEEP** but normalize phrasing to `Bitcoin Core v31.1 (upstream)` | Truth base is BTC 31.1; removing erases provenance. Keep exactly `phase4/phase5` docs. |
| **C11** | `gen-bitcoin-conf.sh` filename / `Doxyfile.in: PROJECT_LOGO = doc/bitcoin_logo_doxygen.png` / `contrib/debian/copyright` attribution | **KEEP filename**, fix prose to note `generates satoxcoin.conf` | File exists on disk; renaming is a codebase change out-of-scope for this doc-only plan |
| **C12** | BIP prose `The URI format for Bitcoin payments` (`doc/bips.md:8`) | **OPTIONAL KEEP** — add clause ` (Satoxcoin uses satoxcoin: URI, same BIP21 format)` | BIP21 itself is Bitcoin-defined; local implementation is `satoxcoin:` (`src/qt/guiutil.cpp: parseSatoxcoinURI`) |
| **C13** | Case variants: `BTC`→`SATOX`, `Btc`→`Satox`, `btc`→`satox`, `Bitcoin`→`Satoxcoin`, `bitcoin`→`satoxcoin` | Apply per C1-C6 | Ensure `satoxcoin` lowercases in paths, `Satoxcoin` title case in prose |

> If in doubt: **search the codebase**. `grep -rn "8333\|bitcoind" src/` shows 8333 only appears in help-text examples or legacy vectors; Satoxcoin defaults are the C* above. When a doc example still shows `8333`, it is stale.

## 4. Per-File Action List (non-archival, ranked by risk)

### P0 — Must fix (operator copy-paste breaks)

| File | Hits | Action |
|------|------|--------|
| `doc/README_windows.txt` | 3 | **Rewrite** entire file: replace `Bitcoin Core` intro, `bitcoin-qt.exe`→`satoxcoin-qt.exe`, wiki link `en.bitcoin.it`→`docs.satoverse.io`. Currently 100% Bitcoin copy-paste. |
| `doc/man/satoxcoind.1`, `doc/man/satoxcoin-qt.1`, `doc/man/satoxcoin-cli.1`, `doc/man/satoxcoin-tx.1`, `doc/man/satoxcoin-wallet.1`, `doc/man/satoxcoin-util.1`, `doc/man/satoxcoin.1` | ~45 | **Regenerate** via `contrib/devtools/gen-manpages.py` on a built `build/` tree; then hand-patch description `Bitcoin network`→`Satoxcoin network`, `-port` defaults, `-rpcport` defaults (`7777/19766/38332/19443`), `bitcoincore.org`→`satoverse.io`, `github.com/bitcoin/bitcoin`→`github.com/satoverse/satoxcoin`. Currently shows Bitcoin ports/description. |
| `doc/assumeutxo.md:3,20,72` | 4 | `bitcoind`→`satoxcoind`, `bitcoin-cli`→`satoxcoin-cli`. Keep design doc link intact. |
| `doc/REST-interface.md:5,161` | 3 | Ports `8332/18332/...`→`7777/19766/38332/19443`; `bitcoind`→`satoxcoind`. Fix curl example `18332`→`7777` (or `19766` for testnet example). |
| `doc/build-osx.md:189,193` | 4 | `bitcoin` CLI (`./build/bin/bitcoin`)→`satoxcoin`, `bitcoind/bitcoin-qt`→`satoxcoind/satoxcoin-qt`. Fix path `Library/app Support` typo → `Library/Application Support`. |

### P1 — High (rebrand incomplete, confuses new devs)

| File | Hits | Action |
|------|------|--------|
| `doc/Doxyfile.in:27,54,1267,1275` | 4 | `PROJECT_NAME "Bitcoin Core"`→`"Satoxcoin Core"`, `PROJECT_LOGO doc/bitcoin_logo_doxygen.png`→`doc/assets/satoxcoin-banner.svg` (or keep file but update reference if banner exists), `DOCSET_BUNDLE_ID org.bitcoin.Bitcoin-Core`→`org.satoverse.satoxcoin`, `DOCSET_PUBLISHER_ID` similarly. |
| `doc/external-signer.md:1,3,7,14,17,28,42,45,52` | 12 | Title `Bitcoin Core`→`Satoxcoin Core`; all CLI `bitcoind/bitcoin-cli/bitcoin rpc`→`satoxcoind/satoxcoin-cli/satoxcoin rpc`. Keep HWI upstream `github.com/bitcoin-core/HWI` URL (C7). |
| `doc/multisig-tutorial.md:9,12,30,52,73,92,105,151,155,169` | 28 | Every `./build/bin/bitcoin rpc` / `bitcoind` → `satoxcoin` / `satoxcoind`; `any valid bitcoin address`→`any valid satoxcoin address`; keep `bitcoinops.org` / `bitcointalk.org` source links (C7). |
| `doc/multiprocess.md:7,28,29,44,46` | 6 | `bitcoin-node/bitcoin-gui/bitcoin -m`→`satoxcoin-node/satoxcoin-gui/satoxcoin -m`. Keep upstream `github.com/bitcoin-core/libmultiprocess` URL. |
| `doc/i2p.md:1,3,10,65,81,109-112,116,119` | 9 | Header `I2P support in Bitcoin Core`→`Satoxcoin Core`; `Bitcoin Core` prose → `Satoxcoin Core`; `bitcoin-cli`→`satoxcoin-cli`; keep `SAM v3.1` / `geti2p.net` links. |
| `doc/tor.md:28,30,87,89,104,126,131,134,139,156,182,186,189,192,214,220,225,232` | 18 | All `bitcoind/bitcoin-cli/bitcoin rpc`→`satoxcoin*`; `HiddenServiceDir /var/lib/tor/bitcoin-service/`→`satoxcoin-service/`; ports `8333/8334`→`60777/60778` (mainnet) with note `7060/7061` testnet etc. Keep `127.0.0.1:9051` Tor control. |
| `doc/tracing.md:1,3,14,174,326,425,433,437,449,473` | 11 | Title + prose `Bitcoin Core`→`Satoxcoin Core`; binary `bitcoind`→`satoxcoind` (`build/bin/satoxcoind`), `bench_bitcoin`→`bench_satoxcoin` if present; keep `stap` probe names. |
| `doc/developer-notes.md:314,315,325,349-351,392,394,395,414,471,472,569,575,662,1150,1287,1301` | 20+ | `bitcoind`→`satoxcoind`, `bitcoin-cli`→`satoxcoin-cli`, `test_bitcoin`/`bench_bitcoin`→`test_satoxcoin`/`bench_satoxcoin`, `play bitcoins`→`play satoxcoins` (or keep if quoting upstream technique). Keep `github.com/bitcoin/bitcoin` commit URLs (C7). |
| `doc/fuzzing.md:9,29,79,204,231,250,251,258` | 8 | `cd bitcoin/`→`cd satoxcoin/`; `Bitcoin Core`→`Satoxcoin Core` in OSS-Fuzz sentence but keep `projects/bitcoin-core` / `issues?q=bitcoin-core` URLs. |
| `doc/reduce-memory.md:3,8,10,26,55,60` | 7 | `bitcoind`→`satoxcoind`; `bitcoin's trustless model`→`Satoxcoin's trustless model`. |
| `doc/reduce-traffic.md:38` | 1 | `bitcoin's`→`Satoxcoin's` |
| `doc/productivity.md:47,48,49,156` | 4 | `bitcoind bitcoin-cli bitcoin-qt bench_bitcoin`→`satoxcoind satoxcoin-cli satoxcoin-qt bench_satoxcoin`; `git@github.com:bitcoin/bitcoin.git` **KEEP** as example remote (C7) but add comment `# upstream`. |
| `doc/files.md:140` | 1 | `[Generated](...gen-bitcoin-conf.sh)` keep filename, change cell text `satoxcoin.conf … [Generated] configuration file (via gen-bitcoin-conf.sh)` to avoid implying rename. |
| `doc/satoxcoin-conf.md:84,90` | 2 | Keep `gen-bitcoin-conf.sh` link; fix `cp share/examples/satoxcoin.conf ~/.satoxcoin`→`cp share/examples/satoxcoin.conf ~/.satoxcoin/satoxcoin.conf`. |
| `doc/init.md:49` + `doc/release-process.md:10` | 2 | `gen-bitcoin-conf.sh` anchor `#gen-bitcoin-confsh` keep; ensure section title note matches `doc/README.md: gen-bitcoin-confsh` or rename anchor to `gen-satoxcoin-conf` only if script renamed — do NOT rename script in this doc-only PR. |

### P2 — Low / deliberate keeps (document & annotate)

| File | Action |
|------|--------|
| `doc/lineage.md:6,25` | **No change** to `Bitcoin Core (0.15→0.21)` ancestry; optionally add `(upstream)` clarifier. |
| `doc/bips.md:1,3-26` | Header already `inherited via Bitcoin Core 31.1 rebase` — **keep**. BIP link targets (`github.com/bitcoin/bips`) **keep**. Only fix if a line says `Bitcoin Core GUI since v0.9.0` without clarifying Satoxcoin inheritance — add ` (inherited)` annotation rather than rename. |
| `doc/dnsseed-policy.md:7,9,19,29,45,47,54` | `Bitcoin community / Bitcoin nodes` in policy boilerplate → decide: either keep verbatim (policy borrowed from Bitcoin) or add `Satoxcoin (originally Bitcoin)` footnote. Recommend keep + footnote, do not bulk-replace. |
| `doc/translation_process.md:9,11,15,17,19,37,44,56` | Keep `Bitcoin's global adoption` + `Transifex Bitcoin project` URLs; change only `bitcoin_xx.ts`/`bitcoin_en.ts` if files were renamed in codebase — they are still `bitcoin_en.ts` on disk → keep filename, update prose to `Satoxcoin translation source (bitcoin_en.ts upstream name)`. |
| `doc/assets-attribution.md:1` | Keep `bitcoin source` sentence — it credits `contrib/debian/copyright` upstream attribution. Optionally prepend `Satoxcoin (derived from Bitcoin)` . |
| `doc/security/audit/phase4-btc31-plan.md`, `phase5-btc31-rebase-plan.md`, `phase3-verification.md`, `testnet-bootstrap-runbook.md:4,27` | **KEEP** all `BTC` / `Bitcoin` when describing rebase strategy; these are audit history. Only fix if they describe live runtime (e.g., `satoxcoind` invocation already correct). |
| `doc/design/*`, `doc/policy/*` | No BTC hits except `libmultiprocess` — keep upstream references. |
| `doc/cjdns.md`, `doc/p2p-bad-ports.md`, `doc/benchmarking.md`, `doc/dependencies.md`, `doc/descriptors.md`, `doc/JSON-RPC-interface.md`, `doc/zmq.md:90` | Minor or zero hits; verify but expect no change. `zmq.md:90` already correct `satoxcoin node/gui can be substituted`. |

## 5. Mapping Reference (apply case-sensitively, whole-word)

```
Bitcoin Core        → Satoxcoin Core
Bitcoin             → Satoxcoin          (prose, not in URLs)
bitcoin             → satoxcoin          (paths, lower-case prose)
bitcoind            → satoxcoind
bitcoin-cli         → satoxcoin-cli
bitcoin-qt          → satoxcoin-qt
bitcoin-tx          → satoxcoin-tx
bitcoin-wallet      → satoxcoin-wallet
bitcoin-util        → satoxcoin-util
bitcoin-node        → satoxcoin-node
bitcoin-gui         → satoxcoin-gui
~/.bitcoin          → ~/.satoxcoin
~/.bitcoin/         → ~/.satoxcoin/
btc / BTC ticker    → satox / SATOX      (only when meaning Satoxcoin currency; NOT in "BTC 31.1")
```

**Regex guard (do NOT replace inside):**
```
https?://github\.com/bitcoin/
https?://.*bitcoincore\.org
https?://.*en\.bitcoin\.it
bitcoin-seeder
bitcoin-core/
github\.com/bitcoin-core/
```
If a replacement would touch one of these, skip or annotate.

## 6. Execution Phases

**Phase 0 — Prep (no edits):**
1. Create this plan (`doc/plan-doc-rebrand.md`) and get reviewer sign-off.
2. Confirm ticker style: `SATOX` confirmed (`README.md:73`); if marketing prefers `SATOX` vs `SATOXCOIN`, update mapping table once.

**Phase 1 — Ports & binaries (P0):**
1. `doc/man/*.1` — rebuild-or-patch as single commit `docs(man): regenerate with Satoxcoin ports/URLs (codebase is truth)`.
2. `doc/assumeutxo.md`, `doc/REST-interface.md`, `doc/build-osx.md` — one commit `docs: rebrand daemon/CLI and fix ports`.
3. Verify: `grep -R "8333\|8332\|18333\|bitcoind" doc/*.md | grep -v release-notes | grep -v "github.com/bitcoin"` should shrink to upstream-only hits.

**Phase 2 — Full prose rebrand (P1):**
- Batch by directory to keep diffs reviewable: `doc/*.md` top-level, then `doc/design/`, then `doc/man/` if manual follow-ups.
- One commit per batch, e.g., `docs: rebrand doc/*.md bitcoin→satoxcoin (C1-C6, keep C7-C11)`.
- Use `sed` per file, not global repo rename, to avoid touching `src/` or `contrib/devtools/gen-bitcoin-conf.sh`.

**Phase 3 — Doxyfile & assets (P1):**
- `doc/Doxyfile.in` edits + check `doc/bitcoin_logo_doxygen.png` exists → if not, point to `doc/assets/satoxcoin-banner.svg` and add fallback comment.

**Phase 4 — Verification:**
```bash
# should return ~0 outside release-notes / upstream URLs
grep -R -n "bitcoind\|bitcoin-cli\|bitcoin-qt" doc/*.md doc/**/*.md | grep -v "release-notes" | grep -v "github.com/bitcoin" | grep -v "bitcoin-seeder"
# should show only lineage/audit deliberate keeps
grep -R -n "Bitcoin Core" doc/ | grep -v "release-notes" | grep -v "upstream" | grep -v "phase"
cmake -B build && cmake --build build --target man  # ensure gen-manpages still works
npm run build 2>&1 | head  # if docs site present — not required for core build
```

## 7. Risks & Non-Goals

- **Do NOT rename** `contrib/devtools/gen-bitcoin-conf.sh`, `src/bitcoin-build-config.h.in` references, or any `src/` identifier — that is a codebase change requiring separate consensus.
- **Do NOT rewrite** `doc/release-notes/*.md` archives — they are immutable history.
- Over-replacing `BTC 31.1` → `SATOX 31.1` would erase upstream provenance; keep `Bitcoin Core 31.1 (upstream)` phrasing per C10.
- Ticker `BTC` appears in code comments about block subsidy halving — those are consensus comments, out-of-scope for docs.

## 8. Verification Checklist

- [ ] No user-facing `doc/*.md` (ex release-notes, ex upstream URLs) contains `bitcoind` / `bitcoin-cli` / `bitcoin-qt`
- [ ] `grep -R "8333\|8332" doc/*.md` returns only `release-notes/` or annotated ` (deprecated Bitcoin default)` notes
- [ ] `doc/README_windows.txt` reads as Satoxcoin, not Bitcoin
- [ ] `doc/Doxyfile.in` `PROJECT_NAME` is `Satoxcoin Core`
- [ ] `doc/man/*.1` `-port` / `-rpcport` match `src/kernel/chainparams.cpp` + `src/chainparamsbase.cpp`
- [ ] `doc/tor.md` HiddenServiceDir + ports use Satoxcoin values
- [ ] Reviewer confirms C7 keep-list is acceptable (no broken external links)

## 9. Future Work (outside this plan)

- Decide whether to rename `gen-bitcoin-conf.sh` → `gen-satoxcoin-conf.sh` with symlink (requires `contrib/` + doc changes together).
- Add `doc/lineage.md` diagram update if 4.0.x → 4.1 branding changes.

---

**Sign-off:** Merge this plan first, then execute Phase 1 PR. Each phase is one PR, 1 reviewer, `codebase is truth` checked via `grep` gates above.
