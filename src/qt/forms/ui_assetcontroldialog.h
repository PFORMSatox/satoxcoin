/********************************************************************************
** Form generated from reading UI file 'assetcontroldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSETCONTROLDIALOG_H
#define UI_ASSETCONTROLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <assetcontroltreewidget.h>

QT_BEGIN_NAMESPACE

class Ui_AssetControlDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutTop;
    QFormLayout *formLayoutAssetControl1;
    QLabel *labelAssetControlQuantityText;
    QLabel *labelAssetControlQuantity;
    QLabel *labelAssetControlBytesText;
    QLabel *labelAssetControlBytes;
    QFormLayout *formLayoutAssetControl2;
    QLabel *labelAssetControlAmountText;
    QLabel *labelAssetControlAmount;
    QLabel *labelAssetControlLowOutputText;
    QLabel *labelAssetControlLowOutput;
    QFormLayout *formLayoutAssetControl3;
    QLabel *labelAssetControlFeeText;
    QLabel *labelAssetControlFee;
    QFormLayout *formLayoutAssetControl4;
    QLabel *labelAssetControlAfterFeeText;
    QLabel *labelAssetControlAfterFee;
    QLabel *labelAssetControlChangeText;
    QLabel *labelAssetControlChange;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayoutPanel;
    QPushButton *pushButtonSelectAll;
    QRadioButton *radioTreeMode;
    QRadioButton *radioListMode;
    QLabel *labelLocked;
    QComboBox *assetList;
    QCheckBox *viewAdministrator;
    QSpacerItem *horizontalSpacer;
    AssetControlTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AssetControlDialog)
    {
        if (AssetControlDialog->objectName().isEmpty())
            AssetControlDialog->setObjectName(QString::fromUtf8("AssetControlDialog"));
        AssetControlDialog->resize(1000, 500);
        verticalLayout = new QVBoxLayout(AssetControlDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayoutTop = new QHBoxLayout();
        horizontalLayoutTop->setObjectName(QString::fromUtf8("horizontalLayoutTop"));
        horizontalLayoutTop->setContentsMargins(-1, 0, -1, 10);
        formLayoutAssetControl1 = new QFormLayout();
        formLayoutAssetControl1->setObjectName(QString::fromUtf8("formLayoutAssetControl1"));
        formLayoutAssetControl1->setHorizontalSpacing(10);
        formLayoutAssetControl1->setVerticalSpacing(10);
        formLayoutAssetControl1->setContentsMargins(6, -1, 6, -1);
        labelAssetControlQuantityText = new QLabel(AssetControlDialog);
        labelAssetControlQuantityText->setObjectName(QString::fromUtf8("labelAssetControlQuantityText"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelAssetControlQuantityText->setFont(font);

        formLayoutAssetControl1->setWidget(0, QFormLayout::LabelRole, labelAssetControlQuantityText);

        labelAssetControlQuantity = new QLabel(AssetControlDialog);
        labelAssetControlQuantity->setObjectName(QString::fromUtf8("labelAssetControlQuantity"));
        labelAssetControlQuantity->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlQuantity->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlQuantity->setText(QString::fromUtf8("0"));
        labelAssetControlQuantity->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl1->setWidget(0, QFormLayout::FieldRole, labelAssetControlQuantity);

        labelAssetControlBytesText = new QLabel(AssetControlDialog);
        labelAssetControlBytesText->setObjectName(QString::fromUtf8("labelAssetControlBytesText"));
        labelAssetControlBytesText->setFont(font);

        formLayoutAssetControl1->setWidget(1, QFormLayout::LabelRole, labelAssetControlBytesText);

        labelAssetControlBytes = new QLabel(AssetControlDialog);
        labelAssetControlBytes->setObjectName(QString::fromUtf8("labelAssetControlBytes"));
        labelAssetControlBytes->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlBytes->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlBytes->setText(QString::fromUtf8("0"));
        labelAssetControlBytes->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl1->setWidget(1, QFormLayout::FieldRole, labelAssetControlBytes);


        horizontalLayoutTop->addLayout(formLayoutAssetControl1);

        formLayoutAssetControl2 = new QFormLayout();
        formLayoutAssetControl2->setObjectName(QString::fromUtf8("formLayoutAssetControl2"));
        formLayoutAssetControl2->setHorizontalSpacing(10);
        formLayoutAssetControl2->setVerticalSpacing(10);
        formLayoutAssetControl2->setContentsMargins(6, -1, 6, -1);
        labelAssetControlAmountText = new QLabel(AssetControlDialog);
        labelAssetControlAmountText->setObjectName(QString::fromUtf8("labelAssetControlAmountText"));
        labelAssetControlAmountText->setFont(font);

        formLayoutAssetControl2->setWidget(0, QFormLayout::LabelRole, labelAssetControlAmountText);

        labelAssetControlAmount = new QLabel(AssetControlDialog);
        labelAssetControlAmount->setObjectName(QString::fromUtf8("labelAssetControlAmount"));
        labelAssetControlAmount->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlAmount->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlAmount->setText(QString::fromUtf8("0.00 RVN"));
        labelAssetControlAmount->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl2->setWidget(0, QFormLayout::FieldRole, labelAssetControlAmount);

        labelAssetControlLowOutputText = new QLabel(AssetControlDialog);
        labelAssetControlLowOutputText->setObjectName(QString::fromUtf8("labelAssetControlLowOutputText"));
        labelAssetControlLowOutputText->setEnabled(false);
        labelAssetControlLowOutputText->setFont(font);

        formLayoutAssetControl2->setWidget(1, QFormLayout::LabelRole, labelAssetControlLowOutputText);

        labelAssetControlLowOutput = new QLabel(AssetControlDialog);
        labelAssetControlLowOutput->setObjectName(QString::fromUtf8("labelAssetControlLowOutput"));
        labelAssetControlLowOutput->setEnabled(false);
        labelAssetControlLowOutput->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlLowOutput->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlLowOutput->setText(QString::fromUtf8("no"));
        labelAssetControlLowOutput->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl2->setWidget(1, QFormLayout::FieldRole, labelAssetControlLowOutput);


        horizontalLayoutTop->addLayout(formLayoutAssetControl2);

        formLayoutAssetControl3 = new QFormLayout();
        formLayoutAssetControl3->setObjectName(QString::fromUtf8("formLayoutAssetControl3"));
        formLayoutAssetControl3->setHorizontalSpacing(10);
        formLayoutAssetControl3->setVerticalSpacing(10);
        formLayoutAssetControl3->setContentsMargins(6, -1, 6, -1);
        labelAssetControlFeeText = new QLabel(AssetControlDialog);
        labelAssetControlFeeText->setObjectName(QString::fromUtf8("labelAssetControlFeeText"));
        labelAssetControlFeeText->setFont(font);

        formLayoutAssetControl3->setWidget(0, QFormLayout::LabelRole, labelAssetControlFeeText);

        labelAssetControlFee = new QLabel(AssetControlDialog);
        labelAssetControlFee->setObjectName(QString::fromUtf8("labelAssetControlFee"));
        labelAssetControlFee->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlFee->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlFee->setText(QString::fromUtf8("0.00 RVN"));
        labelAssetControlFee->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl3->setWidget(0, QFormLayout::FieldRole, labelAssetControlFee);


        horizontalLayoutTop->addLayout(formLayoutAssetControl3);

        formLayoutAssetControl4 = new QFormLayout();
        formLayoutAssetControl4->setObjectName(QString::fromUtf8("formLayoutAssetControl4"));
        formLayoutAssetControl4->setHorizontalSpacing(10);
        formLayoutAssetControl4->setVerticalSpacing(10);
        formLayoutAssetControl4->setContentsMargins(6, -1, 6, -1);
        labelAssetControlAfterFeeText = new QLabel(AssetControlDialog);
        labelAssetControlAfterFeeText->setObjectName(QString::fromUtf8("labelAssetControlAfterFeeText"));
        labelAssetControlAfterFeeText->setFont(font);

        formLayoutAssetControl4->setWidget(0, QFormLayout::LabelRole, labelAssetControlAfterFeeText);

        labelAssetControlAfterFee = new QLabel(AssetControlDialog);
        labelAssetControlAfterFee->setObjectName(QString::fromUtf8("labelAssetControlAfterFee"));
        labelAssetControlAfterFee->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlAfterFee->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlAfterFee->setText(QString::fromUtf8("0.00 RVN"));
        labelAssetControlAfterFee->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl4->setWidget(0, QFormLayout::FieldRole, labelAssetControlAfterFee);

        labelAssetControlChangeText = new QLabel(AssetControlDialog);
        labelAssetControlChangeText->setObjectName(QString::fromUtf8("labelAssetControlChangeText"));
        labelAssetControlChangeText->setEnabled(false);
        labelAssetControlChangeText->setFont(font);

        formLayoutAssetControl4->setWidget(1, QFormLayout::LabelRole, labelAssetControlChangeText);

        labelAssetControlChange = new QLabel(AssetControlDialog);
        labelAssetControlChange->setObjectName(QString::fromUtf8("labelAssetControlChange"));
        labelAssetControlChange->setEnabled(false);
        labelAssetControlChange->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlChange->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlChange->setText(QString::fromUtf8("0.00 RVN"));
        labelAssetControlChange->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl4->setWidget(1, QFormLayout::FieldRole, labelAssetControlChange);


        horizontalLayoutTop->addLayout(formLayoutAssetControl4);


        verticalLayout->addLayout(horizontalLayoutTop);

        frame = new QFrame(AssetControlDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 40));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayoutPanel = new QHBoxLayout();
        horizontalLayoutPanel->setSpacing(14);
        horizontalLayoutPanel->setObjectName(QString::fromUtf8("horizontalLayoutPanel"));
        pushButtonSelectAll = new QPushButton(frame);
        pushButtonSelectAll->setObjectName(QString::fromUtf8("pushButtonSelectAll"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonSelectAll->sizePolicy().hasHeightForWidth());
        pushButtonSelectAll->setSizePolicy(sizePolicy);
        pushButtonSelectAll->setAutoDefault(false);

        horizontalLayoutPanel->addWidget(pushButtonSelectAll);

        radioTreeMode = new QRadioButton(frame);
        radioTreeMode->setObjectName(QString::fromUtf8("radioTreeMode"));
        sizePolicy.setHeightForWidth(radioTreeMode->sizePolicy().hasHeightForWidth());
        radioTreeMode->setSizePolicy(sizePolicy);

        horizontalLayoutPanel->addWidget(radioTreeMode);

        radioListMode = new QRadioButton(frame);
        radioListMode->setObjectName(QString::fromUtf8("radioListMode"));
        sizePolicy.setHeightForWidth(radioListMode->sizePolicy().hasHeightForWidth());
        radioListMode->setSizePolicy(sizePolicy);
        radioListMode->setChecked(true);

        horizontalLayoutPanel->addWidget(radioListMode);

        labelLocked = new QLabel(frame);
        labelLocked->setObjectName(QString::fromUtf8("labelLocked"));
        labelLocked->setText(QString::fromUtf8("(1 locked)"));

        horizontalLayoutPanel->addWidget(labelLocked);

        assetList = new QComboBox(frame);
        assetList->setObjectName(QString::fromUtf8("assetList"));
        assetList->setMinimumContentsLength(30);

        horizontalLayoutPanel->addWidget(assetList);

        viewAdministrator = new QCheckBox(frame);
        viewAdministrator->setObjectName(QString::fromUtf8("viewAdministrator"));

        horizontalLayoutPanel->addWidget(viewAdministrator);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutPanel->addItem(horizontalSpacer);


        horizontalLayout->addLayout(horizontalLayoutPanel);


        verticalLayout->addWidget(frame);

        treeWidget = new AssetControlTreeWidget(AssetControlDialog);
        treeWidget->headerItem()->setText(0, QString());
        treeWidget->headerItem()->setText(7, QString());
        treeWidget->headerItem()->setText(8, QString());
        treeWidget->headerItem()->setText(9, QString());
        treeWidget->headerItem()->setText(10, QString());
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        treeWidget->setSortingEnabled(false);
        treeWidget->setColumnCount(11);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(true));
        treeWidget->header()->setStretchLastSection(false);

        verticalLayout->addWidget(treeWidget);

        buttonBox = new QDialogButtonBox(AssetControlDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AssetControlDialog);

        QMetaObject::connectSlotsByName(AssetControlDialog);
    } // setupUi

    void retranslateUi(QDialog *AssetControlDialog)
    {
        AssetControlDialog->setWindowTitle(QApplication::translate("AssetControlDialog", "Asset Selection", nullptr));
        labelAssetControlQuantityText->setText(QApplication::translate("AssetControlDialog", "Quantity:", nullptr));
        labelAssetControlBytesText->setText(QApplication::translate("AssetControlDialog", "Bytes:", nullptr));
        labelAssetControlAmountText->setText(QApplication::translate("AssetControlDialog", "Amount:", nullptr));
        labelAssetControlLowOutputText->setText(QApplication::translate("AssetControlDialog", "Dust:", nullptr));
        labelAssetControlFeeText->setText(QApplication::translate("AssetControlDialog", "Fee:", nullptr));
        labelAssetControlAfterFeeText->setText(QApplication::translate("AssetControlDialog", "After Fee:", nullptr));
        labelAssetControlChangeText->setText(QApplication::translate("AssetControlDialog", "Change:", nullptr));
        pushButtonSelectAll->setText(QApplication::translate("AssetControlDialog", "(un)select all", nullptr));
        radioTreeMode->setText(QApplication::translate("AssetControlDialog", "Tree mode", nullptr));
        radioListMode->setText(QApplication::translate("AssetControlDialog", "List mode", nullptr));
#ifndef QT_NO_TOOLTIP
        viewAdministrator->setToolTip(QApplication::translate("AssetControlDialog", "View assets that you have the ownership asset for", nullptr));
#endif // QT_NO_TOOLTIP
        viewAdministrator->setText(QApplication::translate("AssetControlDialog", "View Administrator Assets", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(6, QApplication::translate("AssetControlDialog", "Confirmations", nullptr));
        ___qtreewidgetitem->setText(5, QApplication::translate("AssetControlDialog", "Date", nullptr));
        ___qtreewidgetitem->setText(4, QApplication::translate("AssetControlDialog", "Received with address", nullptr));
        ___qtreewidgetitem->setText(3, QApplication::translate("AssetControlDialog", "Received with label", nullptr));
        ___qtreewidgetitem->setText(2, QApplication::translate("AssetControlDialog", "Amount", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("AssetControlDialog", "Asset", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qtreewidgetitem->setToolTip(6, QApplication::translate("AssetControlDialog", "Confirmed", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class AssetControlDialog: public Ui_AssetControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSETCONTROLDIALOG_H
