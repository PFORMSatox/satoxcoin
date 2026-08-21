// Copyright (c) 2019 The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <common/args.h>
#include "assetsnapshotdb.h"
#include "assetdb.h"
#include "assetglobals.h"
#include "validation.h"
#include <key_io.h>
#include "base58.h"

static const uint8_t SNAPSHOTCHECK_FLAG = 'C'; // Snapshot Check

CAssetSnapshotDBEntry::CAssetSnapshotDBEntry()
{
    SetNull();
}

CAssetSnapshotDBEntry::CAssetSnapshotDBEntry(
    const std::string & p_assetName, int p_snapshotHeight,
    const std::set<std::pair<std::string, CAmount>> & p_ownersAndAmounts
)
{
    SetNull();

    height = p_snapshotHeight;
    assetName = p_assetName;
    for (auto const & currPair : p_ownersAndAmounts) {
        ownersAndAmounts.insert(currPair);
    }

    heightAndName = std::to_string(height) + assetName;
}

CAssetSnapshotDB::CAssetSnapshotDB(size_t nCacheSize, bool fMemory, bool fWipe) : CDBWrapper(DBParams{.path = gArgs.GetDataDirNet() / "rewards" / "assetsnapshot", .cache_bytes = nCacheSize, .memory_only = fMemory, .wipe_data = fWipe}) {
}

bool CAssetSnapshotDB::AddAssetOwnershipSnapshot(
    const std::string & p_assetName, int p_height)
{
    LogDebug(BCLog::REWARDS, "AddAssetOwnershipSnapshot: Adding snapshot for '%s' at height %d\n",
        p_assetName.c_str(), p_height);

    //  Retrieve ownership interest for the asset at this height
    if (passetsdb == nullptr) {
        LogDebug(BCLog::REWARDS, "AddAssetOwnershipSnapshot: Invalid assets DB!\n");
        return false;
    }

    std::set<std::pair<std::string, CAmount>> ownersAndAmounts;
    std::vector<std::pair<std::string, CAmount>> tempOwnersAndAmounts;
    int totalEntryCount;

    if (!passetsdb->AssetAddressDir(tempOwnersAndAmounts, totalEntryCount, true, p_assetName, INT_MAX, 0)) {
        LogDebug(BCLog::REWARDS, "AddAssetOwnershipSnapshot: Failed to retrieve assets directory for '%s'\n", p_assetName.c_str());
        return false;
    }

    //  Retrieve all of the addresses/amounts in batches
    const int MAX_RETRIEVAL_COUNT = 100;
    bool errorsOccurred = false;

    for (int retrievalOffset = 0; retrievalOffset < totalEntryCount; retrievalOffset += MAX_RETRIEVAL_COUNT) {
        //  Retrieve the specified segment of addresses
        if (!passetsdb->AssetAddressDir(tempOwnersAndAmounts, totalEntryCount, false, p_assetName, MAX_RETRIEVAL_COUNT, retrievalOffset)) {
            LogDebug(BCLog::REWARDS, "AddAssetOwnershipSnapshot: Failed to retrieve assets directory for '%s'\n", p_assetName.c_str());
            errorsOccurred = true;
            break;
        }

        //  Verify that some addresses were returned
        if (tempOwnersAndAmounts.size() == 0) {
            LogDebug(BCLog::REWARDS, "AddAssetOwnershipSnapshot: No addresses were retrieved.\n");
            continue;
        }

        //  Move these into the main set
        for (auto const & currPair : tempOwnersAndAmounts) {
            //  Verify that the address is valid
            CTxDestination dest = DecodeDestination(currPair.first);
            if (IsValidDestination(dest)) {
                ownersAndAmounts.insert(currPair);
            }
            else {
                LogDebug(BCLog::REWARDS, "AddAssetOwnershipSnapshot: Address '%s' is invalid.\n", currPair.first.c_str());
            }
        }

        tempOwnersAndAmounts.clear();
    }

    if (errorsOccurred) {
        LogDebug(BCLog::REWARDS, "AddAssetOwnershipSnapshot: Errors occurred while acquiring ownership info for asset '%s'.\n", p_assetName.c_str());
        return false;
    }
    if (ownersAndAmounts.size() == 0) {
        LogDebug(BCLog::REWARDS, "AddAssetOwnershipSnapshot: No owners exist for asset '%s'.\n", p_assetName.c_str());
        return false;
    }

    //  Write the snapshot to the database. We don't care if we overwrite, because it should be identical.
    CAssetSnapshotDBEntry snapshotEntry(p_assetName, p_height, ownersAndAmounts);

    Write(std::make_pair(SNAPSHOTCHECK_FLAG, snapshotEntry.heightAndName), snapshotEntry);
    LogDebug(BCLog::REWARDS, "AddAssetOwnershipSnapshot: Successfully added snapshot for '%s' at height %d (ownerCount = %d).\n",
        p_assetName.c_str(), p_height, ownersAndAmounts.size());
    return true;
}

bool CAssetSnapshotDB::RetrieveOwnershipSnapshot(
    const std::string & p_assetName, int p_height,
    CAssetSnapshotDBEntry & p_snapshotEntry)
{
    //  Load up the snapshot entries at this height
    std::string heightAndName = std::to_string(p_height) + p_assetName;

    LogDebug(BCLog::REWARDS, "%s : Attempting to retrieve snapshot: heightAndName='%s'\n",
        __func__,
        heightAndName.c_str());

    bool succeeded = Read(std::make_pair(SNAPSHOTCHECK_FLAG, heightAndName), p_snapshotEntry);

    LogDebug(BCLog::REWARDS, "%s : Retrieval of snapshot for '%s' %s!\n",
        __func__,
        heightAndName.c_str(),
        succeeded ? "succeeded" : "failed");

    return succeeded;
}

bool CAssetSnapshotDB::RemoveOwnershipSnapshot(
    const std::string & p_assetName, int p_height)
{
    //  Load up the snapshot entries at this height
    std::string heightAndName = std::to_string(p_height) + p_assetName;

    LogDebug(BCLog::REWARDS, "%s : Attempting to remove snapshot: heightAndName='%s'\n",
        __func__,
        heightAndName.c_str());

    Erase(std::make_pair(SNAPSHOTCHECK_FLAG, heightAndName), true);

    LogDebug(BCLog::REWARDS, "%s : Removal of snapshot for '%s'!\n",
        __func__,
        heightAndName.c_str());

    return true;
}
