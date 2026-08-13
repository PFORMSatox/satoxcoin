// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_KERNEL_CHAINPARAMS_H
#define BITCOIN_KERNEL_CHAINPARAMS_H

#include <consensus/params.h>
#include <kernel/messagestartchars.h>
#include <primitives/block.h>
#include <uint256.h>
#include <util/chaintype.h>
#include <util/hash_type.h>
#include <util/vector.h>

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

struct AssumeutxoHash : public BaseHash<uint256> {
    explicit AssumeutxoHash(const uint256& hash) : BaseHash(hash) {}
};

/**
 * Holds configuration for use during UTXO snapshot load and validation. The contents
 * here are security critical, since they dictate which UTXO snapshots are recognized
 * as valid.
 */
struct AssumeutxoData {
    int height;

    //! The expected hash of the deserialized UTXO set.
    AssumeutxoHash hash_serialized;

    //! Used to populate the m_chain_tx_count value, which is used during BlockManager::LoadBlockIndex().
    //!
    //! We need to hardcode the value here because this is computed cumulatively using block data,
    //! which we do not necessarily have at the time of snapshot load.
    uint64_t m_chain_tx_count;

    //! The hash of the base block for this snapshot. Used to refer to assumeutxo data
    //! prior to having a loaded blockindex.
    uint256 blockhash;
};

/**
 * Holds various statistics on transactions within a chain. Used to estimate
 * verification progress during chain sync.
 *
 * See also: CChainParams::TxData, GuessVerificationProgress.
 */
struct ChainTxData {
    int64_t nTime;    //!< UNIX timestamp of last known number of transactions
    uint64_t tx_count; //!< total number of transactions between genesis and that timestamp
    double dTxRate;   //!< estimated number of transactions per second after that timestamp
};

//! Configuration for headers sync memory usage.
struct HeadersSyncParams {
    //! Distance in blocks between header commitments.
    size_t commitment_period{0};
    //! Minimum number of validated headers to accumulate in the redownload
    //! buffer before feeding them into the permanent block index.
    size_t redownload_buffer_size{0};
};

/**
 * CChainParams defines various tweakable parameters of a given instance of the
 * Bitcoin system.
 */
class CChainParams
{
public:
    enum Base58Type {
        PUBKEY_ADDRESS,
        SCRIPT_ADDRESS,
        SECRET_KEY,
        EXT_PUBLIC_KEY,
        EXT_SECRET_KEY,

        MAX_BASE58_TYPES
    };

    const Consensus::Params& GetConsensus() const { return consensus; }
    const MessageStartChars& MessageStart() const { return pchMessageStart; }
    uint16_t GetDefaultPort() const { return nDefaultPort; }
    std::vector<int> GetAvailableSnapshotHeights() const;

    const CBlock& GenesisBlock() const { return genesis; }
    /** Default value for -checkmempool and -checkblockindex argument */
    bool DefaultConsistencyChecks() const { return fDefaultConsistencyChecks; }
    /** If this chain is exclusively used for testing */
    bool IsTestChain() const { return m_chain_type != ChainType::MAIN; }
    /** If this chain allows time to be mocked */
    bool IsMockableChain() const { return m_is_mockable_chain; }
    uint64_t PruneAfterHeight() const { return nPruneAfterHeight; }
    /** Minimum free space (in GB) needed for data directory */
    uint64_t AssumedBlockchainSize() const { return m_assumed_blockchain_size; }
    /** Minimum free space (in GB) needed for data directory when pruned; Does not include prune target*/
    uint64_t AssumedChainStateSize() const { return m_assumed_chain_state_size; }
    /** Whether it is possible to mine blocks on demand (no retargeting) */
    bool MineBlocksOnDemand() const { return consensus.fPowNoRetargeting; }
    /** Return the block height at which DarkGravityWave difficulty activates */
    unsigned int DGWActivationBlock() const { return nDGWActivationBlock; }
    /** Return the block height at which messaging activates */
    unsigned int MessagingActivationBlock() const { return nMessagingActivationBlock; }
    /** Return the block height at which restricted assets activate */
    unsigned int RestrictedActivationBlock() const { return nRestrictedActivationBlock; }
    /** Return the asset activation height */
    int GetAssetActivationHeight() const { return nAssetActivationHeight; }
    /** Return the community autonomous fund output amount (percentage) */
    const CAmount& CommunityAutonomousAmount() const { return nCommunityAutonomousAmount; }
    /** Return the community autonomous fund address */
    const std::string& CommunityAutonomousAddress() const { return strCommunityAutonomousAddress; }
    /** Return the global burn address */
    const std::string& IssueAssetBurnAddress() const { return strIssueAssetBurnAddress; }
    const std::string& ReissueAssetBurnAddress() const { return strReissueAssetBurnAddress; }
    const std::string& IssueSubAssetBurnAddress() const { return strIssueSubAssetBurnAddress; }
    const std::string& IssueUniqueAssetBurnAddress() const { return strIssueUniqueAssetBurnAddress; }
    const std::string& IssueMsgChannelAssetBurnAddress() const { return strIssueMsgChannelAssetBurnAddress; }
    const std::string& IssueQualifierAssetBurnAddress() const { return strIssueQualifierAssetBurnAddress; }
    const std::string& IssueSubQualifierAssetBurnAddress() const { return strIssueSubQualifierAssetBurnAddress; }
    const std::string& IssueRestrictedAssetBurnAddress() const { return strIssueRestrictedAssetBurnAddress; }
    const std::string& AddNullQualifierTagBurnAddress() const { return strAddNullQualifierTagBurnAddress; }
    const CAmount& IssueAssetBurnAmount() const { return nIssueAssetBurnAmount; }
    const CAmount& ReissueAssetBurnAmount() const { return nReissueAssetBurnAmount; }
    const CAmount& IssueSubAssetBurnAmount() const { return nIssueSubAssetBurnAmount; }
    const CAmount& IssueUniqueAssetBurnAmount() const { return nIssueUniqueAssetBurnAmount; }
    const CAmount& IssueMsgChannelAssetBurnAmount() const { return nIssueMsgChannelAssetBurnAmount; }
    const CAmount& IssueQualifierAssetBurnAmount() const { return nIssueQualifierAssetBurnAmount; }
    const CAmount& IssueSubQualifierAssetBurnAmount() const { return nIssueSubQualifierAssetBurnAmount; }
    const CAmount& IssueRestrictedAssetBurnAmount() const { return nIssueRestrictedAssetBurnAmount; }
    const CAmount& AddNullQualifierTagBurnAmount() const { return nAddNullQualifierTagBurnAmount; }
    /** Return the global burn address */
    const std::string& GlobalBurnAddress() const { return strGlobalBurnAddress; }
    /** Whether the provided address is a burn/community address */
    bool IsBurnAddress(const std::string& p_address) const
    {
        if (p_address == strIssueAssetBurnAddress
            || p_address == strReissueAssetBurnAddress
            || p_address == strIssueSubAssetBurnAddress
            || p_address == strIssueUniqueAssetBurnAddress
            || p_address == strIssueMsgChannelAssetBurnAddress
            || p_address == strIssueQualifierAssetBurnAddress
            || p_address == strIssueSubQualifierAssetBurnAddress
            || p_address == strIssueRestrictedAssetBurnAddress
            || p_address == strAddNullQualifierTagBurnAddress
            || p_address == strGlobalBurnAddress
            || p_address == strCommunityAutonomousAddress)
        {
            return true;
        }
        return false;
    }
    /** Return the chain type string */
    std::string GetChainTypeString() const { return ChainTypeToString(m_chain_type); }
    /** Return the chain type */
    ChainType GetChainType() const { return m_chain_type; }
    /** Return the list of hostnames to look up for DNS seeds */
    const std::vector<std::string>& DNSSeeds() const { return vSeeds; }
    const std::vector<unsigned char>& Base58Prefix(Base58Type type) const { return base58Prefixes[type]; }
    const std::string& Bech32HRP() const { return bech32_hrp; }
    const std::vector<uint8_t>& FixedSeeds() const { return vFixedSeeds; }
    const HeadersSyncParams& HeadersSync() const { return m_headers_sync_params; }

    std::optional<AssumeutxoData> AssumeutxoForHeight(int height) const
    {
        return FindFirst(m_assumeutxo_data, [&](const auto& d) { return d.height == height; });
    }
    std::optional<AssumeutxoData> AssumeutxoForBlockhash(const uint256& blockhash) const
    {
        return FindFirst(m_assumeutxo_data, [&](const auto& d) { return d.blockhash == blockhash; });
    }

    const ChainTxData& TxData() const { return chainTxData; }

    /**
     * SigNetOptions holds configurations for creating a signet CChainParams.
     */
    struct SigNetOptions {
        std::optional<std::vector<uint8_t>> challenge{};
        std::optional<std::vector<std::string>> seeds{};
    };

    /**
     * VersionBitsParameters holds activation parameters
     */
    struct VersionBitsParameters {
        int64_t start_time;
        int64_t timeout;
        int min_activation_height;
    };

    /**
     * RegTestOptions holds configurations for creating a regtest CChainParams.
     */
    struct RegTestOptions {
        std::unordered_map<Consensus::DeploymentPos, VersionBitsParameters> version_bits_parameters{};
        std::unordered_map<Consensus::BuriedDeployment, int> activation_heights{};
        bool fastprune{false};
        bool enforce_bip94{false};
    };

    static std::unique_ptr<const CChainParams> RegTest(const RegTestOptions& options);
    static std::unique_ptr<const CChainParams> SigNet(const SigNetOptions& options);
    static std::unique_ptr<const CChainParams> Main();
    static std::unique_ptr<const CChainParams> TestNet();
    static std::unique_ptr<const CChainParams> TestNet4();

protected:
    CChainParams() = default;

    Consensus::Params consensus;
    MessageStartChars pchMessageStart;
    uint16_t nDefaultPort;
    uint64_t nPruneAfterHeight;
    uint64_t m_assumed_blockchain_size;
    uint64_t m_assumed_chain_state_size;
    std::vector<std::string> vSeeds;
    std::vector<unsigned char> base58Prefixes[MAX_BASE58_TYPES];
    std::string bech32_hrp;
    ChainType m_chain_type;
    CBlock genesis;
    std::vector<uint8_t> vFixedSeeds;
    bool fDefaultConsistencyChecks;
    bool m_is_mockable_chain;
    std::vector<AssumeutxoData> m_assumeutxo_data;
    ChainTxData chainTxData;
    HeadersSyncParams m_headers_sync_params;
    unsigned int nDGWActivationBlock;
    unsigned int nMessagingActivationBlock;
    unsigned int nRestrictedActivationBlock;
    int nAssetActivationHeight;
    CAmount nCommunityAutonomousAmount;
    std::string strCommunityAutonomousAddress;
    std::string strGlobalBurnAddress;
    std::string strIssueAssetBurnAddress;
    std::string strReissueAssetBurnAddress;
    std::string strIssueSubAssetBurnAddress;
    std::string strIssueUniqueAssetBurnAddress;
    std::string strIssueMsgChannelAssetBurnAddress;
    std::string strIssueQualifierAssetBurnAddress;
    std::string strIssueSubQualifierAssetBurnAddress;
    std::string strIssueRestrictedAssetBurnAddress;
    std::string strAddNullQualifierTagBurnAddress;
    CAmount nIssueAssetBurnAmount;
    CAmount nReissueAssetBurnAmount;
    CAmount nIssueSubAssetBurnAmount;
    CAmount nIssueUniqueAssetBurnAmount;
    CAmount nIssueMsgChannelAssetBurnAmount;
    CAmount nIssueQualifierAssetBurnAmount;
    CAmount nIssueSubQualifierAssetBurnAmount;
    CAmount nIssueRestrictedAssetBurnAmount;
    CAmount nAddNullQualifierTagBurnAmount;
    uint32_t nKAAAWWWPOWActivationTime;
};

std::optional<ChainType> GetNetworkForMagic(const MessageStartChars& pchMessageStart);

#endif // BITCOIN_KERNEL_CHAINPARAMS_H
