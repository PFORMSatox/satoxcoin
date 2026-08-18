// Copyright (c) 2011-present The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SATOXCOIN_QT_SATOXCOINADDRESSVALIDATOR_H
#define SATOXCOIN_QT_SATOXCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class SatoxcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SatoxcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** Bitcoin address widget validator, checks for a valid bitcoin address.
 */
class SatoxcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SatoxcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // SATOXCOIN_QT_SATOXCOINADDRESSVALIDATOR_H
