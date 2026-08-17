Satoxcoin Core version 4.0.1 is now available from:

  <https://github.com/PFORMSatox/satoxcoin/releases/tag/v4.0.1>

This is the first release of Satoxcoin Core 4.0, a major rebase from Bitcoin
Core 0.21 (Ravencoin 4.6.1 base) to **Bitcoin Core 31.1**.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/PFORMSatox/satoxcoin/issues>

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes in some cases), then run the installer
(on Windows) or just copy over `satoxcoind`/`satoxcoin-qt` (on Linux/macOS).

Upgrading directly from Satoxcoin Core 3.x is supported. The data directory
will be migrated on first run.

Compatibility
==============

Satoxcoin Core is supported and tested on the following operating systems:
Ubuntu 22.04+, macOS 14+, and Windows 10+.

Notable Changes
===============

### Bitcoin Core 31.1 Security Base

Satoxcoin 4.0 is rebased onto Bitcoin Core 31.1, inheriting 16 CVE fixes:

- CVE-2024-52911 through CVE-2025-54605
- Fixes across validation, P2P, wallet, and crypto subsystems

### Build System Modernization

- Migrated from autotools to **CMake** (minimum 3.20)
- Updated to **C++17** standard
- Faster compilation with Ninja support

### KAWPOW Security Hardening

- Fixed mix_hash forgery vulnerability
- Fixed nHeight forgery vulnerability
- Fixed forged-epoch DoS vector
- Fixed DAG-context race condition
- Fixed index-load PoW gap

### Asset System Hardening

- 6 critical/high security fixes in ConnectBlock/DisconnectBlock
- Non-fatal error handling for asset operations
- Reissue overflow protection
- Flush corruption prevention

### Full Asset Index System

- Address index (balances, history)
- Spent index (output tracking)
- Timestamp index (time-based queries)
- 7 new RPCs: `getassetindexinfo`, `getassetindexbalance`,
  `getassetindexhistory`, `getassetindexspent`, `getassetindextimestamp`,
  `getassetindexsummary`, `getassetindexblock`

### HIP2 8MB Blocks

- Satoxcoin-specific block size limit of 8MB
- Enabled via HIP2 proposal

### Mainnet Checkpoints

- 55 checkpoints added (height 0 through 1,865,353)
- Full chain hardening against deep reorgs

### CI/CD Improvements

- GitHub Actions release workflow (Linux, macOS, Windows, Docker)
- Dependabot for automated dependency updates
- Docker image published to `ghcr.io`

Known Issues
============

- Asset overflow BIP9 soft-fork is prepared but activation is deferred
  until the 4.0 line is verified and running stable
- Qt wallet branding updated; some legacy icons may appear on first run

Upgrading from 3.x
===================

If upgrading from Satoxcoin Core 3.x:

1. Shut down the old node completely
2. Replace binaries with the 4.0.1 versions
3. Start the node — the data directory will be migrated automatically
4. Allow the node to reindex if prompted (this may take some time)

The new SQLite wallet format will be created on first run. BDB wallets
from 3.x are automatically migrated.

Credits
=======

Thanks to everyone who contributed to Satoxcoin Core 4.0.1:

- Satoxcoin Core developers
- Bitcoin Core developers (upstream base)
- Ravencoin Core developers (asset system lineage)
