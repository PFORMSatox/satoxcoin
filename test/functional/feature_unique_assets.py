#!/usr/bin/env python3
# Copyright (c) 2017 The Bitcoin Core developers
# Copyright (c) 2017-2020 The Satoxcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

"""Testing unique asset use cases"""

import random
from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import assert_contains, assert_does_not_contain_key, assert_equal, assert_raises_rpc_error


def gen_root_asset_name():
    size = random.randint(3, 14)
    name = ""
    for _ in range(1, size + 1):
        ch = random.randint(65, 65 + 25)
        name += chr(ch)
    return name


def gen_unique_asset_name(root):
    tag_ab = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@$%&*()[]{}_.?-:"
    name = root + "#"
    tag_size = random.randint(1, 15)
    for _ in range(1, tag_size + 1):
        tag_c = tag_ab[random.randint(0, len(tag_ab) - 1)]
        name += tag_c
    return name


class UniqueAssetTest(BitcoinTestFramework):
    def set_test_params(self):
        self.setup_clean_chain = True
        self.num_nodes = 3
        self.uses_wallet = True
        self.wallet_names = ['w0', 'w1', 'w2']
        self.extra_args = [['-assetindex'], ['-assetindex'], ['-assetindex']]

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
        self.log.info("Generating for node[0]...")
        n0 = self.nodes[0]
        self.generate(n0, 101)
        self.sync_all()

    def issue_one(self):
        self.log.info("Issuing a unique asset...")
        n0 = self.nodes[0]
        root = gen_root_asset_name()
        n0.issue(asset_name=root)
        self.generate(n0, 1)
        asset_name = gen_unique_asset_name(root)
        n0.issue(asset_name=asset_name)
        self.generate(n0, 1)
        assert_equal(1, n0.listmyassets()[asset_name])

    def issue_invalid(self):
        self.log.info("Trying some invalid calls...")
        n0, n1 = self.nodes[0], self.nodes[1]
        self.generate(n1, 10)
        self.sync_all()
        root = gen_root_asset_name()
        asset_name = gen_unique_asset_name(root)

        # no root
        assert_raises_rpc_error(-32600, f"Wallet doesn't have asset: {root}!", n0.issue, asset_name)

        # don't own root
        n0.sendtoaddress(self.legacy_address(n1), 501)
        self.generate(n0, 1)
        self.sync_all()
        n1.issue(root)
        self.generate(n1, 1)
        self.sync_all()
        assert_contains(root, n0.listassets())
        assert_raises_rpc_error(-32600, f"Wallet doesn't have asset: {root}!", n0.issue, asset_name)
        n1.transfer(f"{root}!", 1, self.legacy_address(n0))
        self.generate(n1, 1)
        self.sync_all()

        # bad qty
        assert_raises_rpc_error(-8, "Invalid parameters for issuing a unique asset.", n0.issue, asset_name, 2)

        # bad units
        assert_raises_rpc_error(-8, "Invalid parameters for issuing a unique asset.", n0.issue, asset_name, 1, "", "", 1)

        # reissuable
        assert_raises_rpc_error(-8, "Invalid parameters for issuing a unique asset.", n0.issue, asset_name, 1, "", "", 0, True)

        # already exists
        n0.issue(asset_name)
        self.generate(n0, 1)
        self.sync_all()
        assert_raises_rpc_error(-8, f"Invalid parameter: asset_name '{asset_name}' has already been used", n0.issue, asset_name)

    def issue_unique_test(self):
        self.log.info("Testing issueunique RPC...")
        n0 = self.nodes[0]
        root = gen_root_asset_name()
        asset_tags = ['primo', 'secundo', 'terzo', 'quarto', 'quinto', 'sesto', 'settimo', 'ottavo', 'nono', 'decimo']
        ipfs_hashes = ['QmYwAPJzv5CZsnAzt8auVZRnYxN7e7J8m1dBzH5tZ4VxFw'] * len(asset_tags)

        n0.issue(asset_name=root)
        self.generate(n0, 1)
        n0.issueunique(root, asset_tags, ipfs_hashes)
        self.generate(n0, 1)
        self.sync_all()

        myassets = n0.listmyassets()
        for asset_name in [f'{root}#{tag}' for tag in asset_tags]:
            assert_equal(1, myassets[asset_name])
            assert_equal(root, n0.getassetdata(asset_name)['name'].split('#')[0])

    def run_test(self):
        self.activate_assets()
        self.issue_one()
        self.issue_invalid()
        self.issue_unique_test()

if __name__ == '__main__':
    UniqueAssetTest(__file__).main()
