// Copyright (c) 2013-present The Bitcoin Core developers
// Copyright (c) 2017-2020 The Raven Core developers
// Copyright (c) 2022-2026 The Satoxcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <hash.h>
#include <span.h>
#include <crypto/common.h>
#include <crypto/hmac_sha512.h>

#include <primitives/block.h>
#include <crypto/ethash/helpers.hpp>
#include <crypto/ethash/include/ethash/progpow.hpp>
#include <util/strencodings.h>

#include <bit>
#include <string>

unsigned int MurmurHash3(unsigned int nHashSeed, std::span<const unsigned char> vDataToHash)
{
    // The following is MurmurHash3 (x86_32), see https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp
    uint32_t h1 = nHashSeed;
    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    const int nblocks = vDataToHash.size() / 4;

    //----------
    // body
    const uint8_t* blocks = vDataToHash.data();

    for (int i = 0; i < nblocks; ++i) {
        uint32_t k1 = ReadLE32(blocks + i*4);

        k1 *= c1;
        k1 = std::rotl(k1, 15);
        k1 *= c2;

        h1 ^= k1;
        h1 = std::rotl(h1, 13);
        h1 = h1 * 5 + 0xe6546b64;
    }

    //----------
    // tail
    const uint8_t* tail = vDataToHash.data() + nblocks * 4;

    uint32_t k1 = 0;

    switch (vDataToHash.size() & 3) {
        case 3:
            k1 ^= tail[2] << 16;
            [[fallthrough]];
        case 2:
            k1 ^= tail[1] << 8;
            [[fallthrough]];
        case 1:
            k1 ^= tail[0];
            k1 *= c1;
            k1 = std::rotl(k1, 15);
            k1 *= c2;
            h1 ^= k1;
    }

    //----------
    // finalization
    h1 ^= vDataToHash.size();
    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;

    return h1;
}

void BIP32Hash(const ChainCode &chainCode, unsigned int nChild, unsigned char header, const unsigned char data[32], unsigned char output[64])
{
    unsigned char num[4];
    WriteBE32(num, nChild);
    CHMAC_SHA512(chainCode.begin(), chainCode.size()).Write(&header, 1).Write(data, 32).Write(num, 4).Finalize(output);
}

uint256 SHA256Uint256(const uint256& input)
{
    uint256 result;
    CSHA256().Write(input.begin(), 32).Finalize(result.begin());
    return result;
}

HashWriter TaggedHash(const std::string& tag)
{
    HashWriter writer{};
    uint256 taghash;
    CSHA256().Write((const unsigned char*)tag.data(), tag.size()).Finalize(taghash.begin());
    writer << taghash << taghash;
    return writer;
}

uint256 KAWPOWHash(const CBlockHeader& blockHeader, uint256& mix_hash)
{
    // Get the context from the block height
    const auto epoch_number = ethash::get_epoch_number(blockHeader.nHeight);

    // Use the thread-safe global epoch context (shared context built under a
    // mutex, cached thread-locally in ethash/lib/ethash/managed.cpp) instead
    // of a shared static unique_ptr. The old code raced across the msghand /
    // import / RPC / miner threads: concurrent reassignment could free the
    // context while another thread dereferences it (use-after-free), and epoch
    // switches caused re-allocation races. This API is safe for concurrent use.
    const ethash::epoch_context& context = ethash::get_global_epoch_context(epoch_number);

    // Build the header_hash
    uint256 nHeaderHash = blockHeader.GetKAWPOWHeaderHash();
    const auto header_hash = to_hash256(nHeaderHash.GetHex());

    // ProgPow hash
    const auto result = progpow::hash(context, blockHeader.nHeight, header_hash, blockHeader.nNonce64);

    mix_hash = uint256S(to_hex(result.mix_hash));
    return uint256S(to_hex(result.final_hash));
}


uint256 KAWPOWHash_OnlyMix(const CBlockHeader& blockHeader)
{
    // Build the header_hash
    uint256 nHeaderHash = blockHeader.GetKAWPOWHeaderHash();
    const auto header_hash = to_hash256(nHeaderHash.GetHex());

    // ProgPow hash
    const auto result = progpow::hash_no_verify(blockHeader.nHeight, header_hash, to_hash256(blockHeader.mix_hash.GetHex()), blockHeader.nNonce64);

    return uint256S(to_hex(result));
}
