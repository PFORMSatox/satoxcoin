// Copyright (c) 2019 The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <common/args.h>
#include "restricteddb.h"
#include "assetglobals.h"
#include "validation.h"


static const uint8_t DB_FLAG = 'D';
static const uint8_t VERIFIER_FLAG = 'V';
static const uint8_t ADDRESS_QULAIFIER_FLAG = 'T';
static const uint8_t QULAIFIER_ADDRESS_FLAG = 'Q';
static const uint8_t RESTRICTED_ADDRESS_FLAG = 'R';
static const uint8_t GLOBAL_RESTRICTION_FLAG = 'G';



CRestrictedDB::CRestrictedDB(size_t nCacheSize, bool fMemory, bool fWipe) : CDBWrapper(DBParams{.path = gArgs.GetDataDirNet() / "assets" / "restricted", .cache_bytes = nCacheSize, .memory_only = fMemory, .wipe_data = fWipe}) {
}

// Restricted Verifier Strings
bool CRestrictedDB::WriteVerifier(const std::string& assetName, const std::string& verifier)
{
    Write(std::make_pair(VERIFIER_FLAG, assetName), verifier);
    return true;
}

bool CRestrictedDB::ReadVerifier(const std::string& assetName, std::string& verifier)
{
    return Read(std::make_pair(VERIFIER_FLAG, assetName), verifier);
}

bool CRestrictedDB::EraseVerifier(const std::string& assetName)
{
    Erase(std::make_pair(VERIFIER_FLAG, assetName));
    return true;
}

// Address Tags
bool CRestrictedDB::WriteAddressQualifier(const std::string &address, const std::string &tag)
{
    int8_t i = 1;
    Write(std::make_pair(ADDRESS_QULAIFIER_FLAG, std::make_pair(address, tag)), i);
    return true;
}

bool CRestrictedDB::ReadAddressQualifier(const std::string &address, const std::string &tag)
{
    int8_t i;
    return Read(std::make_pair(ADDRESS_QULAIFIER_FLAG, std::make_pair(address, tag)), i);
}

bool CRestrictedDB::EraseAddressQualifier(const std::string &address, const std::string &tag)
{
    Erase(std::make_pair(ADDRESS_QULAIFIER_FLAG, std::make_pair(address, tag)));
    return true;
}

// Address Tags
bool CRestrictedDB::WriteQualifierAddress(const std::string &address, const std::string &tag)
{
    int8_t i = 1;
    Write(std::make_pair(QULAIFIER_ADDRESS_FLAG, std::make_pair(tag, address)), i);
    return true;
}

bool CRestrictedDB::ReadQualifierAddress(const std::string &address, const std::string &tag)
{
    int8_t i;
    return Read(std::make_pair(QULAIFIER_ADDRESS_FLAG, std::make_pair(tag, address)), i);
}

bool CRestrictedDB::EraseQualifierAddress(const std::string &address, const std::string &tag)
{
    Erase(std::make_pair(QULAIFIER_ADDRESS_FLAG, std::make_pair(tag, address)));
    return true;
}


// Address Restriction
bool CRestrictedDB::WriteRestrictedAddress(const std::string& address, const std::string& assetName)
{
    int8_t i = 1;
    Write(std::make_pair(RESTRICTED_ADDRESS_FLAG, std::make_pair(address, assetName)), i);
    return true;
}

bool CRestrictedDB::ReadRestrictedAddress(const std::string& address, const std::string& assetName)
{
    int8_t i;
    return Read(std::make_pair(RESTRICTED_ADDRESS_FLAG, std::make_pair(address, assetName)), i);
}

bool CRestrictedDB::EraseRestrictedAddress(const std::string& address, const std::string& assetName)
{
    Erase(std::make_pair(RESTRICTED_ADDRESS_FLAG, std::make_pair(address, assetName)));
    return true;
}

// Global Restriction
bool CRestrictedDB::WriteGlobalRestriction(const std::string& assetName)
{
    int8_t i = 1;
    Write(std::make_pair(GLOBAL_RESTRICTION_FLAG, assetName), i);
    return true;
}

bool CRestrictedDB::ReadGlobalRestriction(const std::string& assetName)
{
    int8_t i;
    return Read(std::make_pair(GLOBAL_RESTRICTION_FLAG, assetName), i);
}

bool CRestrictedDB::EraseGlobalRestriction(const std::string& assetName)
{
    Erase(std::make_pair(GLOBAL_RESTRICTION_FLAG, assetName));
    return true;
}

bool CRestrictedDB::WriteFlag(const std::string &name, bool fValue)
{
    Write(std::make_pair(DB_FLAG, name), fValue ? static_cast<uint8_t>('1') : static_cast<uint8_t>('0'));
    return true;
}

bool CRestrictedDB::ReadFlag(const std::string &name, bool &fValue)
{
    uint8_t ch;
    if (!Read(std::make_pair(DB_FLAG, name), ch))
        return false;
    fValue = ch == '1';
    return true;
}

bool CRestrictedDB::GetQualifierAddresses(std::string& qualifier, std::vector<std::string>& addresses)
{

    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(QULAIFIER_ADDRESS_FLAG, std::make_pair(qualifier, std::string())));

    // Load all qualifiers related to that given address
    while (pcursor->Valid()) {
        std::pair<uint8_t, std::pair<std::string, std::string> > key;
        if (pcursor->GetKey(key) && key.first == QULAIFIER_ADDRESS_FLAG && key.second.first == qualifier) {
            addresses.emplace_back(key.second.second);
            pcursor->Next();
        } else {
            break;
        }
    }

    return true;
}

bool CRestrictedDB::CheckForAddressRootQualifier(const std::string& address, const std::string& qualifier)
{
    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(ADDRESS_QULAIFIER_FLAG, std::make_pair(address, qualifier)));

    // Load all qualifiers related to that given address
    while (pcursor->Valid()) {
        std::pair<uint8_t, std::pair<std::string, std::string> > key;
        if (pcursor->GetKey(key) && key.first == ADDRESS_QULAIFIER_FLAG && key.second.first == address) {
            if (key.second.second == qualifier || key.second.second.rfind(std::string(qualifier + "/"), 0) == 0) {
                return true;
            }
            pcursor->Next();
        } else {
            break;
        }
    }

    return false;
}

bool CRestrictedDB::GetAddressQualifiers(std::string& address, std::vector<std::string>& qualifiers)
{

    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(ADDRESS_QULAIFIER_FLAG, std::make_pair(address, std::string())));

    // Load all qualifiers related to that given address
    while (pcursor->Valid()) {
        std::pair<uint8_t, std::pair<std::string, std::string> > key;
        if (pcursor->GetKey(key) && key.first == ADDRESS_QULAIFIER_FLAG && key.second.first == address) {
            qualifiers.emplace_back(key.second.second);
            pcursor->Next();
        } else {
            break;
        }
    }

    return true;
}

bool CRestrictedDB::GetAddressRestrictions(std::string& address, std::vector<std::string>& restrictions)
{

    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(RESTRICTED_ADDRESS_FLAG, std::make_pair(address, std::string())));

    // Load all restrictions related to the given address
    while (pcursor->Valid()) {
        std::pair<uint8_t, std::pair<std::string, std::string> > key;
        if (pcursor->GetKey(key) && key.first == RESTRICTED_ADDRESS_FLAG && key.second.first == address) {
            restrictions.emplace_back(key.second.second);
            pcursor->Next();
        } else {
            break;
        }
    }

    return true;
}

bool CRestrictedDB::GetGlobalRestrictions(std::vector<std::string>& restrictions)
{

    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(GLOBAL_RESTRICTION_FLAG, std::string()));

    // Load all restrictions related to the given address
    while (pcursor->Valid()) {
        std::pair<uint8_t, std::string> key;
        if (pcursor->GetKey(key) && key.first == GLOBAL_RESTRICTION_FLAG) {
            restrictions.emplace_back(key.second);
            pcursor->Next();
        } else {
            break;
        }
    }

    return true;
}