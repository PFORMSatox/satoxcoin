/********************************************************************************
** Form generated from reading UI file 'restrictedfreezeaddress.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTRICTEDFREEZEADDRESS_H
#define UI_RESTRICTEDFREEZEADDRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvalidatedlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_FreezeAddress
{
public:
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *labelRestricted;
    QLabel *labelAddress;
    QValidatedLineEdit *lineEditAddress;
    QCheckBox *checkBoxChangeAddress;
    QLineEdit *lineEditChangeAddress;
    QComboBox *assetComboBox;
    QLabel *labelAssetData;
    QLineEdit *lineEditAssetData;
    QHBoxLayout *horizontalLayout;
    QLabel *labelAddress_2;
    QLabel *labelGlobal;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBoxFreezeOptions;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonFreezeAddress;
    QRadioButton *radioButtonUnfreezeAddress;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonGlobalFreeze;
    QRadioButton *radioButtonGlobalUnfreeze;
    QLabel *labelWarning;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonCheck;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonClear;
    QPushButton *buttonSubmit;

    void setupUi(QWidget *FreezeAddress)
    {
        if (FreezeAddress->objectName().isEmpty())
            FreezeAddress->setObjectName(QString::fromUtf8("FreezeAddress"));
        FreezeAddress->resize(773, 341);
        verticalLayout_2 = new QVBoxLayout(FreezeAddress);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(10);
        formLayout_2->setVerticalSpacing(10);
        formLayout_2->setContentsMargins(10, -1, 10, -1);
        labelRestricted = new QLabel(FreezeAddress);
        labelRestricted->setObjectName(QString::fromUtf8("labelRestricted"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelRestricted);

        labelAddress = new QLabel(FreezeAddress);
        labelAddress->setObjectName(QString::fromUtf8("labelAddress"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelAddress);

        lineEditAddress = new QValidatedLineEdit(FreezeAddress);
        lineEditAddress->setObjectName(QString::fromUtf8("lineEditAddress"));
        lineEditAddress->setMaxLength(50);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEditAddress);

        checkBoxChangeAddress = new QCheckBox(FreezeAddress);
        checkBoxChangeAddress->setObjectName(QString::fromUtf8("checkBoxChangeAddress"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, checkBoxChangeAddress);

        lineEditChangeAddress = new QLineEdit(FreezeAddress);
        lineEditChangeAddress->setObjectName(QString::fromUtf8("lineEditChangeAddress"));
        lineEditChangeAddress->setEnabled(false);
        lineEditChangeAddress->setMaxLength(50);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, lineEditChangeAddress);

        assetComboBox = new QComboBox(FreezeAddress);
        assetComboBox->setObjectName(QString::fromUtf8("assetComboBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, assetComboBox);

        labelAssetData = new QLabel(FreezeAddress);
        labelAssetData->setObjectName(QString::fromUtf8("labelAssetData"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, labelAssetData);

        lineEditAssetData = new QLineEdit(FreezeAddress);
        lineEditAssetData->setObjectName(QString::fromUtf8("lineEditAssetData"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, lineEditAssetData);


        verticalLayout_2->addLayout(formLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelAddress_2 = new QLabel(FreezeAddress);
        labelAddress_2->setObjectName(QString::fromUtf8("labelAddress_2"));
        labelAddress_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelAddress_2);

        labelGlobal = new QLabel(FreezeAddress);
        labelGlobal->setObjectName(QString::fromUtf8("labelGlobal"));
        labelGlobal->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelGlobal);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBoxFreezeOptions = new QGroupBox(FreezeAddress);
        groupBoxFreezeOptions->setObjectName(QString::fromUtf8("groupBoxFreezeOptions"));
        verticalLayout_5 = new QVBoxLayout(groupBoxFreezeOptions);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonFreezeAddress = new QRadioButton(groupBoxFreezeOptions);
        radioButtonFreezeAddress->setObjectName(QString::fromUtf8("radioButtonFreezeAddress"));

        verticalLayout->addWidget(radioButtonFreezeAddress);

        radioButtonUnfreezeAddress = new QRadioButton(groupBoxFreezeOptions);
        radioButtonUnfreezeAddress->setObjectName(QString::fromUtf8("radioButtonUnfreezeAddress"));

        verticalLayout->addWidget(radioButtonUnfreezeAddress);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButtonGlobalFreeze = new QRadioButton(groupBoxFreezeOptions);
        radioButtonGlobalFreeze->setObjectName(QString::fromUtf8("radioButtonGlobalFreeze"));

        verticalLayout_3->addWidget(radioButtonGlobalFreeze);

        radioButtonGlobalUnfreeze = new QRadioButton(groupBoxFreezeOptions);
        radioButtonGlobalUnfreeze->setObjectName(QString::fromUtf8("radioButtonGlobalUnfreeze"));

        verticalLayout_3->addWidget(radioButtonGlobalUnfreeze);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_3->addWidget(groupBoxFreezeOptions);


        verticalLayout_2->addLayout(horizontalLayout_3);

        labelWarning = new QLabel(FreezeAddress);
        labelWarning->setObjectName(QString::fromUtf8("labelWarning"));

        verticalLayout_2->addWidget(labelWarning);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonCheck = new QPushButton(FreezeAddress);
        buttonCheck->setObjectName(QString::fromUtf8("buttonCheck"));

        horizontalLayout_2->addWidget(buttonCheck);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        buttonClear = new QPushButton(FreezeAddress);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));

        horizontalLayout_2->addWidget(buttonClear);

        buttonSubmit = new QPushButton(FreezeAddress);
        buttonSubmit->setObjectName(QString::fromUtf8("buttonSubmit"));

        horizontalLayout_2->addWidget(buttonSubmit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(FreezeAddress);

        QMetaObject::connectSlotsByName(FreezeAddress);
    } // setupUi

    void retranslateUi(QWidget *FreezeAddress)
    {
        FreezeAddress->setWindowTitle(QApplication::translate("FreezeAddress", "Frame", nullptr));
        labelRestricted->setText(QApplication::translate("FreezeAddress", "Restricted Asset:", nullptr));
        labelAddress->setText(QApplication::translate("FreezeAddress", "Address:", nullptr));
        checkBoxChangeAddress->setText(QApplication::translate("FreezeAddress", "Custom Change Address", nullptr));
        labelAssetData->setText(QApplication::translate("FreezeAddress", "IPFS / Hash:", nullptr));
        labelAddress_2->setText(QApplication::translate("FreezeAddress", "Single Address Options", nullptr));
        labelGlobal->setText(QApplication::translate("FreezeAddress", "Global Options ", nullptr));
        groupBoxFreezeOptions->setTitle(QString());
        radioButtonFreezeAddress->setText(QApplication::translate("FreezeAddress", "Free&ze trading on this address", nullptr));
        radioButtonUnfreezeAddress->setText(QApplication::translate("FreezeAddress", "Unfreeze tradin&g on this address", nullptr));
        radioButtonGlobalFreeze->setText(QApplication::translate("FreezeAddress", "Freeze all &trading for the selected restricted asset", nullptr));
        radioButtonGlobalUnfreeze->setText(QApplication::translate("FreezeAddress", "&Unfreeze all trading for the selected restricted asset", nullptr));
        labelWarning->setText(QString());
        buttonCheck->setText(QApplication::translate("FreezeAddress", "Check", nullptr));
        buttonClear->setText(QApplication::translate("FreezeAddress", "Clear", nullptr));
        buttonSubmit->setText(QApplication::translate("FreezeAddress", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FreezeAddress: public Ui_FreezeAddress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTRICTEDFREEZEADDRESS_H
