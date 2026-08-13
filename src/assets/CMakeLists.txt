# Copyright (c) 2024-present The Satoxcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.

# Asset protocol functionality (Ravencoin-derived assets) used by both
# satoxcoind and the wallet. Kept as its own static library so that the
# node and wallet layers can share the asset consensus and cache code.
add_library(satoxcoin_assets STATIC EXCLUDE_FROM_ALL
  assetdb.cpp
  assetglobals.cpp
  assets.cpp
  assetsnapshotdb.cpp
  assettypes.cpp
  LibBoolEE.cpp
  messages.cpp
  myassetsdb.cpp
  restricteddb.cpp
  rewards.cpp
  snapshotrequestdb.cpp
)
target_link_libraries(satoxcoin_assets
  PRIVATE
    core_interface
    satoxcoin_common
    satoxcoin_util
    univalue
    leveldb
    Boost::headers
)
