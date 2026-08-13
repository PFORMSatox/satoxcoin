// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2017-2021 The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "consensus/merkle.h"

#include "tinyformat.h"
#include "util.h"
#include "utilstrencodings.h"
#include "arith_uint256.h"

#include <assert.h>
#include "chainparamsseeds.h"

//TODO: Take these out
extern double algoHashTotal[16];
extern int algoHashHits[16];


static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
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
    const CScript genesisOutputScript = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

void CChainParams::UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    consensus.vDeployments[d].nStartTime = nStartTime;
    consensus.vDeployments[d].nTimeout = nTimeout;
}

void CChainParams::TurnOffSegwit() {
	consensus.nSegwitEnabled = false;
}

void CChainParams::TurnOffCSV() {
	consensus.nCSVEnabled = false;
}

void CChainParams::TurnOffBIP34() {
	consensus.nBIP34Enabled = false;
}

void CChainParams::TurnOffBIP65() {
	consensus.nBIP65Enabled = false;
}

void CChainParams::TurnOffBIP66() {
	consensus.nBIP66Enabled = false;
}

bool CChainParams::BIP34() {
	return consensus.nBIP34Enabled;
}

bool CChainParams::BIP65() {
	return consensus.nBIP34Enabled;
}

bool CChainParams::BIP66() {
	return consensus.nBIP34Enabled;
}

bool CChainParams::CSVEnabled() const{
	return consensus.nCSVEnabled;
}


/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 2100000;  //~ 4 yrs at 1 min block time
        consensus.nBIP34Enabled = true;
        consensus.nBIP65Enabled = true; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.nBIP66Enabled = true;
        consensus.BIP34LockedIn = 6048; // Locked_in at height 6048
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.powLimit = uint256S("00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.kawpowLimit = uint256S("00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // Estimated starting diff for first 180 kawpow blocks
        consensus.nPowTargetTimespan = 2016 * 60; // 1.4 days
        consensus.nPowTargetSpacing = 1 * 60;
		consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1613; // Approx 80% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nOverrideRuleChangeActivationThreshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;  //Assets (HIP2)
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nOverrideRuleChangeActivationThreshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].bit = 7;  // Assets (HIP5)
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nOverrideRuleChangeActivationThreshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].bit = 8;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nOverrideRuleChangeActivationThreshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nOverrideRuleChangeActivationThreshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].bit = 10;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nStartTime = 1653004800; // Friday, 20 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nTimeout = 1653264000; // Monday, 23 May 2022 00:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nOverrideRuleChangeActivationThreshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nOverrideMinerConfirmationWindow = 2016;


        // The best chain should have at least this much work
        consensus.nMinimumChainWork = uint256S("0x0000000000000000000000000000000000000000000000000000005a0da9fea5"); // Block 2000

        // By default assume that the signatures in ancestors of this block are valid
        consensus.defaultAssumeValid = uint256S("0x0000000002d6de2050f0ff663c31d49d3f50bdb5c6a842a56bfd8309c65fa028"); // Block 1859491 (matches last verified checkpoint)

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

        uint32_t nGenesisTime = 1661730843;

        genesis = CreateGenesisBlock(nGenesisTime, 351574, 0x1e00ffff, 4, 5000 * COIN);

        consensus.hashGenesisBlock = genesis.GetX16RHash();

        assert(consensus.hashGenesisBlock == uint256S("0x000000edd819220359469c54f2614b5602ebc775ea67a64602f354bdaa320f70"));
        assert(genesis.hashMerkleRoot == uint256S("0xe8916cf6592c8433d598c3a5fe60a9741fd2a997b39d93af2d789cdd9d9a7390"));

        vSeeds.emplace_back("xnode1.satoverse.io", false);
        vSeeds.emplace_back("xnode2.satoverse.io", false);

        // Address start with S
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,63);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,122);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,112);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};

        // Satoxcoin BIP44 cointype in mainnet is '1669'
        nExtCoinType = 1669;

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fMiningRequiresPeers = true;

        checkpointData = (CCheckpointData) {
            {
                { 0, uint256S("0x000000edd819220359469c54f2614b5602ebc775ea67a64602f354bdaa320f70")},
                { 1, uint256S("0x0043e718ee6c848abf0bbf8fe94d357c878324b03ce34badd4b6ed71b3533030")},
                { 2, uint256S("0x001f7f5c529b5e3b1c0e8c5ff8592dd1a636d1579430a924574dc696e0456705")},
                { 100, uint256S("0x0000001b0371bf5570c68dda2b73cdcb1909c3357875f0b7cc85b08395853cf7")},
                { 500, uint256S("0x00000022fa6cc7fbe32a126e75f73e0fa3ae7069e8f4cf6ac57f96a7416a5aca")},
                { 1500, uint256S("0x0000000509bd097b77ce6b91fd5a395904a8ec006b984413b50bdb9464276cb6")},
                { 5000, uint256S("0x0000000036b67ab707e7dbcd6047a0ba07724db8640e2100c0c4bb96351b5aa3")},
                { 8000, uint256S("0x0000000083e6d953f6d4278b83cec357bc559a2736501d8f9dff07f411d9b7b0")},
                { 12000, uint256S("0x00000000199b7f1c005dd6bf32e5585727ba488add6ea372944339108a960ea3")},
                { 15000, uint256S("0x00000002a4ddadb03fb7793ae1f97c87e07314e01fb21aa9707111dfa191fff2")},
                { 25000, uint256S("0x00000000fa507ef3854bdb089523a5d2a315a7c0bacbd124f3636a745f8c392d")},
                { 50000, uint256S("0x0000000001a041d0c3b7e9df08ee77f2d64778c1c742078bda24eae4165e0035")},
                { 75000, uint256S("0x0000000000febb89d63e9a64a63aff5b69cc723e4b2f42591424474b3ed276ed")},
                { 100000, uint256S("0x00000000042830c66c2690a6c0d9ae9faaad44e0b044b30c246a1cbebd03bd7c")},
                { 150000, uint256S("0x0000000001d8d8f4535b0844024294333d002a8db40a912d78bccd32edcfdb0a")},
                { 200000, uint256S("0x0000000002eecb6044f171d7096706f218b4d509695c349ebffb18830bd92947")},
                { 250000, uint256S("0x00000000046c890c56e575d8dd6ad79d15505cfdb72284b5d4c5ff67cd42e242")},
                { 300000, uint256S("0x0000000000e02048a31562bc181eb00afdc75ee3cf5c6f0a0dd717011981b0e9")},
                { 350000, uint256S("0x00000000008ce70c1f0b0f04c540ecbc8c7fdf1b88a2191b7f33ce139b2be417")},
                { 400000, uint256S("0x000000000184fdf9ee257ee93bb221c6c3e6e4e0579d9caa798b0eb4427fcf2c")},
                { 450000, uint256S("0x00000000004ea7ea71d71ab57341cec07a38b18064a39c15ff047badf1573ef9")},
                { 500000, uint256S("0x0000000000048ade7ac56b2b8c4237c25b566bbb49b37f825602e66fbab6572b")},
                { 550000, uint256S("0x00000000001b9ab4ef2a73cc46e37822010dd334258c40c91e6e70692c56e5d3")},
                { 600000, uint256S("0x000000000072230765bfaf6a65d13c9d2fc03c8aa1088c4852c9e856c739219d")},
                { 650000, uint256S("0x0000000000f374620debcf7e09e13aa6d6a7abc59927f725d90c82b548d6bb28")},
                { 700000, uint256S("0x0000000000a7de02bc8e8405c18817938c9062ae2b8a098787ff8621bf497049")},
                { 750000, uint256S("0x00000000016981a53e927b430326c0f35c599e1088e1676043d8f6edc0384e09")},
                { 800000, uint256S("0x00000000017bd990b6fb028a91f5b456349f836a9d1d74d7ef0b734dad6a2dbf")},
                { 850000, uint256S("0x0000000000f480b94a7fb80a99a20d78fa7a41dc04eb370caef35c4b27af346c")},
                { 900000, uint256S("0x000000000108180c74e8dd4130545e4bc12e65a74194fe907c8229672a1d0fea")},
                { 950000, uint256S("0x000000000266e5a198e00940b3e3f215afd3a54bd2f1a69b0c71a6ecc808afc9")},
                { 1000000, uint256S("0x0000000000944041d3ec14abf5130bb99ad75e3ef7a46b7a2548595d517f7529")},
                { 1100000, uint256S("0x0000000000bfac39b29a945b216863b95d367c80edcfa0868267220ad8643cb0")},
                { 1200000, uint256S("0x0000000002e29fd539d84a4afb0398a924acdadec563e44f95107b4e47f0ad33")},
                { 1300000, uint256S("0x0000000004480af7b63dec8299b082f6f349d6b6ec8b1edd823eff1900ca5524")},
                { 1400000, uint256S("0x00000000036631a658c9f532b4fb0e55df69f6c0ba26cf8d44fd7f86ea67ef7c")},
                { 1500000, uint256S("0x00000000151335cda86559fde0ef9aa9418a6dae92c8dbd6ec3ac4d6d7cdbf4c")},
                { 1600000, uint256S("0x000000000bc1393bc0a4f671c4bbb391a79b07a03d6aac80daaf06700802725a")},
                { 1700000, uint256S("0x00000000081ee3c218dfaedcf8e272c0db8a2dea2ac240c4bbd99ef8bdc79f8e")},
                { 1794659, uint256S("0x0000000006e5e50ab26a0341425ee2ed39811a659c01025d963ee5df9caec53a")},
                { 1800000, uint256S("0x000000000167a8ed376dbe7722eb08fce8f88d3be1bbe855ae05ed2dfdabc83b")},
                { 1840000, uint256S("0x00000000381fb6afea7e133d120aae4ac2103bcfc7470825e3cfe9b18e3747ca")},
                { 1845912, uint256S("0x0000000017f68d72e076a15b03b35df45e49556f106e03bd533e4ced85b0391f")},
                { 1851982, uint256S("0x000000000ce18c2ae9f74f44c4c2e017252ec976e547be8f3206988370eb43b9")},
                { 1857411, uint256S("0x000000000cb12797dc2da6404812fc3cd1636285bcf00b3b52f98571dccc69c1")},
                { 1858000, uint256S("0x0000000015add8ec8a7697a271f4a2cb7c716d63e17647bec7c3cc4c5f8c228a")},
                { 1858500, uint256S("0x00000000286df3ebecd517578323dd2d518631a67318940837b95f4ded61000f")},
                { 1859000, uint256S("0x000000002d026106e09aeb949305b888b796d4aee9a17e20e0277ac75917274f")},
                { 1859491, uint256S("0x0000000002d6de2050f0ff663c31d49d3f50bdb5c6a842a56bfd8309c65fa028")},
                { 1859669, uint256S("0x000000001b05dd502188d111c62fb074d956eaa56f0f9e39d32c6f7d9d2ed258")},
                { 1861820, uint256S("0x00000000029ed6984cfe2400d35c69abfae5d50733e40834a48868d14995d6fb")},
                { 1862460, uint256S("0x0000000004964dfaf344a310f9f4ae1bb89ceb6c6be23f8cbb7ec5556ca98411")},
                { 1863254, uint256S("0x00000000345b4c6b2c0f5e78ceac111f3ccef8772d89a00e3fa852b147e61607")},
                { 1863823, uint256S("0x000000000f43f9ed24e0639cee23de9fcee68f144cd76faf6f5eec8b7ec375ed")},
                { 1865353, uint256S("0x00000000342546860cd9250210c63c000e67b5fe1b26559fe5e86b4052175c38")}
            }
        };

		// 20969961 transactions as of block #2383625 at 2022-07-28 22:02:22 (UTC)
		// previously set at 6709969 txns by time 1577939273 ==>
        chainTxData = ChainTxData{
            // Update as we know more about the contents of the satoxcoin chain from rpc: getchaintxstats 50000
            0, // * UNIX timestamp of last known number of transactions
            0,      // * total number of transactions between genesis and that timestamp
                        //   (the tx=... number in the SetBestChain debug.log lines)
            0.0     // * estimated number of transactions per second after that timestamp
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

        // Donation Address
        strCommunityAutonomousAddress = "SQ5iQMsmqZiYY96rTx5Hisd7sx5GiGUbbN";

        // DGW Activation
        nDGWActivationBlock = 1;

        nMaxReorganizationDepth = 60; // 60 at 1 minute block timespan is +/- 60 minutes.
        nMinReorganizationPeers = 4;
        nMinReorganizationAge = 60 * 60 * 12; // 12 hours

        nAssetActivationHeight = 1; // Asset activated block height
        nMessagingActivationBlock = 1; // Messaging activated block height
        nRestrictedActivationBlock = 1; // Restricted activated block height

        nKAAAWWWPOWActivationTime = 1662493424;
        nKAWPOWActivationTime = nKAAAWWWPOWActivationTime;
        /** SATOXCOIN End **/
    }
};

/**
 * Testnet (v7)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 2100000;  //~ 4 yrs at 1 min block time
        consensus.nBIP34Enabled = true;
        consensus.nBIP65Enabled = true; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.nBIP66Enabled = true;
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.powLimit = uint256S("00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.kawpowLimit = uint256S("00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // Estimated starting diff for first 180 kawpow blocks
        consensus.nPowTargetTimespan = 2016 * 60; // 1.4 days
        consensus.nPowTargetSpacing = 1 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1613; // Approx 80% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nOverrideRuleChangeActivationThreshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;  //Assets (HIP2)
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nOverrideRuleChangeActivationThreshold = 1814;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].bit = 7;  // Assets (HIP5)
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nOverrideRuleChangeActivationThreshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].bit = 8;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nOverrideRuleChangeActivationThreshold = 1714; // Approx 85% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nOverrideRuleChangeActivationThreshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nOverrideMinerConfirmationWindow = 2016;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].bit = 10;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nStartTime = 1658055600; // Sunday 17 July 2022 12:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nTimeout = 1659178800; // Saturday, 30 July 2022 11:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nOverrideRuleChangeActivationThreshold = 1411; // Approx 70% of 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nOverrideMinerConfirmationWindow = 2016;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x0000000000000000000000000000000000000000000000000000000000100010");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x000000eaab417d6dfe9bd75119972e1d07ecfe8ff655bef7c2acb3d9a0eeed81");


        pchMessageStart[0] = 0x63; // S
        pchMessageStart[1] = 0x56; // A
        pchMessageStart[2] = 0x65; // T
        pchMessageStart[3] = 0x65; // T
        nDefaultPort = 7060;
        nPruneAfterHeight = 1000;

        uint32_t nGenesisTime = 1661734222;

        // This is used inorder to mine the genesis block. Once found, we can use the nonce and block hash found to create a valid genesis block
//        /////////////////////////////////////////////////////////////////


//        arith_uint256 test;
//        bool fNegative;
//        bool fOverflow;
//        test.SetCompact(0x1e00ffff, &fNegative, &fOverflow);
//        std::cout << "Test threshold: " << test.GetHex() << "\n\n";
//
//        int genesisNonce = 0;
//        uint256 TempHashHolding = uint256S("0x0000000000000000000000000000000000000000000000000000000000000000");
//        uint256 BestBlockHash = uint256S("0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
//        for (int i=0;i<40000000;i++) {
//            genesis = CreateGenesisBlock(nGenesisTime, i, 0x1e00ffff, 2, 5000 * COIN);
//            //genesis.hashPrevBlock = TempHashHolding;
//            // Depending on when the timestamp is on the genesis block. You will need to use GetX16RHash or GetX16RV2Hash. Replace GetHash() with these below
//            consensus.hashGenesisBlock = genesis.GetHash();
//
//            arith_uint256 BestBlockHashArith = UintToArith256(BestBlockHash);
//            if (UintToArith256(consensus.hashGenesisBlock) < BestBlockHashArith) {
//                BestBlockHash = consensus.hashGenesisBlock;
//                std::cout << BestBlockHash.GetHex() << " Nonce: " << i << "\n";
//                std::cout << "   PrevBlockHash: " << genesis.hashPrevBlock.GetHex() << "\n";
//            }
//
//            TempHashHolding = consensus.hashGenesisBlock;
//
//            if (BestBlockHashArith < test) {
//                genesisNonce = i - 1;
//                break;
//            }
//            //std::cout << consensus.hashGenesisBlock.GetHex() << "\n";
//        }
//        std::cout << "\n";
//        std::cout << "\n";
//        std::cout << "\n";
//
//        std::cout << "hashGenesisBlock to 0x" << BestBlockHash.GetHex() << std::endl;
//        std::cout << "Genesis Nonce to " << genesisNonce << std::endl;
//        std::cout << "Genesis Merkle " << genesis.hashMerkleRoot.GetHex() << std::endl;
//
//        std::cout << "\n";
//        std::cout << "\n";
//        int totalHits = 0;
//        double totalTime = 0.0;
//
//        for(int x = 0; x < 16; x++) {
//            totalHits += algoHashHits[x];
//            totalTime += algoHashTotal[x];
//            std::cout << "hash algo " << x << " hits " << algoHashHits[x] << " total " << algoHashTotal[x] << " avg " << algoHashTotal[x]/algoHashHits[x] << std::endl;
//        }
//
//        std::cout << "Totals: hash algo " <<  " hits " << totalHits << " total " << totalTime << " avg " << totalTime/totalHits << std::endl;
//
//        genesis.hashPrevBlock = TempHashHolding;
//
//        return;

//        /////////////////////////////////////////////////////////////////

        genesis = CreateGenesisBlock(nGenesisTime, 7680541, 0x1e00ffff, 4, 5000 * COIN);
        consensus.hashGenesisBlock = genesis.GetX16RHash();

        //Test MerkleRoot and GenesisBlock
        assert(consensus.hashGenesisBlock == uint256S("0x000000eaab417d6dfe9bd75119972e1d07ecfe8ff655bef7c2acb3d9a0eeed81"));
        assert(genesis.hashMerkleRoot == uint256S("0xe8916cf6592c8433d598c3a5fe60a9741fd2a997b39d93af2d789cdd9d9a7390"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,63);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,124);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,114);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        // Satoxcoin BIP44 cointype in testnet
        nExtCoinType = 1;

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fMiningRequiresPeers = true;

        checkpointData = (CCheckpointData) {
            {
                    { 0, uint256S("0x000000eaab417d6dfe9bd75119972e1d07ecfe8ff655bef7c2acb3d9a0eeed81")}
            }
        };

        chainTxData = ChainTxData{
            // Update as we know more about the contents of the satoxcoin chain
            1661734222, // * UNIX timestamp of last known number of transactions
            0,     // * total number of transactions between genesis and that timestamp
                        //   (the tx=... number in the SetBestChain debug.log lines)
            0.0        // * estimated number of transactions per second after that timestamp
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

        // 15% of 5000 COIN to Donation
        nCommunityAutonomousAmount = 15;

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

        nMaxReorganizationDepth = 60; // 60 at 1 minute block timespan is +/- 60 minutes.
        nMinReorganizationPeers = 4;
        nMinReorganizationAge = 60 * 60 * 12; // 12 hours

        nAssetActivationHeight = 1; // Asset activated block height
        nMessagingActivationBlock = 1; // Messaging activated block height
        nRestrictedActivationBlock = 1; // Restricted activated block height

        nKAAAWWWPOWActivationTime = 1661833868;
        nKAWPOWActivationTime = nKAAAWWWPOWActivationTime;
        /** SATOXCOIN End **/
    }
};

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        strNetworkID = "regtest";
        consensus.nBIP34Enabled = true;
        consensus.nBIP65Enabled = true; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.nBIP66Enabled = true;
        consensus.nSegwitEnabled = true;
        consensus.nCSVEnabled = true;
        consensus.nSubsidyHalvingInterval = 150;
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.kawpowLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nPowTargetTimespan = 2016 * 60; // 1.4 days
        consensus.nPowTargetSpacing = 1 * 60;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nOverrideRuleChangeActivationThreshold = 108;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nOverrideMinerConfirmationWindow = 144;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit = 6;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nOverrideRuleChangeActivationThreshold = 108;
        consensus.vDeployments[Consensus::DEPLOYMENT_ASSETS].nOverrideMinerConfirmationWindow = 144;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].bit = 7;  // Assets (RIP5)
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nStartTime = 0; // GMT: Sun Mar 3, 2019 5:00:00 PM
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nTimeout = 999999999999ULL; // UTC: Wed Dec 25 2019 07:00:00
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nOverrideRuleChangeActivationThreshold = 108;
        consensus.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].nOverrideMinerConfirmationWindow = 144;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].bit = 8;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nOverrideRuleChangeActivationThreshold = 208;
        consensus.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].nOverrideMinerConfirmationWindow = 288;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].bit = 9;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nOverrideRuleChangeActivationThreshold = 108;
        consensus.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].nOverrideMinerConfirmationWindow = 144;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].bit = 10;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nTimeout = 999999999999ULL;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nOverrideRuleChangeActivationThreshold = 400;
        consensus.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].nOverrideMinerConfirmationWindow = 500;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0x44; // D
        pchMessageStart[1] = 0x52; // R
        pchMessageStart[2] = 0x4F; // O
        pchMessageStart[3] = 0x57; // W
        nDefaultPort = 19444;
        nPruneAfterHeight = 1000;

// This is used inorder to mine the genesis block. Once found, we can use the nonce and block hash found to create a valid genesis block
//        /////////////////////////////////////////////////////////////////
//
//
//        arith_uint256 test;
//        bool fNegative;
//        bool fOverflow;
//        test.SetCompact(0x207fffff, &fNegative, &fOverflow);
//        std::cout << "Test threshold: " << test.GetHex() << "\n\n";
//
//        int genesisNonce = 0;
//        uint256 TempHashHolding = uint256S("0x0000000000000000000000000000000000000000000000000000000000000000");
//        uint256 BestBlockHash = uint256S("0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
//        for (int i=0;i<40000000;i++) {
//            genesis = CreateGenesisBlock(1533751200, i, 0x207fffff, 2, 5000 * COIN);
//            //genesis.hashPrevBlock = TempHashHolding;
//            consensus.hashGenesisBlock = genesis.GetHash();
//
//            arith_uint256 BestBlockHashArith = UintToArith256(BestBlockHash);
//            if (UintToArith256(consensus.hashGenesisBlock) < BestBlockHashArith) {
//                BestBlockHash = consensus.hashGenesisBlock;
//                std::cout << BestBlockHash.GetHex() << " Nonce: " << i << "\n";
//                std::cout << "   PrevBlockHash: " << genesis.hashPrevBlock.GetHex() << "\n";
//            }
//
//            TempHashHolding = consensus.hashGenesisBlock;
//
//            if (BestBlockHashArith < test) {
//                genesisNonce = i - 1;
//                break;
//            }
//            //std::cout << consensus.hashGenesisBlock.GetHex() << "\n";
//        }
//        std::cout << "\n";
//        std::cout << "\n";
//        std::cout << "\n";
//
//        std::cout << "hashGenesisBlock to 0x" << BestBlockHash.GetHex() << std::endl;
//        std::cout << "Genesis Nonce to " << genesisNonce << std::endl;
//        std::cout << "Genesis Merkle " << genesis.hashMerkleRoot.GetHex() << std::endl;
//
//        std::cout << "\n";
//        std::cout << "\n";
//        int totalHits = 0;
//        double totalTime = 0.0;
//
//        for(int x = 0; x < 16; x++) {
//            totalHits += algoHashHits[x];
//            totalTime += algoHashTotal[x];
//            std::cout << "hash algo " << x << " hits " << algoHashHits[x] << " total " << algoHashTotal[x] << " avg " << algoHashTotal[x]/algoHashHits[x] << std::endl;
//        }
//
//        std::cout << "Totals: hash algo " <<  " hits " << totalHits << " total " << totalTime << " avg " << totalTime/totalHits << std::endl;
//
//        genesis.hashPrevBlock = TempHashHolding;
//
//        return;

//        /////////////////////////////////////////////////////////////////


        genesis = CreateGenesisBlock(1661734578, 1, 0x207fffff, 4, 5000 * COIN);
        consensus.hashGenesisBlock = genesis.GetX16RHash();

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;

        checkpointData = (CCheckpointData) {
            {
            }
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,42);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,124);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,114);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x35, 0x87, 0xCF};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x35, 0x83, 0x94};

        // Satoxcoin BIP44 cointype in regtest
        nExtCoinType = 1;

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
        nDGWActivationBlock = 200;

        nMaxReorganizationDepth = 60; // 60 at 1 minute block timespan is +/- 60 minutes.
        nMinReorganizationPeers = 4;
        nMinReorganizationAge = 60 * 60 * 12; // 12 hours

        nAssetActivationHeight = 0; // Asset activated block height
        nMessagingActivationBlock = 0; // Messaging activated block height
        nRestrictedActivationBlock = 0; // Restricted activated block height

        // TODO, we need to figure out what to do with this for regtest. This effects the unit tests
        // For now we can use a timestamp very far away
        // If you are looking to test the kawpow hashing function in regtest. You will need to change this number
        nKAAAWWWPOWActivationTime = 3582830167;
        nKAWPOWActivationTime = nKAAAWWWPOWActivationTime;
        /** SATOXCOIN End **/
    }
};

static std::unique_ptr<CChainParams> globalChainParams;

const CChainParams &GetParams() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<CChainParams> CreateChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams());
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network, bool fForceBlockNetwork)
{
    SelectBaseParams(network);
    if (fForceBlockNetwork) {
        bNetwork.SetNetwork(network);
    }
    globalChainParams = CreateChainParams(network);
}

void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
{
    globalChainParams->UpdateVersionBitsParameters(d, nStartTime, nTimeout);
}

void TurnOffSegwit(){
	globalChainParams->TurnOffSegwit();
}

void TurnOffCSV() {
	globalChainParams->TurnOffCSV();
}

void TurnOffBIP34() {
	globalChainParams->TurnOffBIP34();
}

void TurnOffBIP65() {
	globalChainParams->TurnOffBIP65();
}

void TurnOffBIP66() {
	globalChainParams->TurnOffBIP66();
}
