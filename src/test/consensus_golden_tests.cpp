// Copyright (c) 2026 The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
//
// Golden consensus test. Asserts the consensus-critical parameters captured in
// the frozen mainnet consensus rules. If this test fails, the codebase no
// longer matches the frozen mainnet consensus rules -> do NOT ship.

#include <chainparams.h>
#include <consensus/amount.h>
#include <consensus/params.h>
#include <primitives/block.h>
#include <util/chaintype.h>
#include <validation.h>

#include <test/util/setup_common.h>

#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(consensus_golden_tests, BasicTestingSetup)

BOOST_AUTO_TEST_CASE(mainnet_basic_params)
{
    const auto p = CreateChainParams(*m_node.args, ChainType::MAIN);
    const Consensus::Params& c = p->GetConsensus();

    // Section 1.1
    BOOST_CHECK_EQUAL(c.nSubsidyHalvingInterval, 2100000);
    BOOST_CHECK(c.nBIP34Enabled);
    BOOST_CHECK(c.nBIP65Enabled);
    BOOST_CHECK(c.nBIP66Enabled);
    BOOST_CHECK(c.nCSVEnabled);
    BOOST_CHECK_EQUAL(c.BIP34LockedIn, 6048);

    // Section 1.2
    BOOST_CHECK_EQUAL(c.powLimit.GetHex(), "00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
    BOOST_CHECK_EQUAL(c.kawpowLimit.GetHex(), "00ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
    BOOST_CHECK_EQUAL(c.nPowTargetTimespan, 120960);
    BOOST_CHECK_EQUAL(c.nPowTargetSpacing, 60);
    BOOST_CHECK(!c.fPowAllowMinDifficultyBlocks);
    BOOST_CHECK(!c.fPowNoRetargeting);
    BOOST_CHECK_EQUAL(c.nRuleChangeActivationThreshold, 1613);
    BOOST_CHECK_EQUAL(c.nMinerConfirmationWindow, 2016);

    // Section 1.3
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_ASSETS].bit, 6);
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].bit, 7);
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_TRANSFER_SCRIPT_SIZE].bit, 8);
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].bit, 9);
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_COINBASE_ASSETS].bit, 10);
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].bit, 11);
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_TRANSFER_OVERFLOW].threshold, 1411);
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_ASSETS].threshold, 1814);
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_MSG_REST_ASSETS].threshold, 1714);
    BOOST_CHECK_EQUAL(c.vDeployments[Consensus::DEPLOYMENT_ENFORCE_VALUE].threshold, 1411);

    // Section 1.4
    BOOST_CHECK_EQUAL(c.nMinimumChainWork.GetHex(), "0000000000000000000000000000000000000000000000000000005a0da9fea5");
    BOOST_CHECK_EQUAL(c.defaultAssumeValid.GetHex(), "0000000002d6de2050f0ff663c31d49d3f50bdb5c6a842a56bfd8309c65fa028");

    // Section 1.5
    BOOST_CHECK_EQUAL(p->GetDefaultPort(), 60777);
    BOOST_CHECK_EQUAL(p->PruneAfterHeight(), 100000);

    // Section 1.6
    BOOST_CHECK_EQUAL(p->GenesisBlock().GetHash().GetHex(), "000000edd819220359469c54f2614b5602ebc775ea67a64602f354bdaa320f70");
    BOOST_CHECK_EQUAL(c.hashGenesisBlock.GetHex(), "000000edd819220359469c54f2614b5602ebc775ea67a64602f354bdaa320f70");
    BOOST_CHECK_EQUAL(p->GenesisBlock().hashMerkleRoot.GetHex(), "e8916cf6592c8433d598c3a5fe60a9741fd2a997b39d93af2d789cdd9d9a7390");

    // Section 1.7
    BOOST_CHECK_EQUAL(p->Base58Prefix(CChainParams::PUBKEY_ADDRESS)[0], 63);
    BOOST_CHECK_EQUAL(p->Base58Prefix(CChainParams::SCRIPT_ADDRESS)[0], 122);
    BOOST_CHECK_EQUAL(p->Base58Prefix(CChainParams::SECRET_KEY)[0], 112);

    // Section 1.8 (checkpoints were removed in the Bitcoin Core 31.1 base)
    // Section 1.13
    BOOST_CHECK_EQUAL((uint64_t)nKAWPOWActivationTime, 1662493424ULL);
}

BOOST_AUTO_TEST_CASE(mainnet_block_subsidy)
{
    const auto p = CreateChainParams(*m_node.args, ChainType::MAIN);

    // Section 1.9
    BOOST_CHECK_EQUAL(GetBlockSubsidy(0, p->GetConsensus()), 430000000 * COIN);
    BOOST_CHECK_EQUAL(GetBlockSubsidy(10, p->GetConsensus()), 430000000 * COIN);
    BOOST_CHECK_EQUAL(GetBlockSubsidy(11, p->GetConsensus()), 300 * COIN);
    BOOST_CHECK_EQUAL(GetBlockSubsidy(1000, p->GetConsensus()), 300 * COIN);
    BOOST_CHECK_EQUAL(GetBlockSubsidy(2100000, p->GetConsensus()), 150 * COIN);
    BOOST_CHECK_EQUAL(GetBlockSubsidy(2100001, p->GetConsensus()), 150 * COIN);
    // halvings >= 64 => 0
    BOOST_CHECK_EQUAL(GetBlockSubsidy(2100000 * 64, p->GetConsensus()), 0);
}

BOOST_AUTO_TEST_SUITE_END()
