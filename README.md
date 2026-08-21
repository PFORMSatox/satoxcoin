<div align="center">


<br>

**Satoxcoin ($SATOX)** — A PoW blockchain with native asset support, designed for Play2Earn gaming.

<br>

![Version](https://img.shields.io/badge/4.0.3-blue?style=flat-square&label=version)
![C++](https://img.shields.io/badge/-C++17-darkorchid?style=flat-square)
![KawPoW](https://img.shields.io/badge/-KawPoW-lightcoral?style=flat-square)
![BTC 31.1](https://img.shields.io/badge/-BTC_31.1_rebase-darkorange?style=flat-square)

[![Commits](https://img.shields.io/github/commit-activity/m/PFORMSatox/satoxcoin?style=flat-square&logo=github&color=deeppink)](https://github.com/PFORMSatox/satoxcoin)
[![Discord](https://img.shields.io/discord/954156720639316028?style=flat-square&logo=discord&logoColor=white&label=Discord&color=deeppink)](https://discord.com/invite/GFZYFuuHVq)
[![Website](https://img.shields.io/website?up_message=Online&up_color=deepgreen&down_message=offline&down_color=lightgray&url=https%3A%2F%2Fwww.satoverse.io&style=flat-square&label=satoverse.io)](https://www.satoverse.io)
[![Explorer](https://img.shields.io/website?up_message=Online&up_color=deepgreen&down_message=offline&down_color=lightgray&url=https%3A%2F%2Fxplore.satoverse.io&style=flat-square&label=Explorer)](https://xplore.satoverse.io)
[![Twitter](https://img.shields.io/twitter/follow/Satoverse_io?style=flat-square&logo=twitter&logoColor=deepblue&color=deeppink)](https://x.com/Satoverse_io)

<br>

<a href="#what-is-satoxcoin">About</a> · <a href="#specification">Specification</a> · <a href="#building-from-source">Build</a> · <a href="#lineage">Lineage</a> · <a href="https://discord.com/invite/GFZYFuuHVq">Discord</a> · <a href="https://xplore.satoverse.io">Explorer</a>

</div>

---

> **Note:** This repo contains **Satoxcoin Core** (the wallet & node) only. The Play2Earn system is a separate component.

## Table of Contents

- [What is Satoxcoin?](#what-is-satoxcoin)
- [What is Satoxcoin Core 4.0?](#what-is-satoxcoin-core-40)
- [Key Improvements](#key-improvements)
- [Specification](#specification)
- [What Makes Satoxcoin Unique?](#what-makes-satoxcoin-unique)
- [Building from Source](#building-from-source)
- [Lineage](#lineage)
- [Contributing](#contributing)
- [License](#license)

---

## What is Satoxcoin?

**Satoxcoin ($SATOX)** is a PoW blockchain with native asset support, designed for Play2Earn gaming. Built on Bitcoin Core 31.1 with KAWPOW consensus, it provides full Ravencoin-compatible asset issuance, transfer, and management while maintaining the security guarantees of the modern Bitcoin codebase.

## What is Satoxcoin Core 4.0?

Satoxcoin Core 4.0 is a major rebase from the last public release **2.1.0** (Bitcoin 0.21 / Ravencoin 4.6.1 base, autotools + BerkeleyDB) to **Bitcoin Core 31.1**, bringing all BTC security fixes while preserving the complete Satoxcoin asset system, KAWPOW consensus, and community fund. The intermediate `3.0.x` line was internal/private and never publicly released.

### Key Improvements over 2.1.0

| Area | 2.1.0 (last public) | 4.0.x (this release) |
|:-----|:--------------------|:---------------------|
| Bitcoin base | 0.21 (Ravencoin 4.6.1) | **31.1** — 16 CVEs fixed (CVE-2024-52911 → CVE-2025-54605) |
| Build / language | autotools, **C++11**, BerkeleyDB (BDB) wallets | **CMake**, **C++17**, **SQLite** + descriptor wallets |
| KAWPOW | unhardened (mix\_hash/nHeight/epoch-DoS open) | **hardened** — 3 fixes from `security/kawpow-hardening` |
| Asset system | height-activated (`nAssetActivationHeight=1`), no overflow check | **BIP9** bits 6–10, **6 hardening fixes** (ConnectBlock/DisconnectBlock, reissue overflow, flush corruption). Overflow soft-fork (bit 11) is on frozen branch `security/kawpow-hardening` — **not in this release**, activation is slow/per-policy |
| Block size | 4 MB serial / 8 MB HIP2 already present | **retained 8 MB HIP2** |
| Checkpoints | 1 (genesis only) | **55** (height 0 → 1,865,353) |
| Indexes / RPCs | none (no address/spent/timestamp) | **full index system** — `addressindex`, `spentindex`, `timestampindex` + 7 RPCs, `getaddressdeltas` etc. |
| AssumeUTXO | absent | present (header sync + snapshot load) |

---

## Specification

| Property | Value |
|:---------|:------|
| **Total Supply** | 8 Billion (minted over ~100 years) |
| **Algorithm** | KawPoW |
| **Type** | PoW |
| **Block Time** | 60 seconds |
| **Block Reward** | 90% PoW / 10% P2E Fund |
| **Halving Interval** | 2,100,000 blocks (~4 years) |
| **Post-halving Subsidy** | 300 SATOX |
| **Dev / P2E Fund** | 10% of subsidy to `SQ5iQMsmqZiYY96rTx5Hisd7sx5GiGUbbN` |
| **P2P Port** | 60777 (mainnet) · 7060 (testnet) · 19444 (regtest) |
| **BIP44 Coin Type** | 1669 |
| **Base58 Prefix** | 63 (S) · 122 (script) · 112 (secret key) |

---

## What Makes Satoxcoin Unique?

- **No dedicated servers** — First P2E that works without infrastructure overhead
- **1,160+ Steam games** — Native support across the Steam catalog
- **Console support** — Works with Xbox and Steam Deck

---

## Building from Source

### Prerequisites

| Dependency | Minimum Version | Notes |
|:-----------|:----------------|:------|
| C++ compiler | **GCC 12.1+ / Clang 17.0+** (C++17) | per `doc/dependencies.md` |
| CMake | **3.22+** | |
| Boost | **1.74+** | header-only + `boost::thread` via `libboost-dev` |
| libevent | **2.1.8+** | `libevent-dev` |
| SQLite | **3.7.17+** | `libsqlite3-dev` (wallet) — **replaces BerkeleyDB** from 2.1.0 |

> **Quick install (Ubuntu/Debian, prompted sudo):**
> ```bash
> contrib/install-dependencies.sh          # core + wallet, no GUI
> contrib/install-dependencies.sh --with-gui  # + Qt6 / qrencode
> contrib/install-dependencies.sh --dry-run   # preview, no sudo
> ```
> Or install manually per [`doc/build-unix.md`](doc/build-unix.md) (`sudo apt install build-essential cmake libboost-dev libevent-dev libsqlite3-dev` …)
> or self-compile everything via the [`depends` system](depends/README.md) (`make -C depends -j$(nproc)`), which needs no `sudo`.

### Build

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
```

### Test

```bash
cd build
ctest -j$(nproc)

# Functional tests
python3 test/functional/test_runner.py
```

See [`doc/build-*.md`](doc/build-*.md) for platform-specific instructions.

---

## Lineage

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
| **Satoxcoin 2.1.0** | last public | Community fund (10% P2E), branding, DGW |
| **Satoxcoin 4.0** | 4.0.x (main) | Full rebase to **Bitcoin Core 31.1** — 16 CVEs, C++17/CMake, SQLite/descriptor wallets, cherry-picked KAWPOW hardening, 55 checkpoints, indexes, assumeUTXO — **overflow soft-fork NOT included** |
| **Frozen patch** | `consensus/asset-overflow` | Asset-transfer overflow check (BIP9 bit 11) + wallet lock fix — **built on top of 4.0**, activation is slow/per-policy |

---

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for the contribution workflow.

## Security

See [SECURITY.md](SECURITY.md) for the security policy and vulnerability disclosure process.

## License

Satoxcoin Core is released under the [MIT License](COPYING).

## Copyright

Copyright (c) 2013-2022 The Bitcoin Core developers
Copyright (c) 2014-2018 The Raven Core developers
Copyright (c) 2022-present The Satoxcoin Core developers

---

<p align="center">
  <a href="https://www.satoverse.io"><b>Website</b></a> · 
  <a href="https://xplore.satoverse.io"><b>Explorer</b></a> · 
  <a href="https://discord.com/invite/GFZYFuuHVq"><b>Discord</b></a> · 
  <a href="https://x.com/Satoverse_io"><b>Twitter</b></a> · 
  <a href="https://docs.satoverse.io"><b>Docs</b></a>
</p>
