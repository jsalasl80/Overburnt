#include "simulationmenu.h"
#include "ui_simulationmenu.h"
#include "simulationover.h"

SimulationMenu::SimulationMenu(QWidget *parent, TastiestRestaurant *tastiest, Restaurant* restaurant)
    : QDialog(parent)
    , ui(new Ui::SimulationMenu)
{
    ui->setupUi(this);
    this->restaurant = restaurant;
    this->tastiest = tastiest;

    mMediaPlayer = new QMediaPlayer(this);
    mAudioOutput = new QAudioOutput(this);
    mMediaPlayer->setAudioOutput(mAudioOutput);
    mMediaPlayer->setSource(QUrl("qrc:/Music/PopSound.mp3"));

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
    delete mMediaPlayer;
}

void SimulationMenu::on_ReturnButton_clicked()
{
    mMediaPlayer->play();

    this->close();
}

void SimulationMenu::on_EndButton_clicked()
{
    mMediaPlayer->play();
    restaurant -> stopRestaurantSimulation();
    tastiest -> stopSimulating();
    qApp->closeAllWindows();

    delete restaurant;
    SimulationOver *so = new SimulationOver();
    so->show();
}


void SimulationMenu::on_WinningsButton_clicked()
{
    mMediaPlayer->play();
    restaurant -> reportRestaurantCurrentState();
    QString message = "Report created (RestaurantReport.txt)";
    QMessageBox::information(nullptr, "Report", message);
}

