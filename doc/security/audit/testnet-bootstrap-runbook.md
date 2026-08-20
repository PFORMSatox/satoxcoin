# Public Testnet Bootstrap Runbook

This runbook explains how to launch the first public Satoxcoin testnet on the
4.0 (Bitcoin v31) codebase.

> Status: operational draft. There is no public Satoxcoin testnet yet — this
> would be the first one.

## Why this is needed

Satoxcoin has no public testnet. Mainnet and regtest both work on the 4.0
line, but testnet v3 exists only in the code: it has no seeds and no mined
chain. A public testnet is also a prerequisite for signalling and activating
the asset-overflow soft-fork in production, as described in
`asset-overflow-activation-runbook.md`.

## Which chain to use

Use **testnet v3** (`-testnet`).

- Testnet v3 is fully kawpow-enabled: it defines `consensus.kawpowLimit` and
  `nKAWPOWActivationTime`, pays the 15% community fund, and includes the full
  asset deployment set. The asset deployments (assets, restricted assets,
  enforce-value, coinbase-assets — bits 6-10) have start times in the past, so
  they activate automatically as the bootstrap miner signals started BIP9
  bits during the first retarget windows (see "Mine the first blocks").
- The Bitcoin-testnet4 chain that came over with the v31.1 rebase was removed:
  it was unusable (no `kawpowLimit`, so unmineable first 180 kawpow blocks).
  Satoxcoin has exactly one testnet.

### Required code fix (already applied)

Testnet v3 inherited the same p2p message-start magic as mainnet
(`0x63 0x56 0x65 0x65`) from the 2.1.0 line. With identical magic, testnet
nodes could connect to mainnet peers. The fix changes only the testnet side
(`src/kernel/chainparams.cpp`, testnet section):

- `pchMessageStart = { 0x74, 0x53, 0x41, 0x54 }` (`tSAT`).
- Mainnet's magic is left untouched — changing it would fork the live node
  fleet, so the testnet side has to differ.

Every network must have a distinct magic:

| Network    | Magic bytes | Port   |
|------------|-------------|--------|
| mainnet    | 63 56 65 65 | 60777  |
| testnet v3 | 74 53 41 54 | 7060   |
| regtest    | 44 52 4f 57 | 19444  |

## Testnet vs mainnet vs regtest

Testnet behaves like **mainnet**, not regtest:

| Property           | mainnet                      | testnet v3                   | regtest                     |
|--------------------|------------------------------|------------------------------|-----------------------------|
| PoW                | KAWPOW                       | KAWPOW                       | KAWPOW (any diff, on demand)|
| Block time         | 1 min                        | 1 min                        | instant (`generate`)        |
| Retarget           | every 2016 blocks            | every 2016 blocks            | disabled                    |
| Min-difficulty rule| off                          | off (`fPowAllowMinDifficultyBlocks=false`) | n/a              |
| Subsidy            | 5000 SATOX, halving 2100000  | 5000 SATOX, halving 2100000  | 5000 SATOX                  |
| Community fund     | yes                          | 15% (`nCommunityAutonomousAmount=15`) | no               |
| Difficulty now     | real                         | minimum (`0x1e00ffff`)       | n/a                         |

It only *feels* like regtest today because the difficulty is still at the
minimum and no blocks have been mined. Once mining starts, difficulty adjusts
normally.

## Prerequisites

- A 4.0 build with the testnet magic fix (`cmake --build build -j4`).
- At least one public node (two or more recommended) on a VPS with a public
  IP and port **7060/tcp** reachable.
- The bootstrap operator mines the first blocks with the node's built-in
  miner — no external pool is needed while difficulty is at the minimum.

## Bootstrap procedure

### 1. Start the bootstrap node

```bash
# public node #1 (VPS)
satoxcoind -testnet -server -listen -daemon
```

- Open `7060/tcp` in the firewall or security group.
- Restrict RPC access: use the default cookie auth and add `-rpcallowip` only
  for the operator's admin IP(s). Do not expose RPC publicly.
- Confirm the node is on testnet:

```bash
satoxcoin-cli -testnet getblockchaininfo
# chain: "test", bestblockhash: 000000eaab417d... (genesis)
```

The genesis hash is fixed:
`000000eaab417d6dfe9bd75119972e1d07ecfe8ff655bef7c2acb3d9a0eeed81`.
If a node reports any other best block, it is on the wrong chain.

### 2. Mine the first blocks

The testnet chain is empty, so it must be mined from genesis. With difficulty
at the minimum (`bits 1e00ffff`), the built-in miner finds blocks quickly:

```bash
# on the bootstrap node
satoxcoin-cli -testnet createwallet bootstrap
ADDR=$(satoxcoin-cli -testnet getnewaddress)
satoxcoin-cli -testnet generatetoaddress 2016 "$ADDR"
```

- `generatetoaddress`/`generateblock` are not regtest-gated on this line
  (`src/rpc/mining.cpp:generateBlocks`), so they work on testnet.
- The built-in miner signals every BIP9 deployment whose start time has
  passed. All testnet asset deployments (bits 6-10) qualify, so they lock in
  and activate automatically as the first few 2016-block windows are mined.
  The asset-overflow deployment (bit 11) does **not** start until 2026-09-20
  (`nStartTime`), so it will not activate during this bootstrap.
- Mining **2016 blocks** also clears the first retarget window, letting the
  difficulty reflect real hash rate instead of staying at the floor.
- Blocks take a little while; watch progress:

```bash
satoxcoin-cli -testnet getblockchaininfo | grep -E '"blocks"|"difficulty"'
```

### 3. Verify the chain and core features

```bash
satoxcoin-cli -testnet getblockchaininfo   # height advancing, valid kawpow
satoxcoin-cli -testnet getnetworkinfo      # listening, connections
```

Then exercise the main features on testnet:

```bash
# plain transfer
satoxcoin-cli -testnet sendtoaddress "$ADDR2" 100

# asset issue + transfer
# (assets auto-activate via BIP9 once the miner's signalled bits cross the
# threshold in the first retarget windows; check status before issuing):
satoxcoin-cli -testnet getblockchaininfo | grep -A2 transfer_overflow   # bip9 statuses
satoxcoin-cli -testnet issue "$ADDR2" 100 8 testasset "" ""
```

### 4. Peer discovery (no fixed seeds yet)

Testnet has no fixed seeds (`vSeeds`/`vFixedSeeds` are empty), so early
participants connect explicitly:

```bash
# on each participant node
satoxcoin-cli -testnet addnode "<bootstrap-ip>" "add"
# or at startup:
satoxcoind -testnet -addnode=<bootstrap-ip>
```

Only add `vFixedSeeds` or a DNS seed to `src/kernel/chainparams.cpp` once the
bootstrap IPs are stable and permanent. Do not add seeds for throwaway test
VPSes.

### 5. Verify with a second independent node

Run a second node on a different machine or container. If seeds exist, start
it with no `-addnode`; otherwise pass `-addnode=<bootstrap-ip>`. Then confirm:

```bash
satoxcoin-cli -testnet getblockchaininfo   # syncs to the same tip
satoxcoin-cli -testnet getnetworkinfo      # has at least 1 connection
satoxcoin-cli -testnet getpeerinfo | grep -i addr
```

Also confirm testnet/mainnet isolation: a testnet node must never accept
mainnet peers (distinct message-start magic) and vice versa.

## Operating the testnet

- **Keep the bootstrap miner running** (or point a small kawpow pool at the
  chain) so blocks continue. With a 1-minute block time and no miners, the
  chain stalls: testnet v3 has no min-difficulty rescue rule, so blocks stop
  if the hash rate drops.
- **Announcements:** publish the bootstrap IP, port 7060, and the exact
  version/commit so participants run a compatible node (consensus and p2p
  magic must match).
- **Reset policy:** a testnet is disposable. To reset, delete the testnet
  datadir on every node and re-run the bootstrap (re-mine from genesis).
  Changing the genesis hash would require a code change (new genesis
  time/nonce in `CTestNetParams`) — avoid unless necessary.

## Parameters reference (testnet v3)

| Parameter              | Value                                        |
|------------------------|----------------------------------------------|
| Chain id               | `test`                                       |
| Genesis hash           | `000000eaab417d6dfe9bd75119972e1d07ecfe8ff655bef7c2acb3d9a0eeed81` |
| Genesis time           | 1661734222                                   |
| PoW                    | KAWPOW (after `nKAWPOWActivationTime`)       |
| kawpowLimit            | `00ffffffff...` (minimum difficulty start)   |
| Block time / retarget  | 60 s / 2016 blocks                           |
| Subsidy / halving      | 5000 SATOX / 2100000                         |
| Community fund         | 15% (`nCommunityAutonomousAmount=15`)        |
| Assets deployment      | BIP9 bits 6-10, start times in the past (auto-activate during bootstrap mining) |
| Asset-overflow (bit 11)| BIP9, starts 2026-09-20, not activated       |
| BIP34 height           | 6048                                         |
| Port                   | 7060                                         |
| Message start          | `tSAT` (`0x74 0x53 0x41 0x54`)               |
| Seeds                  | none (bootstrap via `-addnode`)              |