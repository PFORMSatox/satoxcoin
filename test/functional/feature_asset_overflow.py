#!/usr/bin/env python3
# Copyright (c) 2026 The Satoxcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

"""Test the asset transfer overflow soft-fork (BIP9 DEPLOYMENT_TRANSFER_OVERFLOW, bit 11).

Pre-activation the overflow check only logs ("Input Overflow Check-*") and makes
exactly the same accept/reject decision as legacy nodes. Post-activation,
overflowing asset transfer outputs are rejected with
bad-txns-transfer-asset-amount-toolarge before the balance check runs.

A crafted transaction is used because wallet/RPC asset amounts are bounded by
MAX_MONEY (issue/reissue reject larger amounts), so the int64 wrap of the
per-asset input/output accumulation can only be reached with a raw transaction.
"""

import struct
from decimal import Decimal

from test_framework.key import ECKey
from test_framework.messages import COutPoint, CTransaction, CTxIn, CTxOut
from test_framework.script import hash160
from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import assert_equal, assert_raises_rpc_error

# OP_SATOX_ASSET = 0xc0, OP_DROP = 0x75. The "rvnt" prefix is the Satoxcoin
# asset marker (SATOX_N/E/X/T). IsScriptTransferAsset requires OP_SATOX_ASSET at
# byte index 25 with the "rvnt" marker at indexes 27-30.
OP_SATOX_ASSET = 0xC0
OP_DROP = 0x75
P2PKH_TEMPLATE = bytes.fromhex("76a914") + b"\x00" * 20 + bytes.fromhex("88ac")

VB_PERIOD = 500          # regtest deployment period
INT64_MAX = (1 << 63) - 1  # 9223372036854775807


class AssetOverflowTest(BitcoinTestFramework):
    def set_test_params(self):
        self.setup_clean_chain = True
        self.num_nodes = 1
        self.uses_wallet = True
        self.wallet_names = ['w0']
        self.extra_args = [['-assetindex']]

    def legacy_address(self, node):
        return node.getnewaddress("", "legacy")

    def generate(self, node, nblocks, address=None, sync=True):
        if address is None:
            address = self.legacy_address(node)
        sync_fun = self.sync_all if sync else (lambda: None)
        return self.generatetoaddress(node, nblocks, address, sync_fun=sync_fun)

    def init_wallet(self, node):
        wallet_name = self.wallet_names[node]
        if wallet_name is not None:
            self.nodes[node].createwallet(wallet_name=wallet_name, load_on_startup=True)

    def send_blocks_with_version(self, node, numblocks):
        """Mine numblocks blocks. The node's own miner signals every started
        BIP9 deployment, so bit 11 is signalled automatically from height 500;
        transfer_overflow therefore activates at height 1500 (since=1500)."""
        self.generate(node, numblocks)

    def build_transfer_script(self, h160, name, amount):
        """Build a legacy-layout asset transfer script (P2PKH + asset payload)."""
        p2pkh = bytes.fromhex("76a914") + h160 + bytes.fromhex("88ac")
        name_bytes = name.encode()
        # CAssetTransfer serialization with empty message/expiry:
        # CompactSize(name) + name + int64 LE amount.
        payload = bytes([len(name_bytes)]) + name_bytes + struct.pack("<q", amount)
        vch_message = b"rvnt" + payload
        assert len(vch_message) < 76  # single-byte data push
        return p2pkh + bytes([OP_SATOX_ASSET, len(vch_message)]) + vch_message + bytes([OP_DROP])

    def make_overflow_tx(self, node, utxo, h160, name):
        """Raw tx: 1 BTC input, BTC change, and two huge transfer outputs of `name`.

        The two outputs of INT64_MAX make the per-asset output accumulation wrap
        the second time around, tripping the overflow check (post-activation).
        """
        tx = CTransaction()
        tx.vin = [CTxIn(COutPoint(int(utxo['txid'], 16), utxo['vout']))]
        # Plain P2PKH change output (asset scripts start with the same 25 bytes).
        change_script = bytes.fromhex("76a914") + h160 + bytes.fromhex("88ac")
        change_amount = int((utxo['amount'] - Decimal('1.00')) * 100000000)
        tx.vout = [
            CTxOut(change_amount, change_script),
            CTxOut(0, self.build_transfer_script(h160, name, INT64_MAX)),
            CTxOut(0, self.build_transfer_script(h160, name, INT64_MAX)),
        ]
        return tx

    def deployment_status(self, node):
        return node.getdeploymentinfo()["deployments"]["transfer_overflow"]["bip9"]["status"]

    def deployment_active(self, node):
        return node.getdeploymentinfo()["deployments"]["transfer_overflow"]["active"]

    def run_test(self):
        node = self.nodes[0]
        self.log.info("Funding node and issuing an asset...")
        self.generate(node, 101)
        addr = self.legacy_address(node)
        node.issue(asset_name="OVF", qty=1000, to_address=addr, change_address="", units=8)
        self.generate(node, 1)

        self.log.info("Check the deployment is defined but not active (pre-activation)...")
        softfork = node.getdeploymentinfo()["deployments"]["transfer_overflow"]
        assert_equal(softfork["type"], "bip9")
        assert_equal(softfork["bip9"]["status"], "defined")
        assert_equal(self.deployment_active(node), False)

        self.log.info("Building the crafted overflow transaction...")
        key = ECKey()
        key.generate()
        h160 = hash160(key.get_pubkey().get_bytes())
        utxo = node.listunspent()[0]
        overflow_tx = self.make_overflow_tx(node, utxo, h160, "OVF")
        tx_hex = overflow_tx.serialize().hex()

        self.log.info("Pre-activation: log-only, legacy accept/reject decision unchanged...")
        # No asset inputs -> balance mismatch, exactly as legacy nodes decide.
        # The overflow log must still fire before that reject.
        with node.assert_debug_log(["Input Overflow Check: output asset amount overflow"]):
            assert_raises_rpc_error(-26, "bad-tx-inputs-outputs-mismatch", node.sendrawtransaction, tx_hex)

        self.log.info("Activating bit 11 (mining to height 1500, signalled by the node's miner)...")
        # transfer_overflow enters "started" at height 500 and the node's miner
        # signals bit 11 automatically, so a full signalled period
        # [500, 1000), then the locked-in period [1000, 1500), then a buffer.
        self.send_blocks_with_version(node, 3 * VB_PERIOD)
        assert_equal(self.deployment_status(node), "active")
        assert_equal(self.deployment_active(node), True)

        self.log.info("Post-activation: overflow rejected with bad-txns-transfer-asset-amount-toolarge...")
        assert_raises_rpc_error(-26, "bad-txns-transfer-asset-amount-toolarge", node.sendrawtransaction, tx_hex)

        self.log.info("Post-activation regression: normal asset transfers still work...")
        node.transfer(asset_name="OVF", qty=1, to_address=addr)
        self.generate(node, 1)
        assert_equal(node.getmempoolinfo()["size"], 0)
        node.transfer(asset_name="OVF", qty=1, to_address=addr)
        self.generate(node, 1)
        assert_equal(node.getmempoolinfo()["size"], 0)


if __name__ == '__main__':
    AssetOverflowTest(__file__).main()