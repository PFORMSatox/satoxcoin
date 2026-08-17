Satoxcoin Core
=============

Setup
---------------------
Satoxcoin Core is the official client for the Satoxcoin network. It is a standalone fork from Ravencoin, rebased on Bitcoin Core v31.1, featuring KAWPOW consensus and native asset support for play-to-earn gaming. Satoxcoin started in 2022 and uses the latest Bitcoin Core rebase (v31.1).

To download Satoxcoin Core, visit [satoverse.io](https://www.satoverse.io).

Running
---------------------
The following are some helpful notes on how to run Satoxcoin Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/satoxcoin-qt` (GUI) or
- `bin/satoxcoind` (headless)

### Windows

Unpack the files into a directory, and then run satoxcoin-qt.exe.

### macOS

Drag Satoxcoin Core to your applications folder, and then run Satoxcoin Core.

### Need Help?

* See the documentation at [docs.satoverse.io](https://docs.satoverse.io)
for help and more information.
* Ask for help on the [Satoxcoin Discord](https://discord.com/invite/GFZYFuuHVq).
* Visit the [Satoxcoin Explorer](https://xplore.satoverse.io) to browse blocks and transactions.

Building
---------------------
The following are developer notes on how to build Satoxcoin Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows-msvc.md)
- [FreeBSD Build Notes](build-freebsd.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)

Development
---------------------
The Satoxcoin repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Productivity Notes](productivity.md)
- [Release Process](release-process.md)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [JSON-RPC Interface](JSON-RPC-interface.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)
- [Internal Design Docs](design/)

### Resources
* Discuss on the [Satoxcoin Discord](https://discord.com/invite/GFZYFuuHVq).
* Visit [docs.satoverse.io](https://docs.satoverse.io) for project documentation.

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [satoxcoin.conf Configuration File](bitcoin-conf.md)
- [CJDNS Support](cjdns.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [I2P Support](i2p.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [Managing Wallets](managing-wallets.md)
- [Multisig Tutorial](multisig-tutorial.md)
- [Offline Signing Tutorial](offline-signing-tutorial.md)
- [P2P bad ports definition and list](p2p-bad-ports.md)
- [PSBT support](psbt.md)
- [Reduce Memory](reduce-memory.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Transaction Relay Policy](policy/README.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
