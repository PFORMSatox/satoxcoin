/********************************************************************************
** Form generated from reading UI file 'mnemonicdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MNEMONICDIALOG_H
#define UI_MNEMONICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MnemonicDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lblHelp;
    QTabWidget *tabWidget;
    QWidget *tabImport;
    QGridLayout *gridLayout_2;
    QLabel *mnemonicLabel;
    QTextEdit *tbxMnemonic;
    QFormLayout *mnemonicLayout;
    QLabel *passwordLabel;
    QLineEdit *edtPassword;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnImport;
    QPushButton *btnGenerate;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *MnemonicDialog)
    {
        if (MnemonicDialog->objectName().isEmpty())
            MnemonicDialog->setObjectName(QString::fromUtf8("MnemonicDialog"));
        MnemonicDialog->resize(810, 297);
        gridLayout = new QGridLayout(MnemonicDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblHelp = new QLabel(MnemonicDialog);
        lblHelp->setObjectName(QString::fromUtf8("lblHelp"));
        lblHelp->setEnabled(true);
        lblHelp->setStyleSheet(QString::fromUtf8("color : red"));

        gridLayout->addWidget(lblHelp, 0, 0, 1, 1);

        tabWidget = new QTabWidget(MnemonicDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabImport = new QWidget();
        tabImport->setObjectName(QString::fromUtf8("tabImport"));
        gridLayout_2 = new QGridLayout(tabImport);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mnemonicLabel = new QLabel(tabImport);
        mnemonicLabel->setObjectName(QString::fromUtf8("mnemonicLabel"));

        gridLayout_2->addWidget(mnemonicLabel, 0, 0, 1, 1);

        tbxMnemonic = new QTextEdit(tabImport);
        tbxMnemonic->setObjectName(QString::fromUtf8("tbxMnemonic"));
        tbxMnemonic->setLineWrapMode(QTextEdit::WidgetWidth);

        gridLayout_2->addWidget(tbxMnemonic, 1, 0, 1, 1);

        mnemonicLayout = new QFormLayout();
        mnemonicLayout->setObjectName(QString::fromUtf8("mnemonicLayout"));
        passwordLabel = new QLabel(tabImport);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        mnemonicLayout->setWidget(0, QFormLayout::LabelRole, passwordLabel);

        edtPassword = new QLineEdit(tabImport);
        edtPassword->setObjectName(QString::fromUtf8("edtPassword"));

        mnemonicLayout->setWidget(0, QFormLayout::FieldRole, edtPassword);

        label_3 = new QLabel(tabImport);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        mnemonicLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(tabImport);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        mnemonicLayout->setWidget(1, QFormLayout::FieldRole, label_2);


        gridLayout_2->addLayout(mnemonicLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnImport = new QPushButton(tabImport);
        btnImport->setObjectName(QString::fromUtf8("btnImport"));
        btnImport->setMinimumSize(QSize(150, 0));
        btnImport->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(btnImport);

        btnGenerate = new QPushButton(tabImport);
        btnGenerate->setObjectName(QString::fromUtf8("btnGenerate"));
        btnGenerate->setMinimumSize(QSize(150, 0));

        horizontalLayout_2->addWidget(btnGenerate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        tabWidget->addTab(tabImport, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(MnemonicDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MnemonicDialog);
    } // setupUi

    void retranslateUi(QDialog *MnemonicDialog)
    {
        MnemonicDialog->setWindowTitle(QApplication::translate("MnemonicDialog", "HD Wallet Setup", nullptr));
        lblHelp->setText(QString());
        mnemonicLabel->setText(QApplication::translate("MnemonicDialog", "Import Recovery Phrase", nullptr));
#ifndef QT_NO_TOOLTIP
        tbxMnemonic->setToolTip(QApplication::translate("MnemonicDialog", "Enter your BIP39 compliant Recovery Phrase/Mnemonic - Typing your own words will probably not work how you expect, since the words require a particular structure (the last word is a checksum).", nullptr));
#endif // QT_NO_TOOLTIP
        passwordLabel->setText(QApplication::translate("MnemonicDialog", "Recovery Passphrase ", nullptr));
#ifndef QT_NO_TOOLTIP
        edtPassword->setToolTip(QApplication::translate("MnemonicDialog", "Enter a passphrase to protect your Recovery Phrase (optional)", nullptr));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MnemonicDialog", "Warning", nullptr));
        label_2->setText(QApplication::translate("MnemonicDialog", "Please ensure you backup your Recovery Phrase and Passphrase - they are not recoverable!", nullptr));
        btnImport->setText(QApplication::translate("MnemonicDialog", "Import", nullptr));
        btnGenerate->setText(QApplication::translate("MnemonicDialog", "Generate", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabImport), QApplication::translate("MnemonicDialog", "Import", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MnemonicDialog: public Ui_MnemonicDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MNEMONICDIALOG_H
