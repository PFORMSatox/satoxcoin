// Copyright (c) 2017-2021 The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <assets/assetglobals.h>
#include <assets/assetdb.h>
#include <assets/assets.h>
#include <assets/assetsnapshotdb.h>
#include <assets/messages.h>
#include <assets/myassetsdb.h>
#include <assets/restricteddb.h>
#include <assets/snapshotrequestdb.h>
#include <assets/assettypes.h>

CAssetsDB *passetsdb = nullptr;
CAssetsCache *passets = nullptr;
CLRUCache<std::string, CDatabasedAssetData> *passetsCache = nullptr;
CLRUCache<std::string, CMessage> *pMessagesCache = nullptr;
CLRUCache<std::string, int> *pMessageSubscribedChannelsCache = nullptr;
CLRUCache<std::string, int> *pMessagesSeenAddressCache = nullptr;
CMessageDB *pmessagedb = nullptr;
CMessageChannelDB *pmessagechanneldb = nullptr;
CMyRestrictedDB *pmyrestricteddb = nullptr;
CRestrictedDB *prestricteddb = nullptr;
CLRUCache<std::string, CNullAssetTxVerifierString> *passetsVerifierCache = nullptr;
CLRUCache<std::string, int8_t> *passetsQualifierCache = nullptr;
CLRUCache<std::string, int8_t> *passetsRestrictionCache = nullptr;
CLRUCache<std::string, int8_t> *passetsGlobalRestrictionCache = nullptr;
CAssetSnapshotDB *pAssetSnapshotDb = nullptr;
CSnapshotRequestDB *pSnapshotRequestDb = nullptr;
CDistributeSnapshotRequestDB *pDistributeSnapshotDb = nullptr;

bool fAssetIndex = false;

CAssetsCache* GetCurrentAssetCache()
{
    return passets;
}
