<div align="center">


<br>

**Satoxcoin ($SATOX)** — A PoW blockchain with native asset support, designed for Play2Earn gaming.

<br>

![Version](https://img.shields.io/badge/4.0.0-blue?style=flat-square&label=version)
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

Satoxcoin Core 4.0 is a major rebase from Bitcoin Core 0.21 (Ravencoin 4.6.1 base) to **Bitcoin Core 31.1**, bringing all BTC security fixes while preserving the complete Satoxcoin asset system, KAWPOW consensus, and community fund.

### Key Improvements

| Feature | Details |
|:--------|:--------|
| BTC 31.1 security base | 16 CVEs fixed (CVE-2024-52911 through CVE-2025-54605) |
| C++17 / CMake | Modern build system, faster compilation |
| 55 mainnet checkpoints | Full chain hardening (height 0 → 1,865,353) |
| HIP2 8MB blocks | Satoxcoin-specific block size limit |
| KAWPOW security hardening | mix\_hash forgery, nHeight forgery, epoch-DoS fixes |
| Asset system hardening | 6 critical/high security fixes in ConnectBlock/DisconnectBlock |
| Full asset index system | Address, spent, and timestamp indexes with 7 RPCs |
| Asset overflow BIP9 | Soft-fork prepared (activation deferred per policy) |

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

| Dependency | Minimum Version |
|:-----------|:----------------|
| C++ compiler | GCC 10+ / Clang 12+ (C++17) |
| CMake | 3.20+ |
| Ninja | recommended |
| Boost | 1.74+ |
| libevent | — |
| SQLite | bundled |

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
Bitcoin Core (0.15)
  └── Ravencoin (v4.6.1 / develop)
        └── Satoxcoin (3.0.0-rebase)
              └── Satoxcoin 4.0 (rebase → Bitcoin Core 31.1)
```

| Base | Version | What was taken |
|:-----|:--------|:---------------|
| **Bitcoin Core** | 31.1 | Consensus kernel, C++17, CMake build, security base, UTXO model, script engine, mempool |
| **Ravencoin** | 4.6.1 | Asset system, KAWPOW/X16RV2 PoW, restricted assets, qualifiers, messaging, HIP2 8MB blocks |
| **Satoxcoin 3.0.0** | 3.0.0-rebase | KAWPOW security fixes, asset-overflow BIP9, community autonomous fund (10% P2E), branding, 55 checkpoints |
| **Satoxcoin 4.0** | 4.0 | All above + BTC 31.1 security (16 CVEs), C++17, CMake, modernized asset DB, SQLite wallet, indexes |

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

<div align="center">

**[Website](https://www.satoverse.io)** · **[Explorer](https://xplore.satoverse.io)** · **[Discord](https://discord.com/invite/GFZYFuuHVq)** · **[Twitter](https://x.com/Satoverse_io)** · **[Docs](https://docs.satoverse.io)**

</div>
