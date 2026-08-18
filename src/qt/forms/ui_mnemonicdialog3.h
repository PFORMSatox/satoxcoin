/********************************************************************************
** Form generated from reading UI file 'mnemonicdialog3.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MNEMONICDIALOG3_H
#define UI_MNEMONICDIALOG3_H

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

class Ui_MnemonicDialog3
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblHelp;
    QLabel *lblWarningJapanese;
    QComboBox *languageSeedWords;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *seedwordsEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *passphraseEdit;
    QLabel *passwordLabel;
    QSpacerItem *verticalSpacer_4;
    QFormLayout *mnemonicLayout;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *acceptButton;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QFrame *MnemonicDialog3)
    {
        if (MnemonicDialog3->objectName().isEmpty())
            MnemonicDialog3->setObjectName(QString::fromUtf8("MnemonicDialog3"));
        MnemonicDialog3->resize(810, 436);
        MnemonicDialog3->setFrameShape(QFrame::StyledPanel);
        MnemonicDialog3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(MnemonicDialog3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblHelp = new QLabel(MnemonicDialog3);
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

        lblWarningJapanese = new QLabel(MnemonicDialog3);
        lblWarningJapanese->setObjectName(QString::fromUtf8("lblWarningJapanese"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        lblWarningJapanese->setPalette(palette1);

        verticalLayout->addWidget(lblWarningJapanese);

        languageSeedWords = new QComboBox(MnemonicDialog3);
        languageSeedWords->setObjectName(QString::fromUtf8("languageSeedWords"));

        verticalLayout->addWidget(languageSeedWords);

        groupBox = new QGroupBox(MnemonicDialog3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        seedwordsEdit = new QPlainTextEdit(groupBox);
        seedwordsEdit->setObjectName(QString::fromUtf8("seedwordsEdit"));
        seedwordsEdit->setReadOnly(false);

        gridLayout_3->addWidget(seedwordsEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(MnemonicDialog3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        passphraseEdit = new QLineEdit(groupBox_2);
        passphraseEdit->setObjectName(QString::fromUtf8("passphraseEdit"));

        verticalLayout_2->addWidget(passphraseEdit);

        passwordLabel = new QLabel(groupBox_2);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        verticalLayout_2->addWidget(passwordLabel);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        mnemonicLayout = new QFormLayout();
        mnemonicLayout->setObjectName(QString::fromUtf8("mnemonicLayout"));
        label_3 = new QLabel(MnemonicDialog3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        mnemonicLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(MnemonicDialog3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        mnemonicLayout->setWidget(1, QFormLayout::FieldRole, label_2);


        verticalLayout->addLayout(mnemonicLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        acceptButton = new QPushButton(MnemonicDialog3);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));
        acceptButton->setMinimumSize(QSize(150, 0));
        acceptButton->setMaximumSize(QSize(150, 16777215));
        acceptButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(acceptButton);

        backButton = new QPushButton(MnemonicDialog3);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMinimumSize(QSize(150, 0));
        backButton->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(MnemonicDialog3);

        QMetaObject::connectSlotsByName(MnemonicDialog3);
    } // setupUi

    void retranslateUi(QFrame *MnemonicDialog3)
    {
        MnemonicDialog3->setWindowTitle(QApplication::translate("MnemonicDialog3", "Previous HD Wallet Re-creation", nullptr));
        lblHelp->setText(QString());
        lblWarningJapanese->setText(QString());
        groupBox->setTitle(QApplication::translate("MnemonicDialog3", "BIP39 Compliant Seed Words:", nullptr));
        seedwordsEdit->setPlaceholderText(QApplication::translate("MnemonicDialog3", "Enter the 12 seed words from your previous wallet here.", nullptr));
        groupBox_2->setTitle(QApplication::translate("MnemonicDialog3", "Seed Extension Word:", nullptr));
#ifndef QT_NO_TOOLTIP
        passphraseEdit->setToolTip(QApplication::translate("MnemonicDialog3", "The Seed Extension Word is like adding a password to your randomly generated seed phrase. If someone finds your written 12 word seed phrase, but you\342\200\231ve chosen to use a Seed Extension Word, they will not be able to access your wallet.", nullptr));
#endif // QT_NO_TOOLTIP
        passwordLabel->setText(QApplication::translate("MnemonicDialog3", "Enter the Seed Extension Word from your previous wallet (if it used one).", nullptr));
        label_3->setText(QApplication::translate("MnemonicDialog3", "Warning: ", nullptr));
        label_2->setText(QApplication::translate("MnemonicDialog3", "Please continue to remember your 12 seed words and extension word before accepting.\n"
"They are not recoverable!!", nullptr));
        acceptButton->setText(QApplication::translate("MnemonicDialog3", "Accept", nullptr));
        backButton->setText(QApplication::translate("MnemonicDialog3", "Go Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MnemonicDialog3: public Ui_MnemonicDialog3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MNEMONICDIALOG3_H
