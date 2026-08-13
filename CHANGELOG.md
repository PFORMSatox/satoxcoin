# Changelog

All notable changes to this project are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

> **Fork restart note (v3.0.0 baseline):** this project is a fork of Ravencoin
> (Bitcoin Core 0.21-era lineage). The pre-3.0 history contained fabricated and
> unverifiable release notes imported from upstream; those were removed. The
> changelog below is the authoritative record from the 3.0.0 baseline onward.
> Earlier history is summarized in
> `doc/release-notes/release-notes-legacy-history.md` (git-verified facts only).

## [Unreleased]

## [3.0.0] - 2026

**Major release-series reboot.** Rebased the entire codebase from the old
Bitcoin Core 0.15.x-era base onto **Ravencoin 4.6.1 / Bitcoin Core 0.21-era**
while preserving Satoxcoin's live-mainnet consensus byte-for-byte. Verified by a
golden consensus self-test and mainnet sync parity.

### Consensus (unchanged, verified)
- Mainnet subsidy 430,000,000 COIN (blocks 0–10) / 300 COIN (≥ 11), halving
  every 2,100,000 blocks.
- Community autonomous fund (10% mainnet / 15% testnet) enforced on every
  coinbase.
- KAWPOW / X16R / X16RV2 PoW, DarkGravityWave, all asset/messaging/restricted
  activation rules.
- 55 mainnet checkpoints to height 1,865,353; `defaultAssumeValid` at 1,859,491.
- **Verified:** `consensus_golden_tests` pass; mainnet sync at checkpoints
  100–8000 produces hashes identical to the golden manifest.

### Base modernization (from the 0.21-era base)
- Bitcoin Core 0.21-era networking, validation, wallet, and RPC internals.
- C++17 toolchain (already adopted in 2.4.0; confirmed on the new base).
- Assets/messaging/restricted-assets subsystem now the modern Ravencoin 4.6.1
  lineage (consensus-compatible — verified byte-identical asset markers).

### Security
- CVE-2024-52912 (timestamp overflow), CVE-2024-52917 (miniupnpc 2.2.2),
  CVE-2020-14198 (banlist cap) re-applied on the new base.
- Removed unsafe `-promiscuousmempoolflags`.
- Newer base carries the 0.21-era fixes for the 2024 CVE wave.

### Build / deps
- depends: Qt 5.12.11, Boost 1.71.0, OpenSSL 1.1.1k, ZeroMQ 4.3.4, libevent
  2.1.12, miniupnpc 2.2.2, libxkbcommon 0.8.4.
- Functional test framework runs on Python 3.12 (asyncore backport).

### Breaking changes for this series
- **MAJOR bump** because the underlying base changed (0.15-era → 0.21-era).
  Protocol version stays 70028.
- DB format follows the 0.21-era chainstate/block format; a full reindex is
  required when upgrading from 2.x.
