// Copyright (c) 2017-2021 The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef SATOXCOIN_ASSETGLOBALS_H
#define SATOXCOIN_ASSETGLOBALS_H

#include <string>

class CAssetsDB;
class CAssetsCache;
class CDatabasedAssetData;
class CMessage;
class CMessageDB;
class CMessageChannelDB;
class CMyRestrictedDB;
class CRestrictedDB;
class CAssetSnapshotDB;
class CSnapshotRequestDB;
class CDistributeSnapshotRequestDB;
class CNullAssetTxVerifierString;

template <typename K, typename V>
class CLRUCache;

/** Global variable that points to the active assets database (protected by cs_main) */
extern CAssetsDB *passetsdb;

/** Global variable that points to the active assets (protected by cs_main) */
extern CAssetsCache *passets;

/** Global variable that points to the assets metadata LRU Cache (protected by cs_main) */
extern CLRUCache<std::string, CDatabasedAssetData> *passetsCache;

/** Global variable that points to the subscribed channel LRU Cache (protected by cs_main) */
extern CLRUCache<std::string, CMessage> *pMessagesCache;

/** Global variable that points to the subscribed channel LRU Cache (protected by cs_main) */
extern CLRUCache<std::string, int> *pMessageSubscribedChannelsCache;

/** Global variable that points to the address seen LRU Cache (protected by cs_main) */
extern CLRUCache<std::string, int> *pMessagesSeenAddressCache;

/** Global variable that points to the messages database (protected by cs_main) */
extern CMessageDB *pmessagedb;

/** Global variable that points to the message channel database (protected by cs_main) */
extern CMessageChannelDB *pmessagechanneldb;

/** Global variable that points to my wallets restricted database (protected by cs_main) */
extern CMyRestrictedDB *pmyrestricteddb;

/** Global variable that points to the active restricted asset database (protected by cs_main) */
extern CRestrictedDB *prestricteddb;

/** Global variable that points to the asset verifier LRU Cache (protected by cs_main) */
extern CLRUCache<std::string, CNullAssetTxVerifierString> *passetsVerifierCache;

/** Global variable that points to the asset address qualifier LRU Cache (protected by cs_main) */
extern CLRUCache<std::string, int8_t> *passetsQualifierCache;

/** Global variable that points to the asset address restriction LRU Cache (protected by cs_main) */
extern CLRUCache<std::string, int8_t> *passetsRestrictionCache;

/** Global variable that points to the global restriction LRU Cache (protected by cs_main) */
extern CLRUCache<std::string, int8_t> *passetsGlobalRestrictionCache;

/** Global variable that points to the asset snapshot database (protected by cs_main) */
extern CAssetSnapshotDB *pAssetSnapshotDb;

/** Global variable that points to the snapshot request database (protected by cs_main) */
extern CSnapshotRequestDB *pSnapshotRequestDb;

/** Global variable that points to the distribute snapshot database (protected by cs_main) */
extern CDistributeSnapshotRequestDB *pDistributeSnapshotDb;

extern bool fAssetIndex;
extern bool fAddressIndex;
extern bool fSpentIndex;
extern bool fTimestampIndex;

CAssetsCache* GetCurrentAssetCache();

#endif // SATOXCOIN_ASSETGLOBALS_H
