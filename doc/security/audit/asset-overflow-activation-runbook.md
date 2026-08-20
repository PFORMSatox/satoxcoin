# Asset Overflow Soft-Fork — Implementation & Activation Runbook

**Branch:** `consensus/asset-overflow` (4.0 / Bitcoin Core v31.1 line)
**Status:** **FROZEN** — implemented, tested, **NOT activated**. Gated by the
sequencing policy in
[`phase5-btc31-rebase-plan.md`](phase5-btc31-rebase-plan.md): no asset-consensus
push (activation) until the 4.0 rebase is complete, verified, and running stable.

Pre-activation this code is **log-only** (`Input Overflow Check-*`) and makes
exactly the same accept/reject decision as legacy nodes — zero reorg risk, safe
to ship in 4.0 releases and run on exchanges/pools ahead of activation.

---

## 1. The vulnerability

`Consensus::CheckTxAssets` accumulates per-asset input and output amounts in
`int64_t` maps (`totalInputs`, `totalOutputs`). Two asset outputs (or inputs) of
the same asset whose summed amounts exceed `int64` max wrap the accumulator,
letting an attacker pass the input/output balance comparison. This is
Ravencoin issue #1287. The wallet/RPC paths bound amounts to `MAX_MONEY`, so the
wrap is only reachable via crafted raw transactions.

## 2. Implementation overview

Deployment parameters (mainnet, in `src/kernel/chainparams.cpp`):

| Param           | Value                                      |
|-----------------|--------------------------------------------|
| bit             | 11                                         |
| start           | `1789862400` (Sun 2026-09-20 00:00:00 UTC) |
| timeout         | `1821398400` (Mon 2027-09-20 00:00:00 UTC) |
| threshold       | 1411 (≈70% of 2016)                        |
| period          | 2016                                       |

Regtest uses `start=0`, `NO_TIMEOUT`, threshold 400 / period 500.

### Consensus fix (`src/consensus/tx_verify.cpp`)
- `CheckTxAssets` gained a trailing `fTransferOverflowDeployed` parameter.
- In both accumulation loops (inputs and outputs) the code now, per asset:
  - rejects `data.nAmount < 0` (post-activation: `bad-txns-input-asset-amount-negative`
    / `bad-txns-transfer-asset-amount-negative`);
  - rejects the wrap `nPrev > max - nAmount` (post-activation:
    `bad-txns-input-asset-amount-toolarge` / `bad-txns-transfer-asset-amount-toolarge`);
  - **pre-activation** logs `Input Overflow Check: ...` via `LogInfo` and
    continues with the legacy wrapping accumulation so the accept/reject
    decision is byte-for-byte identical to legacy nodes.
- The wrapping accumulation uses a small `WrappedAdd` helper (unsigned
  two's-complement add, cast back to `CAmount`). This is **required**: debug
  builds use `-ftrapv`, and relying on signed-overflow UB would abort the node
  (`__addvdi3`) the moment the wrap is reached pre-activation.

### Deployment gate (`src/assets/assets.{h,cpp}`)
- `IsTransferOverflowCheckDeployed(const CBlockIndex*, const ChainstateManager&)`
  returns `DeploymentActiveAfter(pindexPrev, chainman, DEPLOYMENT_TRANSFER_OVERFLOW)`.

### Validation threading (`src/validation.cpp`)
- Mempool accept: evaluated against the active chain tip.
- Block connect: evaluated against `pindex->pprev` (the block's parent), so the
  gate follows activation height exactly.

### RPC reporting (`src/rpc/blockchain.cpp`)
- `getblockchaininfo` reports `softforks` again (was dropped in the v31 rebase),
  and `DeploymentInfo()` lists the satoxcoin deployments (ASSETS, MSG_REST_ASSETS,
  TRANSFER_SCRIPT_SIZE, ENFORCE_VALUE, COINBASE_ASSETS, TRANSFER_OVERFLOW) so the
  state of every satoxcoin BIP9 soft-fork is observable.

### Functional test (`test/functional/feature_asset_overflow.py`)
- Issues a `units=8` asset, then crafts a raw transaction spending one BTC input
  into two `INT64_MAX` transfer outputs.
- Pre-activation: expects the legacy reject (`bad-tx-inputs-outputs-mismatch`)
  while asserting the `Input Overflow Check: output asset amount overflow` log.
- Activation: mines to regtest height 1500. The node's own miner signals every
  **started** BIP9 deployment, so bit 11 is signalled automatically from height
  500 and `transfer_overflow` activates at height 1500 (`since=1500`) — no
  crafted/P2P blocks needed.
- Post-activation: expects `bad-txns-transfer-asset-amount-toolarge`, then
  verifies normal transfers still work (regression).

### Supporting fix (`src/wallet/asset_tx.cpp`)
- Lock-order inversion fixed (`LOCK2(wallet.cs_wallet, cs_main)` in the three
  asset transaction builders) — without it the daemon deadlocked (assert) on
  asset RPCs. Required for `feature_assets.py` / `feature_asset_overflow.py`.

## 3. Implementation workflow (how to port/reproduce)

1. On the 4.0 branch, ensure the satoxcoin deployments exist in
   `Consensus::DeploymentPos` and regtest/mainnet params (bit 11, threshold,
   period) before wiring anything.
2. Add `IsTransferOverflowCheckDeployed` and thread the deployment state into
   `CheckTxAssets` from the **mempool** (active tip) and **block connect**
   (parent block) paths.
3. Implement the per-asset negative/overflow guards; keep the legacy wrapping
   accumulation pre-activation but make the wrap **defined** (`WrappedAdd`) —
   verify against `-ftrapv` debug builds.
4. Restore `softforks` in `getblockchaininfo` and add the satoxcoin deployments
   to `DeploymentInfo()` so activation state is observable.
5. Add/verify the functional test and the golden asserts (bit 11, threshold 1411).
6. Commit on `consensus/asset-overflow`; do **not** activate.

## 4. Verification workflow

```bash
cmake --build build -j4                                  # 4.0 CMake build

# Functional tests (kawpow node; the miner signals started BIP9 bits):
cd test/functional
python3 feature_asset_overflow.py                        # M4 gate
python3 feature_assets.py                                # asset regression
python3 feature_raw_restricted_assets.py
python3 feature_assets_mempool.py
python3 rpc_assettransfer.py

# Unit suites:
build/bin/test_satoxcoin --run_test=consensus_golden_tests
build/bin/test_satoxcoin --run_test=kawpow_tests
build/bin/test_satoxcoin --run_test=script_assets_tests
build/bin/test_satoxcoin --run_test=transaction_tests
```

> Note: the full unit suite currently reports pre-existing failures
> (`ArgsManager::AddArg` duplicate-registration assert in
> `walletload_tests/wallet_load_descriptors`) unrelated to this soft-fork; run
> the targeted suites above.

## 5. Activation workflow (only after the sequencing policy allows)

Preconditions — **all** must hold (see `phase5-btc31-rebase-plan.md`):
- [ ] 4.0 released and running stable on mainnet (M6 golden + sync parity green).
- [ ] Feature set diffed against latest `ravencoin develop`; gaps fixed — even
      problems ravencoin has not solved.
- [ ] Soft-fork window still open (`getblockchaininfo` start < now < timeout).
- [ ] This branch/tag is the activation source; no consensus divergence.

Signalling order — pools **first** (only pools can trigger activation):

1. **Mining pools** — signal BIP9 bit 11 (≥1411 of 2016 blocks ≈70%).
2. **Exchanges** — run this (or later 4.0) build; coordinate deposit/withdraw
   readiness.
3. **Explorers** — confirm the `softforks.transfer_overflow` state transitions.
4. **Nodes / wallets** — upgrade paths in place; the soft-fork is backwards
   compatible (rejects only the previously-exploitable crafted txs).
5. **Solo miners** — signal once pools have triggered.

BIP9 mechanics: a full signalled period puts the deployment into `locked_in`,
the following period into `active`, then enforcement begins.

Verify status:

```bash
# Pre-activation safety check — must show log-only behavior:
satoxcoin-cli getblockchaininfo | jq '.softforks.transfer_overflow'
satoxcoin-cli getdeploymentinfo | jq '.deployments.transfer_overflow'

# During signalling (pool side): status should read started -> locked_in:
satoxcoin-cli getdeploymentinfo | jq '.deployments.transfer_overflow.bip9'

# Post-activation: active=true, and crafted overflow txs reject with
# bad-txns-transfer-asset-amount-toolarge.
```

Post-activation verification:
- [ ] `softforks.transfer_overflow.active == true`
- [ ] Overflowing raw transfers rejected with `bad-txns-transfer-asset-amount-toolarge`
- [ ] Normal asset transfers/issue/reissue still accepted (mempool + block paths)
- [ ] Chain continues with no reorg; all nodes upgraded remain on the best chain

## 6. Reject codes (once active)

| Code | Meaning |
|------|---------|
| `bad-txns-input-asset-amount-negative` | negative asset input amount |
| `bad-txns-input-asset-amount-toolarge` | input accumulation wraps int64 |
| `bad-txns-transfer-asset-amount-negative` | negative transfer output amount |
| `bad-txns-transfer-asset-amount-toolarge` | output accumulation wraps int64 |

## 7. Links

- Satoxcoin homepage: https://www.satoverse.io
- Docs: https://docs.satoverse.io
- Explorer: https://xplore.satoverse.io
- Source: https://github.com/satoverse/satoxcoin