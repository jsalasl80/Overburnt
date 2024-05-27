/********************************************************************************
** Form generated from reading UI file 'overburnt.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERBURNT_H
#define UI_OVERBURNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OverBurntMain
{
public:
    QWidget *centralwidget;
    QLabel *FoodMenu_pic;
    QLabel *TitleMenu_pic;
    QLabel *LogoRestaurant_pic;
    QLabel *ChopsticksLMenu_pic;
    QLabel *ChopsticksRMenu_pic;
    QPushButton *ButtonMenu;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *OverBurntMain)
    {
        if (OverBurntMain->objectName().isEmpty())
            OverBurntMain->setObjectName("OverBurntMain");
        OverBurntMain->setWindowModality(Qt::WindowModal);
        OverBurntMain->setEnabled(true);
        OverBurntMain->resize(815, 491);
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OverBurntMain->sizePolicy().hasHeightForWidth());
        OverBurntMain->setSizePolicy(sizePolicy);
        OverBurntMain->setMinimumSize(QSize(0, 0));
        OverBurntMain->setMaximumSize(QSize(8000, 8000));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 239, 208, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 247, 231, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 119, 104, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 159, 139, 255));
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
        QBrush brush7(QColor(0, 0, 0, 127));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush2);
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
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
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
        QBrush brush8(QColor(127, 119, 104, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
        OverBurntMain->setPalette(palette);
        OverBurntMain->setAcceptDrops(false);
        OverBurntMain->setLayoutDirection(Qt::LeftToRight);
        OverBurntMain->setAutoFillBackground(true);
        centralwidget = new QWidget(OverBurntMain);
        centralwidget->setObjectName("centralwidget");
        FoodMenu_pic = new QLabel(centralwidget);
        FoodMenu_pic->setObjectName("FoodMenu_pic");
        FoodMenu_pic->setGeometry(QRect(160, 270, 511, 201));
        FoodMenu_pic->setMinimumSize(QSize(0, 0));
        FoodMenu_pic->setMaximumSize(QSize(1000, 1000));
        FoodMenu_pic->setAutoFillBackground(false);
        FoodMenu_pic->setFrameShape(QFrame::NoFrame);
        FoodMenu_pic->setFrameShadow(QFrame::Plain);
        FoodMenu_pic->setScaledContents(false);
        TitleMenu_pic = new QLabel(centralwidget);
        TitleMenu_pic->setObjectName("TitleMenu_pic");
        TitleMenu_pic->setGeometry(QRect(230, 70, 511, 221));
        TitleMenu_pic->setAutoFillBackground(false);
        LogoRestaurant_pic = new QLabel(centralwidget);
        LogoRestaurant_pic->setObjectName("LogoRestaurant_pic");
        LogoRestaurant_pic->setGeometry(QRect(350, 30, 101, 81));
        LogoRestaurant_pic->setAutoFillBackground(false);
        LogoRestaurant_pic->setStyleSheet(QString::fromUtf8("#LogoRestaurant_pic {\n"
"background-color: transparent;\n"
"border-image: url(://LogoRestaurant.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        ChopsticksLMenu_pic = new QLabel(centralwidget);
        ChopsticksLMenu_pic->setObjectName("ChopsticksLMenu_pic");
        ChopsticksLMenu_pic->setGeometry(QRect(0, 30, 211, 251));
        ChopsticksLMenu_pic->setAutoFillBackground(false);
        ChopsticksRMenu_pic = new QLabel(centralwidget);
        ChopsticksRMenu_pic->setObjectName("ChopsticksRMenu_pic");
        ChopsticksRMenu_pic->setGeometry(QRect(610, -10, 261, 311));
        ChopsticksRMenu_pic->setLayoutDirection(Qt::LeftToRight);
        ChopsticksRMenu_pic->setAutoFillBackground(false);
        ButtonMenu = new QPushButton(centralwidget);
        ButtonMenu->setObjectName("ButtonMenu");
        ButtonMenu->setGeometry(QRect(330, 220, 151, 61));
        ButtonMenu->setStyleSheet(QString::fromUtf8("#ButtonMenu {\n"
"background-color: transparent;\n"
"border-image: url(:/Images/ButtonMenu.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        OverBurntMain->setCentralWidget(centralwidget);
        TitleMenu_pic->raise();
        FoodMenu_pic->raise();
        LogoRestaurant_pic->raise();
        ChopsticksLMenu_pic->raise();
        ChopsticksRMenu_pic->raise();
        ButtonMenu->raise();
        menubar = new QMenuBar(OverBurntMain);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 815, 22));
        OverBurntMain->setMenuBar(menubar);
        statusbar = new QStatusBar(OverBurntMain);
        statusbar->setObjectName("statusbar");
        OverBurntMain->setStatusBar(statusbar);

        retranslateUi(OverBurntMain);

        QMetaObject::connectSlotsByName(OverBurntMain);
    } // setupUi

    void retranslateUi(QMainWindow *OverBurntMain)
    {
        OverBurntMain->setWindowTitle(QCoreApplication::translate("OverBurntMain", "OverBurnt Menu", nullptr));
        FoodMenu_pic->setText(QString());
        TitleMenu_pic->setText(QString());
        LogoRestaurant_pic->setText(QString());
        ChopsticksLMenu_pic->setText(QString());
        ChopsticksRMenu_pic->setText(QString());
        ButtonMenu->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OverBurntMain: public Ui_OverBurntMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERBURNT_H
