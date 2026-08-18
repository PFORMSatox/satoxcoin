/********************************************************************************
** Form generated from reading UI file 'restrictedassignqualifier.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTRICTEDASSIGNQUALIFIER_H
#define UI_RESTRICTEDASSIGNQUALIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvalidatedlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_AssignQualifier
{
public:
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *labelAssignType;
    QComboBox *assignTypeComboBox;
    QLabel *labelQualifier;
    QComboBox *assetComboBox;
    QLabel *labelAddress;
    QValidatedLineEdit *lineEditAddress;
    QLabel *labelAssetData;
    QCheckBox *checkBoxChangeAddress;
    QLineEdit *lineEditChangeAddress;
    QLineEdit *lineEditAssetData;
    QLabel *labelWarning;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *buttonCheck;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonClear;
    QPushButton *buttonSubmit;

    void setupUi(QWidget *AssignQualifier)
    {
        if (AssignQualifier->objectName().isEmpty())
            AssignQualifier->setObjectName(QString::fromUtf8("AssignQualifier"));
        AssignQualifier->resize(797, 246);
        verticalLayout_2 = new QVBoxLayout(AssignQualifier);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(10);
        formLayout_2->setVerticalSpacing(10);
        formLayout_2->setContentsMargins(10, -1, 10, -1);
        labelAssignType = new QLabel(AssignQualifier);
        labelAssignType->setObjectName(QString::fromUtf8("labelAssignType"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelAssignType);

        assignTypeComboBox = new QComboBox(AssignQualifier);
        assignTypeComboBox->setObjectName(QString::fromUtf8("assignTypeComboBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, assignTypeComboBox);

        labelQualifier = new QLabel(AssignQualifier);
        labelQualifier->setObjectName(QString::fromUtf8("labelQualifier"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelQualifier);

        assetComboBox = new QComboBox(AssignQualifier);
        assetComboBox->setObjectName(QString::fromUtf8("assetComboBox"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, assetComboBox);

        labelAddress = new QLabel(AssignQualifier);
        labelAddress->setObjectName(QString::fromUtf8("labelAddress"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, labelAddress);

        lineEditAddress = new QValidatedLineEdit(AssignQualifier);
        lineEditAddress->setObjectName(QString::fromUtf8("lineEditAddress"));
        lineEditAddress->setMaxLength(50);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, lineEditAddress);

        labelAssetData = new QLabel(AssignQualifier);
        labelAssetData->setObjectName(QString::fromUtf8("labelAssetData"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, labelAssetData);

        checkBoxChangeAddress = new QCheckBox(AssignQualifier);
        checkBoxChangeAddress->setObjectName(QString::fromUtf8("checkBoxChangeAddress"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, checkBoxChangeAddress);

        lineEditChangeAddress = new QLineEdit(AssignQualifier);
        lineEditChangeAddress->setObjectName(QString::fromUtf8("lineEditChangeAddress"));
        lineEditChangeAddress->setEnabled(false);
        lineEditChangeAddress->setMaxLength(50);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, lineEditChangeAddress);

        lineEditAssetData = new QLineEdit(AssignQualifier);
        lineEditAssetData->setObjectName(QString::fromUtf8("lineEditAssetData"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, lineEditAssetData);


        verticalLayout_2->addLayout(formLayout_2);

        labelWarning = new QLabel(AssignQualifier);
        labelWarning->setObjectName(QString::fromUtf8("labelWarning"));

        verticalLayout_2->addWidget(labelWarning);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        buttonCheck = new QPushButton(AssignQualifier);
        buttonCheck->setObjectName(QString::fromUtf8("buttonCheck"));

        horizontalLayout_2->addWidget(buttonCheck);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        buttonClear = new QPushButton(AssignQualifier);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));

        horizontalLayout_2->addWidget(buttonClear);

        buttonSubmit = new QPushButton(AssignQualifier);
        buttonSubmit->setObjectName(QString::fromUtf8("buttonSubmit"));

        horizontalLayout_2->addWidget(buttonSubmit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(AssignQualifier);

        QMetaObject::connectSlotsByName(AssignQualifier);
    } // setupUi

    void retranslateUi(QWidget *AssignQualifier)
    {
        AssignQualifier->setWindowTitle(QApplication::translate("AssignQualifier", "Frame", nullptr));
        labelAssignType->setText(QApplication::translate("AssignQualifier", "Select Type:", nullptr));
        labelQualifier->setText(QApplication::translate("AssignQualifier", "Select Qualifier:", nullptr));
        labelAddress->setText(QApplication::translate("AssignQualifier", "Address:", nullptr));
        labelAssetData->setText(QApplication::translate("AssignQualifier", "IPFS / Hash:", nullptr));
        checkBoxChangeAddress->setText(QApplication::translate("AssignQualifier", "Custom Change Address", nullptr));
        labelWarning->setText(QString());
        buttonCheck->setText(QApplication::translate("AssignQualifier", "Check", nullptr));
        buttonClear->setText(QApplication::translate("AssignQualifier", "Clear", nullptr));
        buttonSubmit->setText(QApplication::translate("AssignQualifier", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssignQualifier: public Ui_AssignQualifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTRICTEDASSIGNQUALIFIER_H
