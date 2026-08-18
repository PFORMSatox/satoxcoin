/********************************************************************************
** Form generated from reading UI file 'encryptdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCRYPTDIALOG_H
#define UI_ENCRYPTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EncryptDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *linePwd;
    QLineEdit *linePwdConfirm;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *EncryptDialog)
    {
        if (EncryptDialog->objectName().isEmpty())
            EncryptDialog->setObjectName(QString::fromUtf8("EncryptDialog"));
        EncryptDialog->resize(611, 150);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EncryptDialog->sizePolicy().hasHeightForWidth());
        EncryptDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(EncryptDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(EncryptDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(9);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        linePwd = new QLineEdit(EncryptDialog);
        linePwd->setObjectName(QString::fromUtf8("linePwd"));
        linePwd->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(linePwd);

        linePwdConfirm = new QLineEdit(EncryptDialog);
        linePwdConfirm->setObjectName(QString::fromUtf8("linePwdConfirm"));
        linePwdConfirm->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(linePwdConfirm);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(100);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(100, -1, 100, -1);
        btnOK = new QPushButton(EncryptDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout_5->addWidget(btnOK);

        btnCancel = new QPushButton(EncryptDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_5->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(EncryptDialog);

        QMetaObject::connectSlotsByName(EncryptDialog);
    } // setupUi

    void retranslateUi(QDialog *EncryptDialog)
    {
        EncryptDialog->setWindowTitle(QApplication::translate("EncryptDialog", "Encrypt Wallet", nullptr));
        label_3->setText(QApplication::translate("EncryptDialog", "Please enter a passphrase to encrypt your wallet. This is required. Please use a passphrase of ten or more random characters, or eight or more words.", nullptr));
        linePwd->setPlaceholderText(QApplication::translate("EncryptDialog", "New passphrase", nullptr));
        linePwdConfirm->setPlaceholderText(QApplication::translate("EncryptDialog", "Repeat new passphrase", nullptr));
        btnOK->setText(QApplication::translate("EncryptDialog", "Confirm", nullptr));
#ifndef QT_NO_SHORTCUT
        btnOK->setShortcut(QApplication::translate("EncryptDialog", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        btnCancel->setText(QApplication::translate("EncryptDialog", "Cancel", nullptr));
#ifndef QT_NO_SHORTCUT
        btnCancel->setShortcut(QApplication::translate("EncryptDialog", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
    } // retranslateUi

};

namespace Ui {
    class EncryptDialog: public Ui_EncryptDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCRYPTDIALOG_H
