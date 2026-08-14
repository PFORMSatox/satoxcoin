// Copyright (c) 2017-2019 The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SATOXCOIN_ASSETDB_H
#define SATOXCOIN_ASSETDB_H

#include <util/fs.h>
#include "serialize.h"
#include <consensus/amount.h>

#include <string>
#include <map>
#include <dbwrapper.h>

const int8_t ASSET_UNDO_INCLUDES_VERIFIER_STRING = -1;

class CNewAsset;
class uint256;
class COutPoint;
class CDatabasedAssetData;

struct CBlockAssetUndo
{
    bool fChangedIPFS{false};
    bool fChangedUnits{false};
    std::string strIPFS;
    int32_t nUnits{0};
    int8_t version{0};
    bool fChangedVerifierString{false};
    std::string verifierString;

    // Explicit Serialize/Unserialize because the read path uses s.empty()/s.size()
    // which only exist on certain stream types (DataStream), not all.
    template <typename Stream>
    void Serialize(Stream& s) const
    {
        ::Serialize(s, fChangedUnits);
        ::Serialize(s, fChangedIPFS);
        ::Serialize(s, strIPFS);
        ::Serialize(s, nUnits);
        ::Serialize(s, ASSET_UNDO_INCLUDES_VERIFIER_STRING);
        ::Serialize(s, fChangedVerifierString);
        ::Serialize(s, verifierString);
    }

    template <typename Stream>
    void Unserialize(Stream& s)
    {
        ::Unserialize(s, fChangedUnits);
        ::Unserialize(s, fChangedIPFS);
        ::Unserialize(s, strIPFS);
        ::Unserialize(s, nUnits);
        if (!s.empty() && s.size() >= 1) {
            int8_t nVersionCheck;
            ::Unserialize(s, nVersionCheck);

            if (nVersionCheck == ASSET_UNDO_INCLUDES_VERIFIER_STRING) {
                ::Unserialize(s, fChangedVerifierString);
                ::Unserialize(s, verifierString);
            }
            version = nVersionCheck;
        }
    }
};

/** Access to the block database (blocks/index/) */
class CAssetsDB : public CDBWrapper
{
public:
    explicit CAssetsDB(size_t nCacheSize, bool fMemory = false, bool fWipe = false);

    CAssetsDB(const CAssetsDB&) = delete;
    CAssetsDB& operator=(const CAssetsDB&) = delete;

    // Write to database functions
    bool WriteAssetData(const CNewAsset& asset, const int nHeight, const uint256& blockHash);
    bool WriteAssetAddressQuantity(const std::string& assetName, const std::string& address, const CAmount& quantity);
    bool WriteAddressAssetQuantity( const std::string& address, const std::string& assetName, const CAmount& quantity);
    bool WriteBlockUndoAssetData(const uint256& blockhash, const std::vector<std::pair<std::string, CBlockAssetUndo> >& assetUndoData);
    bool WriteReissuedMempoolState();

    // Read from database functions
    bool ReadAssetData(const std::string& strName, CNewAsset& asset, int& nHeight, uint256& blockHash);
    bool ReadAssetAddressQuantity(const std::string& assetName, const std::string& address, CAmount& quantity);
    bool ReadAddressAssetQuantity(const std::string& address, const std::string& assetName, CAmount& quantity);
    bool ReadBlockUndoAssetData(const uint256& blockhash, std::vector<std::pair<std::string, CBlockAssetUndo> >& assetUndoData);
    bool ReadReissuedMempoolState();

    // Erase from database functions
    bool EraseAssetData(const std::string& assetName);
    bool EraseMyAssetData(const std::string& assetName);
    bool EraseAssetAddressQuantity(const std::string &assetName, const std::string &address);
    bool EraseAddressAssetQuantity(const std::string &address, const std::string &assetName);

    // Helper functions
    bool LoadAssets();
    bool AssetDir(std::vector<CDatabasedAssetData>& assets, const std::string filter, const size_t count, const long start);
    bool AssetDir(std::vector<CDatabasedAssetData>& assets);

    bool AddressDir(std::vector<std::pair<std::string, CAmount> >& vecAssetAmount, int& totalEntries, const bool& fGetTotal, const std::string& address, const size_t count, const long start);
    bool AssetAddressDir(std::vector<std::pair<std::string, CAmount> >& vecAddressAmount, int& totalEntries, const bool& fGetTotal, const std::string& assetName, const size_t count, const long start);
};


#endif //SATOXCOIN_ASSETDB_H
