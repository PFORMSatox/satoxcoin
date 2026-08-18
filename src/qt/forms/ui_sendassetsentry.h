/********************************************************************************
** Form generated from reading UI file 'sendassetsentry.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDASSETSENTRY_H
#define UI_SENDASSETSENTRY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <satoxcoinamountfield.h>
#include "qvalidatedlineedit.h"
#include "satoxcoinamountfield.h"

QT_BEGIN_NAMESPACE

class Ui_SendAssetsEntry
{
public:
    QFrame *SendCoins;
    QGridLayout *gridLayout;
    QLabel *messageTextLabel;
    QLabel *assetAmountLabel;
    QLabel *memoLabel;
    QLabel *amountLabel;
    QLineEdit *addAsLabel;
    QLabel *labellLabel;
    QLabel *ownershipWarningMessage;
    QLabel *assetBoxLabel;
    QHBoxLayout *horizontalLayoutAmount;
    AssetAmountField *payAssetAmount;
    QHBoxLayout *payToLayout;
    QValidatedLineEdit *payTo;
    QToolButton *addressBookButton;
    QToolButton *pasteButton;
    QToolButton *deleteButton;
    QLabel *messageLabel;
    QLabel *payToLabel;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *assetSelectionBox;
    QCheckBox *administratorCheckbox;
    QSpacerItem *horizontalSpacer;
    QLineEdit *memoBox;
    QFrame *SendCoins_UnauthenticatedPaymentRequest;
    QGridLayout *gridLayout_is;
    QLabel *payToLabel_is;
    QHBoxLayout *payToLayout_is;
    QLabel *payTo_is;
    QToolButton *deleteButton_is;
    QLabel *memoLabel_is;
    QLabel *memoTextLabel_is;
    QLabel *amountLabel_is;
    QLineEdit *payAmount_is;
    QFrame *SendCoins_AuthenticatedPaymentRequest;
    QGridLayout *gridLayout_s;
    QLabel *payToLabel_s;
    QHBoxLayout *payToLayout_s;
    QLabel *payTo_s;
    QToolButton *deleteButton_s;
    QLabel *memoLabel_s;
    QLabel *memoTextLabel_s;
    QLabel *amountLabel_s;
    SatoxcoinAmountField *payAmount_s;

    void setupUi(QStackedWidget *SendAssetsEntry)
    {
        if (SendAssetsEntry->objectName().isEmpty())
            SendAssetsEntry->setObjectName(QString::fromUtf8("SendAssetsEntry"));
        SendAssetsEntry->resize(883, 262);
        SendAssetsEntry->setFocusPolicy(Qt::TabFocus);
        SendAssetsEntry->setAutoFillBackground(false);
        SendCoins = new QFrame();
        SendCoins->setObjectName(QString::fromUtf8("SendCoins"));
        SendCoins->setFrameShape(QFrame::NoFrame);
        gridLayout = new QGridLayout(SendCoins);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(12);
        gridLayout->setVerticalSpacing(8);
        gridLayout->setContentsMargins(-1, 8, -1, 4);
        messageTextLabel = new QLabel(SendCoins);
        messageTextLabel->setObjectName(QString::fromUtf8("messageTextLabel"));
        messageTextLabel->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(messageTextLabel, 9, 1, 1, 1);

        assetAmountLabel = new QLabel(SendCoins);
        assetAmountLabel->setObjectName(QString::fromUtf8("assetAmountLabel"));
        assetAmountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(assetAmountLabel, 7, 1, 1, 1);

        memoLabel = new QLabel(SendCoins);
        memoLabel->setObjectName(QString::fromUtf8("memoLabel"));
        memoLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(memoLabel, 5, 0, 1, 1);

        amountLabel = new QLabel(SendCoins);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(amountLabel, 4, 0, 1, 1);

        addAsLabel = new QLineEdit(SendCoins);
        addAsLabel->setObjectName(QString::fromUtf8("addAsLabel"));

        gridLayout->addWidget(addAsLabel, 3, 1, 1, 1);

        labellLabel = new QLabel(SendCoins);
        labellLabel->setObjectName(QString::fromUtf8("labellLabel"));
        labellLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labellLabel, 3, 0, 1, 1);

        ownershipWarningMessage = new QLabel(SendCoins);
        ownershipWarningMessage->setObjectName(QString::fromUtf8("ownershipWarningMessage"));

        gridLayout->addWidget(ownershipWarningMessage, 8, 1, 1, 1);

        assetBoxLabel = new QLabel(SendCoins);
        assetBoxLabel->setObjectName(QString::fromUtf8("assetBoxLabel"));
        assetBoxLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(assetBoxLabel, 1, 0, 1, 1);

        horizontalLayoutAmount = new QHBoxLayout();
        horizontalLayoutAmount->setObjectName(QString::fromUtf8("horizontalLayoutAmount"));
        payAssetAmount = new AssetAmountField(SendCoins);
        payAssetAmount->setObjectName(QString::fromUtf8("payAssetAmount"));

        horizontalLayoutAmount->addWidget(payAssetAmount);


        gridLayout->addLayout(horizontalLayoutAmount, 4, 1, 1, 1);

        payToLayout = new QHBoxLayout();
        payToLayout->setSpacing(0);
        payToLayout->setObjectName(QString::fromUtf8("payToLayout"));
        payTo = new QValidatedLineEdit(SendCoins);
        payTo->setObjectName(QString::fromUtf8("payTo"));

        payToLayout->addWidget(payTo);

        addressBookButton = new QToolButton(SendCoins);
        addressBookButton->setObjectName(QString::fromUtf8("addressBookButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/address-book"), QSize(), QIcon::Normal, QIcon::Off);
        addressBookButton->setIcon(icon);
        addressBookButton->setIconSize(QSize(22, 22));

        payToLayout->addWidget(addressBookButton);

        pasteButton = new QToolButton(SendCoins);
        pasteButton->setObjectName(QString::fromUtf8("pasteButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/editpaste"), QSize(), QIcon::Normal, QIcon::Off);
        pasteButton->setIcon(icon1);
        pasteButton->setIconSize(QSize(22, 22));

        payToLayout->addWidget(pasteButton);

        deleteButton = new QToolButton(SendCoins);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/remove"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon2);
        deleteButton->setIconSize(QSize(22, 22));

        payToLayout->addWidget(deleteButton);


        gridLayout->addLayout(payToLayout, 2, 1, 1, 1);

        messageLabel = new QLabel(SendCoins);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(messageLabel, 10, 0, 1, 1);

        payToLabel = new QLabel(SendCoins);
        payToLabel->setObjectName(QString::fromUtf8("payToLabel"));
        payToLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(payToLabel, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        assetSelectionBox = new QComboBox(SendCoins);
        assetSelectionBox->setObjectName(QString::fromUtf8("assetSelectionBox"));
        assetSelectionBox->setMinimumContentsLength(32);

        horizontalLayout_3->addWidget(assetSelectionBox);

        administratorCheckbox = new QCheckBox(SendCoins);
        administratorCheckbox->setObjectName(QString::fromUtf8("administratorCheckbox"));

        horizontalLayout_3->addWidget(administratorCheckbox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        memoBox = new QLineEdit(SendCoins);
        memoBox->setObjectName(QString::fromUtf8("memoBox"));
        memoBox->setMaxLength(64);

        gridLayout->addWidget(memoBox, 5, 1, 1, 1);

        SendAssetsEntry->addWidget(SendCoins);
        SendCoins_UnauthenticatedPaymentRequest = new QFrame();
        SendCoins_UnauthenticatedPaymentRequest->setObjectName(QString::fromUtf8("SendCoins_UnauthenticatedPaymentRequest"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 255, 191, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 127, 63, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 170, 84, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        SendCoins_UnauthenticatedPaymentRequest->setPalette(palette);
        SendCoins_UnauthenticatedPaymentRequest->setAutoFillBackground(true);
        SendCoins_UnauthenticatedPaymentRequest->setFrameShape(QFrame::NoFrame);
        gridLayout_is = new QGridLayout(SendCoins_UnauthenticatedPaymentRequest);
        gridLayout_is->setSpacing(12);
        gridLayout_is->setObjectName(QString::fromUtf8("gridLayout_is"));
        payToLabel_is = new QLabel(SendCoins_UnauthenticatedPaymentRequest);
        payToLabel_is->setObjectName(QString::fromUtf8("payToLabel_is"));
        payToLabel_is->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_is->addWidget(payToLabel_is, 0, 0, 1, 1);

        payToLayout_is = new QHBoxLayout();
        payToLayout_is->setSpacing(0);
        payToLayout_is->setObjectName(QString::fromUtf8("payToLayout_is"));
        payTo_is = new QLabel(SendCoins_UnauthenticatedPaymentRequest);
        payTo_is->setObjectName(QString::fromUtf8("payTo_is"));

        payToLayout_is->addWidget(payTo_is);

        deleteButton_is = new QToolButton(SendCoins_UnauthenticatedPaymentRequest);
        deleteButton_is->setObjectName(QString::fromUtf8("deleteButton_is"));
        deleteButton_is->setIcon(icon2);

        payToLayout_is->addWidget(deleteButton_is);


        gridLayout_is->addLayout(payToLayout_is, 0, 1, 1, 1);

        memoLabel_is = new QLabel(SendCoins_UnauthenticatedPaymentRequest);
        memoLabel_is->setObjectName(QString::fromUtf8("memoLabel_is"));
        memoLabel_is->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_is->addWidget(memoLabel_is, 1, 0, 1, 1);

        memoTextLabel_is = new QLabel(SendCoins_UnauthenticatedPaymentRequest);
        memoTextLabel_is->setObjectName(QString::fromUtf8("memoTextLabel_is"));
        memoTextLabel_is->setTextFormat(Qt::PlainText);

        gridLayout_is->addWidget(memoTextLabel_is, 1, 1, 1, 1);

        amountLabel_is = new QLabel(SendCoins_UnauthenticatedPaymentRequest);
        amountLabel_is->setObjectName(QString::fromUtf8("amountLabel_is"));
        amountLabel_is->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_is->addWidget(amountLabel_is, 2, 0, 1, 1);

        payAmount_is = new QLineEdit(SendCoins_UnauthenticatedPaymentRequest);
        payAmount_is->setObjectName(QString::fromUtf8("payAmount_is"));
        payAmount_is->setAcceptDrops(false);

        gridLayout_is->addWidget(payAmount_is, 2, 1, 1, 1);

        SendAssetsEntry->addWidget(SendCoins_UnauthenticatedPaymentRequest);
        SendCoins_AuthenticatedPaymentRequest = new QFrame();
        SendCoins_AuthenticatedPaymentRequest->setObjectName(QString::fromUtf8("SendCoins_AuthenticatedPaymentRequest"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush7(QColor(140, 232, 119, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush7);
        QBrush brush8(QColor(230, 255, 224, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush8);
        QBrush brush9(QColor(185, 243, 171, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush9);
        QBrush brush10(QColor(70, 116, 59, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(93, 155, 79, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush12(QColor(155, 255, 147, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush12);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush13(QColor(119, 255, 233, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush14(QColor(197, 243, 187, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        QBrush brush15(QColor(125, 194, 122, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::NoRole, brush15);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::NoRole, brush15);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::NoRole, brush15);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        SendCoins_AuthenticatedPaymentRequest->setPalette(palette1);
        SendCoins_AuthenticatedPaymentRequest->setAutoFillBackground(true);
        SendCoins_AuthenticatedPaymentRequest->setFrameShape(QFrame::NoFrame);
        gridLayout_s = new QGridLayout(SendCoins_AuthenticatedPaymentRequest);
        gridLayout_s->setSpacing(12);
        gridLayout_s->setObjectName(QString::fromUtf8("gridLayout_s"));
        payToLabel_s = new QLabel(SendCoins_AuthenticatedPaymentRequest);
        payToLabel_s->setObjectName(QString::fromUtf8("payToLabel_s"));
        payToLabel_s->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_s->addWidget(payToLabel_s, 0, 0, 1, 1);

        payToLayout_s = new QHBoxLayout();
        payToLayout_s->setSpacing(0);
        payToLayout_s->setObjectName(QString::fromUtf8("payToLayout_s"));
        payTo_s = new QLabel(SendCoins_AuthenticatedPaymentRequest);
        payTo_s->setObjectName(QString::fromUtf8("payTo_s"));
        payTo_s->setTextFormat(Qt::PlainText);

        payToLayout_s->addWidget(payTo_s);

        deleteButton_s = new QToolButton(SendCoins_AuthenticatedPaymentRequest);
        deleteButton_s->setObjectName(QString::fromUtf8("deleteButton_s"));
        deleteButton_s->setIcon(icon2);

        payToLayout_s->addWidget(deleteButton_s);


        gridLayout_s->addLayout(payToLayout_s, 0, 1, 1, 1);

        memoLabel_s = new QLabel(SendCoins_AuthenticatedPaymentRequest);
        memoLabel_s->setObjectName(QString::fromUtf8("memoLabel_s"));
        memoLabel_s->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_s->addWidget(memoLabel_s, 1, 0, 1, 1);

        memoTextLabel_s = new QLabel(SendCoins_AuthenticatedPaymentRequest);
        memoTextLabel_s->setObjectName(QString::fromUtf8("memoTextLabel_s"));
        memoTextLabel_s->setTextFormat(Qt::PlainText);

        gridLayout_s->addWidget(memoTextLabel_s, 1, 1, 1, 1);

        amountLabel_s = new QLabel(SendCoins_AuthenticatedPaymentRequest);
        amountLabel_s->setObjectName(QString::fromUtf8("amountLabel_s"));
        amountLabel_s->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_s->addWidget(amountLabel_s, 2, 0, 1, 1);

        payAmount_s = new SatoxcoinAmountField(SendCoins_AuthenticatedPaymentRequest);
        payAmount_s->setObjectName(QString::fromUtf8("payAmount_s"));
        payAmount_s->setAcceptDrops(false);

        gridLayout_s->addWidget(payAmount_s, 2, 1, 1, 1);

        SendAssetsEntry->addWidget(SendCoins_AuthenticatedPaymentRequest);
#ifndef QT_NO_SHORTCUT
        labellLabel->setBuddy(addAsLabel);
        payToLabel->setBuddy(payTo);
        amountLabel_is->setBuddy(payAmount_is);
        amountLabel_s->setBuddy(payAmount_s);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(payTo, addressBookButton);
        QWidget::setTabOrder(addressBookButton, pasteButton);
        QWidget::setTabOrder(pasteButton, deleteButton);
        QWidget::setTabOrder(deleteButton, addAsLabel);
        QWidget::setTabOrder(addAsLabel, payAmount_is);
        QWidget::setTabOrder(payAmount_is, deleteButton_is);
        QWidget::setTabOrder(deleteButton_is, payAmount_s);
        QWidget::setTabOrder(payAmount_s, deleteButton_s);

        retranslateUi(SendAssetsEntry);

        SendAssetsEntry->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SendAssetsEntry);
    } // setupUi

    void retranslateUi(QStackedWidget *SendAssetsEntry)
    {
#ifndef QT_NO_TOOLTIP
        SendCoins->setToolTip(QApplication::translate("SendAssetsEntry", "This is an asset payment", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        messageTextLabel->setToolTip(QApplication::translate("SendAssetsEntry", "A message that was attached to the satoxcoin: URI which will be stored with the transaction for your reference. Note: This message will not be sent over the Satoxcoin network.", nullptr));
#endif // QT_NO_TOOLTIP
        assetAmountLabel->setText(QString());
        memoLabel->setText(QApplication::translate("SendAssetsEntry", "Memo:", nullptr));
        amountLabel->setText(QApplication::translate("SendAssetsEntry", "Amount:", nullptr));
#ifndef QT_NO_TOOLTIP
        addAsLabel->setToolTip(QApplication::translate("SendAssetsEntry", "Enter a label for this address to add it to the list of used addresses", nullptr));
#endif // QT_NO_TOOLTIP
        labellLabel->setText(QApplication::translate("SendAssetsEntry", "&Label:", nullptr));
        ownershipWarningMessage->setText(QString());
        assetBoxLabel->setText(QApplication::translate("SendAssetsEntry", "Asset:", nullptr));
#ifndef QT_NO_TOOLTIP
        payTo->setToolTip(QApplication::translate("SendAssetsEntry", "The Satoxcoin address to send the payment to", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addressBookButton->setToolTip(QApplication::translate("SendAssetsEntry", "Choose previously used address", nullptr));
#endif // QT_NO_TOOLTIP
        addressBookButton->setText(QString());
#ifndef QT_NO_SHORTCUT
        addressBookButton->setShortcut(QApplication::translate("SendAssetsEntry", "Alt+A", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        pasteButton->setToolTip(QApplication::translate("SendAssetsEntry", "Paste address from clipboard", nullptr));
#endif // QT_NO_TOOLTIP
        pasteButton->setText(QString());
#ifndef QT_NO_SHORTCUT
        pasteButton->setShortcut(QApplication::translate("SendAssetsEntry", "Alt+P", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("SendAssetsEntry", "Remove this entry", nullptr));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QString());
        messageLabel->setText(QApplication::translate("SendAssetsEntry", "Message:", nullptr));
        payToLabel->setText(QApplication::translate("SendAssetsEntry", "Transfer &To:", nullptr));
        administratorCheckbox->setText(QApplication::translate("SendAssetsEntry", "Transfer Administrator Asset", nullptr));
        memoBox->setPlaceholderText(QApplication::translate("SendAssetsEntry", "Put a IPFS or Txid hash here to be sent with the asset transfer", nullptr));
#ifndef QT_NO_TOOLTIP
        SendCoins_UnauthenticatedPaymentRequest->setToolTip(QApplication::translate("SendAssetsEntry", "This is an unauthenticated payment request.", nullptr));
#endif // QT_NO_TOOLTIP
        payToLabel_is->setText(QApplication::translate("SendAssetsEntry", "Transfer to:", nullptr));
#ifndef QT_NO_TOOLTIP
        deleteButton_is->setToolTip(QApplication::translate("SendAssetsEntry", "Remove this entry", nullptr));
#endif // QT_NO_TOOLTIP
        deleteButton_is->setText(QString());
        memoLabel_is->setText(QApplication::translate("SendAssetsEntry", "Memo:", nullptr));
        amountLabel_is->setText(QApplication::translate("SendAssetsEntry", "A&mount:", nullptr));
#ifndef QT_NO_TOOLTIP
        SendCoins_AuthenticatedPaymentRequest->setToolTip(QApplication::translate("SendAssetsEntry", "This is an authenticated payment request.", nullptr));
#endif // QT_NO_TOOLTIP
        payToLabel_s->setText(QApplication::translate("SendAssetsEntry", "Transfer to:", nullptr));
#ifndef QT_NO_TOOLTIP
        deleteButton_s->setToolTip(QApplication::translate("SendAssetsEntry", "Remove this entry", nullptr));
#endif // QT_NO_TOOLTIP
        deleteButton_s->setText(QString());
        memoLabel_s->setText(QApplication::translate("SendAssetsEntry", "Memo:", nullptr));
        amountLabel_s->setText(QApplication::translate("SendAssetsEntry", "A&mount:", nullptr));
        Q_UNUSED(SendAssetsEntry);
    } // retranslateUi

};

namespace Ui {
    class SendAssetsEntry: public Ui_SendAssetsEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDASSETSENTRY_H
