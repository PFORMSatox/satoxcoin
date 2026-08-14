# Phase 4 — Bitcoin Core 31.x Rebase: Feasibility Assessment & Plan

**Date:** 2026-08-13
**Status:** SUPERSEDED — see `phase5-btc31-rebase-plan.md` (recommendation flipped to GO)
**Base:** satoxcoin 3.0.0-rebase (Ravencoin 4.6.1 = Bitcoin Core 0.21-era)
**Target:** Bitcoin Core v31.1 (`9be056a`, released 2026)

## The gap: 0.21 → 31.1 is ~10 major versions of Bitcoin Core

| Aspect | Current base (0.21-era) | Target (31.1) | Impact |
|---|---|---|---|
| Build system | autotools (`configure.ac`) | **CMake** (`CMakeLists.txt`, `cmake/`) | Full build-system rewrite |
| C++ standard | C++17 | **C++20** | Compiler/stdlib migration |
| Mempool | legacy `CTxMemPool` | cluster-mempool era, `txorphanage` | Large rewrite |
| Validation | monolithic `validation.cpp` (6441 lines) | split into `kernel/`, `node/`, `interfaces/` modules | Structural re-port |
| Wallet | legacy `CWallet` (BDB) | descriptor wallets | Major |
| Consensus lib | `libsatoxcoinconsensus` | `kernel` library | Re-architecture |
| RPC | old-style registration | modern `RPCHelpMan` | Mechanical |
| Assets (satoxcoin) | `src/assets/*` + asset consensus | **does not exist in BTC** | Full re-port needed |
| Messaging/restricted | satoxcoin/Ravencoin-only | **does not exist in BTC** | Full re-port needed |
| KAWPOW/X16R | `src/crypto/ethash/`, `src/algo/` | **not in BTC** | Full re-port needed |
| Community fund | satoxcoin coinbase rule | **not in BTC** | Re-apply |

## Feasibility assessment

**This is effectively a re-port, not a rebase.** Phase 3 was tractable because
Ravencoin 4.6.1 was the *same lineage* (0.21-era) with the assets/KAWPOW code
already present and byte-identical. Phase 4 is different:

1. **Every satoxcoin/Ravencoin-specific subsystem must be re-ported** onto a
   fundamentally restructured BTC 31.x codebase:
   - assets (18 files + RPC + validation hooks)
   - messaging / restricted assets / rewards
   - KAWPOW + X16R/X16RV2 PoW (`crypto/ethash/`, `algo/`)
   - community autonomous fund (coinbase rule)
   - BIP39 wallet integration
2. **The base APIs changed so much** that the satoxcoin code would need
   substantial adaptation (new mempool, new validation structure, new RPC
   framework, C++20, CMake).
3. **CVE coverage:** the 2024-wave fixes we backported in Phase 1/3 are *already
   present* in BTC 31.x (they were fixed upstream in 0.22-29). So a 31.x base
   would carry those fixes natively — that's the main *benefit*.

## The real question: is it worth it?

**Benefit of BTC 31.x base:**
- Native fixes for ALL known CVEs (2024 wave, 2025 wave)
- Modern mempool (cluster), assumeutxo, modern RPC/descriptors
- C++20 + CMake (modern toolchain)
- Continued upstream security fixes (Bitcoin Core is actively maintained)

**Cost:**
- Very large re-port effort (weeks-months), high regression risk
- Every consensus-critical subsystem (assets, PoW, community fund) re-verified
  against the golden manifest + full sync parity
- The 3.0.0-rebase (Phase 3) already gives: modern 0.21 base, C++17, all CVEs
  backported, verified consensus

## Recommendation

**Defer Phase 4 indefinitely, or treat as a stretch goal.** The 3.0.0-rebase
already achieves the security goals (all CVEs fixed, verified consensus).
The marginal security benefit of 31.x is small (newer CVEs can be backported to
the 0.21 base as they arise — which is what we already do via
`audit/cve-audit.md`). The cost/risk of a full 0.21→31 re-port is very high
for a small-altcoin team.

If pursued later, the sensible path is **incremental**: target 0.21 → 22/24
first (smaller jumps), not a single 0.21 → 31 leap.

## If decided (stretch-goal plan)

1. **M0**: build BTC 31.1 baseline (CMake, C++20) — verify it compiles
2. **M1**: re-port PoW (KAWPOW/X16R) onto 31.x CBlockHeader/validation
3. **M2**: re-port assets/messaging/restricted + community fund
4. **M3**: re-port BIP39 wallet
5. **M4**: re-port RPC + qt GUI
6. **M5**: golden test + full sync parity (the hard gate)
7. **M6**: release

## Status
- [x] Gap assessment (0.21 → 31.1 = 10 majors, build/C++/structure all change)
- [x] Recommendation accepted — **PROCEED (GO)** per `phase5-btc31-rebase-plan.md`
- [x] Superseded by Phase 5 plan (this file kept for the feasibility analysis)
- [ ] M0 baseline build
