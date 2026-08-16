// Copyright (c) The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/test/unit_test.hpp>

#include <chain.h>
#include <streams.h>
#include <test/util/setup_common.h>

#include <memory>

BOOST_FIXTURE_TEST_SUITE(chain_tests, BasicTestingSetup)

namespace {

const CBlockIndex* NaiveGetAncestor(const CBlockIndex* a, int height)
{
    while (a->nHeight > height) {
        a = a->pprev;
    }
    BOOST_REQUIRE_EQUAL(a->nHeight, height);
    return a;
}

const CBlockIndex* NaiveLastCommonAncestor(const CBlockIndex* a, const CBlockIndex* b)
{
    while (a->nHeight > b->nHeight) {
        a = a->pprev;
    }
    while (b->nHeight > a->nHeight) {
        b = b->pprev;
    }
    while (a != b) {
        BOOST_REQUIRE_EQUAL(a->nHeight, b->nHeight);
        a = a->pprev;
        b = b->pprev;
    }
    BOOST_REQUIRE_EQUAL(a, b);
    return a;
}

} // namespace

BOOST_AUTO_TEST_CASE(chain_test)
{
    FastRandomContext ctx;
    std::vector<std::unique_ptr<CBlockIndex>> block_index;
    // Run 10 iterations of the whole test.
    for (int i = 0; i < 10; ++i) {
        block_index.clear();
        // Create genesis block.
        auto genesis = std::make_unique<CBlockIndex>();
        genesis->nHeight = 0;
        block_index.push_back(std::move(genesis));
        // Create 10000 more blocks.
        for (int b = 0; b < 10000; ++b) {
            auto new_index = std::make_unique<CBlockIndex>();
            // 95% of blocks build on top of the last block; the others fork off randomly.
            if (ctx.randrange(20) != 0) {
                new_index->pprev = block_index.back().get();
            } else {
                new_index->pprev = block_index[ctx.randrange(block_index.size())].get();
            }
            new_index->nHeight = new_index->pprev->nHeight + 1;
            new_index->BuildSkip();
            block_index.push_back(std::move(new_index));
        }
        // Run 10000 random GetAncestor queries.
        for (int q = 0; q < 10000; ++q) {
            const CBlockIndex* block = block_index[ctx.randrange(block_index.size())].get();
            unsigned height = ctx.randrange<unsigned>(block->nHeight + 1);
            const CBlockIndex* result = block->GetAncestor(height);
            BOOST_CHECK(result == NaiveGetAncestor(block, height));
        }
        // Run 10000 random LastCommonAncestor queries.
        for (int q = 0; q < 10000; ++q) {
            const CBlockIndex* block1 = block_index[ctx.randrange(block_index.size())].get();
            const CBlockIndex* block2 = block_index[ctx.randrange(block_index.size())].get();
            const CBlockIndex* result = LastCommonAncestor(block1, block2);
            BOOST_CHECK(result == NaiveLastCommonAncestor(block1, block2));
        }
    }
}

BOOST_AUTO_TEST_CASE(disk_block_index_kawpow_roundtrip)
{
    // CDiskBlockIndex must persist the KAWPOW header fields (nHeight is the
    // existing chain-height member; nNonce64 and mix_hash are new) so that
    // LoadBlockIndexGuts can reconstruct the exact block hash for the
    // CheckProofOfWork gate on reload. Regression test for the index-load PoW
    // gap (synced KAWPOW blocks failed reload with CheckProofOfWork failed).
    // nHeight=0 keeps the KAWPOW epoch-0 cache tiny so the hash is cheap.
    CBlockHeader header;
    header.SetNull();
    header.nVersion = 0x30000000;
    header.hashPrevBlock = uint256S("ab" + std::string(62, '0'));
    header.hashMerkleRoot = uint256S("cd" + std::string(62, '0'));
    header.nTime = nKAWPOWActivationTime + 1;
    header.nBits = 0x1d00ffff;
    header.nHeight = 0;
    header.nNonce64 = 0xdeadbeefcafebabeULL;
    header.mix_hash = uint256S("ef" + std::string(62, '0'));

    CBlockIndex index(header);
    BOOST_CHECK_EQUAL(index.nHeight, 0);
    BOOST_CHECK_EQUAL(index.nNonce64, 0xdeadbeefcafebabeULL);
    BOOST_CHECK_EQUAL(index.mix_hash.GetHex(), header.mix_hash.GetHex());

    // Round-trip through a DataStream like the block index DB write path.
    CDiskBlockIndex disk(&index);
    DataStream ss{};
    ss << disk;
    CDiskBlockIndex disk_loaded;
    ss >> disk_loaded;

    BOOST_CHECK_EQUAL(disk_loaded.nHeight, 0);
    BOOST_CHECK_EQUAL(disk_loaded.nNonce64, 0xdeadbeefcafebabeULL);
    BOOST_CHECK_EQUAL(disk_loaded.mix_hash.GetHex(), header.mix_hash.GetHex());

    // Round-trip the reconstructed header once more to confirm stability.
    CDiskBlockIndex disk2(&disk_loaded);
    DataStream ss2{};
    ss2 << disk2;
    CDiskBlockIndex disk2_loaded;
    ss2 >> disk2_loaded;
    BOOST_CHECK_EQUAL(disk2_loaded.nNonce64, 0xdeadbeefcafebabeULL);
    BOOST_CHECK_EQUAL(disk2_loaded.mix_hash.GetHex(), header.mix_hash.GetHex());
}

BOOST_AUTO_TEST_SUITE_END()
