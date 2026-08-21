# Lineage

Full derivation history for Satoxcoin Core.

```
Bitcoin Core (0.15 → 0.21)
  └── Ravencoin (v4.6.1 / develop, autotools + BerkeleyDB)
        └── Satoxcoin 2.1.0 (last public, autotools + BerkeleyDB)
              └── Satoxcoin 4.0 (main → Bitcoin Core 31.1, CMake + SQLite)
                    └── patch/frozen: asset-overflow soft-fork (BIP9 bit 11) — on top of 4.0
                        branch `consensus/asset-overflow` (tag `asset-overflow-frozen`)
```

| Base | Version | What was taken |
|:-----|:--------|:---------------|
| **Ravencoin** | 4.6.1 (Bitcoin 0.21 base) | Asset system, KAWPOW/X16RV2 PoW, restricted assets, qualifiers, messaging, HIP2 8MB blocks |
| **Satoxcoin 2.1.0** | last public | Dev fund / P2E fund (10%), branding, DGW |
| **Satoxcoin 4.0** | 4.0.x (main) | Full rebase to **Bitcoin Core 31.1** — 16 CVEs, C++17/CMake, SQLite/descriptor wallets, cherry-picked KAWPOW hardening, 55 checkpoints, indexes, assumeUTXO — **overflow soft-fork NOT included** |
| **Frozen patch** | `consensus/asset-overflow` | Asset-transfer overflow check (BIP9 bit 11) + wallet lock fix — **built on top of 4.0**, activation is slow/per-policy |

## Key Improvements over 2.1.0

| Area | 2.1.0 (last public) | 4.0.x (this release) |
|:-----|:--------------------|:---------------------|
| Bitcoin base | 0.21 (Ravencoin 4.6.1) | **31.1** — 16 CVEs fixed (CVE-2024-52911 → CVE-2025-54605) |
| Build / language | autotools, **C++11**, BerkeleyDB (BDB) wallets | **CMake**, **C++17**, **SQLite** + descriptor wallets |
| KAWPOW | unhardened (mix_hash/nHeight/epoch-DoS open) | **hardened** — 3 fixes from `security/kawpow-hardening` |
| Asset system | height-activated (`nAssetActivationHeight=1`), no overflow check | **BIP9** bits 6–10, **6 hardening fixes** (ConnectBlock/DisconnectBlock, reissue overflow, flush corruption). Overflow soft-fork (bit 11) is on frozen branch `consensus/asset-overflow` — **not in this release**, activation is slow/per-policy |
| Block size | 4 MB serial / 8 MB HIP2 already present | **retained 8 MB HIP2** |
| Checkpoints | 1 (genesis only) | **55** (height 0 → 1,865,353) |
| Indexes / RPCs | none (no address/spent/timestamp) | **full index system** — `addressindex`, `spentindex`, `timestampindex` + 7 RPCs, `getaddressdeltas` etc. |
| AssumeUTXO | absent | present (header sync + snapshot load) |
