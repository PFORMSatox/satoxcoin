/********************************************************************************
** Form generated from reading UI file 'restrictedassetsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTRICTEDASSETSDIALOG_H
#define UI_RESTRICTEDASSETSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RestrictedAssetsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *frameAssetBalance;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelAssetBalance;
    QLineEdit *lineEditAssetSearch;
    QTableView *listAssets;
    QFrame *frameAddressList;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelAddressList;
    QLineEdit *lineEditAddressSearch;
    QTableView *myAddressList;
    QHBoxLayout *horizontalLayout_4;
    QFrame *tabFrame;
    QVBoxLayout *verticalLayout_8;
    QTabWidget *tabWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *labelBalance;

    void setupUi(QDialog *RestrictedAssetsDialog)
    {
        if (RestrictedAssetsDialog->objectName().isEmpty())
            RestrictedAssetsDialog->setObjectName(QString::fromUtf8("RestrictedAssetsDialog"));
        RestrictedAssetsDialog->resize(1168, 1000);
        verticalLayout = new QVBoxLayout(RestrictedAssetsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 20, 20, 20);
        frameAssetBalance = new QFrame(RestrictedAssetsDialog);
        frameAssetBalance->setObjectName(QString::fromUtf8("frameAssetBalance"));
        frameAssetBalance->setFrameShape(QFrame::StyledPanel);
        frameAssetBalance->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frameAssetBalance);
        verticalLayout_7->setSpacing(12);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(4, 4, 4, 4);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(12);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(4, 4, 4, 4);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(10);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(10, -1, -1, -1);
        labelAssetBalance = new QLabel(frameAssetBalance);
        labelAssetBalance->setObjectName(QString::fromUtf8("labelAssetBalance"));

        horizontalLayout_8->addWidget(labelAssetBalance);

        lineEditAssetSearch = new QLineEdit(frameAssetBalance);
        lineEditAssetSearch->setObjectName(QString::fromUtf8("lineEditAssetSearch"));

        horizontalLayout_8->addWidget(lineEditAssetSearch);


        verticalLayout_4->addLayout(horizontalLayout_8);

        listAssets = new QTableView(frameAssetBalance);
        listAssets->setObjectName(QString::fromUtf8("listAssets"));

        verticalLayout_4->addWidget(listAssets);


        verticalLayout_7->addLayout(verticalLayout_4);


        horizontalLayout->addWidget(frameAssetBalance);

        frameAddressList = new QFrame(RestrictedAssetsDialog);
        frameAddressList->setObjectName(QString::fromUtf8("frameAddressList"));
        frameAddressList->setFrameShape(QFrame::StyledPanel);
        frameAddressList->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frameAddressList);
        verticalLayout_10->setSpacing(12);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(12);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(4, 4, 4, 4);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        labelAddressList = new QLabel(frameAddressList);
        labelAddressList->setObjectName(QString::fromUtf8("labelAddressList"));

        horizontalLayout_9->addWidget(labelAddressList);

        lineEditAddressSearch = new QLineEdit(frameAddressList);
        lineEditAddressSearch->setObjectName(QString::fromUtf8("lineEditAddressSearch"));

        horizontalLayout_9->addWidget(lineEditAddressSearch);


        verticalLayout_9->addLayout(horizontalLayout_9);

        myAddressList = new QTableView(frameAddressList);
        myAddressList->setObjectName(QString::fromUtf8("myAddressList"));

        verticalLayout_9->addWidget(myAddressList);


        verticalLayout_10->addLayout(verticalLayout_9);


        horizontalLayout->addWidget(frameAddressList);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(34);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(40, 0, 40, 40);
        tabFrame = new QFrame(RestrictedAssetsDialog);
        tabFrame->setObjectName(QString::fromUtf8("tabFrame"));
        tabFrame->setFrameShape(QFrame::StyledPanel);
        tabFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(tabFrame);
        verticalLayout_8->setSpacing(12);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(4, 4, 4, 4);
        tabWidget = new QTabWidget(tabFrame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);

        verticalLayout_8->addWidget(tabWidget);


        horizontalLayout_4->addWidget(tabFrame);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(RestrictedAssetsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label, 0, Qt::AlignRight);

        labelBalance = new QLabel(RestrictedAssetsDialog);
        labelBalance->setObjectName(QString::fromUtf8("labelBalance"));
        sizePolicy.setHeightForWidth(labelBalance->sizePolicy().hasHeightForWidth());
        labelBalance->setSizePolicy(sizePolicy);
        labelBalance->setCursor(QCursor(Qt::IBeamCursor));
        labelBalance->setText(QString::fromUtf8("123.456 RVN"));
        labelBalance->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(labelBalance, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(RestrictedAssetsDialog);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(RestrictedAssetsDialog);
    } // setupUi

    void retranslateUi(QDialog *RestrictedAssetsDialog)
    {
        RestrictedAssetsDialog->setWindowTitle(QApplication::translate("RestrictedAssetsDialog", "Send Coins", nullptr));
        labelAssetBalance->setText(QApplication::translate("RestrictedAssetsDialog", "Asset Balances", nullptr));
        lineEditAssetSearch->setPlaceholderText(QApplication::translate("RestrictedAssetsDialog", "Search", nullptr));
        labelAddressList->setText(QApplication::translate("RestrictedAssetsDialog", "Address List", nullptr));
        lineEditAddressSearch->setPlaceholderText(QApplication::translate("RestrictedAssetsDialog", "Search", nullptr));
        label->setText(QApplication::translate("RestrictedAssetsDialog", "Balance:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RestrictedAssetsDialog: public Ui_RestrictedAssetsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTRICTEDASSETSDIALOG_H
