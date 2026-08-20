Satoxcoin Core version 4.0.3 is now available from:

  <https://github.com/PFORMSatox/satoxcoin/releases/tag/v4.0.3>

This release prepares the public launch of the Satoxcoin testnet: it gives
testnet its own peer-to-peer network identity, removes the unusable Bitcoin
testnet4 chain that came over with the upstream rebase, and mints a fresh,
satoxcoin-specific testnet genesis block. Mainnet is unaffected.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/PFORMSatox/satoxcoin/issues>

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes in some cases), then run the installer
(on Windows) or just copy over `satoxcoind`/`satoxcoin-qt` (on Linux/macOS).

Mainnet users upgrading from 4.0.x can upgrade directly; no reindex or
migration is needed.

Compatibility
=============

Satoxcoin Core is supported and tested on the following operating systems:
Ubuntu 22.04+, macOS 14+, and Windows 10+.

Notable Changes
===============

### Testnet P2P Magic Fix

Testnet v3 inherited the same p2p message-start bytes as mainnet from the 2.x
lineage, so testnet nodes could connect to mainnet peers. Testnet now uses its
own magic (`tSAT`, `0x74 0x53 0x41 0x54`). The mainnet magic is unchanged.

### Bitcoin Testnet4 Removed

The Bitcoin-testnet4 chain that came over with the Bitcoin Core 31.1 rebase was
never a usable Satoxcoin network (its first kawpow blocks had no mineable
target) and has been removed. The `-testnet4` option, `[testnet4]` config
section, and all related GUI/test scaffolding are gone. Satoxcoin has exactly
one testnet, selected with `-testnet`.

### New Unique Testnet Genesis

Because the previous testnet never worked, its genesis block — which was shared
with another network — has been replaced with a fresh satoxcoin-specific one:

- Genesis hash: `000000b0a696734e3c0849dd835048cf3645e94ffc4bd20f4f8d7108c6146e33`
- Coinbase string: `Satoxcoin Public Testnet Launch 08/21/2026 - Satoverse tSAT`

Any old testnet data directories must be deleted before running this version;
the new chain starts from height 0. See
`doc/security/audit/testnet-bootstrap-runbook.md` for the full bootstrap
procedure.

### Testnet Bootstrap Runbook

A new operations runbook (`doc/security/audit/testnet-bootstrap-runbook.md`)
documents how to bootstrap the public testnet: chain parameters, first-block
mining, peer discovery via `-addnode`, and reset policy.

Known Issues
============

- Asset overflow BIP9 soft-fork is prepared but activation is deferred
  until the 4.0 line is verified and running stable
- New checkpoints will be added on upcoming releases as the chain advances

Credits
=======

Thanks to everyone who contributed to Satoxcoin Core 4.0.3:

- Satoxcoin Core developers
- Bitcoin Core developers (upstream base)
- Ravencoin Core developers (asset system lineage)
