#!/usr/bin/env python3
# Copyright (c) 2017 The Bitcoin Core developers
# Copyright (c) 2017-2020 The Satoxcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

"""Testing asset reorg use cases"""

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import assert_equal

class AssetReorgTest(BitcoinTestFramework):
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
        self.generate(n0, 101)
        self.sync_all()
        self.generate(n1, 101)
        self.sync_all()
        assert n0.getbalance() > 0
        assert n1.getbalance() > 0

    def issue_reorg_test(self):
        self.log.info("Testing issue reorg 2...")
        n0, n1 = self.nodes[0], self.nodes[1]

        self.disconnect_nodes(0, 1)

        asset_name = "DOUBLE_TROUBLE"

        # Issue asset on chain 1
        n0.issue(asset_name)
        self.generate(n0, 15, sync=False)

        # Issue asset on chain 2
        self.generate(n1, 5, sync=False)
        n1.issue(asset_name)
        self.generate(n1, 5, sync=False)

        # Do some validity checks, make sure we have separate chains
        node_0_hash = n0.getbestblockhash()
        node_0_height = n0.getblockcount()

        # They should each on their chains the asset DOUBLE_TROUBLE and DOUBLE_TROUBLE!
        assert_equal(True, n0.listmyassets() == n1.listmyassets())
        assert_equal(True, node_0_hash is not n1.getbestblockhash())

        # Connect the nodes together, and force a reorg to occur
        self.connect_nodes(0, 1)
        self.sync_blocks()

        # Verify that node1 reorged to the node0 chain and that node0 has the asset and not node1
        assert_equal(node_0_height, n1.getblockcount())
        assert_equal(node_0_hash, n1.getbestblockhash())
        assert_equal(True, n0.listmyassets() != n1.listmyassets())

        # Disconnect all nodes
        self.disconnect_nodes(0, 1)

        # Issue second asset on chain 1 and mine 5 blocks
        n0.issue(asset_name + '2')
        self.generate(n0, 5, sync=False)

        # Mine 5 blocks, issue second asset on chain 2, mine 5 more blocks, giving node1 more chain weight
        self.generate(n1, 5, sync=False)
        n1.issue(asset_name + '2')
        self.generate(n1, 5, sync=False)

        node_1_hash = n1.getbestblockhash()
        node_1_height = n1.getblockcount()
        assert_equal(True, n0.getbestblockhash() is not node_1_hash)
        assert_equal(True, n0.listmyassets('DOUBLE_TROUBLE2*') == n1.listmyassets('DOUBLE_TROUBLE2*'))

        # Connect the nodes together, and force a reorg to occur
        self.connect_nodes(0, 1)
        self.sync_blocks()

        # Verify that node0 reorged to the node1 chain and that node1 has the asset and not node0
        assert_equal(n0.getblockcount(), node_1_height)
        assert_equal(n0.getbestblockhash(), node_1_hash)
        assert_equal(True, n0.listmyassets() != n1.listmyassets())

    def reorg_chain_state_test(self):
        self.log.info("Testing issue reorg to invalid chain...")
        n0, n1 = self.nodes[0], self.nodes[1]

        self.disconnect_nodes(0, 1)

        # Mine 40 blocks
        self.generate(n0, 40, sync=False)
        node_0_hash = n0.getbestblockhash()
        node_0_height = n0.getblockcount()

        # Mine 44 blocks on chain 2
        self.generate(n1, 20, sync=False)
        node_1_hash_20 = n1.getbestblockhash()

        self.generate(n1, 24, sync=False)
        node_1_hash_44 = n1.getbestblockhash()
        node_1_height_44 = n1.getblockcount()

        # Do some validity checks, make sure we have separate chains
        assert_equal(True, node_0_hash is not n1.getbestblockhash())
        assert_equal(True, (node_1_height_44 - node_0_height) == 4)

        # Connect the nodes together, and force a reorg to occur
        self.connect_nodes(0, 1)
        self.sync_blocks()

        node_0_hash_after_reorg = n0.getbestblockhash()
        node_0_height_after_reorg = n0.getblockcount()

        # Make sure the reorg was successful
        assert_equal(True, node_0_hash_after_reorg == node_1_hash_44)
        assert_equal(True, node_0_height_after_reorg == node_1_height_44)

        # Invalidate node 1 block height at 20
        n0.invalidateblock(node_1_hash_20)

        # When node0 invalidated the block, it should automatically connect to the longest valid chain
        # which is the chain that node0 mined at the start of the test
        node_0_hash_invalidated = n0.getbestblockhash()
        node_0_height_invalidated = n0.getblockcount()
        assert_equal(True, node_0_height == node_0_height_invalidated)
        assert_equal(True, node_0_hash == node_0_hash_invalidated)

    def run_test(self):
        self.activate_assets()
        self.issue_reorg_test()
        self.reorg_chain_state_test()

if __name__ == '__main__':
    AssetReorgTest(__file__).main()
