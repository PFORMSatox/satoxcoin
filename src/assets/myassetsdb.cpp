// Copyright (c) 2018-2020 The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include <common/args.h>
#include "validation.h"
#include "myassetsdb.h"
#include "assetglobals.h"
#include "messages.h"


static const uint8_t MESSAGE_FLAG = 'Z'; // Message
static const uint8_t MY_MESSAGE_CHANNEL = 'C'; // My followed Channels
static const uint8_t MY_SEEN_ADDRESSES = 'S'; // Addresses that have been seen on the chain
static const uint8_t DB_FLAG = 'D'; // Database Flags

static const uint8_t MY_TAGGED_ADDRESSES = 'T'; // Addresses that have been tagged
static const uint8_t MY_RESTRICTED_ADDRESSES = 'R'; // Addresses that have been restricted

CMessageDB::CMessageDB(size_t nCacheSize, bool fMemory, bool fWipe) : CDBWrapper(DBParams{.path = gArgs.GetDataDirNet() / "messages" / "messages", .cache_bytes = nCacheSize, .memory_only = fMemory, .wipe_data = fWipe}) {
}

bool CMessageDB::WriteMessage(const CMessage &message)
{
    Write(std::make_pair(MESSAGE_FLAG, message.out), message);
}

bool CMessageDB::ReadMessage(const COutPoint &out, CMessage &message)
{
    return Read(std::make_pair(MESSAGE_FLAG, out), message);
}

bool CMessageDB::EraseMessage(const COutPoint &out)
{
    Erase(std::make_pair(MESSAGE_FLAG, out));
}

bool CMessageDB::LoadMessages(std::set<CMessage>& setMessages)
{
    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(MESSAGE_FLAG, COutPoint()));

    // Load messages
    while (pcursor->Valid()) {
        std::pair<uint8_t, COutPoint> key;
        if (pcursor->GetKey(key) && key.first == MESSAGE_FLAG) {
            CMessage message;
            if (pcursor->GetValue(message)) {
                setMessages.insert(message);
                pcursor->Next();
            } else {
                LogInfo("%s: failed to read message\n", __func__);
                pcursor->Next();
            }
        } else {
            break;
        }
    }
    return true;
}

bool CMessageDB::EraseAllMessages(int& count)
{
    std::set<CMessage> setMessages;
    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(MESSAGE_FLAG, COutPoint()));

    // Load messages
    while (pcursor->Valid()) {
        std::pair<uint8_t, COutPoint> key;
        if (pcursor->GetKey(key) && key.first == MESSAGE_FLAG) {
            CMessage message;
            if (pcursor->GetValue(message)) {
                setMessages.insert(message);
                pcursor->Next();
            } else {
                LogInfo("%s: failed to read message\n", __func__);
                pcursor->Next();
            }
        } else {
            break;
        }
    }

    count += setMessages.size();
    for (auto message : setMessages)
        EraseMessage(message.out);

    return true;
}

bool CMessageDB::Flush() {
    try {

        for (auto messageRemove : setDirtyMessagesRemove) {
            if (!EraseMessage(messageRemove)) {
                LogError("%s: failed to erase message %s", __func__, messageRemove.ToString());
                return false;
            }
        }

        for (auto messageAdd : mapDirtyMessagesAdd) {
            if (!WriteMessage(messageAdd.second)) {
                LogError("%s: failed to write message %s", __func__, messageAdd.second.ToString());
                return false;
            }

            mapDirtyMessagesOrphaned.erase(messageAdd.first);
        }

        for (auto orphans : mapDirtyMessagesOrphaned) {
            CMessage msg = orphans.second;
            msg.status = MessageStatus::ORPHAN;
            if (!WriteMessage(msg)) {
                LogError("%s: failed to write message orphan %s", __func__, msg.ToString());
                return false;
            }
        }

        setDirtyMessagesRemove.clear();
        mapDirtyMessagesAdd.clear();
        mapDirtyMessagesOrphaned.clear();
    } catch (const std::runtime_error& e) {
        LogError("%s : %s ", __func__, std::string("System error while flushing messages: ") + e.what());
        return false;
    }

    return true;
}

CMessageChannelDB::CMessageChannelDB(size_t nCacheSize, bool fMemory, bool fWipe) : CDBWrapper(DBParams{.path = gArgs.GetDataDirNet() / "messages" / "channels", .cache_bytes = nCacheSize, .memory_only = fMemory, .wipe_data = fWipe}) {
}

bool CMessageChannelDB::WriteMyMessageChannel(const std::string& channelname)
{
    Write(std::make_pair(MY_MESSAGE_CHANNEL, channelname), 1);
}

bool CMessageChannelDB::ReadMyMessageChannel(const std::string& channelname)
{
    int i = 1;
    return Read(std::make_pair(MY_MESSAGE_CHANNEL, channelname), i);
}

bool CMessageChannelDB::EraseMyMessageChannel(const std::string& channelname)
{
    Erase(std::make_pair(MY_MESSAGE_CHANNEL, channelname));
}

bool CMessageChannelDB::LoadMyMessageChannels(std::set<std::string>& setChannels)
{
    setChannels.clear();
    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(MY_MESSAGE_CHANNEL, std::string()));

    // Load messages
    while (pcursor->Valid()) {
        std::pair<uint8_t, std::string> key;
        if (pcursor->GetKey(key) && key.first == MY_MESSAGE_CHANNEL) {
            setChannels.insert(key.second);
            pcursor->Next();
        } else {
            break;
        }
    }

    return true;
}

bool CMessageDB::WriteFlag(const std::string &name, bool fValue)
{
    Write(std::make_pair(DB_FLAG, name), fValue ? static_cast<uint8_t>(1) : static_cast<uint8_t>(0));
}

bool CMessageDB::ReadFlag(const std::string &name, bool &fValue)
{
    uint8_t ch;
    if (!Read(std::make_pair(DB_FLAG, name), ch))
        return false;
    fValue = ch == '1';
    return true;
}


bool CMessageChannelDB::WriteUsedAddress(const std::string& address)
{
    Write(std::make_pair(MY_SEEN_ADDRESSES, address), 1);
}
bool CMessageChannelDB::ReadUsedAddress(const std::string& address)
{
    int i;
    return Read(std::make_pair(MY_SEEN_ADDRESSES, address), i);
}
bool CMessageChannelDB::EraseUsedAddress(const std::string& address)
{
    Erase(std::make_pair(MY_SEEN_ADDRESSES, address));
}

bool CMessageChannelDB::WriteFlag(const std::string &name, bool fValue)
{
    Write(std::make_pair(DB_FLAG, name), fValue ? static_cast<uint8_t>(1) : static_cast<uint8_t>(0));
}

bool CMessageChannelDB::ReadFlag(const std::string &name, bool &fValue)
{
    uint8_t ch;
    if (!Read(std::make_pair(DB_FLAG, name), ch))
        return false;
    fValue = ch == '1';
    return true;
}

bool CMessageChannelDB::Flush() {
    try {
        LogInfo("%s: Flushing messagechannelsdb addSize:%u, removeSize:%u, seenAddressSize:%u\n", __func__, setDirtyChannelsAdd.size(), setDirtyChannelsRemove.size(), setDirtySeenAddressAdd.size());

        for (auto channelRemove : setDirtyChannelsRemove) {
            if (!EraseMyMessageChannel(channelRemove)) {
                LogError("%s: failed to erase messagechannel %s", __func__, channelRemove);
                return false;
            }
        }

        for (auto channelAdd : setDirtyChannelsAdd) {
            if (!WriteMyMessageChannel(channelAdd)) {
                LogError("%s: failed to write messagechannel %s", __func__, channelAdd);
                return false;
            }
        }

        for (auto seenAddress : setDirtySeenAddressAdd) {
            if (!WriteUsedAddress(seenAddress)) {
                LogError("%s: failed to write seenaddress %s", __func__, seenAddress);
                return false;
            }
        }

        setDirtyChannelsRemove.clear();
        setDirtyChannelsAdd.clear();
        setDirtySeenAddressAdd.clear();
        setSubscribedChannelsAskedForFalse.clear();
        setAddressAskedForFalse.clear();
    } catch (const std::runtime_error& e) {
        LogError("%s : %s ", __func__, std::string("System error while flushing messagechannels: ") + e.what());
        return false;
    }

    return true;
}

CMyRestrictedDB::CMyRestrictedDB(size_t nCacheSize, bool fMemory, bool fWipe) : CDBWrapper(DBParams{.path = gArgs.GetDataDirNet() / "myrestricted", .cache_bytes = nCacheSize, .memory_only = fMemory, .wipe_data = fWipe}) {
}

bool CMyRestrictedDB::WriteTaggedAddress(const std::string& address, const std::string& tag_name, const bool fAdd, const uint32_t& nHeight)
{
    Write(std::make_pair(MY_TAGGED_ADDRESSES, std::make_pair(address, tag_name)), std::make_pair(fAdd ? 1 : 0, nHeight));
}
bool CMyRestrictedDB::ReadTaggedAddress(const std::string& address, const std::string& tag_name, bool& fAdd, uint32_t& nHeight)
{
    std::pair<int, uint32_t> value;
    bool ret = Read(std::make_pair(MY_TAGGED_ADDRESSES, std::make_pair(address, tag_name)), value);
    fAdd = value.first;
    nHeight = value.second;
    return ret;
}
bool CMyRestrictedDB::EraseTaggedAddress(const std::string& address, const std::string& tag_name)
{
    Erase(std::make_pair(MY_TAGGED_ADDRESSES, std::make_pair(address, tag_name)));
}
bool CMyRestrictedDB::LoadMyTaggedAddresses(std::vector<std::tuple<std::string, std::string, bool, uint32_t> >& vecTaggedAddresses)
{
    vecTaggedAddresses.clear();
    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(MY_TAGGED_ADDRESSES, std::make_pair(std::string(), std::string())));

    // Load messages
    while (pcursor->Valid()) {
        std::pair<uint8_t, std::pair<std::string, std::string>> key;
        if (pcursor->GetKey(key) && key.first == MY_TAGGED_ADDRESSES) {
            std::pair<int, uint32_t> value;
            if (pcursor->GetValue(value)) {
                vecTaggedAddresses.emplace_back(std::make_tuple(key.second.first, key.second.second, value.first ? true : false, value.second));
            }
            pcursor->Next();
        } else {
            break;
        }
    }

    return true;
}

bool CMyRestrictedDB::WriteRestrictedAddress(const std::string& address, const std::string& tag_name, const bool fAdd, const uint32_t& nHeight)
{
    Write(std::make_pair(MY_RESTRICTED_ADDRESSES, std::make_pair(address, tag_name)), std::make_pair(fAdd ? 1 : 0, nHeight));
}

bool CMyRestrictedDB::ReadRestrictedAddress(const std::string& address, const std::string& tag_name, bool& fAdd, uint32_t& nHeight)
{
    std::pair<int, uint32_t> value;
    bool ret = Read(std::make_pair(MY_RESTRICTED_ADDRESSES, std::make_pair(address, tag_name)), value);
    fAdd = value.first;
    nHeight = value.second;
    return ret;
}

bool CMyRestrictedDB::EraseRestrictedAddress(const std::string& address, const std::string& tag_name)
{
    Erase(std::make_pair(MY_RESTRICTED_ADDRESSES, std::make_pair(address, tag_name)));
}

bool CMyRestrictedDB::LoadMyRestrictedAddresses(std::vector<std::tuple<std::string, std::string, bool, uint32_t> >& vecRestrictedAddresses)
{
    vecRestrictedAddresses.clear();
    std::unique_ptr<CDBIterator> pcursor(NewIterator());

    pcursor->Seek(std::make_pair(MY_RESTRICTED_ADDRESSES, std::make_pair(std::string(), std::string())));

    // Load messages
    while (pcursor->Valid()) {
        std::pair<uint8_t, std::pair<std::string, std::string>> key;
        if (pcursor->GetKey(key) && key.first == MY_RESTRICTED_ADDRESSES) {
            std::pair<int, uint32_t> value;
            if (pcursor->GetValue(value)) {
                vecRestrictedAddresses.emplace_back(std::make_tuple(key.second.first, key.second.second, value.first ? true : false, value.second));
            }
            pcursor->Next();
        } else {
            break;
        }
    }

    return true;
}


bool CMyRestrictedDB::WriteFlag(const std::string &name, bool fValue)
{
    Write(std::make_pair(DB_FLAG, name), fValue ? static_cast<uint8_t>(1) : static_cast<uint8_t>(0));
}

bool CMyRestrictedDB::ReadFlag(const std::string &name, bool &fValue)
{
    uint8_t ch;
    if (!Read(std::make_pair(DB_FLAG, name), ch))
        return false;
    fValue = ch == '1';
    return true;
}
