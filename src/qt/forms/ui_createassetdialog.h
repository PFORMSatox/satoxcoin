/********************************************************************************
** Form generated from reading UI file 'createassetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEASSETDIALOG_H
#define UI_CREATEASSETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvalidatedlineedit.h"
#include "satoxcoinamountfield.h"

QT_BEGIN_NAMESPACE

class Ui_CreateAssetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QFrame *frameCoinControl;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayoutCoinControl;
    QHBoxLayout *horizontalLayoutCoinControl1;
    QLabel *labelCoinControlFeatures;
    QHBoxLayout *horizontalLayoutCoinControl2;
    QPushButton *pushButtonCoinControl;
    QLabel *labelCoinControlAutomaticallySelected;
    QLabel *labelCoinControlInsuffFunds;
    QSpacerItem *horizontalSpacerCoinControl;
    QWidget *widgetCoinControl;
    QHBoxLayout *horizontalLayoutCoinControl5;
    QHBoxLayout *horizontalLayoutCoinControl3;
    QFormLayout *formLayoutCoinControl1;
    QLabel *labelCoinControlQuantityText;
    QLabel *labelCoinControlQuantity;
    QLabel *labelCoinControlBytesText;
    QLabel *labelCoinControlBytes;
    QFormLayout *formLayoutCoinControl2;
    QLabel *labelCoinControlAmountText;
    QLabel *labelCoinControlAmount;
    QLabel *labelCoinControlLowOutputText;
    QLabel *labelCoinControlLowOutput;
    QFormLayout *formLayoutCoinControl3;
    QLabel *labelCoinControlFeeText;
    QLabel *labelCoinControlFee;
    QFormLayout *formLayoutCoinControl4;
    QLabel *labelCoinControlAfterFeeText;
    QLabel *labelCoinControlAfterFee;
    QLabel *labelCoinControlChangeText;
    QLabel *labelCoinControlChange;
    QHBoxLayout *horizontalLayoutCoinControl4;
    QCheckBox *checkBoxCoinControlChange;
    QValidatedLineEdit *lineEditCoinControlChange;
    QLabel *labelCoinControlChangeLabel;
    QSpacerItem *verticalSpacerCoinControl;
    QFrame *frameAssetData;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *assetTypeLabel;
    QComboBox *assetType;
    QComboBox *assetList;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *assetNameLabel;
    QLineEdit *nameText;
    QLabel *assetFullName;
    QPushButton *availabilityButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *addressLabel;
    QLineEdit *addressText;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelVerifierString;
    QLineEdit *lineEditVerifierString;
    QLabel *labelVerifierStringErrorMessage;
    QHBoxLayout *horizontalLayout_2;
    QLabel *quantityLabel;
    QDoubleSpinBox *quantitySpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *unitsLabel;
    QSpinBox *unitBox;
    QLabel *unitExampleLabel;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *reissuableBox;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *ipfsBox;
    QLineEdit *ipfsText;
    QPushButton *openIpfsButton;
    QLabel *messageLabel;
    QSpacerItem *verticalSpacer;
    QFrame *frameFee;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayoutFee2;
    QHBoxLayout *horizontalLayoutFee1;
    QVBoxLayout *verticalLayoutFee7;
    QSpacerItem *verticalSpacerSmartFee;
    QHBoxLayout *horizontalLayoutSmartFee;
    QLabel *labelFeeHeadline;
    QLabel *labelFeeMinimized;
    QPushButton *buttonChooseFee;
    QSpacerItem *verticalSpacer_5;
    QLabel *fallbackFeeWarningLabel;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *buttonMinimizeFee;
    QFrame *frameFeeSelection;
    QVBoxLayout *verticalLayoutFee12;
    QGridLayout *gridLayoutFee;
    QVBoxLayout *verticalLayoutFee8;
    QHBoxLayout *horizontalLayoutFee13;
    QLabel *labelCustomPerKilobyte;
    SatoxcoinAmountField *customFee;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayoutFee8;
    QCheckBox *checkBoxMinimumFee;
    QLabel *labelMinFeeWarning;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayoutFee4;
    QRadioButton *radioSmartFee;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayoutFee9;
    QRadioButton *radioCustomFee;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayoutFee3;
    QHBoxLayout *horizontalLayoutFee12;
    QLabel *labelSmartFee;
    QLabel *labelFeeEstimation;
    QLabel *labelSmartFee2;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayoutFee9;
    QVBoxLayout *verticalLayoutFee6;
    QLabel *labelSmartFee3;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayoutFee5;
    QHBoxLayout *horizontalLayoutConfTarget;
    QComboBox *confTargetSelector;
    QSpacerItem *horizontalSpacerConfTarget;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *optInRBF;
    QSpacerItem *verticalSpacerFee;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *createAssetButton;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLabel *labelBalance;
    QButtonGroup *groupFee;

    void setupUi(QDialog *CreateAssetDialog)
    {
        if (CreateAssetDialog->objectName().isEmpty())
            CreateAssetDialog->setObjectName(QString::fromUtf8("CreateAssetDialog"));
        CreateAssetDialog->setWindowModality(Qt::NonModal);
        CreateAssetDialog->resize(941, 1120);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateAssetDialog->sizePolicy().hasHeightForWidth());
        CreateAssetDialog->setSizePolicy(sizePolicy);
        CreateAssetDialog->setWindowTitle(QString::fromUtf8("Asset Creation Form"));
        CreateAssetDialog->setSizeGripEnabled(false);
        CreateAssetDialog->setModal(false);
        verticalLayout = new QVBoxLayout(CreateAssetDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(20);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(20, 20, 20, 20);
        frameCoinControl = new QFrame(CreateAssetDialog);
        frameCoinControl->setObjectName(QString::fromUtf8("frameCoinControl"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frameCoinControl->sizePolicy().hasHeightForWidth());
        frameCoinControl->setSizePolicy(sizePolicy1);
        frameCoinControl->setFrameShape(QFrame::StyledPanel);
        frameCoinControl->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameCoinControl);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayoutCoinControl = new QVBoxLayout();
        verticalLayoutCoinControl->setSpacing(0);
        verticalLayoutCoinControl->setObjectName(QString::fromUtf8("verticalLayoutCoinControl"));
        verticalLayoutCoinControl->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayoutCoinControl->setContentsMargins(10, 10, -1, -1);
        horizontalLayoutCoinControl1 = new QHBoxLayout();
        horizontalLayoutCoinControl1->setObjectName(QString::fromUtf8("horizontalLayoutCoinControl1"));
        horizontalLayoutCoinControl1->setContentsMargins(-1, -1, -1, 15);
        labelCoinControlFeatures = new QLabel(frameCoinControl);
        labelCoinControlFeatures->setObjectName(QString::fromUtf8("labelCoinControlFeatures"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelCoinControlFeatures->sizePolicy().hasHeightForWidth());
        labelCoinControlFeatures->setSizePolicy(sizePolicy2);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelCoinControlFeatures->setFont(font);
        labelCoinControlFeatures->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        horizontalLayoutCoinControl1->addWidget(labelCoinControlFeatures);


        verticalLayoutCoinControl->addLayout(horizontalLayoutCoinControl1);

        horizontalLayoutCoinControl2 = new QHBoxLayout();
        horizontalLayoutCoinControl2->setSpacing(8);
        horizontalLayoutCoinControl2->setObjectName(QString::fromUtf8("horizontalLayoutCoinControl2"));
        horizontalLayoutCoinControl2->setContentsMargins(-1, -1, -1, 10);
        pushButtonCoinControl = new QPushButton(frameCoinControl);
        pushButtonCoinControl->setObjectName(QString::fromUtf8("pushButtonCoinControl"));
        pushButtonCoinControl->setStyleSheet(QString::fromUtf8(""));
        pushButtonCoinControl->setAutoDefault(false);

        horizontalLayoutCoinControl2->addWidget(pushButtonCoinControl);

        labelCoinControlAutomaticallySelected = new QLabel(frameCoinControl);
        labelCoinControlAutomaticallySelected->setObjectName(QString::fromUtf8("labelCoinControlAutomaticallySelected"));
        labelCoinControlAutomaticallySelected->setMargin(5);

        horizontalLayoutCoinControl2->addWidget(labelCoinControlAutomaticallySelected);

        labelCoinControlInsuffFunds = new QLabel(frameCoinControl);
        labelCoinControlInsuffFunds->setObjectName(QString::fromUtf8("labelCoinControlInsuffFunds"));
        labelCoinControlInsuffFunds->setFont(font);
        labelCoinControlInsuffFunds->setStyleSheet(QString::fromUtf8("color:red;font-weight:bold;"));
        labelCoinControlInsuffFunds->setMargin(5);

        horizontalLayoutCoinControl2->addWidget(labelCoinControlInsuffFunds);

        horizontalSpacerCoinControl = new QSpacerItem(40, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutCoinControl2->addItem(horizontalSpacerCoinControl);


        verticalLayoutCoinControl->addLayout(horizontalLayoutCoinControl2);

        widgetCoinControl = new QWidget(frameCoinControl);
        widgetCoinControl->setObjectName(QString::fromUtf8("widgetCoinControl"));
        sizePolicy.setHeightForWidth(widgetCoinControl->sizePolicy().hasHeightForWidth());
        widgetCoinControl->setSizePolicy(sizePolicy);
        widgetCoinControl->setMinimumSize(QSize(0, 0));
        widgetCoinControl->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutCoinControl5 = new QHBoxLayout(widgetCoinControl);
        horizontalLayoutCoinControl5->setObjectName(QString::fromUtf8("horizontalLayoutCoinControl5"));
        horizontalLayoutCoinControl5->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutCoinControl3 = new QHBoxLayout();
        horizontalLayoutCoinControl3->setSpacing(20);
        horizontalLayoutCoinControl3->setObjectName(QString::fromUtf8("horizontalLayoutCoinControl3"));
        horizontalLayoutCoinControl3->setContentsMargins(-1, 0, -1, 10);
        formLayoutCoinControl1 = new QFormLayout();
        formLayoutCoinControl1->setObjectName(QString::fromUtf8("formLayoutCoinControl1"));
        formLayoutCoinControl1->setHorizontalSpacing(10);
        formLayoutCoinControl1->setVerticalSpacing(14);
        formLayoutCoinControl1->setContentsMargins(10, 4, 6, -1);
        labelCoinControlQuantityText = new QLabel(widgetCoinControl);
        labelCoinControlQuantityText->setObjectName(QString::fromUtf8("labelCoinControlQuantityText"));
        labelCoinControlQuantityText->setFont(font);
        labelCoinControlQuantityText->setMargin(0);

        formLayoutCoinControl1->setWidget(0, QFormLayout::LabelRole, labelCoinControlQuantityText);

        labelCoinControlQuantity = new QLabel(widgetCoinControl);
        labelCoinControlQuantity->setObjectName(QString::fromUtf8("labelCoinControlQuantity"));
        labelCoinControlQuantity->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlQuantity->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlQuantity->setText(QString::fromUtf8("0"));
        labelCoinControlQuantity->setMargin(0);
        labelCoinControlQuantity->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl1->setWidget(0, QFormLayout::FieldRole, labelCoinControlQuantity);

        labelCoinControlBytesText = new QLabel(widgetCoinControl);
        labelCoinControlBytesText->setObjectName(QString::fromUtf8("labelCoinControlBytesText"));
        labelCoinControlBytesText->setFont(font);

        formLayoutCoinControl1->setWidget(1, QFormLayout::LabelRole, labelCoinControlBytesText);

        labelCoinControlBytes = new QLabel(widgetCoinControl);
        labelCoinControlBytes->setObjectName(QString::fromUtf8("labelCoinControlBytes"));
        labelCoinControlBytes->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlBytes->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlBytes->setText(QString::fromUtf8("0"));
        labelCoinControlBytes->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl1->setWidget(1, QFormLayout::FieldRole, labelCoinControlBytes);


        horizontalLayoutCoinControl3->addLayout(formLayoutCoinControl1);

        formLayoutCoinControl2 = new QFormLayout();
        formLayoutCoinControl2->setObjectName(QString::fromUtf8("formLayoutCoinControl2"));
        formLayoutCoinControl2->setHorizontalSpacing(10);
        formLayoutCoinControl2->setVerticalSpacing(14);
        formLayoutCoinControl2->setContentsMargins(6, 4, 6, -1);
        labelCoinControlAmountText = new QLabel(widgetCoinControl);
        labelCoinControlAmountText->setObjectName(QString::fromUtf8("labelCoinControlAmountText"));
        labelCoinControlAmountText->setFont(font);
        labelCoinControlAmountText->setMargin(0);

        formLayoutCoinControl2->setWidget(0, QFormLayout::LabelRole, labelCoinControlAmountText);

        labelCoinControlAmount = new QLabel(widgetCoinControl);
        labelCoinControlAmount->setObjectName(QString::fromUtf8("labelCoinControlAmount"));
        labelCoinControlAmount->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlAmount->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlAmount->setText(QString::fromUtf8("0.00 RVN"));
        labelCoinControlAmount->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl2->setWidget(0, QFormLayout::FieldRole, labelCoinControlAmount);

        labelCoinControlLowOutputText = new QLabel(widgetCoinControl);
        labelCoinControlLowOutputText->setObjectName(QString::fromUtf8("labelCoinControlLowOutputText"));
        labelCoinControlLowOutputText->setFont(font);

        formLayoutCoinControl2->setWidget(1, QFormLayout::LabelRole, labelCoinControlLowOutputText);

        labelCoinControlLowOutput = new QLabel(widgetCoinControl);
        labelCoinControlLowOutput->setObjectName(QString::fromUtf8("labelCoinControlLowOutput"));
        labelCoinControlLowOutput->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlLowOutput->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlLowOutput->setText(QString::fromUtf8("no"));
        labelCoinControlLowOutput->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl2->setWidget(1, QFormLayout::FieldRole, labelCoinControlLowOutput);


        horizontalLayoutCoinControl3->addLayout(formLayoutCoinControl2);

        formLayoutCoinControl3 = new QFormLayout();
        formLayoutCoinControl3->setObjectName(QString::fromUtf8("formLayoutCoinControl3"));
        formLayoutCoinControl3->setHorizontalSpacing(10);
        formLayoutCoinControl3->setVerticalSpacing(14);
        formLayoutCoinControl3->setContentsMargins(6, 4, 6, -1);
        labelCoinControlFeeText = new QLabel(widgetCoinControl);
        labelCoinControlFeeText->setObjectName(QString::fromUtf8("labelCoinControlFeeText"));
        labelCoinControlFeeText->setFont(font);
        labelCoinControlFeeText->setMargin(0);

        formLayoutCoinControl3->setWidget(0, QFormLayout::LabelRole, labelCoinControlFeeText);

        labelCoinControlFee = new QLabel(widgetCoinControl);
        labelCoinControlFee->setObjectName(QString::fromUtf8("labelCoinControlFee"));
        labelCoinControlFee->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlFee->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlFee->setText(QString::fromUtf8("0.00 RVN"));
        labelCoinControlFee->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl3->setWidget(0, QFormLayout::FieldRole, labelCoinControlFee);


        horizontalLayoutCoinControl3->addLayout(formLayoutCoinControl3);

        formLayoutCoinControl4 = new QFormLayout();
        formLayoutCoinControl4->setObjectName(QString::fromUtf8("formLayoutCoinControl4"));
        formLayoutCoinControl4->setHorizontalSpacing(10);
        formLayoutCoinControl4->setVerticalSpacing(14);
        formLayoutCoinControl4->setContentsMargins(6, 4, 6, -1);
        labelCoinControlAfterFeeText = new QLabel(widgetCoinControl);
        labelCoinControlAfterFeeText->setObjectName(QString::fromUtf8("labelCoinControlAfterFeeText"));
        labelCoinControlAfterFeeText->setFont(font);
        labelCoinControlAfterFeeText->setMargin(0);

        formLayoutCoinControl4->setWidget(0, QFormLayout::LabelRole, labelCoinControlAfterFeeText);

        labelCoinControlAfterFee = new QLabel(widgetCoinControl);
        labelCoinControlAfterFee->setObjectName(QString::fromUtf8("labelCoinControlAfterFee"));
        labelCoinControlAfterFee->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlAfterFee->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlAfterFee->setText(QString::fromUtf8("0.00 RVN"));
        labelCoinControlAfterFee->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl4->setWidget(0, QFormLayout::FieldRole, labelCoinControlAfterFee);

        labelCoinControlChangeText = new QLabel(widgetCoinControl);
        labelCoinControlChangeText->setObjectName(QString::fromUtf8("labelCoinControlChangeText"));
        labelCoinControlChangeText->setFont(font);

        formLayoutCoinControl4->setWidget(1, QFormLayout::LabelRole, labelCoinControlChangeText);

        labelCoinControlChange = new QLabel(widgetCoinControl);
        labelCoinControlChange->setObjectName(QString::fromUtf8("labelCoinControlChange"));
        labelCoinControlChange->setCursor(QCursor(Qt::IBeamCursor));
        labelCoinControlChange->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelCoinControlChange->setText(QString::fromUtf8("0.00 RVN"));
        labelCoinControlChange->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutCoinControl4->setWidget(1, QFormLayout::FieldRole, labelCoinControlChange);


        horizontalLayoutCoinControl3->addLayout(formLayoutCoinControl4);

        horizontalLayoutCoinControl3->setStretch(3, 1);

        horizontalLayoutCoinControl5->addLayout(horizontalLayoutCoinControl3);


        verticalLayoutCoinControl->addWidget(widgetCoinControl);

        horizontalLayoutCoinControl4 = new QHBoxLayout();
        horizontalLayoutCoinControl4->setSpacing(12);
        horizontalLayoutCoinControl4->setObjectName(QString::fromUtf8("horizontalLayoutCoinControl4"));
        horizontalLayoutCoinControl4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayoutCoinControl4->setContentsMargins(-1, 5, 5, -1);
        checkBoxCoinControlChange = new QCheckBox(frameCoinControl);
        checkBoxCoinControlChange->setObjectName(QString::fromUtf8("checkBoxCoinControlChange"));

        horizontalLayoutCoinControl4->addWidget(checkBoxCoinControlChange);

        lineEditCoinControlChange = new QValidatedLineEdit(frameCoinControl);
        lineEditCoinControlChange->setObjectName(QString::fromUtf8("lineEditCoinControlChange"));
        lineEditCoinControlChange->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEditCoinControlChange->sizePolicy().hasHeightForWidth());
        lineEditCoinControlChange->setSizePolicy(sizePolicy1);

        horizontalLayoutCoinControl4->addWidget(lineEditCoinControlChange);

        labelCoinControlChangeLabel = new QLabel(frameCoinControl);
        labelCoinControlChangeLabel->setObjectName(QString::fromUtf8("labelCoinControlChangeLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelCoinControlChangeLabel->sizePolicy().hasHeightForWidth());
        labelCoinControlChangeLabel->setSizePolicy(sizePolicy3);
        labelCoinControlChangeLabel->setMinimumSize(QSize(0, 0));
        labelCoinControlChangeLabel->setMargin(3);

        horizontalLayoutCoinControl4->addWidget(labelCoinControlChangeLabel);


        verticalLayoutCoinControl->addLayout(horizontalLayoutCoinControl4);

        verticalSpacerCoinControl = new QSpacerItem(800, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutCoinControl->addItem(verticalSpacerCoinControl);


        verticalLayout_2->addLayout(verticalLayoutCoinControl);


        verticalLayout_5->addWidget(frameCoinControl);

        frameAssetData = new QFrame(CreateAssetDialog);
        frameAssetData->setObjectName(QString::fromUtf8("frameAssetData"));
        frameAssetData->setMinimumSize(QSize(0, 220));
        frameAssetData->setFrameShape(QFrame::StyledPanel);
        frameAssetData->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frameAssetData);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        assetTypeLabel = new QLabel(frameAssetData);
        assetTypeLabel->setObjectName(QString::fromUtf8("assetTypeLabel"));

        horizontalLayout_10->addWidget(assetTypeLabel);

        assetType = new QComboBox(frameAssetData);
        assetType->setObjectName(QString::fromUtf8("assetType"));

        horizontalLayout_10->addWidget(assetType);

        assetList = new QComboBox(frameAssetData);
        assetList->setObjectName(QString::fromUtf8("assetList"));

        horizontalLayout_10->addWidget(assetList);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        assetNameLabel = new QLabel(frameAssetData);
        assetNameLabel->setObjectName(QString::fromUtf8("assetNameLabel"));

        horizontalLayout->addWidget(assetNameLabel);

        nameText = new QLineEdit(frameAssetData);
        nameText->setObjectName(QString::fromUtf8("nameText"));
        nameText->setMaxLength(30);

        horizontalLayout->addWidget(nameText);

        assetFullName = new QLabel(frameAssetData);
        assetFullName->setObjectName(QString::fromUtf8("assetFullName"));
        assetFullName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(assetFullName);

        availabilityButton = new QPushButton(frameAssetData);
        availabilityButton->setObjectName(QString::fromUtf8("availabilityButton"));

        horizontalLayout->addWidget(availabilityButton);


        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        addressLabel = new QLabel(frameAssetData);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        horizontalLayout_3->addWidget(addressLabel);

        addressText = new QLineEdit(frameAssetData);
        addressText->setObjectName(QString::fromUtf8("addressText"));

        horizontalLayout_3->addWidget(addressText);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        labelVerifierString = new QLabel(frameAssetData);
        labelVerifierString->setObjectName(QString::fromUtf8("labelVerifierString"));

        horizontalLayout_9->addWidget(labelVerifierString);

        lineEditVerifierString = new QLineEdit(frameAssetData);
        lineEditVerifierString->setObjectName(QString::fromUtf8("lineEditVerifierString"));

        horizontalLayout_9->addWidget(lineEditVerifierString);


        verticalLayout_6->addLayout(horizontalLayout_9);

        labelVerifierStringErrorMessage = new QLabel(frameAssetData);
        labelVerifierStringErrorMessage->setObjectName(QString::fromUtf8("labelVerifierStringErrorMessage"));

        verticalLayout_6->addWidget(labelVerifierStringErrorMessage);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        quantityLabel = new QLabel(frameAssetData);
        quantityLabel->setObjectName(QString::fromUtf8("quantityLabel"));

        horizontalLayout_2->addWidget(quantityLabel);

        quantitySpinBox = new QDoubleSpinBox(frameAssetData);
        quantitySpinBox->setObjectName(QString::fromUtf8("quantitySpinBox"));
        quantitySpinBox->setDecimals(0);
        quantitySpinBox->setMinimum(1.000000000000000);
        quantitySpinBox->setMaximum(21000000000.000000000000000);
        quantitySpinBox->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(quantitySpinBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        unitsLabel = new QLabel(frameAssetData);
        unitsLabel->setObjectName(QString::fromUtf8("unitsLabel"));

        horizontalLayout_4->addWidget(unitsLabel);

        unitBox = new QSpinBox(frameAssetData);
        unitBox->setObjectName(QString::fromUtf8("unitBox"));
        unitBox->setMaximum(8);

        horizontalLayout_4->addWidget(unitBox);

        unitExampleLabel = new QLabel(frameAssetData);
        unitExampleLabel->setObjectName(QString::fromUtf8("unitExampleLabel"));

        horizontalLayout_4->addWidget(unitExampleLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        reissuableBox = new QCheckBox(frameAssetData);
        reissuableBox->setObjectName(QString::fromUtf8("reissuableBox"));

        horizontalLayout_5->addWidget(reissuableBox);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ipfsBox = new QCheckBox(frameAssetData);
        ipfsBox->setObjectName(QString::fromUtf8("ipfsBox"));

        horizontalLayout_6->addWidget(ipfsBox);

        ipfsText = new QLineEdit(frameAssetData);
        ipfsText->setObjectName(QString::fromUtf8("ipfsText"));
        ipfsText->setMaxLength(64);

        horizontalLayout_6->addWidget(ipfsText);

        openIpfsButton = new QPushButton(frameAssetData);
        openIpfsButton->setObjectName(QString::fromUtf8("openIpfsButton"));

        horizontalLayout_6->addWidget(openIpfsButton);


        verticalLayout_6->addLayout(horizontalLayout_6);

        messageLabel = new QLabel(frameAssetData);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setStyleSheet(QString::fromUtf8("color: red"));

        verticalLayout_6->addWidget(messageLabel);

        verticalSpacer = new QSpacerItem(20, 1000, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_6);


        verticalLayout_5->addWidget(frameAssetData);

        frameFee = new QFrame(CreateAssetDialog);
        frameFee->setObjectName(QString::fromUtf8("frameFee"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frameFee->sizePolicy().hasHeightForWidth());
        frameFee->setSizePolicy(sizePolicy4);
        frameFee->setFrameShape(QFrame::StyledPanel);
        frameFee->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frameFee);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayoutFee2 = new QVBoxLayout();
        verticalLayoutFee2->setSpacing(0);
        verticalLayoutFee2->setObjectName(QString::fromUtf8("verticalLayoutFee2"));
        verticalLayoutFee2->setContentsMargins(10, 0, -1, -1);
        horizontalLayoutFee1 = new QHBoxLayout();
        horizontalLayoutFee1->setObjectName(QString::fromUtf8("horizontalLayoutFee1"));
        horizontalLayoutFee1->setContentsMargins(-1, -1, -1, 0);
        verticalLayoutFee7 = new QVBoxLayout();
        verticalLayoutFee7->setSpacing(0);
        verticalLayoutFee7->setObjectName(QString::fromUtf8("verticalLayoutFee7"));
        verticalSpacerSmartFee = new QSpacerItem(1, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayoutFee7->addItem(verticalSpacerSmartFee);

        horizontalLayoutSmartFee = new QHBoxLayout();
        horizontalLayoutSmartFee->setSpacing(10);
        horizontalLayoutSmartFee->setObjectName(QString::fromUtf8("horizontalLayoutSmartFee"));
        labelFeeHeadline = new QLabel(frameFee);
        labelFeeHeadline->setObjectName(QString::fromUtf8("labelFeeHeadline"));
        sizePolicy2.setHeightForWidth(labelFeeHeadline->sizePolicy().hasHeightForWidth());
        labelFeeHeadline->setSizePolicy(sizePolicy2);
        labelFeeHeadline->setFont(font);
        labelFeeHeadline->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        horizontalLayoutSmartFee->addWidget(labelFeeHeadline);

        labelFeeMinimized = new QLabel(frameFee);
        labelFeeMinimized->setObjectName(QString::fromUtf8("labelFeeMinimized"));

        horizontalLayoutSmartFee->addWidget(labelFeeMinimized);

        buttonChooseFee = new QPushButton(frameFee);
        buttonChooseFee->setObjectName(QString::fromUtf8("buttonChooseFee"));

        horizontalLayoutSmartFee->addWidget(buttonChooseFee);


        verticalLayoutFee7->addLayout(horizontalLayoutSmartFee);

        verticalSpacer_5 = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutFee7->addItem(verticalSpacer_5);


        horizontalLayoutFee1->addLayout(verticalLayoutFee7);

        fallbackFeeWarningLabel = new QLabel(frameFee);
        fallbackFeeWarningLabel->setObjectName(QString::fromUtf8("fallbackFeeWarningLabel"));
        fallbackFeeWarningLabel->setFont(font);
        fallbackFeeWarningLabel->setWordWrap(false);

        horizontalLayoutFee1->addWidget(fallbackFeeWarningLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayoutFee1->addItem(horizontalSpacer_5);

        buttonMinimizeFee = new QPushButton(frameFee);
        buttonMinimizeFee->setObjectName(QString::fromUtf8("buttonMinimizeFee"));

        horizontalLayoutFee1->addWidget(buttonMinimizeFee);


        verticalLayoutFee2->addLayout(horizontalLayoutFee1);

        frameFeeSelection = new QFrame(frameFee);
        frameFeeSelection->setObjectName(QString::fromUtf8("frameFeeSelection"));
        verticalLayoutFee12 = new QVBoxLayout(frameFeeSelection);
        verticalLayoutFee12->setSpacing(0);
        verticalLayoutFee12->setObjectName(QString::fromUtf8("verticalLayoutFee12"));
        verticalLayoutFee12->setContentsMargins(0, 0, 0, 0);
        gridLayoutFee = new QGridLayout();
        gridLayoutFee->setObjectName(QString::fromUtf8("gridLayoutFee"));
        gridLayoutFee->setHorizontalSpacing(10);
        gridLayoutFee->setVerticalSpacing(4);
        gridLayoutFee->setContentsMargins(-1, 10, -1, 4);
        verticalLayoutFee8 = new QVBoxLayout();
        verticalLayoutFee8->setSpacing(6);
        verticalLayoutFee8->setObjectName(QString::fromUtf8("verticalLayoutFee8"));
        horizontalLayoutFee13 = new QHBoxLayout();
        horizontalLayoutFee13->setObjectName(QString::fromUtf8("horizontalLayoutFee13"));
        labelCustomPerKilobyte = new QLabel(frameFeeSelection);
        labelCustomPerKilobyte->setObjectName(QString::fromUtf8("labelCustomPerKilobyte"));

        horizontalLayoutFee13->addWidget(labelCustomPerKilobyte);

        customFee = new SatoxcoinAmountField(frameFeeSelection);
        customFee->setObjectName(QString::fromUtf8("customFee"));

        horizontalLayoutFee13->addWidget(customFee);

        horizontalSpacer_6 = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutFee13->addItem(horizontalSpacer_6);


        verticalLayoutFee8->addLayout(horizontalLayoutFee13);

        horizontalLayoutFee8 = new QHBoxLayout();
        horizontalLayoutFee8->setObjectName(QString::fromUtf8("horizontalLayoutFee8"));
        checkBoxMinimumFee = new QCheckBox(frameFeeSelection);
        checkBoxMinimumFee->setObjectName(QString::fromUtf8("checkBoxMinimumFee"));

        horizontalLayoutFee8->addWidget(checkBoxMinimumFee);

        labelMinFeeWarning = new QLabel(frameFeeSelection);
        labelMinFeeWarning->setObjectName(QString::fromUtf8("labelMinFeeWarning"));
        labelMinFeeWarning->setEnabled(true);
        labelMinFeeWarning->setMargin(5);

        horizontalLayoutFee8->addWidget(labelMinFeeWarning);

        horizontalSpacer_7 = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutFee8->addItem(horizontalSpacer_7);


        verticalLayoutFee8->addLayout(horizontalLayoutFee8);


        gridLayoutFee->addLayout(verticalLayoutFee8, 1, 1, 1, 1);

        verticalLayoutFee4 = new QVBoxLayout();
        verticalLayoutFee4->setObjectName(QString::fromUtf8("verticalLayoutFee4"));
        radioSmartFee = new QRadioButton(frameFeeSelection);
        groupFee = new QButtonGroup(CreateAssetDialog);
        groupFee->setObjectName(QString::fromUtf8("groupFee"));
        groupFee->addButton(radioSmartFee);
        radioSmartFee->setObjectName(QString::fromUtf8("radioSmartFee"));
        radioSmartFee->setChecked(true);

        verticalLayoutFee4->addWidget(radioSmartFee);

        verticalSpacer_2 = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutFee4->addItem(verticalSpacer_2);

        verticalLayoutFee4->setStretch(1, 1);

        gridLayoutFee->addLayout(verticalLayoutFee4, 0, 0, 1, 1);

        verticalLayoutFee9 = new QVBoxLayout();
        verticalLayoutFee9->setObjectName(QString::fromUtf8("verticalLayoutFee9"));
        radioCustomFee = new QRadioButton(frameFeeSelection);
        groupFee->addButton(radioCustomFee);
        radioCustomFee->setObjectName(QString::fromUtf8("radioCustomFee"));

        verticalLayoutFee9->addWidget(radioCustomFee);

        verticalSpacer_6 = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutFee9->addItem(verticalSpacer_6);

        verticalLayoutFee9->setStretch(1, 1);

        gridLayoutFee->addLayout(verticalLayoutFee9, 1, 0, 1, 1);

        verticalLayoutFee3 = new QVBoxLayout();
        verticalLayoutFee3->setSpacing(6);
        verticalLayoutFee3->setObjectName(QString::fromUtf8("verticalLayoutFee3"));
        verticalLayoutFee3->setContentsMargins(-1, 2, -1, -1);
        horizontalLayoutFee12 = new QHBoxLayout();
        horizontalLayoutFee12->setObjectName(QString::fromUtf8("horizontalLayoutFee12"));
        labelSmartFee = new QLabel(frameFeeSelection);
        labelSmartFee->setObjectName(QString::fromUtf8("labelSmartFee"));
        labelSmartFee->setMargin(2);

        horizontalLayoutFee12->addWidget(labelSmartFee);

        labelFeeEstimation = new QLabel(frameFeeSelection);
        labelFeeEstimation->setObjectName(QString::fromUtf8("labelFeeEstimation"));

        horizontalLayoutFee12->addWidget(labelFeeEstimation);

        labelSmartFee2 = new QLabel(frameFeeSelection);
        labelSmartFee2->setObjectName(QString::fromUtf8("labelSmartFee2"));
        labelSmartFee2->setMargin(2);

        horizontalLayoutFee12->addWidget(labelSmartFee2);

        horizontalSpacer_8 = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutFee12->addItem(horizontalSpacer_8);


        verticalLayoutFee3->addLayout(horizontalLayoutFee12);

        horizontalLayoutFee9 = new QHBoxLayout();
        horizontalLayoutFee9->setObjectName(QString::fromUtf8("horizontalLayoutFee9"));
        verticalLayoutFee6 = new QVBoxLayout();
        verticalLayoutFee6->setObjectName(QString::fromUtf8("verticalLayoutFee6"));
        labelSmartFee3 = new QLabel(frameFeeSelection);
        labelSmartFee3->setObjectName(QString::fromUtf8("labelSmartFee3"));
        labelSmartFee3->setMargin(2);

        verticalLayoutFee6->addWidget(labelSmartFee3);

        verticalSpacer_3 = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutFee6->addItem(verticalSpacer_3);


        horizontalLayoutFee9->addLayout(verticalLayoutFee6);

        verticalLayoutFee5 = new QVBoxLayout();
        verticalLayoutFee5->setObjectName(QString::fromUtf8("verticalLayoutFee5"));
        verticalLayoutFee5->setContentsMargins(-1, -1, 30, -1);
        horizontalLayoutConfTarget = new QHBoxLayout();
        horizontalLayoutConfTarget->setObjectName(QString::fromUtf8("horizontalLayoutConfTarget"));
        horizontalLayoutConfTarget->setContentsMargins(-1, -1, -1, 0);
        confTargetSelector = new QComboBox(frameFeeSelection);
        confTargetSelector->setObjectName(QString::fromUtf8("confTargetSelector"));

        horizontalLayoutConfTarget->addWidget(confTargetSelector);

        horizontalSpacerConfTarget = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutConfTarget->addItem(horizontalSpacerConfTarget);


        verticalLayoutFee5->addLayout(horizontalLayoutConfTarget);


        horizontalLayoutFee9->addLayout(verticalLayoutFee5);


        verticalLayoutFee3->addLayout(horizontalLayoutFee9);

        verticalSpacer_4 = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutFee3->addItem(verticalSpacer_4);

        verticalLayoutFee3->setStretch(2, 1);

        gridLayoutFee->addLayout(verticalLayoutFee3, 0, 1, 1, 1);


        verticalLayoutFee12->addLayout(gridLayoutFee);

        optInRBF = new QCheckBox(frameFeeSelection);
        optInRBF->setObjectName(QString::fromUtf8("optInRBF"));

        verticalLayoutFee12->addWidget(optInRBF);


        verticalLayoutFee2->addWidget(frameFeeSelection);

        verticalSpacerFee = new QSpacerItem(40, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutFee2->addItem(verticalSpacerFee);


        verticalLayout_3->addLayout(verticalLayoutFee2);


        verticalLayout_5->addWidget(frameFee);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        createAssetButton = new QPushButton(CreateAssetDialog);
        createAssetButton->setObjectName(QString::fromUtf8("createAssetButton"));
        createAssetButton->setMinimumSize(QSize(150, 0));

        horizontalLayout_8->addWidget(createAssetButton);

        clearButton = new QPushButton(CreateAssetDialog);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout_8->addWidget(clearButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(CreateAssetDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_7->addWidget(label);

        labelBalance = new QLabel(CreateAssetDialog);
        labelBalance->setObjectName(QString::fromUtf8("labelBalance"));
        labelBalance->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_7->addWidget(labelBalance);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(verticalLayout_5);


        retranslateUi(CreateAssetDialog);

        QMetaObject::connectSlotsByName(CreateAssetDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateAssetDialog)
    {
        labelCoinControlFeatures->setText(QApplication::translate("CreateAssetDialog", "Coin Control Features", nullptr));
        pushButtonCoinControl->setText(QApplication::translate("CreateAssetDialog", "Inputs...", nullptr));
        labelCoinControlAutomaticallySelected->setText(QApplication::translate("CreateAssetDialog", "automatically selected", nullptr));
        labelCoinControlInsuffFunds->setText(QApplication::translate("CreateAssetDialog", "Insufficient funds!", nullptr));
        labelCoinControlQuantityText->setText(QApplication::translate("CreateAssetDialog", "Quantity:", nullptr));
        labelCoinControlBytesText->setText(QApplication::translate("CreateAssetDialog", "Bytes:", nullptr));
        labelCoinControlAmountText->setText(QApplication::translate("CreateAssetDialog", "Amount:", nullptr));
        labelCoinControlLowOutputText->setText(QApplication::translate("CreateAssetDialog", "Dust:", nullptr));
        labelCoinControlFeeText->setText(QApplication::translate("CreateAssetDialog", "Fee:", nullptr));
        labelCoinControlAfterFeeText->setText(QApplication::translate("CreateAssetDialog", "After Fee:", nullptr));
        labelCoinControlChangeText->setText(QApplication::translate("CreateAssetDialog", "Change:", nullptr));
#ifndef QT_NO_TOOLTIP
        checkBoxCoinControlChange->setToolTip(QApplication::translate("CreateAssetDialog", "If this is activated, but the change address is empty or invalid, change will be sent to a newly generated address.", nullptr));
#endif // QT_NO_TOOLTIP
        checkBoxCoinControlChange->setText(QApplication::translate("CreateAssetDialog", "Custom change address", nullptr));
        labelCoinControlChangeLabel->setText(QString());
        assetTypeLabel->setText(QString());
        assetNameLabel->setText(QApplication::translate("CreateAssetDialog", "Name:", nullptr));
#ifndef QT_NO_TOOLTIP
        nameText->setToolTip(QApplication::translate("CreateAssetDialog", "A-Z 0-9 and . or _ as the second character", nullptr));
#endif // QT_NO_TOOLTIP
        nameText->setPlaceholderText(QApplication::translate("CreateAssetDialog", "The name of the asset you would like to create", nullptr));
        assetFullName->setText(QString());
        availabilityButton->setText(QApplication::translate("CreateAssetDialog", "Check Availabilty", nullptr));
        addressLabel->setText(QApplication::translate("CreateAssetDialog", "Address:", nullptr));
        addressText->setText(QString());
        addressText->setPlaceholderText(QApplication::translate("CreateAssetDialog", "The RVN address that will hold this asset (You must own this address). Leave blank to create a new address.", nullptr));
        labelVerifierString->setText(QApplication::translate("CreateAssetDialog", "Verifier String:", nullptr));
        lineEditVerifierString->setPlaceholderText(QApplication::translate("CreateAssetDialog", "Create a verifier string built from Qualifier names e.g (#KYC & #VALID). Leave blank to default to true", nullptr));
        labelVerifierStringErrorMessage->setText(QApplication::translate("CreateAssetDialog", "Warning:", nullptr));
        quantityLabel->setText(QApplication::translate("CreateAssetDialog", "Quantity:", nullptr));
#ifndef QT_NO_TOOLTIP
        quantitySpinBox->setToolTip(QApplication::translate("CreateAssetDialog", "The number of assets that will be created", nullptr));
#endif // QT_NO_TOOLTIP
        unitsLabel->setText(QApplication::translate("CreateAssetDialog", "Units:", nullptr));
#ifndef QT_NO_TOOLTIP
        unitBox->setToolTip(QApplication::translate("CreateAssetDialog", "How divisble the assets will be (e.g. 8 = 1.00000000, 2 = 1.00)", nullptr));
#endif // QT_NO_TOOLTIP
        unitExampleLabel->setText(QApplication::translate("CreateAssetDialog", "e.g. 1", nullptr));
#ifndef QT_NO_TOOLTIP
        reissuableBox->setToolTip(QApplication::translate("CreateAssetDialog", "If the owner of this asset will be able to issue more assets in the future", nullptr));
#endif // QT_NO_TOOLTIP
        reissuableBox->setText(QApplication::translate("CreateAssetDialog", "Reissuable", nullptr));
#ifndef QT_NO_TOOLTIP
        ipfsBox->setToolTip(QApplication::translate("CreateAssetDialog", "Does this asset have an ipfs hash to go with it", nullptr));
#endif // QT_NO_TOOLTIP
        ipfsBox->setText(QApplication::translate("CreateAssetDialog", "Add IPFS/Txid Hash", nullptr));
#ifndef QT_NO_TOOLTIP
        ipfsText->setToolTip(QApplication::translate("CreateAssetDialog", "The ipfs/txid hash that contains information about the asset", nullptr));
#endif // QT_NO_TOOLTIP
        ipfsText->setPlaceholderText(QApplication::translate("CreateAssetDialog", "The ipfs/txid hash that is associated with the asset being created (e.g. QmU4h365LYMHx...)", nullptr));
        openIpfsButton->setText(QApplication::translate("CreateAssetDialog", "Browse IPFS", nullptr));
        messageLabel->setText(QApplication::translate("CreateAssetDialog", "ERROR TEXT", nullptr));
        labelFeeHeadline->setText(QApplication::translate("CreateAssetDialog", "Transaction Fee:", nullptr));
        labelFeeMinimized->setText(QString());
        buttonChooseFee->setText(QApplication::translate("CreateAssetDialog", "Choose...", nullptr));
#ifndef QT_NO_TOOLTIP
        fallbackFeeWarningLabel->setToolTip(QApplication::translate("CreateAssetDialog", "Using the fallbackfee can result in sending a transaction that will take several hours or days (or never) to confirm. Consider choosing your fee manually or wait until you have validated the complete chain.", nullptr));
#endif // QT_NO_TOOLTIP
        fallbackFeeWarningLabel->setText(QApplication::translate("CreateAssetDialog", "Warning: Fee estimation is currently not possible.", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonMinimizeFee->setToolTip(QApplication::translate("CreateAssetDialog", "collapse fee-settings", nullptr));
#endif // QT_NO_TOOLTIP
        buttonMinimizeFee->setText(QApplication::translate("CreateAssetDialog", "Hide", nullptr));
#ifndef QT_NO_TOOLTIP
        labelCustomPerKilobyte->setToolTip(QApplication::translate("CreateAssetDialog", "If the custom fee is set to 1000 satoshis and the transaction is only 250 bytes, then \"per kilobyte\" only pays 250 satoshis in fee, while \"total at least\" pays 1000 satoshis. For transactions bigger than a kilobyte both pay by kilobyte.", nullptr));
#endif // QT_NO_TOOLTIP
        labelCustomPerKilobyte->setText(QApplication::translate("CreateAssetDialog", "per kilobyte", nullptr));
#ifndef QT_NO_TOOLTIP
        checkBoxMinimumFee->setToolTip(QApplication::translate("CreateAssetDialog", "Paying only the minimum fee is just fine as long as there is less transaction volume than space in the blocks. But be aware that this can end up in a never confirming transaction once there is more demand for satoxcoin transactions than the network can process.", nullptr));
#endif // QT_NO_TOOLTIP
        checkBoxMinimumFee->setText(QString());
#ifndef QT_NO_TOOLTIP
        labelMinFeeWarning->setToolTip(QApplication::translate("CreateAssetDialog", "Paying only the minimum fee is just fine as long as there is less transaction volume than space in the blocks. But be aware that this can end up in a never confirming transaction once there is more demand for satoxcoin transactions than the network can process.", nullptr));
#endif // QT_NO_TOOLTIP
        labelMinFeeWarning->setText(QApplication::translate("CreateAssetDialog", "(read the tooltip)", nullptr));
        radioSmartFee->setText(QApplication::translate("CreateAssetDialog", "Recommended:", nullptr));
        radioCustomFee->setText(QApplication::translate("CreateAssetDialog", "C&ustom:", nullptr));
        labelSmartFee->setText(QString());
        labelFeeEstimation->setText(QString());
        labelSmartFee2->setText(QApplication::translate("CreateAssetDialog", "(Smart fee not initialized yet. This usually takes a few blocks...)", nullptr));
        labelSmartFee3->setText(QApplication::translate("CreateAssetDialog", "Confirmation time target:", nullptr));
#ifndef QT_NO_TOOLTIP
        optInRBF->setToolTip(QApplication::translate("CreateAssetDialog", "Indicates that the sender may wish to replace this transaction with a new one paying higher fees (prior to being confirmed).", nullptr));
#endif // QT_NO_TOOLTIP
        optInRBF->setText(QApplication::translate("CreateAssetDialog", "Request Replace-By-Fee", nullptr));
        createAssetButton->setText(QApplication::translate("CreateAssetDialog", "Create Asset", nullptr));
        clearButton->setText(QApplication::translate("CreateAssetDialog", "Clear", nullptr));
        label->setText(QApplication::translate("CreateAssetDialog", "Balance:", nullptr));
        labelBalance->setText(QApplication::translate("CreateAssetDialog", "123.456 RVN", nullptr));
        Q_UNUSED(CreateAssetDialog);
    } // retranslateUi

};

namespace Ui {
    class CreateAssetDialog: public Ui_CreateAssetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEASSETDIALOG_H
