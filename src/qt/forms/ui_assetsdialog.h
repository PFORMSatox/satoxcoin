/********************************************************************************
** Form generated from reading UI file 'assetsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSETSDIALOG_H
#define UI_ASSETSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvalidatedlineedit.h"
#include "satoxcoinamountfield.h"

QT_BEGIN_NAMESPACE

class Ui_AssetsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QFrame *frameAssetControl;
    QVBoxLayout *verticalLayoutAssetControl2;
    QVBoxLayout *verticalLayoutAssetControl;
    QHBoxLayout *horizontalLayoutAssetControl1;
    QLabel *labelAssetControlFeatures;
    QHBoxLayout *horizontalLayoutAssetControl2;
    QPushButton *pushButtonAssetControl;
    QLabel *labelAssetControlAutomaticallySelected;
    QLabel *labelAssetControlInsuffFunds;
    QSpacerItem *horizontalSpacerAssetControl;
    QWidget *widgetAssetControl;
    QHBoxLayout *horizontalLayoutAssetControl5;
    QHBoxLayout *horizontalLayoutAssetControl3;
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
    QHBoxLayout *horizontalLayoutAssetControl4;
    QCheckBox *checkBoxAssetControlChange;
    QValidatedLineEdit *lineEditAssetControlChange;
    QLabel *labelAssetControlChangeLabel;
    QSpacerItem *verticalSpacerAssetControl;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *entries;
    QSpacerItem *verticalSpacer;
    QFrame *frameFee;
    QVBoxLayout *verticalLayoutFee1;
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
    QSpacerItem *horizontalSpacer_4;
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
    QSpacerItem *horizontalSpacer_2;
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
    QSpacerItem *horizontalSpacer_5;
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
    QHBoxLayout *horizontalLayout;
    QPushButton *sendButton;
    QPushButton *clearButton;
    QPushButton *addButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *labelBalance;
    QButtonGroup *groupFee;

    void setupUi(QDialog *AssetsDialog)
    {
        if (AssetsDialog->objectName().isEmpty())
            AssetsDialog->setObjectName(QString::fromUtf8("AssetsDialog"));
        AssetsDialog->resize(1070, 822);
        verticalLayout = new QVBoxLayout(AssetsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 8);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, 20, 20, 20);
        frameAssetControl = new QFrame(AssetsDialog);
        frameAssetControl->setObjectName(QString::fromUtf8("frameAssetControl"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameAssetControl->sizePolicy().hasHeightForWidth());
        frameAssetControl->setSizePolicy(sizePolicy);
        frameAssetControl->setMaximumSize(QSize(16777215, 16777215));
        frameAssetControl->setFrameShape(QFrame::StyledPanel);
        frameAssetControl->setFrameShadow(QFrame::Sunken);
        verticalLayoutAssetControl2 = new QVBoxLayout(frameAssetControl);
        verticalLayoutAssetControl2->setSpacing(0);
        verticalLayoutAssetControl2->setObjectName(QString::fromUtf8("verticalLayoutAssetControl2"));
        verticalLayoutAssetControl2->setContentsMargins(0, 0, 0, 6);
        verticalLayoutAssetControl = new QVBoxLayout();
        verticalLayoutAssetControl->setSpacing(0);
        verticalLayoutAssetControl->setObjectName(QString::fromUtf8("verticalLayoutAssetControl"));
        verticalLayoutAssetControl->setContentsMargins(10, 10, -1, -1);
        horizontalLayoutAssetControl1 = new QHBoxLayout();
        horizontalLayoutAssetControl1->setObjectName(QString::fromUtf8("horizontalLayoutAssetControl1"));
        horizontalLayoutAssetControl1->setContentsMargins(-1, -1, -1, 15);
        labelAssetControlFeatures = new QLabel(frameAssetControl);
        labelAssetControlFeatures->setObjectName(QString::fromUtf8("labelAssetControlFeatures"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelAssetControlFeatures->sizePolicy().hasHeightForWidth());
        labelAssetControlFeatures->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelAssetControlFeatures->setFont(font);
        labelAssetControlFeatures->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        horizontalLayoutAssetControl1->addWidget(labelAssetControlFeatures);


        verticalLayoutAssetControl->addLayout(horizontalLayoutAssetControl1);

        horizontalLayoutAssetControl2 = new QHBoxLayout();
        horizontalLayoutAssetControl2->setSpacing(8);
        horizontalLayoutAssetControl2->setObjectName(QString::fromUtf8("horizontalLayoutAssetControl2"));
        horizontalLayoutAssetControl2->setContentsMargins(-1, -1, -1, 10);
        pushButtonAssetControl = new QPushButton(frameAssetControl);
        pushButtonAssetControl->setObjectName(QString::fromUtf8("pushButtonAssetControl"));
        pushButtonAssetControl->setStyleSheet(QString::fromUtf8(""));
        pushButtonAssetControl->setAutoDefault(false);

        horizontalLayoutAssetControl2->addWidget(pushButtonAssetControl);

        labelAssetControlAutomaticallySelected = new QLabel(frameAssetControl);
        labelAssetControlAutomaticallySelected->setObjectName(QString::fromUtf8("labelAssetControlAutomaticallySelected"));
        labelAssetControlAutomaticallySelected->setMargin(5);

        horizontalLayoutAssetControl2->addWidget(labelAssetControlAutomaticallySelected);

        labelAssetControlInsuffFunds = new QLabel(frameAssetControl);
        labelAssetControlInsuffFunds->setObjectName(QString::fromUtf8("labelAssetControlInsuffFunds"));
        labelAssetControlInsuffFunds->setFont(font);
        labelAssetControlInsuffFunds->setStyleSheet(QString::fromUtf8("color:red;font-weight:bold;"));
        labelAssetControlInsuffFunds->setMargin(5);

        horizontalLayoutAssetControl2->addWidget(labelAssetControlInsuffFunds);

        horizontalSpacerAssetControl = new QSpacerItem(40, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutAssetControl2->addItem(horizontalSpacerAssetControl);


        verticalLayoutAssetControl->addLayout(horizontalLayoutAssetControl2);

        widgetAssetControl = new QWidget(frameAssetControl);
        widgetAssetControl->setObjectName(QString::fromUtf8("widgetAssetControl"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widgetAssetControl->sizePolicy().hasHeightForWidth());
        widgetAssetControl->setSizePolicy(sizePolicy2);
        widgetAssetControl->setMinimumSize(QSize(0, 0));
        widgetAssetControl->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutAssetControl5 = new QHBoxLayout(widgetAssetControl);
        horizontalLayoutAssetControl5->setObjectName(QString::fromUtf8("horizontalLayoutAssetControl5"));
        horizontalLayoutAssetControl5->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutAssetControl3 = new QHBoxLayout();
        horizontalLayoutAssetControl3->setSpacing(20);
        horizontalLayoutAssetControl3->setObjectName(QString::fromUtf8("horizontalLayoutAssetControl3"));
        horizontalLayoutAssetControl3->setContentsMargins(-1, 0, -1, 10);
        formLayoutAssetControl1 = new QFormLayout();
        formLayoutAssetControl1->setObjectName(QString::fromUtf8("formLayoutAssetControl1"));
        formLayoutAssetControl1->setHorizontalSpacing(10);
        formLayoutAssetControl1->setVerticalSpacing(14);
        formLayoutAssetControl1->setContentsMargins(10, 4, 6, -1);
        labelAssetControlQuantityText = new QLabel(widgetAssetControl);
        labelAssetControlQuantityText->setObjectName(QString::fromUtf8("labelAssetControlQuantityText"));
        labelAssetControlQuantityText->setFont(font);
        labelAssetControlQuantityText->setMargin(0);

        formLayoutAssetControl1->setWidget(0, QFormLayout::LabelRole, labelAssetControlQuantityText);

        labelAssetControlQuantity = new QLabel(widgetAssetControl);
        labelAssetControlQuantity->setObjectName(QString::fromUtf8("labelAssetControlQuantity"));
        labelAssetControlQuantity->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlQuantity->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlQuantity->setText(QString::fromUtf8("0"));
        labelAssetControlQuantity->setMargin(0);
        labelAssetControlQuantity->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl1->setWidget(0, QFormLayout::FieldRole, labelAssetControlQuantity);

        labelAssetControlBytesText = new QLabel(widgetAssetControl);
        labelAssetControlBytesText->setObjectName(QString::fromUtf8("labelAssetControlBytesText"));
        labelAssetControlBytesText->setFont(font);

        formLayoutAssetControl1->setWidget(1, QFormLayout::LabelRole, labelAssetControlBytesText);

        labelAssetControlBytes = new QLabel(widgetAssetControl);
        labelAssetControlBytes->setObjectName(QString::fromUtf8("labelAssetControlBytes"));
        labelAssetControlBytes->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlBytes->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlBytes->setText(QString::fromUtf8("0"));
        labelAssetControlBytes->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl1->setWidget(1, QFormLayout::FieldRole, labelAssetControlBytes);


        horizontalLayoutAssetControl3->addLayout(formLayoutAssetControl1);

        formLayoutAssetControl2 = new QFormLayout();
        formLayoutAssetControl2->setObjectName(QString::fromUtf8("formLayoutAssetControl2"));
        formLayoutAssetControl2->setHorizontalSpacing(10);
        formLayoutAssetControl2->setVerticalSpacing(14);
        formLayoutAssetControl2->setContentsMargins(6, 4, 6, -1);
        labelAssetControlAmountText = new QLabel(widgetAssetControl);
        labelAssetControlAmountText->setObjectName(QString::fromUtf8("labelAssetControlAmountText"));
        labelAssetControlAmountText->setFont(font);
        labelAssetControlAmountText->setMargin(0);

        formLayoutAssetControl2->setWidget(0, QFormLayout::LabelRole, labelAssetControlAmountText);

        labelAssetControlAmount = new QLabel(widgetAssetControl);
        labelAssetControlAmount->setObjectName(QString::fromUtf8("labelAssetControlAmount"));
        labelAssetControlAmount->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlAmount->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlAmount->setText(QString::fromUtf8("0.00 RVN"));
        labelAssetControlAmount->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl2->setWidget(0, QFormLayout::FieldRole, labelAssetControlAmount);

        labelAssetControlLowOutputText = new QLabel(widgetAssetControl);
        labelAssetControlLowOutputText->setObjectName(QString::fromUtf8("labelAssetControlLowOutputText"));
        labelAssetControlLowOutputText->setFont(font);

        formLayoutAssetControl2->setWidget(1, QFormLayout::LabelRole, labelAssetControlLowOutputText);

        labelAssetControlLowOutput = new QLabel(widgetAssetControl);
        labelAssetControlLowOutput->setObjectName(QString::fromUtf8("labelAssetControlLowOutput"));
        labelAssetControlLowOutput->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlLowOutput->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlLowOutput->setText(QString::fromUtf8("no"));
        labelAssetControlLowOutput->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl2->setWidget(1, QFormLayout::FieldRole, labelAssetControlLowOutput);


        horizontalLayoutAssetControl3->addLayout(formLayoutAssetControl2);

        formLayoutAssetControl3 = new QFormLayout();
        formLayoutAssetControl3->setObjectName(QString::fromUtf8("formLayoutAssetControl3"));
        formLayoutAssetControl3->setHorizontalSpacing(10);
        formLayoutAssetControl3->setVerticalSpacing(14);
        formLayoutAssetControl3->setContentsMargins(6, 4, 6, -1);
        labelAssetControlFeeText = new QLabel(widgetAssetControl);
        labelAssetControlFeeText->setObjectName(QString::fromUtf8("labelAssetControlFeeText"));
        labelAssetControlFeeText->setFont(font);
        labelAssetControlFeeText->setMargin(0);

        formLayoutAssetControl3->setWidget(0, QFormLayout::LabelRole, labelAssetControlFeeText);

        labelAssetControlFee = new QLabel(widgetAssetControl);
        labelAssetControlFee->setObjectName(QString::fromUtf8("labelAssetControlFee"));
        labelAssetControlFee->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlFee->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlFee->setText(QString::fromUtf8("0.00 RVN"));
        labelAssetControlFee->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl3->setWidget(0, QFormLayout::FieldRole, labelAssetControlFee);


        horizontalLayoutAssetControl3->addLayout(formLayoutAssetControl3);

        formLayoutAssetControl4 = new QFormLayout();
        formLayoutAssetControl4->setObjectName(QString::fromUtf8("formLayoutAssetControl4"));
        formLayoutAssetControl4->setHorizontalSpacing(10);
        formLayoutAssetControl4->setVerticalSpacing(14);
        formLayoutAssetControl4->setContentsMargins(6, 4, 6, -1);
        labelAssetControlAfterFeeText = new QLabel(widgetAssetControl);
        labelAssetControlAfterFeeText->setObjectName(QString::fromUtf8("labelAssetControlAfterFeeText"));
        labelAssetControlAfterFeeText->setFont(font);
        labelAssetControlAfterFeeText->setMargin(0);

        formLayoutAssetControl4->setWidget(0, QFormLayout::LabelRole, labelAssetControlAfterFeeText);

        labelAssetControlAfterFee = new QLabel(widgetAssetControl);
        labelAssetControlAfterFee->setObjectName(QString::fromUtf8("labelAssetControlAfterFee"));
        labelAssetControlAfterFee->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlAfterFee->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlAfterFee->setText(QString::fromUtf8("0.00 RVN"));
        labelAssetControlAfterFee->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl4->setWidget(0, QFormLayout::FieldRole, labelAssetControlAfterFee);

        labelAssetControlChangeText = new QLabel(widgetAssetControl);
        labelAssetControlChangeText->setObjectName(QString::fromUtf8("labelAssetControlChangeText"));
        labelAssetControlChangeText->setFont(font);

        formLayoutAssetControl4->setWidget(1, QFormLayout::LabelRole, labelAssetControlChangeText);

        labelAssetControlChange = new QLabel(widgetAssetControl);
        labelAssetControlChange->setObjectName(QString::fromUtf8("labelAssetControlChange"));
        labelAssetControlChange->setCursor(QCursor(Qt::IBeamCursor));
        labelAssetControlChange->setContextMenuPolicy(Qt::ActionsContextMenu);
        labelAssetControlChange->setText(QString::fromUtf8("0.00 RVN"));
        labelAssetControlChange->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayoutAssetControl4->setWidget(1, QFormLayout::FieldRole, labelAssetControlChange);


        horizontalLayoutAssetControl3->addLayout(formLayoutAssetControl4);

        horizontalLayoutAssetControl3->setStretch(3, 1);

        horizontalLayoutAssetControl5->addLayout(horizontalLayoutAssetControl3);


        verticalLayoutAssetControl->addWidget(widgetAssetControl);

        horizontalLayoutAssetControl4 = new QHBoxLayout();
        horizontalLayoutAssetControl4->setSpacing(12);
        horizontalLayoutAssetControl4->setObjectName(QString::fromUtf8("horizontalLayoutAssetControl4"));
        horizontalLayoutAssetControl4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayoutAssetControl4->setContentsMargins(-1, 5, 5, -1);
        checkBoxAssetControlChange = new QCheckBox(frameAssetControl);
        checkBoxAssetControlChange->setObjectName(QString::fromUtf8("checkBoxAssetControlChange"));

        horizontalLayoutAssetControl4->addWidget(checkBoxAssetControlChange);

        lineEditAssetControlChange = new QValidatedLineEdit(frameAssetControl);
        lineEditAssetControlChange->setObjectName(QString::fromUtf8("lineEditAssetControlChange"));
        lineEditAssetControlChange->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEditAssetControlChange->sizePolicy().hasHeightForWidth());
        lineEditAssetControlChange->setSizePolicy(sizePolicy);

        horizontalLayoutAssetControl4->addWidget(lineEditAssetControlChange);

        labelAssetControlChangeLabel = new QLabel(frameAssetControl);
        labelAssetControlChangeLabel->setObjectName(QString::fromUtf8("labelAssetControlChangeLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelAssetControlChangeLabel->sizePolicy().hasHeightForWidth());
        labelAssetControlChangeLabel->setSizePolicy(sizePolicy3);
        labelAssetControlChangeLabel->setMinimumSize(QSize(0, 0));
        labelAssetControlChangeLabel->setMargin(3);

        horizontalLayoutAssetControl4->addWidget(labelAssetControlChangeLabel);


        verticalLayoutAssetControl->addLayout(horizontalLayoutAssetControl4);

        verticalSpacerAssetControl = new QSpacerItem(800, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutAssetControl->addItem(verticalSpacerAssetControl);

        verticalLayoutAssetControl->setStretch(4, 1);

        verticalLayoutAssetControl2->addLayout(verticalLayoutAssetControl);


        verticalLayout_3->addWidget(frameAssetControl);

        scrollArea = new QScrollArea(AssetsDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1010, 257));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        entries = new QVBoxLayout();
        entries->setSpacing(6);
        entries->setObjectName(QString::fromUtf8("entries"));

        verticalLayout_2->addLayout(entries);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout_2->setStretch(1, 1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        frameFee = new QFrame(AssetsDialog);
        frameFee->setObjectName(QString::fromUtf8("frameFee"));
        sizePolicy.setHeightForWidth(frameFee->sizePolicy().hasHeightForWidth());
        frameFee->setSizePolicy(sizePolicy);
        frameFee->setMaximumSize(QSize(16777215, 16777215));
        frameFee->setFrameShape(QFrame::StyledPanel);
        frameFee->setFrameShadow(QFrame::Sunken);
        verticalLayoutFee1 = new QVBoxLayout(frameFee);
        verticalLayoutFee1->setSpacing(0);
        verticalLayoutFee1->setObjectName(QString::fromUtf8("verticalLayoutFee1"));
        verticalLayoutFee1->setContentsMargins(0, 0, 0, 0);
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
        sizePolicy1.setHeightForWidth(labelFeeHeadline->sizePolicy().hasHeightForWidth());
        labelFeeHeadline->setSizePolicy(sizePolicy1);
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

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayoutFee1->addItem(horizontalSpacer_4);

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

        horizontalSpacer_2 = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutFee8->addItem(horizontalSpacer_2);


        verticalLayoutFee8->addLayout(horizontalLayoutFee8);


        gridLayoutFee->addLayout(verticalLayoutFee8, 1, 1, 1, 1);

        verticalLayoutFee4 = new QVBoxLayout();
        verticalLayoutFee4->setObjectName(QString::fromUtf8("verticalLayoutFee4"));
        radioSmartFee = new QRadioButton(frameFeeSelection);
        groupFee = new QButtonGroup(AssetsDialog);
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

        horizontalSpacer_5 = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutFee12->addItem(horizontalSpacer_5);


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


        verticalLayoutFee1->addLayout(verticalLayoutFee2);


        verticalLayout_3->addWidget(frameFee);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sendButton = new QPushButton(AssetsDialog);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setMinimumSize(QSize(150, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/send"), QSize(), QIcon::Normal, QIcon::Off);
        sendButton->setIcon(icon);
        sendButton->setAutoDefault(false);

        horizontalLayout->addWidget(sendButton);

        clearButton = new QPushButton(AssetsDialog);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy4);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/remove"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon1);
        clearButton->setAutoDefault(false);

        horizontalLayout->addWidget(clearButton);

        addButton = new QPushButton(AssetsDialog);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/add"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon2);
        addButton->setAutoDefault(false);

        horizontalLayout->addWidget(addButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(AssetsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(label);

        labelBalance = new QLabel(AssetsDialog);
        labelBalance->setObjectName(QString::fromUtf8("labelBalance"));
        sizePolicy5.setHeightForWidth(labelBalance->sizePolicy().hasHeightForWidth());
        labelBalance->setSizePolicy(sizePolicy5);
        labelBalance->setCursor(QCursor(Qt::IBeamCursor));
        labelBalance->setText(QString::fromUtf8("123.456 RVN"));
        labelBalance->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(labelBalance);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_3);


        retranslateUi(AssetsDialog);

        sendButton->setDefault(false);


        QMetaObject::connectSlotsByName(AssetsDialog);
    } // setupUi

    void retranslateUi(QDialog *AssetsDialog)
    {
        AssetsDialog->setWindowTitle(QApplication::translate("AssetsDialog", "Send Coins", nullptr));
        labelAssetControlFeatures->setText(QApplication::translate("AssetsDialog", "Asset Control Features", nullptr));
        pushButtonAssetControl->setText(QApplication::translate("AssetsDialog", "Inputs...", nullptr));
        labelAssetControlAutomaticallySelected->setText(QApplication::translate("AssetsDialog", "automatically selected", nullptr));
        labelAssetControlInsuffFunds->setText(QApplication::translate("AssetsDialog", "Insufficient funds!", nullptr));
        labelAssetControlQuantityText->setText(QApplication::translate("AssetsDialog", "Quantity:", nullptr));
        labelAssetControlBytesText->setText(QApplication::translate("AssetsDialog", "Bytes:", nullptr));
        labelAssetControlAmountText->setText(QApplication::translate("AssetsDialog", "Amount:", nullptr));
        labelAssetControlLowOutputText->setText(QApplication::translate("AssetsDialog", "Dust:", nullptr));
        labelAssetControlFeeText->setText(QApplication::translate("AssetsDialog", "Fee:", nullptr));
        labelAssetControlAfterFeeText->setText(QApplication::translate("AssetsDialog", "After Fee:", nullptr));
        labelAssetControlChangeText->setText(QApplication::translate("AssetsDialog", "Change:", nullptr));
#ifndef QT_NO_TOOLTIP
        checkBoxAssetControlChange->setToolTip(QApplication::translate("AssetsDialog", "If this is activated, but the change address is empty or invalid, change will be sent to a newly generated address.", nullptr));
#endif // QT_NO_TOOLTIP
        checkBoxAssetControlChange->setText(QApplication::translate("AssetsDialog", "Custom change address", nullptr));
        labelAssetControlChangeLabel->setText(QString());
        labelFeeHeadline->setText(QApplication::translate("AssetsDialog", "Transaction Fee:", nullptr));
        labelFeeMinimized->setText(QString());
        buttonChooseFee->setText(QApplication::translate("AssetsDialog", "Choose...", nullptr));
#ifndef QT_NO_TOOLTIP
        fallbackFeeWarningLabel->setToolTip(QApplication::translate("AssetsDialog", "Using the fallbackfee can result in sending a transaction that will take several hours or days (or never) to confirm. Consider choosing your fee manually or wait until you have validated the complete chain.", nullptr));
#endif // QT_NO_TOOLTIP
        fallbackFeeWarningLabel->setText(QApplication::translate("AssetsDialog", "Warning: Fee estimation is currently not possible.", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonMinimizeFee->setToolTip(QApplication::translate("AssetsDialog", "collapse fee-settings", nullptr));
#endif // QT_NO_TOOLTIP
        buttonMinimizeFee->setText(QApplication::translate("AssetsDialog", "Hide", nullptr));
#ifndef QT_NO_TOOLTIP
        labelCustomPerKilobyte->setToolTip(QApplication::translate("AssetsDialog", "If the custom fee is set to 1000 satoshis and the transaction is only 250 bytes, then \"per kilobyte\" only pays 250 satoshis in fee, while \"total at least\" pays 1000 satoshis. For transactions bigger than a kilobyte both pay by kilobyte.", nullptr));
#endif // QT_NO_TOOLTIP
        labelCustomPerKilobyte->setText(QApplication::translate("AssetsDialog", "per kilobyte", nullptr));
#ifndef QT_NO_TOOLTIP
        checkBoxMinimumFee->setToolTip(QApplication::translate("AssetsDialog", "Paying only the minimum fee is just fine as long as there is less transaction volume than space in the blocks. But be aware that this can end up in a never confirming transaction once there is more demand for satoxcoin transactions than the network can process.", nullptr));
#endif // QT_NO_TOOLTIP
        checkBoxMinimumFee->setText(QString());
#ifndef QT_NO_TOOLTIP
        labelMinFeeWarning->setToolTip(QApplication::translate("AssetsDialog", "Paying only the minimum fee is just fine as long as there is less transaction volume than space in the blocks. But be aware that this can end up in a never confirming transaction once there is more demand for satoxcoin transactions than the network can process.", nullptr));
#endif // QT_NO_TOOLTIP
        labelMinFeeWarning->setText(QApplication::translate("AssetsDialog", "(read the tooltip)", nullptr));
        radioSmartFee->setText(QApplication::translate("AssetsDialog", "Recommended:", nullptr));
        radioCustomFee->setText(QApplication::translate("AssetsDialog", "Custom:", nullptr));
        labelSmartFee->setText(QString());
        labelFeeEstimation->setText(QString());
        labelSmartFee2->setText(QApplication::translate("AssetsDialog", "(Smart fee not initialized yet. This usually takes a few blocks...)", nullptr));
        labelSmartFee3->setText(QApplication::translate("AssetsDialog", "Confirmation time target:", nullptr));
#ifndef QT_NO_TOOLTIP
        optInRBF->setToolTip(QApplication::translate("AssetsDialog", "Indicates that the sender may wish to replace this transaction with a new one paying higher fees (prior to being confirmed).", nullptr));
#endif // QT_NO_TOOLTIP
        optInRBF->setText(QApplication::translate("AssetsDialog", "Request Replace-By-Fee", nullptr));
#ifndef QT_NO_TOOLTIP
        sendButton->setToolTip(QApplication::translate("AssetsDialog", "Confirm the send action", nullptr));
#endif // QT_NO_TOOLTIP
        sendButton->setText(QApplication::translate("AssetsDialog", "S&end", nullptr));
#ifndef QT_NO_TOOLTIP
        clearButton->setToolTip(QApplication::translate("AssetsDialog", "Clear all fields of the form.", nullptr));
#endif // QT_NO_TOOLTIP
        clearButton->setText(QApplication::translate("AssetsDialog", "Clear &All", nullptr));
#ifndef QT_NO_TOOLTIP
        addButton->setToolTip(QApplication::translate("AssetsDialog", "Transfer to multiple recipients at once", nullptr));
#endif // QT_NO_TOOLTIP
        addButton->setText(QApplication::translate("AssetsDialog", "Add &Recipient", nullptr));
        label->setText(QApplication::translate("AssetsDialog", "Balance:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssetsDialog: public Ui_AssetsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSETSDIALOG_H
