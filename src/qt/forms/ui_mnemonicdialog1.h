/********************************************************************************
** Form generated from reading UI file 'mnemonicdialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MNEMONICDIALOG1_H
#define UI_MNEMONICDIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MnemonicDialog1
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *walletLabel;
    QSpacerItem *verticalSpacer_4;
    QLabel *wallettypeLabel;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *walletNewRadio;
    QSpacerItem *verticalSpacer_3;
    QRadioButton *walletOldRadio;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *acceptButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QFrame *MnemonicDialog1)
    {
        if (MnemonicDialog1->objectName().isEmpty())
            MnemonicDialog1->setObjectName(QString::fromUtf8("MnemonicDialog1"));
        MnemonicDialog1->resize(674, 415);
        MnemonicDialog1->setFrameShape(QFrame::StyledPanel);
        MnemonicDialog1->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(MnemonicDialog1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        walletLabel = new QLabel(MnemonicDialog1);
        walletLabel->setObjectName(QString::fromUtf8("walletLabel"));
        walletLabel->setStyleSheet(QString::fromUtf8("QLabel { font-style:italic; }"));
        walletLabel->setWordWrap(true);

        verticalLayout->addWidget(walletLabel);

        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_4);

        wallettypeLabel = new QLabel(MnemonicDialog1);
        wallettypeLabel->setObjectName(QString::fromUtf8("wallettypeLabel"));
        wallettypeLabel->setWordWrap(true);

        verticalLayout->addWidget(wallettypeLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox = new QGroupBox(MnemonicDialog1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        walletNewRadio = new QRadioButton(groupBox);
        walletNewRadio->setObjectName(QString::fromUtf8("walletNewRadio"));

        verticalLayout_2->addWidget(walletNewRadio);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        walletOldRadio = new QRadioButton(groupBox);
        walletOldRadio->setObjectName(QString::fromUtf8("walletOldRadio"));

        verticalLayout_2->addWidget(walletOldRadio);


        verticalLayout->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        acceptButton = new QPushButton(MnemonicDialog1);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));
        acceptButton->setAutoDefault(false);

        horizontalLayout->addWidget(acceptButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MnemonicDialog1);

        QMetaObject::connectSlotsByName(MnemonicDialog1);
    } // setupUi

    void retranslateUi(QFrame *MnemonicDialog1)
    {
        MnemonicDialog1->setWindowTitle(QApplication::translate("MnemonicDialog1", "HD Wallet Setup", nullptr));
        walletLabel->setText(QApplication::translate("MnemonicDialog1", "Select the type of wallet to create.", nullptr));
        wallettypeLabel->setText(QApplication::translate("MnemonicDialog1", "Since no wallet.dat file was found in the Satoxcoin block chain data directory, a wallet file will be created.", nullptr));
        groupBox->setTitle(QApplication::translate("MnemonicDialog1", "Please choose what you would like to do:", nullptr));
        walletNewRadio->setText(QApplication::translate("MnemonicDialog1", "Create a new wallet using a new BIP39 compliant set of 12 seed words.", nullptr));
        walletOldRadio->setText(QApplication::translate("MnemonicDialog1", "Re-create an existing wallet using a previously used BIP39 compliant set \n"
"    of 12 seed words which you know.", nullptr));
        acceptButton->setText(QApplication::translate("MnemonicDialog1", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MnemonicDialog1: public Ui_MnemonicDialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MNEMONICDIALOG1_H
