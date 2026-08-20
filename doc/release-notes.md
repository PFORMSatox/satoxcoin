Satoxcoin Core version 4.0.2 is now available from:

  <https://github.com/PFORMSatox/satoxcoin/releases/tag/v4.0.2>

This release fixes the peer-discovery and disk-space reporting issues found
after the 4.0 rebase, and completes the Satoxcoin branding and asset GUI work.

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

### Peer Discovery Fix (DNS Seeds)

Fixed a regression from the Bitcoin Core 31.1 rebase where the mainnet seed
hostnames (`xnode1.satoverse.io`, `xnode2.satoverse.io`) were stored as empty
strings, so nodes could never discover peers. Fresh nodes now resolve the seed
nodes and connect to the network on first start.

### Disk-Space Warning Fix

The mainnet assumed blockchain size still carried the upstream Bitcoin value
(856 GB). It now reflects the real Satoxcoin chain size (~5 GB), so the
disk-space warning and the Qt intro wizard show correct values.

### Satoxcoin Branding

- Ticker updated to `SATOX` / `mSATOX` / `µSATOX` throughout the Qt wallet
- All wallet dialog strings, status tips, and forms rebranded from Bitcoin
  to Satoxcoin
- All 101 locale translation files updated
- Executables and helper binaries renamed to `satoxcoin-*`
  (`satoxcoin-node`, `satoxcoin-gui`, `satoxcoin-qt`, `satoxcoin-cli`,
  `satoxcoin-wallet`, `satoxcoin-tx`, `satoxcoin-util`, `satoxcoin-chainstate`)
- `satoxcoin:` URI scheme used consistently

### Asset GUI

- Asset creation, reissue, and restricted-asset dialogs
- Asset control tree widget and send-assets entry
- Asset management views in the wallet UI

### Dark Mode

- Optional dark theme for the Qt wallet

### Additional Fixes

- `wallet`: value-initialize `CRecipient::scriptOverride`
- `sign`: treat `RESTRICTED_ASSET_DATA` as non-signable in `SignStep`
- `qt`: reference `SatoxcoinAmountField` (actual class name) in the amount
  field `.ui` forms
- `build`: guard undefined-macro checks with `defined()` for C preprocessor
  portability
- `build`: add `boost-thread` to Windows vcpkg dependencies for
  `assetsnapshotdb`

Known Issues
============

- Asset overflow BIP9 soft-fork is prepared but activation is deferred
  until the 4.0 line is verified and running stable
- New checkpoints will be added on upcoming releases as the chain advances

Upgrading from 3.x
==================

If upgrading from Satoxcoin Core 3.x:

1. Shut down the old node completely
2. Replace binaries with the 4.0.2 versions
3. Start the node — the data directory will be migrated automatically
4. Allow the node to reindex if prompted (this may take some time)

The new SQLite wallet format will be created on first run. BDB wallets
from 3.x are automatically migrated.

Credits
=======

Thanks to everyone who contributed to Satoxcoin Core 4.0.2:

- Satoxcoin Core developers
- Bitcoin Core developers (upstream base)
- Ravencoin Core developers (asset system lineage)