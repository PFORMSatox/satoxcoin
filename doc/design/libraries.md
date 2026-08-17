# Libraries

| Name                     | Description |
|--------------------------|-------------|
| *libsatoxcoin_cli*       | RPC client functionality used by *satoxcoin-cli* executable |
| *libsatoxcoin_common*    | Home for common functionality shared by different executables and libraries. Similar to *libsatoxcoin_util*, but higher-level (see [Dependencies](#dependencies)). |
| *libsatoxcoin_consensus* | Consensus functionality used by *libsatoxcoin_node* and *libsatoxcoin_wallet*. |
| *libsatoxcoin_crypto*    | Hardware-optimized functions for data encryption, hashing, message authentication, and key derivation. |
| *libsatoxcoin_kernel*    | Consensus engine and support library used for validation by *libsatoxcoin_node*. |
| *libsatoxcoinqt*         | GUI functionality used by *satoxcoin-qt* and *satoxcoin-gui* executables. |
| *libsatoxcoin_ipc*       | IPC functionality used by *satoxcoin-node* and *satoxcoin-gui* executables to communicate when [`-DENABLE_IPC=ON`](multiprocess.md) is used. |
| *libsatoxcoin_node*      | P2P and RPC server functionality used by *satoxcoind* and *satoxcoin-qt* executables. |
| *libsatoxcoin_util*      | Home for common functionality shared by different executables and libraries. Similar to *libsatoxcoin_common*, but lower-level (see [Dependencies](#dependencies)). |
| *libsatoxcoin_wallet*    | Wallet functionality used by *satoxcoind* and *satoxcoin-wallet* executables. |
| *libsatoxcoin_wallet_tool* | Lower-level wallet functionality used by *satoxcoin-wallet* executable. |
| *libsatoxcoin_zmq*       | [ZeroMQ](../zmq.md) functionality used by *satoxcoind* and *satoxcoin-qt* executables. |

## Conventions

- Most libraries are internal libraries and have APIs which are completely unstable! There are few or no restrictions on backwards compatibility or rules about external dependencies. An exception is *libsatoxcoin_kernel*, which, at some future point, will have a documented external interface.

- Generally each library should have a corresponding source directory and namespace. Source code organization is a work in progress, so it is true that some namespaces are applied inconsistently, and if you look at [`add_library(satoxcoin_* ...)`](../../src/CMakeLists.txt) lists you can see that many libraries pull in files from outside their source directory. But when working with libraries, it is good to follow a consistent pattern like:

  - *libsatoxcoin_node* code lives in `src/node/` in the `node::` namespace
  - *libsatoxcoin_wallet* code lives in `src/wallet/` in the `wallet::` namespace
  - *libsatoxcoin_ipc* code lives in `src/ipc/` in the `ipc::` namespace
  - *libsatoxcoin_util* code lives in `src/util/` in the `util::` namespace
  - *libsatoxcoin_consensus* code lives in `src/consensus/` in the `Consensus::` namespace

## Dependencies

- Libraries should minimize what other libraries they depend on, and only reference symbols following the arrows shown in the dependency graph below:

<table><tr><td>

```mermaid

%%{ init : { "flowchart" : { "curve" : "basis" }}}%%

graph TD;

satoxcoin-cli[satoxcoin-cli]-->libsatoxcoin_cli;

satoxcoind[satoxcoind]-->libsatoxcoin_node;
satoxcoind[satoxcoind]-->libsatoxcoin_wallet;

satoxcoin-qt[satoxcoin-qt]-->libsatoxcoin_node;
satoxcoin-qt[satoxcoin-qt]-->libsatoxcoinqt;
satoxcoin-qt[satoxcoin-qt]-->libsatoxcoin_wallet;

satoxcoin-wallet[satoxcoin-wallet]-->libsatoxcoin_wallet;
satoxcoin-wallet[satoxcoin-wallet]-->libsatoxcoin_wallet_tool;

libsatoxcoin_cli-->libsatoxcoin_util;
libsatoxcoin_cli-->libsatoxcoin_common;

libsatoxcoin_consensus-->libsatoxcoin_crypto;

libsatoxcoin_common-->libsatoxcoin_consensus;
libsatoxcoin_common-->libsatoxcoin_crypto;
libsatoxcoin_common-->libsatoxcoin_util;

libsatoxcoin_kernel-->libsatoxcoin_consensus;
libsatoxcoin_kernel-->libsatoxcoin_crypto;
libsatoxcoin_kernel-->libsatoxcoin_util;

libsatoxcoin_node-->libsatoxcoin_consensus;
libsatoxcoin_node-->libsatoxcoin_crypto;
libsatoxcoin_node-->libsatoxcoin_kernel;
libsatoxcoin_node-->libsatoxcoin_common;
libsatoxcoin_node-->libsatoxcoin_util;

libsatoxcoinqt-->libsatoxcoin_common;
libsatoxcoinqt-->libsatoxcoin_util;

libsatoxcoin_util-->libsatoxcoin_crypto;

libsatoxcoin_wallet-->libsatoxcoin_common;
libsatoxcoin_wallet-->libsatoxcoin_crypto;
libsatoxcoin_wallet-->libsatoxcoin_util;

libsatoxcoin_wallet_tool-->libsatoxcoin_wallet;
libsatoxcoin_wallet_tool-->libsatoxcoin_util;

classDef bold stroke-width:2px, font-weight:bold, font-size: smaller;
class satoxcoin-qt,satoxcoind,satoxcoin-cli,satoxcoin-wallet bold
```
</td></tr><tr><td>

**Dependency graph**. Arrows show linker symbol dependencies. *Crypto* lib depends on nothing. *Util* lib is depended on by everything. *Kernel* lib depends only on consensus, crypto, and util.

</td></tr></table>

- The graph shows what _linker symbols_ (functions and variables) from each library other libraries can call and reference directly, but it is not a call graph. For example, there is no arrow connecting *libsatoxcoin_wallet* and *libsatoxcoin_node* libraries, because these libraries are intended to be modular and not depend on each other's internal implementation details. But wallet code is still able to call node code indirectly through the `interfaces::Chain` abstract class in [`interfaces/chain.h`](../../src/interfaces/chain.h) and node code calls wallet code through the `interfaces::ChainClient` and `interfaces::Chain::Notifications` abstract classes in the same file. In general, defining abstract classes in [`src/interfaces/`](../../src/interfaces/) can be a convenient way of avoiding unwanted direct dependencies or circular dependencies between libraries.

- *libsatoxcoin_crypto* should be a standalone dependency that any library can depend on, and it should not depend on any other libraries itself.

- *libsatoxcoin_consensus* should only depend on *libsatoxcoin_crypto*, and all other libraries besides *libsatoxcoin_crypto* should be allowed to depend on it.

- *libsatoxcoin_util* should be a standalone dependency that any library can depend on, and it should not depend on other libraries except *libsatoxcoin_crypto*. It provides basic utilities that fill in gaps in the C++ standard library and provide lightweight abstractions over platform-specific features. Since the util library is distributed with the kernel and is usable by kernel applications, it shouldn't contain functions that external code shouldn't call, like higher level code targeted at the node or wallet. (*libsatoxcoin_common* is a better place for higher level code, or code that is meant to be used by internal applications only.)

- *libsatoxcoin_common* is a home for miscellaneous shared code used by different Satoxcoin Core applications. It should not depend on anything other than *libsatoxcoin_util*, *libsatoxcoin_consensus*, and *libsatoxcoin_crypto*.

- *libsatoxcoin_kernel* should only depend on *libsatoxcoin_util*, *libsatoxcoin_consensus*, and *libsatoxcoin_crypto*.

- The only thing that should depend on *libsatoxcoin_kernel* internally should be *libsatoxcoin_node*. GUI and wallet libraries *libsatoxcoinqt* and *libsatoxcoin_wallet* in particular should not depend on *libsatoxcoin_kernel* and the unneeded functionality it would pull in, like block validation. To the extent that GUI and wallet code need scripting and signing functionality, they should be able to get it from *libsatoxcoin_consensus*, *libsatoxcoin_common*, *libsatoxcoin_crypto*, and *libsatoxcoin_util*, instead of *libsatoxcoin_kernel*.

- GUI, node, and wallet code internal implementations should all be independent of each other, and the *libsatoxcoinqt*, *libsatoxcoin_node*, *libsatoxcoin_wallet* libraries should never reference each other's symbols. They should only call each other through [`src/interfaces/`](../../src/interfaces/) abstract interfaces.

## Work in progress

- Validation code is moving from *libsatoxcoin_node* to *libsatoxcoin_kernel* as part of the libbitcoinkernel project.
