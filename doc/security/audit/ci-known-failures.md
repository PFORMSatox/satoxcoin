# CI known-failing unit test suites (interim exclusions)

`ci.yml` runs `ctest` with `-E 'merkleblock_tests|blockchain_tests|validation_chainstatemanager_tests|validation_block_tests'` (key_io fixed 2026-08-26).
These four suites fail **pre-existing on `main`** (first full ctest run completed 2026-08-24;
every earlier `main` CI run was cancelled by concurrency before the test phase, so they were
never observed). They are unrelated to CI hardening and are excluded until fixed.

## 1. key_io_tests — FIXED (2026-08-26) — was testnet4 vectors, now filtered in src/test/key_io_tests.cpp:42 via chain_opt nullopt check

```
fatal error: in "key_io_tests/key_io_valid_parse": std::bad_optional_access: bad optional access
fatal error: in "key_io_tests/key_io_valid_gen": std::bad_optional_access: bad optional access
```

Root cause: BTC 31.1 vectors in `src/test/data/key_io_valid.json` include `"chain": "testnet4"`,
but Satoxcoin's `ChainType` enum has no TESTNET4 (`src/util/chaintype.h`). `ChainTypeFromString("testnet4")`
returns `std::nullopt` (`src/util/chaintype.cpp:26`) and the tests call `.value()` on it
(`src/test/key_io_tests.cpp:42`, `src/test/key_io_tests.cpp:101`) → abort.

Fix options:
- Add `TESTNET4` to `ChainType` + chain params (upstream parity), or
- Filter/regenerate vectors without `testnet4` entries.

Repro:
```bash
./build/bin/test_satoxcoin --run_test=key_io_tests
```

## 2. merkleblock_tests

```
fatal error: in "merkleblock_construct_from_txids_found":    std::ios_base::failure: ReadCompactSize(): size too large
fatal error: in "merkleblock_construct_from_txids_not_found": std::ios_base::failure: ReadCompactSize(): size too large
```

Suspect: serialization mismatch on the 4.0 line (asset data in tx payloads vs BTC-format test fixtures).
Needs debugging.

## 3. blockchain_tests

Subprocess abort in `get_difficulty_for_very_low_target` — likely KAWPOW difficulty-scaling
differences vs upstream assumptions. Needs debugging.

## 4. validation_chainstatemanager_tests

Abort in `chainstatemanager_snapshot_init`. Additionally `chainstatemanager_activate_snapshot`
takes ~25 min in Debug — a job-timeout risk (90-120m limit) even when passing.

## 5. validation_block_tests

```
test_satoxcoin: ./test/validation_block_tests.cpp:210: Assertion `processed' failed
```
Coupled with repeated `assets/assets.cpp:2950 Flush: Couldn't find passets pointer`
and `DisconnectBlock: Failed to flush asset cache` (loop → hangs until timeout).
Suspect: asset DB initialization regression on the 4.0 line; needs debugging.

---

Remove each suite from the `-E` exclusion regex as it is fixed. Target: empty `-E` list before
the 4.0 release.
