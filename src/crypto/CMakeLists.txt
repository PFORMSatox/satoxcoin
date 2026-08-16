# Copyright (c) 2023-present The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or https://opensource.org/license/mit/.

add_library(satoxcoin_crypto STATIC EXCLUDE_FROM_ALL
  aes.cpp
  chacha20.cpp
  chacha20poly1305.cpp
  hex_base.cpp
  hkdf_sha256_32.cpp
  hmac_sha256.cpp
  hmac_sha512.cpp
  muhash.cpp
  poly1305.cpp
  ripemd160.cpp
  sha1.cpp
  sha256.cpp
  sha256_sse4.cpp
  sha3.cpp
  sha512.cpp
  siphash.cpp
  ../support/cleanse.cpp
)

target_link_libraries(satoxcoin_crypto
  PRIVATE
    core_interface
)

# ethash (ProgPoW/KAWPOW) library — vendored from Ravencoin, upstream copyright
# (c) 2018-2019 Pawel Bylica. Source files are left unmodified.
add_library(satoxcoin_ethash STATIC EXCLUDE_FROM_ALL
  ethash/lib/ethash/ethash.cpp
  ethash/lib/ethash/managed.cpp
  ethash/lib/ethash/progpow.cpp
  ethash/lib/ethash/primes.c
  ethash/lib/keccak/keccak.c
  ethash/lib/keccak/keccakf1600.c
  ethash/lib/keccak/keccakf800.c
)
target_include_directories(satoxcoin_ethash
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/ethash/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ethash/lib/ethash
    ${CMAKE_CURRENT_SOURCE_DIR}/ethash/lib/support
)
target_compile_features(satoxcoin_ethash PRIVATE c_std_99)
target_link_libraries(satoxcoin_ethash PRIVATE core_interface)

# x16r/x16rv2 algo library — vendored from Ravencoin (sphlib, Projet RNRT SAPHIR).
# Source files are left unmodified.
add_library(satoxcoin_algo STATIC EXCLUDE_FROM_ALL
  ../algo/groestl.c
  ../algo/blake.c
  ../algo/bmw.c
  ../algo/cubehash.c
  ../algo/echo.c
  ../algo/jh.c
  ../algo/keccak.c
  ../algo/luffa.c
  ../algo/shavite.c
  ../algo/simd.c
  ../algo/skein.c
  ../algo/hamsi.c
  ../algo/whirlpool.c
  ../algo/shabal.c
  ../algo/fugue.c
  ../algo/sha2.c
  ../algo/extra.c
  ../algo/sph_sha2big.c
  ../algo/haval.c
  ../algo/sph_sha2.c
  ../algo/gost_streebog.c
  ../algo/tiger.cpp
  ../algo/lyra2.cpp
  ../algo/sponge.cpp
)
target_include_directories(satoxcoin_algo
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../algo
)
target_compile_features(satoxcoin_algo PRIVATE c_std_99)


if(HAVE_SSE41)
  target_compile_definitions(satoxcoin_crypto PRIVATE ENABLE_SSE41)
  target_sources(satoxcoin_crypto PRIVATE sha256_sse41.cpp)
  set_property(SOURCE sha256_sse41.cpp PROPERTY
    COMPILE_OPTIONS ${SSE41_CXXFLAGS}
  )
endif()

if(HAVE_AVX2)
  target_compile_definitions(satoxcoin_crypto PRIVATE ENABLE_AVX2)
  target_sources(satoxcoin_crypto PRIVATE sha256_avx2.cpp)
  set_property(SOURCE sha256_avx2.cpp PROPERTY
    COMPILE_OPTIONS ${AVX2_CXXFLAGS}
  )
endif()

if(HAVE_SSE41 AND HAVE_X86_SHANI)
  target_compile_definitions(satoxcoin_crypto PRIVATE ENABLE_SSE41 ENABLE_X86_SHANI)
  target_sources(satoxcoin_crypto PRIVATE sha256_x86_shani.cpp)
  set_property(SOURCE sha256_x86_shani.cpp PROPERTY
    COMPILE_OPTIONS ${SSE41_CXXFLAGS} ${X86_SHANI_CXXFLAGS}
  )
endif()

if(HAVE_ARM_SHANI)
  target_compile_definitions(satoxcoin_crypto PRIVATE ENABLE_ARM_SHANI)
  target_sources(satoxcoin_crypto PRIVATE sha256_arm_shani.cpp)
  set_property(SOURCE sha256_arm_shani.cpp PROPERTY
    COMPILE_OPTIONS ${ARM_SHANI_CXXFLAGS}
  )
endif()
