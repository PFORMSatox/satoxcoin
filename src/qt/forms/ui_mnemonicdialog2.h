/********************************************************************************
** Form generated from reading UI file 'mnemonicdialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MNEMONICDIALOG2_H
#define UI_MNEMONICDIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MnemonicDialog2
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblHelp;
    QComboBox *languageSeedWords;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *generateButton;
    QSpacerItem *horizontalSpacer_2;
    QPlainTextEdit *seedwordsText;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *passphraseEdit;
    QLabel *passphraseLabel;
    QSpacerItem *verticalSpacer_5;
    QFormLayout *mnemonicLayout;
    QLabel *label_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *acceptButton;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QFrame *MnemonicDialog2)
    {
        if (MnemonicDialog2->objectName().isEmpty())
            MnemonicDialog2->setObjectName(QString::fromUtf8("MnemonicDialog2"));
        MnemonicDialog2->resize(810, 436);
        MnemonicDialog2->setFrameShape(QFrame::StyledPanel);
        MnemonicDialog2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(MnemonicDialog2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblHelp = new QLabel(MnemonicDialog2);
        lblHelp->setObjectName(QString::fromUtf8("lblHelp"));
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        lblHelp->setPalette(palette);

        verticalLayout->addWidget(lblHelp);

        languageSeedWords = new QComboBox(MnemonicDialog2);
        languageSeedWords->setObjectName(QString::fromUtf8("languageSeedWords"));

        verticalLayout->addWidget(languageSeedWords);

        groupBox = new QGroupBox(MnemonicDialog2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        generateButton = new QPushButton(groupBox);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setMinimumSize(QSize(150, 0));
        generateButton->setCheckable(false);

        horizontalLayout->addWidget(generateButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);

        seedwordsText = new QPlainTextEdit(groupBox);
        seedwordsText->setObjectName(QString::fromUtf8("seedwordsText"));
        seedwordsText->setReadOnly(true);

        gridLayout_3->addWidget(seedwordsText, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        groupBox_2 = new QGroupBox(MnemonicDialog2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        passphraseEdit = new QLineEdit(groupBox_2);
        passphraseEdit->setObjectName(QString::fromUtf8("passphraseEdit"));

        verticalLayout_2->addWidget(passphraseEdit);

        passphraseLabel = new QLabel(groupBox_2);
        passphraseLabel->setObjectName(QString::fromUtf8("passphraseLabel"));

        verticalLayout_2->addWidget(passphraseLabel);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        mnemonicLayout = new QFormLayout();
        mnemonicLayout->setObjectName(QString::fromUtf8("mnemonicLayout"));
        label_3 = new QLabel(MnemonicDialog2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        mnemonicLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(MnemonicDialog2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        mnemonicLayout->setWidget(1, QFormLayout::FieldRole, label_2);


        verticalLayout->addLayout(mnemonicLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        acceptButton = new QPushButton(MnemonicDialog2);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));
        acceptButton->setMinimumSize(QSize(150, 0));
        acceptButton->setMaximumSize(QSize(150, 16777215));
        acceptButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(acceptButton);

        backButton = new QPushButton(MnemonicDialog2);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMinimumSize(QSize(150, 0));
        backButton->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(MnemonicDialog2);

        QMetaObject::connectSlotsByName(MnemonicDialog2);
    } // setupUi

    void retranslateUi(QFrame *MnemonicDialog2)
    {
        MnemonicDialog2->setWindowTitle(QApplication::translate("MnemonicDialog2", "New HD Wallet Creation", nullptr));
        lblHelp->setText(QString());
        groupBox->setTitle(QApplication::translate("MnemonicDialog2", "BIP39 Compliant Seed Words:", nullptr));
        generateButton->setText(QApplication::translate("MnemonicDialog2", "Generate New Seed Words", nullptr));
        seedwordsText->setPlaceholderText(QApplication::translate("MnemonicDialog2", "These 12 generated seed words will be used.", nullptr));
        groupBox_2->setTitle(QApplication::translate("MnemonicDialog2", "Optional Seed Extension Word:", nullptr));
#ifndef QT_NO_TOOLTIP
        passphraseEdit->setToolTip(QApplication::translate("MnemonicDialog2", "A 12 word seed phrase is a useful way of backing up a wallet, because it is a system for generating the keys to all Satoxcoin and Assets. However, anyone who finds/learns your seed phrase will likewise have control of your wallet. For this reason, some users choose to add another level of security to these 12 words. Unlike your 12 word phrase, which is generated randomly, this 13th word (known as the Seed Extension Word) is something the user comes up with themselves and memorizes, or stores separately from their seed phrase.\n"
"                \n"
"                The Seed Extension Word is like adding a password to your randomly generated seed phrase. If someone finds your written 12 word seed phrase, but you\342\200\231ve chosen to use a Seed Extension Word, they will not be able to access your wallet.", nullptr));
#endif // QT_NO_TOOLTIP
        passphraseLabel->setText(QApplication::translate("MnemonicDialog2", "You may enter an optional extension word to protect your seed.", nullptr));
        label_3->setText(QApplication::translate("MnemonicDialog2", "Warning: ", nullptr));
        label_2->setText(QApplication::translate("MnemonicDialog2", "Please write down your 12 seed words and the optional seed extension word before accepting.\n"
"They are not recoverable!!", nullptr));
        acceptButton->setText(QApplication::translate("MnemonicDialog2", "Accept", nullptr));
        backButton->setText(QApplication::translate("MnemonicDialog2", "Go Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MnemonicDialog2: public Ui_MnemonicDialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MNEMONICDIALOG2_H
