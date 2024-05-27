/********************************************************************************
** Form generated from reading UI file 'simulationover.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATIONOVER_H
#define UI_SIMULATIONOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SimulationOver
{
public:
    QPushButton *RestartButton;
    QPushButton *ShutDownButton;
    QLabel *TitleSimulationOver_pic;
    QLabel *LogoRestaurant_pic;
    QLabel *CatImage_pic;
    QLabel *FoodSimulationOver_pic;

    void setupUi(QDialog *SimulationOver)
    {
        if (SimulationOver->objectName().isEmpty())
            SimulationOver->setObjectName("SimulationOver");
        SimulationOver->resize(745, 444);
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
        SimulationOver->setPalette(palette);
        RestartButton = new QPushButton(SimulationOver);
        RestartButton->setObjectName("RestartButton");
        RestartButton->setGeometry(QRect(300, 100, 151, 61));
        RestartButton->setStyleSheet(QString::fromUtf8("#RestartButton{\n"
"background-color: transparent;\n"
"border-image: url(:/Images/RestartDayButton.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        ShutDownButton = new QPushButton(SimulationOver);
        ShutDownButton->setObjectName("ShutDownButton");
        ShutDownButton->setGeometry(QRect(270, 160, 211, 81));
        ShutDownButton->setStyleSheet(QString::fromUtf8("#ShutDownButton{\n"
"background-color: transparent;\n"
"border-image: url(:/Images/ShutDownButton.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        TitleSimulationOver_pic = new QLabel(SimulationOver);
        TitleSimulationOver_pic->setObjectName("TitleSimulationOver_pic");
        TitleSimulationOver_pic->setGeometry(QRect(140, 30, 421, 111));
        LogoRestaurant_pic = new QLabel(SimulationOver);
        LogoRestaurant_pic->setObjectName("LogoRestaurant_pic");
        LogoRestaurant_pic->setGeometry(QRect(20, 20, 111, 81));
        CatImage_pic = new QLabel(SimulationOver);
        CatImage_pic->setObjectName("CatImage_pic");
        CatImage_pic->setGeometry(QRect(550, 20, 181, 171));
        FoodSimulationOver_pic = new QLabel(SimulationOver);
        FoodSimulationOver_pic->setObjectName("FoodSimulationOver_pic");
        FoodSimulationOver_pic->setGeometry(QRect(30, 190, 661, 261));
        TitleSimulationOver_pic->raise();
        FoodSimulationOver_pic->raise();
        RestartButton->raise();
        ShutDownButton->raise();
        LogoRestaurant_pic->raise();
        CatImage_pic->raise();

        retranslateUi(SimulationOver);

        QMetaObject::connectSlotsByName(SimulationOver);
    } // setupUi

    void retranslateUi(QDialog *SimulationOver)
    {
        SimulationOver->setWindowTitle(QCoreApplication::translate("SimulationOver", "Simulation Over", nullptr));
        RestartButton->setText(QString());
        ShutDownButton->setText(QString());
        TitleSimulationOver_pic->setText(QString());
        LogoRestaurant_pic->setText(QString());
        CatImage_pic->setText(QString());
        FoodSimulationOver_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SimulationOver: public Ui_SimulationOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATIONOVER_H
