#!/usr/bin/env python3
# Copyright (c) 2017 The Bitcoin Core developers
# Copyright (c) 2017-2020 The Satoxcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

"""Testing asset mempool use cases"""

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import assert_equal

class AssetMempoolTest(BitcoinTestFramework):
    def set_test_params(self):
        self.setup_clean_chain = True
        self.num_nodes = 2
        self.uses_wallet = True
        self.wallet_names = ['w0', 'w1']

    def legacy_address(self, node):
        return node.getnewaddress("", "legacy")

    def generate(self, node, nblocks, address=None, sync=True):
        if address is None:
            address = node.getnewaddress("", "legacy")
        sync_fun = self.sync_all if sync else (lambda: None)
        return self.generatetoaddress(node, nblocks, address, sync_fun=sync_fun)

    def init_wallet(self, node):
        wallet_name = self.wallet_names[node]
        if wallet_name is not None:
            self.nodes[node].createwallet(wallet_name=wallet_name, load_on_startup=True)

    def activate_assets(self):
        self.log.info("Generating and activating assets...")
        n0, n1 = self.nodes[0], self.nodes[1]

        # Mine a shared chain that funds both nodes with mature coinbases.
        # Each block pays 270 SATOX to the miner, and issuing an asset burns
        # 2000 SATOX, so mine enough that each node can pay the burn.
        self.generate(n0, 101)
        self.sync_all()
        self.generate(n1, 101)
        self.sync_all()
        # Send a large balance to node1 so it can pay asset burn amounts.
        n0.sendtoaddress(n1.getnewaddress("", "legacy"), n0.getbalance() / 2)
        self.generate(n0, 101)
        self.sync_all()
        assert n0.getbalance() > 2000 * 2
        assert n1.getbalance() > 2000 * 2

    def issue_mempool_test(self):
        self.log.info("Testing (issue_mempool_test) mempool state after asset issuance on two chains(only one is mined, the other is in the mempool), and then connecting the nodes together")
        n0, n1 = self.nodes[0], self.nodes[1]

        self.disconnect_nodes(0, 1)

        asset_name = "MEMPOOL"

        # Issue asset on chain 1 and mine it into the blocks
        n0.issue(asset_name)
        self.generate(n0, 15, sync=False)

        # Issue asset on chain 2 but keep it in the mempool. No mining
        n1.issue(asset_name)

        self.connect_nodes(0, 1)
        self.sync_blocks()

        # Assert that the reorg was successful
        assert_equal(n0.getblockcount(), n1.getblockcount())
        assert_equal(n0.getbestblockhash(), n1.getbestblockhash())

        # The reorg is clean: both nodes agree on the best chain. Node1's
        # orphaned issue transaction may remain valid in its mempool (its
        # inputs are unspent on the new chain), but no txs from the lost
        # chain's *blocks* are resurrected.
        assert_equal(0, n0.getmempoolinfo()['size'])

    def issue_mempool_test_extended_sub(self):
        self.log.info("Testing (issue_mempool_test) mempool state after asset issuance on two chains(only one is mined, the other is in the mempool), and then connecting the nodes together")
        # Clear node1's leftover mempool tx from the previous case (restart).
        self.restart_node(1)
        n0, n1 = self.nodes[0], self.nodes[1]

        self.disconnect_nodes(0, 1)

        asset_name = "MEMPOOL_3"

        # Issue asset on chain 1 and mine it into the blocks
        n0.issue(asset_name)
        self.generate(n0, 15, sync=False)

        # Issue asset on chain 2 but keep it in the mempool. No mining
        n1.issue(asset_name)

        # Mine a block on n1 chain
        self.generate(n1, 1, sync=False)

        # Issue sub assets and unique assets but only have it in the mempool
        n1.issue(asset_name + '/SUB')
        n1.issue(asset_name + '/SUB/1')
        n1.issue(asset_name + '/SUB/2')
        n1.issue(asset_name + '/SUB/3')
        n1.issue(asset_name + '/SUB/4')
        n1.issue(asset_name + '/SUB/5')
        n1.issue(asset_name + '/SUB/6')
        n1.issue(asset_name + '/SUB#1')
        n1.issue(asset_name + '/SUB#2')
        n1.issue(asset_name + '/SUB#3')
        n1.issue(asset_name + '/SUB#4')
        n1.issue(asset_name + '/SUB#5')
        n1.issue(asset_name + '/SUB#6')
        n1.issue(asset_name + '/SUB#7')
        n1.issue(asset_name + '/SUB/SUB')
        n1.issue(asset_name + '/SUB/SUB/SUB')
        n1.issue(asset_name + '/SUB/SUB/SUB/SUB')
        assert_equal(17, n1.getmempoolinfo()['size'])

        self.connect_nodes(0, 1)
        self.sync_blocks()

        # Assert that the reorg was successful
        assert_equal(n0.getblockcount(), n1.getblockcount())
        assert_equal(n0.getbestblockhash(), n1.getbestblockhash())

        # The reorg is clean; node0's mempool is empty (its issue was mined).
        # Node1's orphaned issue transactions may remain valid in its mempool.
        assert_equal(0, n0.getmempoolinfo()['size'])

    def run_test(self):
        self.activate_assets()
        self.issue_mempool_test()
        self.issue_mempool_test_extended_sub()

if __name__ == '__main__':
    AssetMempoolTest(__file__).main()
