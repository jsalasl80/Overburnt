/********************************************************************************
** Form generated from reading UI file 'simulationmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATIONMENU_H
#define UI_SIMULATIONMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SimulationMenu
{
public:
    QLabel *SimulationMenuTitle_pic;
    QLabel *ReturnButton_pic;
    QLabel *EndButton_pic;
    QLabel *WinningsButton_pic;
    QPushButton *ReturnButton;
    QPushButton *EndButton;
    QPushButton *WinningsButton;

    void setupUi(QDialog *SimulationMenu)
    {
        if (SimulationMenu->objectName().isEmpty())
            SimulationMenu->setObjectName("SimulationMenu");
        SimulationMenu->resize(826, 460);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 210, 162, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(255, 232, 208, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(127, 105, 81, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 140, 108, 255));
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
        QBrush brush8(QColor(127, 105, 81, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        QBrush brush9(QColor(255, 247, 238, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush9);
        SimulationMenu->setPalette(palette);
        SimulationMenuTitle_pic = new QLabel(SimulationMenu);
        SimulationMenuTitle_pic->setObjectName("SimulationMenuTitle_pic");
        SimulationMenuTitle_pic->setGeometry(QRect(150, 20, 471, 181));
        ReturnButton_pic = new QLabel(SimulationMenu);
        ReturnButton_pic->setObjectName("ReturnButton_pic");
        ReturnButton_pic->setGeometry(QRect(-10, 190, 231, 141));
        EndButton_pic = new QLabel(SimulationMenu);
        EndButton_pic->setObjectName("EndButton_pic");
        EndButton_pic->setGeometry(QRect(230, 180, 291, 151));
        WinningsButton_pic = new QLabel(SimulationMenu);
        WinningsButton_pic->setObjectName("WinningsButton_pic");
        WinningsButton_pic->setGeometry(QRect(530, 180, 251, 161));
        ReturnButton = new QPushButton(SimulationMenu);
        ReturnButton->setObjectName("ReturnButton");
        ReturnButton->setGeometry(QRect(30, 330, 191, 61));
        ReturnButton->setStyleSheet(QString::fromUtf8("#ReturnButton{\n"
"background-color: transparent;\n"
"border-image: url(:/Images/ReturnButton.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        EndButton = new QPushButton(SimulationMenu);
        EndButton->setObjectName("EndButton");
        EndButton->setGeometry(QRect(310, 330, 201, 61));
        EndButton->setStyleSheet(QString::fromUtf8("#EndButton{\n"
"background-color: transparent;\n"
"border-image: url(:/Images/EndButton.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        WinningsButton = new QPushButton(SimulationMenu);
        WinningsButton->setObjectName("WinningsButton");
        WinningsButton->setGeometry(QRect(590, 330, 201, 61));
        WinningsButton->setStyleSheet(QString::fromUtf8("#WinningsButton{\n"
"background-color: transparent;\n"
"border-image: url(:/Images/WinningsButton.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));

        retranslateUi(SimulationMenu);

        QMetaObject::connectSlotsByName(SimulationMenu);
    } // setupUi

    void retranslateUi(QDialog *SimulationMenu)
    {
        SimulationMenu->setWindowTitle(QCoreApplication::translate("SimulationMenu", "SImulation Menu", nullptr));
        SimulationMenuTitle_pic->setText(QString());
        ReturnButton_pic->setText(QString());
        EndButton_pic->setText(QString());
        WinningsButton_pic->setText(QString());
        ReturnButton->setText(QString());
        EndButton->setText(QString());
        WinningsButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SimulationMenu: public Ui_SimulationMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATIONMENU_H
