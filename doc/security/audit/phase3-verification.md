# Phase 3 — Consensus Verification Log

Live verification results for the rebase-ph3 branch (Ravencoin 4.6.1 base).

## Asset consensus: byte-identical to Ravencoin 4.6.1 (2026-08-13)

The old fork dev renamed C identifiers but kept the consensus byte values:

| satoxcoin | raven | byte | ASCII |
|---|---|---|---|
| OP_SATOX_ASSET | OP_RVN_ASSET | 0xc0 | opcode |
| SATOX_N | RVN_R | 114 | 'r' |
| SATOX_E | RVN_V | 118 | 'v' |
| SATOX_X | RVN_N | 110 | 'n' |
| SATOX_Q | RVN_Q | 113 | 'q' |
| SATOX_T | RVN_T | 116 | 't' |
| SATOX_O | RVN_O | 111 | 'o' |

Asset script marker spells "RVN" in both. **No asset/messaging/restricted
consensus port required** — only mechanical rename (M2).

## Mainnet genesis verified (2026-08-13)

`ravend` (rebase-ph3) boots mainnet:
- bestblockhash `000000edd819220359469c54f2614b5602ebc775ea67a64602f354bdaa320f70`
- difficulty_algorithm `BTC`, DGW_activation_height `1`, mediantime `1661730843`

Matches golden-consensus-manifest.md exactly.

## Test suite results on rebase-ph3 (2026-08-13)
- consensus_golden_tests: PASS
- pow_tests, kawpow_tests, bip39_tests: PASS
- asset_tests, asset_reissue_tests: PASS
- Full combined run: crashes at boost recursive_mutex teardown - the SAME
  known pre-existing test-harness issue (Boost + modern glibc) documented in
  phase1-backports.md; not a rebase regression. Individual suites pass.

## Mainnet sync parity (2026-08-13) - PASS at early checkpoints
Rebased satoxcoind (v3.0.0.0) connected to live mainnet and synced. Block
hashes at checkpoints 100/500/1500/5000 EXACTLY match the golden manifest:
- h100  0000001b0371bf5570c68dda2b73cdcb1909c3357875f0b7cc85b08395853cf7
- h500  00000022fa6cc7fbe32a126e75f73e0fa3ae7069e8f4cf6ac57f96a7416a5aca
- h1500 0000000509bd097b77ce6b91fd5a395904a8ec006b984413b50bdb9464276cb6
- h5000 0000000036b67ab707e7dbcd6047a0ba07724db8640e2100c0c4bb96351b5aa3

The node validates the real live chain correctly -> consensus-identical.
