// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <kernel/chainparams.h>

#include <chainparamsseeds.h>
#include <consensus/amount.h>
#include <consensus/merkle.h>
#include <consensus/params.h>
#include <crypto/hex_base.h>
#include <hash.h>
#include <kernel/messagestartchars.h>
#include <primitives/block.h>
#include <primitives/transaction.h>
#include <script/interpreter.h>
#include <script/script.h>
#include <uint256.h>
#include <util/chaintype.h>
#include <util/log.h>
#include <util/strencodings.h>

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iterator>
#include <map>
#include <span>
#include <utility>

using namespace util::hex_literals;

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.version = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << CScriptNum(0) << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "The WSJ 08/28/2022 Investors Ramp Up Bets Against Stock Market";
    const CScript genesisOutputScript = CScript() << "04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f"_hex << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network on which people trade goods and services.
 */
class CMainParams : public CChainParams {
public:
    CMainParams() {
        m_chain_type = ChainType::MAIN;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 2100000;  //~ 4 yrs at 1 min block time
        consensus.nBIP34Enabled = true;
        consensus.nBIP65Enabled = true; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.nBIP66Enabled = true;
        consensus.BIP34LockedIn = 6048; // Locked_in at height 6048
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.BIP34Height = 6048;
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;
        consensus.CSVHeight = 0;
        consensus.SegwitHeight = 0;
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256{"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
        consensus.kawpowLimit = uint256{"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"}; // Estimated starting diff for first 180 kawpow blocks
        consensus.nPowTargetTimespan = 2016 * 60; // 1.4 days
        consensus.nPowTargetSpacing = 1 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.enforce_BIP94 = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1613; // Approx 80% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 2016;
        // Taproot was never deployed on satoxcoin mainnet; keep the slot
        // populated with a distinct bit but never-active to match history.
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 1815;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;  //Assets (HIP2)
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].threshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].bit = 7;  // Assets (HIP5)
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].threshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].bit = 8;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].threshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].bit = 10;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].bit = 11;  // Asset transfer overflow check
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nStartTime = 1789862400; // UTC: Sun Sept 20 2026 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nTimeout = 1821398400; // UTC: Mon Sept 20 2027 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].period = 2016;

        // The best chain should have at least this much work
        consensus.nMinimumChainWork = uint256{"0000000000000000000000000000000000000000000000000000005a0da9fea5"}; // Block 2000

        // By default assume that the signatures in ancestors of this block are valid
        consensus.defaultAssumeValid = uint256{"0000000002d6de2050f0ff663c31d49d3f50bdb5c6a842a56bfd8309c65fa028"}; // Block 1859491 (matches last verified checkpoint)

        // Hardcoded mainnet checkpoints (block height -> known-valid hash).
        // Ported back from satoxcoin (Bitcoin Core 31.1 removed the mechanism);
        // used to reject forks of the main chain that diverge below the last one.
        consensus.mapCheckpoints = {
            {0, uint256{"000000edd819220359469c54f2614b5602ebc775ea67a64602f354bdaa320f70"}},
            {1, uint256{"0043e718ee6c848abf0bbf8fe94d357c878324b03ce34badd4b6ed71b3533030"}},
            {2, uint256{"001f7f5c529b5e3b1c0e8c5ff8592dd1a636d1579430a924574dc696e0456705"}},
            {100, uint256{"0000001b0371bf5570c68dda2b73cdcb1909c3357875f0b7cc85b08395853cf7"}},
            {500, uint256{"00000022fa6cc7fbe32a126e75f73e0fa3ae7069e8f4cf6ac57f96a7416a5aca"}},
            {1500, uint256{"0000000509bd097b77ce6b91fd5a395904a8ec006b984413b50bdb9464276cb6"}},
            {5000, uint256{"0000000036b67ab707e7dbcd6047a0ba07724db8640e2100c0c4bb96351b5aa3"}},
            {8000, uint256{"0000000083e6d953f6d4278b83cec357bc559a2736501d8f9dff07f411d9b7b0"}},
            {12000, uint256{"00000000199b7f1c005dd6bf32e5585727ba488add6ea372944339108a960ea3"}},
            {15000, uint256{"00000002a4ddadb03fb7793ae1f97c87e07314e01fb21aa9707111dfa191fff2"}},
            {25000, uint256{"00000000fa507ef3854bdb089523a5d2a315a7c0bacbd124f3636a745f8c392d"}},
            {50000, uint256{"0000000001a041d0c3b7e9df08ee77f2d64778c1c742078bda24eae4165e0035"}},
            {75000, uint256{"0000000000febb89d63e9a64a63aff5b69cc723e4b2f42591424474b3ed276ed"}},
            {100000, uint256{"00000000042830c66c2690a6c0d9ae9faaad44e0b044b30c246a1cbebd03bd7c"}},
            {150000, uint256{"0000000001d8d8f4535b0844024294333d002a8db40a912d78bccd32edcfdb0a"}},
            {200000, uint256{"0000000002eecb6044f171d7096706f218b4d509695c349ebffb18830bd92947"}},
            {250000, uint256{"00000000046c890c56e575d8dd6ad79d15505cfdb72284b5d4c5ff67cd42e242"}},
            {300000, uint256{"0000000000e02048a31562bc181eb00afdc75ee3cf5c6f0a0dd717011981b0e9"}},
            {350000, uint256{"00000000008ce70c1f0b0f04c540ecbc8c7fdf1b88a2191b7f33ce139b2be417"}},
            {400000, uint256{"000000000184fdf9ee257ee93bb221c6c3e6e4e0579d9caa798b0eb4427fcf2c"}},
            {450000, uint256{"00000000004ea7ea71d71ab57341cec07a38b18064a39c15ff047badf1573ef9"}},
            {500000, uint256{"0000000000048ade7ac56b2b8c4237c25b566bbb49b37f825602e66fbab6572b"}},
            {550000, uint256{"00000000001b9ab4ef2a73cc46e37822010dd334258c40c91e6e70692c56e5d3"}},
            {600000, uint256{"000000000072230765bfaf6a65d13c9d2fc03c8aa1088c4852c9e856c739219d"}},
            {650000, uint256{"0000000000f374620debcf7e09e13aa6d6a7abc59927f725d90c82b548d6bb28"}},
            {700000, uint256{"0000000000a7de02bc8e8405c18817938c9062ae2b8a098787ff8621bf497049"}},
            {750000, uint256{"00000000016981a53e927b430326c0f35c599e1088e1676043d8f6edc0384e09"}},
            {800000, uint256{"00000000017bd990b6fb028a91f5b456349f836a9d1d74d7ef0b734dad6a2dbf"}},
            {850000, uint256{"0000000000f480b94a7fb80a99a20d78fa7a41dc04eb370caef35c4b27af346c"}},
            {900000, uint256{"000000000108180c74e8dd4130545e4bc12e65a74194fe907c8229672a1d0fea"}},
            {950000, uint256{"000000000266e5a198e00940b3e3f215afd3a54bd2f1a69b0c71a6ecc808afc9"}},
            {1000000, uint256{"0000000000944041d3ec14abf5130bb99ad75e3ef7a46b7a2548595d517f7529"}},
            {1100000, uint256{"0000000000bfac39b29a945b216863b95d367c80edcfa0868267220ad8643cb0"}},
            {1200000, uint256{"0000000002e29fd539d84a4afb0398a924acdadec563e44f95107b4e47f0ad33"}},
            {1300000, uint256{"0000000004480af7b63dec8299b082f6f349d6b6ec8b1edd823eff1900ca5524"}},
            {1400000, uint256{"00000000036631a658c9f532b4fb0e55df69f6c0ba26cf8d44fd7f86ea67ef7c"}},
            {1500000, uint256{"00000000151335cda86559fde0ef9aa9418a6dae92c8dbd6ec3ac4d6d7cdbf4c"}},
            {1600000, uint256{"000000000bc1393bc0a4f671c4bbb391a79b07a03d6aac80daaf06700802725a"}},
            {1700000, uint256{"00000000081ee3c218dfaedcf8e272c0db8a2dea2ac240c4bbd99ef8bdc79f8e"}},
            {1794659, uint256{"0000000006e5e50ab26a0341425ee2ed39811a659c01025d963ee5df9caec53a"}},
            {1800000, uint256{"000000000167a8ed376dbe7722eb08fce8f88d3be1bbe855ae05ed2dfdabc83b"}},
            {1840000, uint256{"00000000381fb6afea7e133d120aae4ac2103bcfc7470825e3cfe9b18e3747ca"}},
            {1845912, uint256{"0000000017f68d72e076a15b03b35df45e49556f106e03bd533e4ced85b0391f"}},
            {1851982, uint256{"000000000ce18c2ae9f74f44c4c2e017252ec976e547be8f3206988370eb43b9"}},
            {1857411, uint256{"000000000cb12797dc2da6404812fc3cd1636285bcf00b3b52f98571dccc69c1"}},
            {1858000, uint256{"0000000015add8ec8a7697a271f4a2cb7c716d63e17647bec7c3cc4c5f8c228a"}},
            {1858500, uint256{"00000000286df3ebecd517578323dd2d518631a67318940837b95f4ded61000f"}},
            {1859000, uint256{"000000002d026106e09aeb949305b888b796d4aee9a17e20e0277ac75917274f"}},
            {1859491, uint256{"0000000002d6de2050f0ff663c31d49d3f50bdb5c6a842a56bfd8309c65fa028"}},
            {1859669, uint256{"000000001b05dd502188d111c62fb074d956eaa56f0f9e39d32c6f7d9d2ed258"}},
            {1861820, uint256{"00000000029ed6984cfe2400d35c69abfae5d50733e40834a48868d14995d6fb"}},
            {1862460, uint256{"0000000004964dfaf344a310f9f4ae1bb89ceb6c6be23f8cbb7ec5556ca98411"}},
            {1863254, uint256{"00000000345b4c6b2c0f5e78ceac111f3ccef8772d89a00e3fa852b147e61607"}},
            {1863823, uint256{"000000000f43f9ed24e0639cee23de9fcee68f144cd76faf6f5eec8b7ec375ed"}},
            {1865353, uint256{"00000000342546860cd9250210c63c000e67b5fe1b26559fe5e86b4052175c38"}},
        };

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0x63; // S
        pchMessageStart[1] = 0x56; // A
        pchMessageStart[2] = 0x65; // T
        pchMessageStart[3] = 0x65; // T
        nDefaultPort = 60777;
        nPruneAfterHeight = 100000;
        m_assumed_blockchain_size = 5;
        m_assumed_chain_state_size = 1;

        uint32_t nGenesisTime = 1661730843;
        genesis = CreateGenesisBlock(nGenesisTime, 351574, 0x1e00ffff, 4, 5000 * COIN);
        consensus.hashGenesisBlock = genesis.GetX16RHash();
        assert(consensus.hashGenesisBlock == uint256{"000000edd819220359469c54f2614b5602ebc775ea67a64602f354bdaa320f70"});
        assert(genesis.hashMerkleRoot == uint256{"e8916cf6592c8433d598c3a5fe60a9741fd2a997b39d93af2d789cdd9d9a7390"});

        vSeeds.emplace_back("xnode1.satoverse.io");
        vSeeds.emplace_back("xnode2.satoverse.io");

        // Address start with S
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,63);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,122);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,112);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        bech32_hrp = "bc";

        vFixedSeeds.clear(); // satoxcoin uses DNS seeds only for now

        fDefaultConsistencyChecks = false;
        m_is_mockable_chain = false;

        chainTxData = ChainTxData{
            .nTime = 0,
            .tx_count = 0,
            .dTxRate = 0.0,
        };

        m_headers_sync_params = HeadersSyncParams{
            .commitment_period = 641,
            .redownload_buffer_size = 15218, // 15218/641 = ~23.7 commitments
        };

        /** SATOXCOIN Start **/
        // Burn Amounts
        nIssueAssetBurnAmount = 2000 * COIN;
        nReissueAssetBurnAmount = 1000 * COIN;
        nIssueSubAssetBurnAmount = 1000 * COIN;
        nIssueUniqueAssetBurnAmount = 50 * COIN;
        nIssueMsgChannelAssetBurnAmount = 1000 * COIN;
        nIssueQualifierAssetBurnAmount = 1000 * COIN;
        nIssueSubQualifierAssetBurnAmount = 100 * COIN;
        nIssueRestrictedAssetBurnAmount = 1500 * COIN;
        nAddNullQualifierTagBurnAmount = .1 * COIN;

        // 10% of 300 COIN to Donation
        nCommunityAutonomousAmount = 10;

        // Burn Addresses
        strIssueAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strReissueAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueSubAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueUniqueAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueMsgChannelAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueQualifierAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueSubQualifierAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueRestrictedAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strAddNullQualifierTagBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";

        //Global Burn Address
        strGlobalBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";

        //CommunityAutonomousAddress
        strCommunityAutonomousAddress = "SQ5iQMsmqZiYY96rTx5Hisd7sx5GiGUbbN";

        // DGW Activation
        nDGWActivationBlock = 1;

        nAssetActivationHeight = 1; // Asset activated block height
        nMessagingActivationBlock = 1; // Messaging activated block height
        nRestrictedActivationBlock = 1; // Restricted activated block height

        nKAAAWWWPOWActivationTime = 1662493424;
        nKAWPOWActivationTime = nKAAAWWWPOWActivationTime;
        /** SATOXCOIN End **/
    }
};

/**
 * Testnet (v3): public test network which is reset from time to time.
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        m_chain_type = ChainType::TESTNET;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 2100000;  //~ 4 yrs at 1 min block time
        consensus.nBIP34Enabled = true;
        consensus.nBIP65Enabled = true; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.nBIP66Enabled = true;
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.BIP34Height = 6048;
        consensus.BIP65Height = 0;
        consensus.BIP66Height = 0;
        consensus.CSVHeight = 0;
        consensus.SegwitHeight = 0;
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256{"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
        consensus.kawpowLimit = uint256{"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"}; // Estimated starting diff for first 180 kawpow blocks
        consensus.nPowTargetTimespan = 2016 * 60; // 1.4 days
        consensus.nPowTargetSpacing = 1 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.enforce_BIP94 = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1613; // Approx 80% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 2016;
        // Taproot was never deployed on satoxcoin testnet; keep the slot
        // populated with a distinct bit but never-active to match history.
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 1815;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;  //Assets (HIP2)
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].threshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].bit = 7;  // Assets (HIP5)
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].threshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].bit = 8;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].threshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].bit = 10;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].bit = 11;  // Asset transfer overflow check
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nStartTime = 1789862400; // UTC: Sun Sept 20 2026 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nTimeout = 1821398400; // UTC: Mon Sept 20 2027 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].period = 2016;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256{"0000000000000000000000000000000000000000000000000000000000100010"};

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256{"000000eaab417d6dfe9bd75119972e1d07ecfe8ff655bef7c2acb3d9a0eeed81"};

        pchMessageStart[0] = 0x74; // t
        pchMessageStart[1] = 0x53; // S
        pchMessageStart[2] = 0x41; // A
        pchMessageStart[3] = 0x54; // T
        nDefaultPort = 7060;
        nPruneAfterHeight = 1000;
        m_assumed_blockchain_size = 245;
        m_assumed_chain_state_size = 19;

        uint32_t nGenesisTime = 1661734222;
        genesis = CreateGenesisBlock(nGenesisTime, 7680541, 0x1e00ffff, 4, 5000 * COIN);
        consensus.hashGenesisBlock = genesis.GetX16RHash();
        assert(consensus.hashGenesisBlock == uint256{"000000eaab417d6dfe9bd75119972e1d07ecfe8ff655bef7c2acb3d9a0eeed81"});
        assert(genesis.hashMerkleRoot == uint256{"e8916cf6592c8433d598c3a5fe60a9741fd2a997b39d93af2d789cdd9d9a7390"});

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,63);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,124);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,114);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tb";

        fDefaultConsistencyChecks = false;
        m_is_mockable_chain = false;

        chainTxData = ChainTxData{
            .nTime = 0,
            .tx_count = 0,
            .dTxRate = 0.0,
        };

        m_headers_sync_params = HeadersSyncParams{
            .commitment_period = 673,
            .redownload_buffer_size = 14460, // 14460/673 = ~21.5 commitments
        };

        /** SATOXCOIN Start **/
        // Burn Amounts
        nIssueAssetBurnAmount = 500 * COIN;
        nReissueAssetBurnAmount = 100 * COIN;
        nIssueSubAssetBurnAmount = 100 * COIN;
        nIssueUniqueAssetBurnAmount = 5 * COIN;
        nIssueMsgChannelAssetBurnAmount = 100 * COIN;
        nIssueQualifierAssetBurnAmount = 1000 * COIN;
        nIssueSubQualifierAssetBurnAmount = 100 * COIN;
        nIssueRestrictedAssetBurnAmount = 1500 * COIN;
        nAddNullQualifierTagBurnAmount = .1 * COIN;

        nCommunityAutonomousAmount = 15;

        strIssueAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strReissueAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueSubAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueUniqueAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueMsgChannelAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueQualifierAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueSubQualifierAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueRestrictedAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strAddNullQualifierTagBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";

        strGlobalBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strCommunityAutonomousAddress = "SQ5iQMsmqZiYY96rTx5Hisd7sx5GiGUbbN";

        nDGWActivationBlock = 1;
        nAssetActivationHeight = 1; // Asset activated block height
        nMessagingActivationBlock = 1; // Messaging activated block height
        nRestrictedActivationBlock = 1; // Restricted activated block height

        nKAAAWWWPOWActivationTime = 1661833868;
        nKAWPOWActivationTime = nKAAAWWWPOWActivationTime;
        /** SATOXCOIN End **/
    }
};

/**
 * Testnet (v4): public test network which is reset from time to time.
 */
class CTestNet4Params : public CChainParams {
public:
    CTestNet4Params() {
        m_chain_type = ChainType::TESTNET4;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nSubsidyHalvingInterval = 2100000;  //~ 4 yrs at 1 min block time
        consensus.nBIP34Enabled = true;
        consensus.nBIP65Enabled = true;
        consensus.nBIP66Enabled = true;
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256{};
        consensus.BIP65Height = 1;
        consensus.BIP66Height = 1;
        consensus.CSVHeight = 1;
        consensus.SegwitHeight = 1;
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256{"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
        consensus.nPowTargetTimespan = 2016 * 60; // 1.4 days
        consensus.nPowTargetSpacing = 1 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.enforce_BIP94 = false;
        consensus.fPowNoRetargeting = false;

        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 1512; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 2016;

        // Deployment of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 1512; // 75%
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 2016;

        // Satoxcoin asset deployments (HIP2/HIP5 etc.) with the original
        // satoxcoin mainnet values, which is what actually worked.
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].threshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].bit = 7;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].threshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].bit = 8;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].threshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].bit = 10;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].bit = 11;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nStartTime = 1789862400; // UTC: Sun Sept 20 2026 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nTimeout = 1821398400; // UTC: Mon Sept 20 2027 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].period = 2016;

        nCommunityAutonomousAmount = 0;

        consensus.nMinimumChainWork = uint256{"0000000000000000000000000000000000000000000009a0fe15d0177d086304"};
        consensus.defaultAssumeValid = uint256{"0000000002368b1e4ee27e2e85676ae6f9f9e69579b29093e9a82c170bf7cf8a"}; // 123613

        pchMessageStart[0] = 0x1c;
        pchMessageStart[1] = 0x16;
        pchMessageStart[2] = 0x3f;
        pchMessageStart[3] = 0x28;
        nDefaultPort = 48333;
        nPruneAfterHeight = 1000;
        m_assumed_blockchain_size = 31;
        m_assumed_chain_state_size = 2;

        const char* testnet4_genesis_msg = "The WSJ 08/28/2022 Investors Ramp Up Bets Against Stock Market";
        const CScript testnet4_genesis_script = CScript() << "04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f"_hex << OP_CHECKSIG;
        genesis = CreateGenesisBlock(testnet4_genesis_msg,
                testnet4_genesis_script,
                1661734222,
                7680541,
                0x1e00ffff,
                4,
                5000 * COIN);
        consensus.hashGenesisBlock = genesis.GetX16RHash();
        assert(consensus.hashGenesisBlock == uint256{"000000eaab417d6dfe9bd75119972e1d07ecfe8ff655bef7c2acb3d9a0eeed81"});
        assert(genesis.hashMerkleRoot == uint256{"e8916cf6592c8433d598c3a5fe60a9741fd2a997b39d93af2d789cdd9d9a7390"});

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,63);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,124);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,114);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tb";

        fDefaultConsistencyChecks = false;
        m_is_mockable_chain = false;

        m_assumeutxo_data = {
            {
                .height = 90'000,
                .hash_serialized = AssumeutxoHash{uint256{"784fb5e98241de66fdd429f4392155c9e7db5c017148e66e8fdbc95746f8b9b5"}},
                .m_chain_tx_count = 11347043,
                .blockhash = uint256{"0000000002ebe8bcda020e0dd6ccfbdfac531d2f6a81457191b99fc2df2dbe3b"},
            },
            {
                .height = 120'000,
                .hash_serialized = AssumeutxoHash{uint256{"10b05d05ad468d0971162e1b222a4aa66caca89da2bb2a93f8f37fb29c4794b0"}},
                .m_chain_tx_count = 14141057,
                .blockhash = uint256{"000000000bd2317e51b3c5794981c35ba894ce27d3e772d5c39ecd9cbce01dc8"},
            }
        };

        chainTxData = ChainTxData{
            .nTime    = 1772013387,
            .tx_count = 14191421,
            .dTxRate  = 0.01848579579528412,
        };

        /** SATOXCOIN Start **/
        // Burn Amounts
        nIssueAssetBurnAmount = 500 * COIN;
        nReissueAssetBurnAmount = 100 * COIN;
        nIssueSubAssetBurnAmount = 100 * COIN;
        nIssueUniqueAssetBurnAmount = 5 * COIN;
        nIssueMsgChannelAssetBurnAmount = 100 * COIN;
        nIssueQualifierAssetBurnAmount = 1000 * COIN;
        nIssueSubQualifierAssetBurnAmount = 100 * COIN;
        nIssueRestrictedAssetBurnAmount = 1500 * COIN;
        nAddNullQualifierTagBurnAmount = .1 * COIN;

        nCommunityAutonomousAmount = 15;

        strIssueAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strReissueAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueSubAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueUniqueAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueMsgChannelAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueQualifierAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueSubQualifierAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strIssueRestrictedAssetBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strAddNullQualifierTagBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";

        strGlobalBurnAddress = "SNAfE1SrtPirLK3HxfJvV37fQkYj7ragtC";
        strCommunityAutonomousAddress = "SQ5iQMsmqZiYY96rTx5Hisd7sx5GiGUbbN";

        nDGWActivationBlock = 1;
        nAssetActivationHeight = 1;
        nMessagingActivationBlock = 1;
        nRestrictedActivationBlock = 1;

        nKAAAWWWPOWActivationTime = 1661833868;
        /** SATOXCOIN End **/

        // Generated by headerssync-params.py on 2026-02-25.
        m_headers_sync_params = HeadersSyncParams{
            .commitment_period = 606,
            .redownload_buffer_size = 16092, // 16092/606 = ~26.6 commitments
        };
    }
};

/**
 * Signet: test network with an additional consensus parameter (see BIP325).
 */
class SigNetParams : public CChainParams {
public:
    explicit SigNetParams(const SigNetOptions& options)
    {
        std::vector<uint8_t> bin;
        vFixedSeeds.clear();
        vSeeds.clear();

        if (!options.challenge) {
            bin = "512103ad5e0edad18cb1f0fc0d28a3d4f1f3e445640337489abb10404f2d1e086be430210359ef5021964fe22d6f8e05b2463c9540ce96883fe3b278760f048f5189f2e6c452ae"_hex_v_u8;
            vFixedSeeds = std::vector<uint8_t>(std::begin(chainparams_seed_signet), std::end(chainparams_seed_signet));
            vSeeds.emplace_back("seed.signet.bitcoin.sprovoost.nl.");
            vSeeds.emplace_back("seed.signet.achownodes.xyz."); // Ava Chow, only supports x1, x5, x9, x49, x809, x849, xd, x400, x404, x408, x448, xc08, xc48, x40c

            consensus.nMinimumChainWork = uint256{"00000000000000000000000000000000000000000000000000000b463ea0a4b8"};
            consensus.defaultAssumeValid = uint256{"00000008414aab61092ef93f1aacc54cf9e9f16af29ddad493b908a01ff5c329"}; // 293175
            m_assumed_blockchain_size = 24;
            m_assumed_chain_state_size = 4;
            chainTxData = ChainTxData{
                // Data from RPC: getchaintxstats 4096 00000008414aab61092ef93f1aacc54cf9e9f16af29ddad493b908a01ff5c329
                .nTime    = 1772055248,
                .tx_count = 28676833,
                .dTxRate  = 0.06736623436338929,
            };
        } else {
            bin = *options.challenge;
            consensus.nMinimumChainWork = uint256{};
            consensus.defaultAssumeValid = uint256{};
            m_assumed_blockchain_size = 0;
            m_assumed_chain_state_size = 0;
            chainTxData = ChainTxData{
                0,
                0,
                0,
            };
            LogInfo("Signet with challenge %s", HexStr(bin));
        }

        if (options.seeds) {
            vSeeds = *options.seeds;
        }

        m_chain_type = ChainType::SIGNET;
        consensus.signet_blocks = true;
        consensus.signet_challenge.assign(bin.begin(), bin.end());
        consensus.nSubsidyHalvingInterval = 210000;
        consensus.BIP34Height = 1;
        consensus.BIP34Hash = uint256{};
        consensus.BIP65Height = 1;
        consensus.BIP66Height = 1;
        consensus.CSVHeight = 1;
        consensus.SegwitHeight = 1;
        consensus.nPowTargetTimespan = 14 * 24 * 60 * 60; // two weeks
        consensus.nPowTargetSpacing = 10 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.enforce_BIP94 = false;
        consensus.fPowNoRetargeting = false;
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256{"00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 1815; // 90%
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 2016;

        // Activation of Taproot (BIPs 340-342)
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].min_activation_height = 0; // No activation delay
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 1815; // 90%
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 2016;

        // Satoxcoin asset deployments (HIP2/HIP5 etc.) with the original
        // satoxcoin mainnet values, which is what actually worked.
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].threshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].bit = 7;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].threshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].bit = 8;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].threshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].bit = 10;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].period = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].bit = 11;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nStartTime = 1789862400; // UTC: Sun Sept 20 2026 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nTimeout = 1821398400; // UTC: Mon Sept 20 2027 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].threshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].period = 2016;

        nCommunityAutonomousAmount = 0;

        // message start is defined as the first 4 bytes of the sha256d of the block script
        HashWriter h{};
        h << consensus.signet_challenge;
        uint256 hash = h.GetHash();
        std::copy_n(hash.begin(), 4, pchMessageStart.begin());

        nDefaultPort = 38333;
        nPruneAfterHeight = 1000;

        genesis = CreateGenesisBlock(1661730843, 351574, 0x1e00ffff, 4, 5000 * COIN);
        consensus.hashGenesisBlock = genesis.GetX16RHash();
        assert(consensus.hashGenesisBlock == uint256{"000000edd819220359469c54f2614b5602ebc775ea67a64602f354bdaa320f70"});
        assert(genesis.hashMerkleRoot == uint256{"e8916cf6592c8433d598c3a5fe60a9741fd2a997b39d93af2d789cdd9d9a7390"});

        m_assumeutxo_data = {
            {
                .height = 160'000,
                .hash_serialized = AssumeutxoHash{uint256{"fe0a44309b74d6b5883d246cb419c6221bcccf0b308c9b59b7d70783dbdf928a"}},
                .m_chain_tx_count = 2289496,
                .blockhash = uint256{"0000003ca3c99aff040f2563c2ad8f8ec88bd0fd6b8f0895cfaf1ef90353a62c"},
            },
            {
                .height = 290'000,
                .hash_serialized = AssumeutxoHash{uint256{"97267e000b4b876800167e71b9123f1529d13b14308abec2888bbd2160d14545"}},
                .m_chain_tx_count = 28547497,
                .blockhash = uint256{"0000000577f2741bb30cd9d39d6d71b023afbeb9764f6260786a97969d5c9ac0"},
            }
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "tb";

        fDefaultConsistencyChecks = false;
        m_is_mockable_chain = false;

        // Generated by headerssync-params.py on 2026-02-25.
        m_headers_sync_params = HeadersSyncParams{
            .commitment_period = 620,
            .redownload_buffer_size = 15724, // 15724/620 = ~25.4 commitments
        };
    }
};

/**
 * Regression test: intended for private networks only. Has minimal difficulty to ensure that
 * blocks can be found instantly.
 */
class CRegTestParams : public CChainParams
{
public:
    explicit CRegTestParams(const RegTestOptions& opts)
    {
        m_chain_type = ChainType::REGTEST;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();
        consensus.nBIP34Enabled = true;
        consensus.nBIP65Enabled = true; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.nBIP66Enabled = true;
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.nSubsidyHalvingInterval = 150;
        consensus.BIP34Height = 1; // Always active unless overridden
        consensus.BIP65Height = 1;  // Always active unless overridden
        consensus.BIP66Height = 1;  // Always active unless overridden
        consensus.CSVHeight = 1;    // Always active unless overridden
        consensus.SegwitHeight = 0; // Always active unless overridden
        consensus.MinBIP9WarningHeight = 0;
        consensus.powLimit = uint256{"7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
        consensus.kawpowLimit = uint256{"7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
        consensus.nPowTargetTimespan = 2016 * 60; // 1.4 days
        consensus.nPowTargetSpacing = 1 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.enforce_BIP94 = opts.enforce_bip94;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].threshold = 108;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].period = 144;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].bit = 2;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nStartTime = Consensus::BIP9Deployment::ALWAYS_ACTIVE;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].threshold = 108;
        consensus.vDeployments[Consensus::DEPLOYMENT_TAPROOT].period = 144;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].threshold = 108;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].period = 144;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].bit = 7;  // Assets (RIP5)
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].threshold = 108;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].period = 144;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].bit = 8;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].threshold = 208;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].period = 288;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].threshold = 108;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].period = 144;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].bit = 10;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].threshold = 400;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].period = 500;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].bit = 11;  // Asset transfer overflow check
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].threshold = 400;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].period = 500;

        consensus.nMinimumChainWork = uint256{};
        consensus.defaultAssumeValid = uint256{};

        pchMessageStart[0] = 0x44; // D
        pchMessageStart[1] = 0x52; // R
        pchMessageStart[2] = 0x4F; // O
        pchMessageStart[3] = 0x57; // W
        nDefaultPort = 19444;
        nPruneAfterHeight = opts.fastprune ? 100 : 1000;
        m_assumed_blockchain_size = 0;
        m_assumed_chain_state_size = 0;

        for (const auto& [dep, height] : opts.activation_heights) {
            switch (dep) {
            case Consensus::BuriedDeployment::DEPLOYMENT_SEGWIT:
                consensus.SegwitHeight = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_HEIGHTINCB:
                consensus.BIP34Height = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_DERSIG:
                consensus.BIP66Height = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_CLTV:
                consensus.BIP65Height = int{height};
                break;
            case Consensus::BuriedDeployment::DEPLOYMENT_CSV:
                consensus.CSVHeight = int{height};
                break;
            }
        }

        for (const auto& [deployment_pos, version_bits_params] : opts.version_bits_parameters) {
            consensus.vDeployments[deployment_pos].nStartTime = version_bits_params.start_time;
            consensus.vDeployments[deployment_pos].nTimeout = version_bits_params.timeout;
            consensus.vDeployments[deployment_pos].min_activation_height = version_bits_params.min_activation_height;
        }

        genesis = CreateGenesisBlock(1661734578, 671, 0x207fffff, 4, 5000 * COIN);
        consensus.hashGenesisBlock = genesis.GetX16RHash();
        assert(consensus.hashGenesisBlock == uint256{"006909eb6fd3fcf752b96039a91f06dd7eaf579a19a8d0092a70e09da8d8a3a6"});
        assert(genesis.hashMerkleRoot == uint256{"e8916cf6592c8433d598c3a5fe60a9741fd2a997b39d93af2d789cdd9d9a7390"});

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();
        vSeeds.emplace_back("dummySeed.invalid.");

        fDefaultConsistencyChecks = true;
        m_is_mockable_chain = true;

        m_assumeutxo_data = {
            {   // For use by unit tests
                .height = 110,
                .hash_serialized = AssumeutxoHash{uint256{"6fdc5ec2417b773d371d77c4f662b3e2dca763d12059d5f18c94428cde04b1ef"}},
                .m_chain_tx_count = 111,
                .blockhash = uint256{"03e64597cf3d71428725389b0faf9764b30fc4a453a2f9463d22daccd02c80cc"},
            },
            {
                // For use by fuzz target src/test/fuzz/utxo_snapshot.cpp
                .height = 200,
                .hash_serialized = AssumeutxoHash{uint256{"59c4d509ddc035344b895250fbe96fe9ef4ec263f8daa6ff0a87a4ab478414eb"}},
                .m_chain_tx_count = 201,
                .blockhash = uint256{"4aad9cb5a9f3edb8de8c2a3437290b23a3f307aeb2667d0355e66cbafbf15192"},
            },
            {
                // For use by test/functional/feature_assumeutxo.py and test/functional/tool_bitcoin_chainstate.py
                .height = 299,
                .hash_serialized = AssumeutxoHash{uint256{"d2b051ff5e8eef46520350776f4100dd710a63447a8e01d917e92e79751a63e2"}},
                .m_chain_tx_count = 334,
                .blockhash = uint256{"7cc695046fec709f8c9394b6f928f81e81fd3ac20977bb68760fa1faa7916ea2"},
            },
        };

        chainTxData = ChainTxData{
            .nTime = 0,
            .tx_count = 0,
            .dTxRate = 0.001, // Set a non-zero rate to make it testable
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,42);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,124);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,114);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        bech32_hrp = "bcrt";

        m_headers_sync_params = HeadersSyncParams{
            .commitment_period = 275,
            .redownload_buffer_size = 7017, // 7017/275 = ~25.5 commitments
        };

        /** SATOXCOIN Start **/
        // Burn Amounts
        nIssueAssetBurnAmount = 500 * COIN;
        nReissueAssetBurnAmount = 100 * COIN;
        nIssueSubAssetBurnAmount = 100 * COIN;
        nIssueUniqueAssetBurnAmount = 5 * COIN;
        nIssueMsgChannelAssetBurnAmount = 100 * COIN;
        nIssueQualifierAssetBurnAmount = 1000 * COIN;
        nIssueSubQualifierAssetBurnAmount = 100 * COIN;
        nIssueRestrictedAssetBurnAmount = 1500 * COIN;
        nAddNullQualifierTagBurnAmount = .1 * COIN;

        nCommunityAutonomousAmount = 10;

        strIssueAssetBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";
        strReissueAssetBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";
        strIssueSubAssetBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";
        strIssueUniqueAssetBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";
        strIssueMsgChannelAssetBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";
        strIssueQualifierAssetBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";
        strIssueSubQualifierAssetBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";
        strIssueRestrictedAssetBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";
        strAddNullQualifierTagBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";

        strGlobalBurnAddress = "Hx3ktVQY3hiWNHVKhTVPF8JtKTZXmUaeFG";
        strCommunityAutonomousAddress = "Hz1NNqgsGrEkhCCHWPbagdfVYmRczcLtur";

        nDGWActivationBlock = 200;
        nAssetActivationHeight = 0; // Asset activated block height
        nMessagingActivationBlock = 0; // Messaging activated block height
        nRestrictedActivationBlock = 0; // Restricted activated block height

        nKAAAWWWPOWActivationTime = 3582830167;
        nKAWPOWActivationTime = nKAAAWWWPOWActivationTime;
        /** SATOXCOIN End **/
    }
};

std::unique_ptr<const CChainParams> CChainParams::SigNet(const SigNetOptions& options)
{
    return std::make_unique<const SigNetParams>(options);
}

std::unique_ptr<const CChainParams> CChainParams::RegTest(const RegTestOptions& options)
{
    return std::make_unique<const CRegTestParams>(options);
}

std::unique_ptr<const CChainParams> CChainParams::Main()
{
    return std::make_unique<const CMainParams>();
}

std::unique_ptr<const CChainParams> CChainParams::TestNet()
{
    return std::make_unique<const CTestNetParams>();
}

std::unique_ptr<const CChainParams> CChainParams::TestNet4()
{
    return std::make_unique<const CTestNet4Params>();
}

std::vector<int> CChainParams::GetAvailableSnapshotHeights() const
{
    std::vector<int> heights;
    heights.reserve(m_assumeutxo_data.size());

    for (const auto& data : m_assumeutxo_data) {
        heights.emplace_back(data.height);
    }
    return heights;
}

std::optional<ChainType> GetNetworkForMagic(const MessageStartChars& message)
{
    const auto mainnet_msg = CChainParams::Main()->MessageStart();
    const auto testnet_msg = CChainParams::TestNet()->MessageStart();
    const auto testnet4_msg = CChainParams::TestNet4()->MessageStart();
    const auto regtest_msg = CChainParams::RegTest({})->MessageStart();
    const auto signet_msg = CChainParams::SigNet({})->MessageStart();

    if (std::ranges::equal(message, mainnet_msg)) {
        return ChainType::MAIN;
    } else if (std::ranges::equal(message, testnet_msg)) {
        return ChainType::TESTNET;
    } else if (std::ranges::equal(message, testnet4_msg)) {
        return ChainType::TESTNET4;
    } else if (std::ranges::equal(message, regtest_msg)) {
        return ChainType::REGTEST;
    } else if (std::ranges::equal(message, signet_msg)) {
        return ChainType::SIGNET;
    }
    return std::nullopt;
}
