<img src="https://www.satoverse.io/wp-content/uploads/2023/06/Satoxcoin-banner-github.png" alt="Satoxcoin - The future of play2earn" title="Satoxcoin - The future of play2earn">

**PS!** This repo ONLY contains the Satoxcoin Core Wallet, <b>NOT</b> the P2E System.

<img src="https://img.shields.io/badge/4.0.0-blue?style=flat-square&label=version" alt="Version">
<img src="https://img.shields.io/badge/-C++-darkorchid?logoColor=white&style=flat-square" alt="C++">
<img src="https://img.shields.io/badge/-KawPoW-lightcoral?logoColor=white&style=flat-square" alt="KawPoW">
<img src="https://img.shields.io/badge/-BTC_31.1_rebase-darkorange?logoColor=white&style=flat-square" alt="BTC 31.1">
<img src="https://img.shields.io/github/commit-activity/m/PFORMSatox/satoxcoin?style=flat-square&logo=github&color=deeppink" alt="Commits"></br>
<img src="https://img.shields.io/discord/954156720639316028?style=%20flat-square&logo=discord&logoColor=white&label=Discord&color=deeppink&link=https%3A%2F%2Fdiscord.com%2Finvite%2FGFZYFuuHVq" alt="Discord"></a>
<img src="https://img.shields.io/website?up_message=Online&up_color=deepgreen&down_message=offline&down_color=lightgray&url=https%3A%2F%2Fwww.satoverse.io&style=flat-square&label=satoverse.io"></a>
<img src="https://img.shields.io/website?up_message=Online&up_color=deepgreen&down_message=offline&down_color=lightgray&url=https%3A%2F%2Fxplore.satoverse.io&style=flat-square&label=Explorer"></a>
<img src="https://img.shields.io/twitter/follow/Satoverse_io?style=flat-square&logo=twitter&logoColor=deepblue&color=deeppink" alt="Twitter"></img>

## What is Satoxcoin?

**Satoxcoin ($SATOX)** is a PoW blockchain with native asset support, designed for Play2Earn gaming. Built on Bitcoin Core 31.1 with KAWPOW consensus, it provides full Ravencoin-compatible asset issuance, transfer, and management while maintaining the security guarantees of the modern Bitcoin codebase.

## What is Satoxcoin Core 4.0?

Satoxcoin Core 4.0 is a major rebase of the Satoxcoin node from Bitcoin Core 0.21 (Ravencoin 4.6.1 base) to **Bitcoin Core 31.1**, bringing all BTC security fixes through v31.1 (the latest release) while preserving the complete Satoxcoin asset system, KAWPOW consensus, and community fund.

**Key improvements in 4.0:**
- **BTC 31.1 security base** — 16 CVEs fixed (CVE-2024-52911 through CVE-2025-54605)
- **C++20 / CMake** — modern build system, faster compilation
- **55 mainnet checkpoints** — full chain hardening (0→1,865,353)
- **HIP2 8MB blocks** — satoxcoin-specific block size limit
- **KAWPOW security hardening** — mix_hash forgery, nHeight forgery, epoch-DoS fixes
- **Asset system hardening** — 6 critical/high security fixes in ConnectBlock/DisconnectBlock
- **Full asset index system** — address, spent, and timestamp indexes with 7 RPCs
- **Asset overflow BIP9** — soft-fork prepared (activation deferred per policy)

## Satoxcoin Specification

| Property | Value |
|----------|-------|
| **Total Supply** | 8 Billion (minted over ~100 years) |
| **Algorithm** | KawPoW |
| **Type** | PoW |
| **Block Time** | 60 seconds |
| **Block Reward** | 90% PoW / 10% P2E Fund |
| **Halving Interval** | 2,100,000 blocks (~4 years) |
| **Initial Subsidy** | 430,000,000 SATOX (first 10 blocks) |
| **Post-halving Subsidy** | 300 SATOX |
| **Community Fund** | 10% of subsidy to `SQ5iQMsmqZiYY96rTx5Hisd7sx5GiGUbbN` |
| **P2P Port** | 60777 (mainnet) / 7060 (testnet) / 19444 (regtest) |
| **BIP44 Coin Type** | 1669 |
| **Base58 Address Prefix** | 63 (S) / 122 (script) / 112 (secret key) |

## What makes Satoxcoin unique?

- ✅ First P2E without the need for dedicated servers
- ✅ First P2E that works on 1160+ games on STEAM
- ✅ First P2E that works with gaming consoles (XBOX, STEAMDECK)

## Building from Source

### Prerequisites

- C++20 compatible compiler (GCC 13+ / Clang 16+)
- CMake 3.25+
- Ninja (recommended)
- Boost 1.74+
- libevent
- BerkeleyDB 4.8 (for legacy wallet)

### Build Commands

```bash
# Configure and build
cmake -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_SATOXCOIN_CLI=ON \
  -DBUILD_SATOXCOIN_TX=ON \
  -DBUILD_SATOXCOIN_UTIL=ON

cmake --build build -j$(nproc)

# Run tests
cd build
ctest -j$(nproc)

# Functional tests (optional)
python3 test/functional/test_runner.py
```

See [doc/build-*.md](doc/build-*.md) for platform-specific build instructions.

## Wallets

| Wallet | Platform | Link |
|--------|----------|------|
| **Core Wallet** | Desktop (Win/Mac/Linux) | [GitHub Releases](https://github.com/PFORMSatox/satoxcoin/releases) |
| **Vidulum** | Android | [Play Store](https://play.google.com/store/apps/details?id=com.vidulumwallet.app) |
| **BeeHive** | Desktop | [beehivewallet.link](https://beehivewallet.link/) |
| **BeeHive** | Android | [Play Store](https://play.google.com/store/apps/details?id=com.beehive.beehivemulti_coinwallet) |
| **Paper Wallet** | Web | [walletgenerator](https://walletgenerator-njizr0am7-nao20010128nao.vercel.app) |

## Links

- **Homepage:** https://www.satoverse.io
- **Explorer:** https://xplore.satoverse.io
- **Discord:** https://discord.com/invite/GFZYFuuHVq
- **Documentation:** https://docs.satoverse.io
- **GitHub:** https://github.com/PFORMSatox/satoxcoin

## Testing

### Automated Testing

Run the test suite with:
```bash
cd build && ctest -j$(nproc)
```

### Functional Tests

```bash
cd test/functional
python3 test_runner.py
```

The functional test suite includes asset-specific tests: `feature_assets.py`, `feature_assets_reorg.py`, `feature_assets_mempool.py`, `feature_listmyassets.py`, `feature_unique_assets.py`, `feature_restricted_assets.py`, and `rpc_assettransfer.py`.

## License

Satoxcoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more information.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for the contribution workflow.
