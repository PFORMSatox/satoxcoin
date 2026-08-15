#!/usr/bin/env python3
# Copyright (c) 2015-2016 The Bitcoin Core developers
# Copyright (c) 2017-2020 The Satoxcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

"""Test listmyassets RPC command."""

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import assert_equal, assert_contains_pair

class ListMyAssetsTest(BitcoinTestFramework):
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

    def listmyassets_filter_zeros(self):
        """Sometimes the asset cache will contain zero-quantity holdings for some assets (until they're flushed).
           These shouldn't be returned by listmyassets.
        """

        # mine enough for coinbase maturity
        self.generate(self.nodes[0], 101)
        self.sync_all()

        assert_equal(0, len(self.nodes[0].listmyassets()))
        assert_equal(0, len(self.nodes[1].listmyassets()))

        self.nodes[0].issue("FOO", 1000)
        self.generate(self.nodes[0], 10)
        self.sync_all()

        result = self.nodes[0].listmyassets()
        assert_equal(2, len(result))
        assert_contains_pair("FOO", 1000, result)
        assert_contains_pair("FOO!", 1, result)

        address_to = self.nodes[1].getnewaddress("", "legacy")
        self.nodes[0].transfer("FOO", 1000, address_to)
        self.generate(self.nodes[0], 10)
        self.sync_all()

        result = self.nodes[0].listmyassets()
        assert_equal(1, len(result))
        assert_contains_pair("FOO!", 1, result)

        result = self.nodes[1].listmyassets()
        assert_equal(1, len(result))
        assert_contains_pair("FOO", 1000, result)

    def run_test(self):
        self.listmyassets_filter_zeros()

if __name__ == '__main__':
    ListMyAssetsTest(__file__).main()
