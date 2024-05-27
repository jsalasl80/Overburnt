#include "simulationmenu.h"
#include "ui_simulationmenu.h"
#include "simulationover.h"


SimulationMenu::SimulationMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SimulationMenu)
{
    ui->setupUi(this);

    QPixmap SimulationMenuTitle(":/Images/SimulationMenuTitle.png");
    ui->SimulationMenuTitle_pic->setPixmap(SimulationMenuTitle);

    QPixmap ImageReturn(":/Images/ImageReturn.png");
    ui->ReturnButton_pic->setPixmap(ImageReturn);

    QPixmap ImageEnd(":/Images/ImageEnd.png");
    ui->EndButton_pic->setPixmap(ImageEnd);

    QPixmap ImageWinnings(":/Images/ImageWinnings.png");
    ui->WinningsButton_pic->setPixmap(ImageWinnings);

}

SimulationMenu::~SimulationMenu()
{
    delete ui;
}

void SimulationMenu::on_ReturnButton_clicked()
{
    this->close();
}

void SimulationMenu::on_EndButton_clicked()
{
    // Close all open windows
    qApp->closeAllWindows();

    // Show the SimulationOver window
    SimulationOver *so = new SimulationOver();
    so->show();
}


void SimulationMenu::on_WinningsButton_clicked()
{
    QString mensaje = "¡Hola desde un QString!";

    // Crear un QMessageBox con un texto personalizado
    QMessageBox::information(nullptr, "Reporte", mensaje);
}

