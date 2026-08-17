// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2024-present The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <rpc/server.h>
#include <rpc/server_util.h>
#include <rpc/util.h>
#include <assets/assetglobals.h>
#include <core_io.h>
#include <node/blockstorage.h>
#include <chain.h>
#include <key_io.h>
#include <util/moneystr.h>
#include <validation.h>

#include <univalue.h>
#include <variant>

static bool ParseAddress(const std::string& address, uint160& hashBytes, int& type)
{
    CTxDestination dest = DecodeDestination(address);
    if (!IsValidDestination(dest))
        throw JSONRPCError(RPC_INVALID_ADDRESS_OR_KEY, std::string("Invalid address: ") + address);

    if (auto pk = std::get_if<PKHash>(&dest)) { hashBytes = uint160(std::span<const unsigned char>(pk->data(), 20)); type = 1; }
    else if (auto sh = std::get_if<ScriptHash>(&dest)) { hashBytes = uint160(std::span<const unsigned char>(sh->data(), 20)); type = 2; }
    else
        throw JSONRPCError(RPC_INVALID_ADDRESS_OR_KEY, "Address type not supported by address index");
    return true;
}

static std::vector<std::string> GetAddressArray(const JSONRPCRequest& request)
{
    std::vector<std::string> result;
    const UniValue& arr = request.params[0];
    for (const auto& v : arr.getValues()) {
        result.push_back(v.get_str());
    }
    return result;
}

static RPCHelpMan getaddresstxids()
{
    return RPCHelpMan{
        "getaddresstxids",
        "Returns the txids for an address",
        {
            {"addresses", RPCArg::Type::ARR, RPCArg::Optional::NO, "The addresses to get the txids for",
                {{"address", RPCArg::Type::STR, RPCArg::Optional::NO, ""}}},
        },
        RPCResult{RPCResult::Type::ARR, "", "list of transaction ids"},
        RPCExamples{
            HelpExampleCli("getaddresstxids", "'{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}'")
            + HelpExampleRpc("getaddresstxids", "{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}"),
        },
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            if (!fAddressIndex) throw JSONRPCError(RPC_MISC_ERROR, "Address index not enabled");
            ChainstateManager& chainman = EnsureAnyChainman(request.context);
            auto addrs = GetAddressArray(request);
            UniValue result(UniValue::VARR);
            for (const auto& addr : addrs) {
                uint160 hashBytes; int type;
                ParseAddress(addr, hashBytes, type);
                std::vector<std::pair<CAddressIndexKey, CAmount>> addressIndex;
                if (!chainman.m_blockman.m_block_tree_db->ReadAddressIndex(hashBytes, type, "", addressIndex))
                    throw JSONRPCError(RPC_DATABASE_ERROR, "Unable to read address index");
                for (const auto& entry : addressIndex)
                    if (!entry.first.spending) result.push_back(entry.first.txhash.GetHex());
            }
            return result;
        },
    };
}

static RPCHelpMan getaddressbalance()
{
    return RPCHelpMan{
        "getaddressbalance",
        "Returns the balance for an address",
        {
            {"addresses", RPCArg::Type::ARR, RPCArg::Optional::NO, "The addresses to get the balance for",
                {{"address", RPCArg::Type::STR, RPCArg::Optional::NO, ""}}},
        },
        RPCResult{RPCResult::Type::OBJ_DYN, "", "address balance object",
            {{RPCResult::Type::NUM, "balance", "The total balance"},
             {RPCResult::Type::NUM, "received", "Total amount received"},
             {RPCResult::Type::NUM, "sent", "Total amount sent"}}},
        RPCExamples{
            HelpExampleCli("getaddressbalance", "'{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}'")
            + HelpExampleRpc("getaddressbalance", "{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}"),
        },
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            if (!fAddressIndex) throw JSONRPCError(RPC_MISC_ERROR, "Address index not enabled");
            ChainstateManager& chainman = EnsureAnyChainman(request.context);
            auto addrs = GetAddressArray(request);
            UniValue result(UniValue::VOBJ);
            CAmount balance{0}, sent{0}, received{0};
            for (const auto& addr : addrs) {
                uint160 hashBytes; int type;
                ParseAddress(addr, hashBytes, type);
                std::vector<std::pair<CAddressIndexKey, CAmount>> addressIndex;
                if (!chainman.m_blockman.m_block_tree_db->ReadAddressIndex(hashBytes, type, "", addressIndex))
                    throw JSONRPCError(RPC_DATABASE_ERROR, "Unable to read address index");
                for (const auto& entry : addressIndex) {
                    if (entry.second > 0) { received += entry.second; balance += entry.second; }
                    else { sent -= entry.second; balance += entry.second; }
                }
            }
            result.pushKV("balance", ValueFromAmount(balance));
            result.pushKV("received", ValueFromAmount(received));
            result.pushKV("sent", ValueFromAmount(sent));
            return result;
        },
    };
}

static RPCHelpMan getaddressdeltas()
{
    return RPCHelpMan{
        "getaddressdeltas",
        "Returns all changes for an address",
        {
            {"addresses", RPCArg::Type::ARR, RPCArg::Optional::NO, "The addresses to get the deltas for",
                {{"address", RPCArg::Type::STR, RPCArg::Optional::NO, ""}}},
        },
        RPCResult{RPCResult::Type::ARR, "", "list of deltas"},
        RPCExamples{
            HelpExampleCli("getaddressdeltas", "'{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}'")
            + HelpExampleRpc("getaddressdeltas", "{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}"),
        },
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            if (!fAddressIndex) throw JSONRPCError(RPC_MISC_ERROR, "Address index not enabled");
            ChainstateManager& chainman = EnsureAnyChainman(request.context);
            auto addrs = GetAddressArray(request);
            UniValue result(UniValue::VARR);
            for (const auto& addr : addrs) {
                uint160 hashBytes; int type;
                ParseAddress(addr, hashBytes, type);
                std::vector<std::pair<CAddressIndexKey, CAmount>> addressIndex;
                if (!chainman.m_blockman.m_block_tree_db->ReadAddressIndex(hashBytes, type, "", addressIndex))
                    throw JSONRPCError(RPC_DATABASE_ERROR, "Unable to read address index");
                for (const auto& entry : addressIndex) {
                    UniValue o(UniValue::VOBJ);
                    o.pushKV("txid", entry.first.txhash.GetHex());
                    o.pushKV("index", static_cast<int64_t>(entry.first.index));
                    o.pushKV("block", entry.first.blockHeight);
                    o.pushKV("blockindex", static_cast<int64_t>(entry.first.txindex));
                    o.pushKV("amount", ValueFromAmount(entry.first.spending ? -entry.second : entry.second));
                    o.pushKV("spending", entry.first.spending);
                    result.push_back(o);
                }
            }
            return result;
        },
    };
}

static RPCHelpMan getaddressutxos()
{
    return RPCHelpMan{
        "getaddressutxos",
        "Returns all unspent outputs for an address",
        {
            {"addresses", RPCArg::Type::ARR, RPCArg::Optional::NO, "The addresses to get the utxos for",
                {{"address", RPCArg::Type::STR, RPCArg::Optional::NO, ""}}},
        },
        RPCResult{RPCResult::Type::ARR, "", "list of UTXOs"},
        RPCExamples{
            HelpExampleCli("getaddressutxos", "'{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}'")
            + HelpExampleRpc("getaddressutxos", "{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}"),
        },
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            if (!fAddressIndex) throw JSONRPCError(RPC_MISC_ERROR, "Address index not enabled");
            ChainstateManager& chainman = EnsureAnyChainman(request.context);
            auto addrs = GetAddressArray(request);
            UniValue result(UniValue::VARR);
            for (const auto& addr : addrs) {
                uint160 hashBytes; int type;
                ParseAddress(addr, hashBytes, type);
                std::vector<std::pair<CAddressUnspentKey, CAddressUnspentValue>> unspentOutputs;
                if (!chainman.m_blockman.m_block_tree_db->ReadAddressUnspentIndex(hashBytes, type, "", unspentOutputs))
                    throw JSONRPCError(RPC_DATABASE_ERROR, "Unable to read address unspent index");
                for (const auto& entry : unspentOutputs) {
                    UniValue o(UniValue::VOBJ);
                    o.pushKV("address", addr);
                    o.pushKV("txid", entry.first.txhash.GetHex());
                    o.pushKV("outputIndex", static_cast<int64_t>(entry.first.index));
                    o.pushKV("script", HexStr(entry.second.script));
                    o.pushKV("satoshis", entry.second.satoshis);
                    o.pushKV("height", entry.second.blockHeight);
                    result.push_back(o);
                }
            }
            return result;
        },
    };
}

static RPCHelpMan getaddressmempool()
{
    return RPCHelpMan{
        "getaddressmempool",
        "Returns all mempool transactions for an address (not yet implemented)",
        {
            {"addresses", RPCArg::Type::ARR, RPCArg::Optional::NO, "The addresses to get the mempool for",
                {{"address", RPCArg::Type::STR, RPCArg::Optional::NO, ""}}},
        },
        RPCResult{RPCResult::Type::ARR, "", "list of mempool deltas"},
        RPCExamples{
            HelpExampleCli("getaddressmempool", "'{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}'")
            + HelpExampleRpc("getaddressmempool", "{\"addresses\": [\"12c6DSiU4Rq3P4ZxziKxzrL5LmMBrzjrJX\"]}"),
        },
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            throw JSONRPCError(RPC_METHOD_NOT_FOUND, "getaddressmempool not yet implemented");
        },
    };
}

static RPCHelpMan getspentinfo()
{
    return RPCHelpMan{
        "getspentinfo",
        "Returns the txid and index for a spent output",
        {
            {"txid", RPCArg::Type::STR_HEX, RPCArg::Optional::NO, "The txid of the transaction"},
            {"index", RPCArg::Type::NUM, RPCArg::Optional::NO, "The output index"},
        },
        RPCResult{RPCResult::Type::OBJ, "", "object with spent info"},
        RPCExamples{
            HelpExampleCli("getspentinfo", "'{\"txid\": \"0437cd7f8525ceed2324359c2d0ba26006d92d856a9c20fa0241106ee5a597c9\", \"index\": 0}'")
            + HelpExampleRpc("getspentinfo", "{\"txid\": \"0437cd7f8525ceed2324359c2d0ba26006d92d856a9c20fa0241106ee5a597c9\", \"index\": 0}"),
        },
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            if (!fSpentIndex) throw JSONRPCError(RPC_MISC_ERROR, "Spent index not enabled");
            ChainstateManager& chainman = EnsureAnyChainman(request.context);
            uint256 txid = ParseHashV(request.params[0], "txid");
            int n = request.params[1].getInt<int>();
            CSpentIndexKey key(txid, n);
            CSpentIndexValue value;
            if (!chainman.m_blockman.m_block_tree_db->ReadSpentIndex(key, value))
                throw JSONRPCError(RPC_INVALID_PARAMETER, "No results found");
            UniValue o(UniValue::VOBJ);
            o.pushKV("txid", value.txid.GetHex());
            o.pushKV("input", static_cast<int64_t>(value.inputIndex));
            o.pushKV("blockheight", value.blockHeight);
            o.pushKV("txhash", value.addressHash.GetHex());
            return o;
        },
    };
}

static RPCHelpMan getblockhashes()
{
    return RPCHelpMan{
        "getblockhashes",
        "Returns the block hashes at the given timestamp range",
        {
            {"high", RPCArg::Type::NUM, RPCArg::Optional::NO, "The high timestamp"},
            {"low", RPCArg::Type::NUM, RPCArg::Optional::NO, "The low timestamp"},
        },
        RPCResult{RPCResult::Type::ARR, "", "list of block hashes"},
        RPCExamples{
            HelpExampleCli("getblockhashes", "1231614698 1231024505")
            + HelpExampleRpc("getblockhashes", "1231614698, 1231024505"),
        },
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            if (!fTimestampIndex) throw JSONRPCError(RPC_MISC_ERROR, "Timestamp index not enabled");
            ChainstateManager& chainman = EnsureAnyChainman(request.context);
            unsigned high = request.params[0].getInt<unsigned>();
            unsigned low = request.params[1].getInt<unsigned>();
            UniValue result(UniValue::VARR);
            std::vector<std::pair<uint256, unsigned int>> hashes;
            if (!chainman.m_blockman.m_block_tree_db->ReadTimestampIndex(high, low, false, hashes))
                throw JSONRPCError(RPC_DATABASE_ERROR, "Unable to read timestamp index");
            for (const auto& entry : hashes)
                result.push_back(entry.first.GetHex());
            return result;
        },
    };
}

void RegisterAddressIndexRPCCommands(CRPCTable& t)
{
    static const CRPCCommand commands[] = {
        {"addressindex", &getaddresstxids},
        {"addressindex", &getaddressbalance},
        {"addressindex", &getaddressdeltas},
        {"addressindex", &getaddressutxos},
        {"addressindex", &getaddressmempool},
        {"index", &getspentinfo},
        {"blockchain", &getblockhashes},
    };
    for (const auto& cmd : commands) {
        t.appendCommand(cmd.name, &cmd);
    }
}
