#include "simulationmenu.h"
#include "ui_simulationmenu.h"
#include "simulationover.h"


SimulationMenu::SimulationMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SimulationMenu)
{
    ui->setupUi(this);

    mMediaPlayer = new QMediaPlayer(this);
    mAudioOutput = new QAudioOutput(this);
    // Configura el reproductor de medios
    mMediaPlayer->setAudioOutput(mAudioOutput);
    mMediaPlayer->setSource(QUrl("qrc:/Music/PopSound.mp3"));
    mAudioOutput->setVolume(5); // Ajusta el volumen según sea necesario

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
    // Reproduce el audio
    mMediaPlayer->play();

    this->close();
}

void SimulationMenu::on_EndButton_clicked()
{
    mMediaPlayer->play();

    // Close all open windows
    qApp->closeAllWindows();

    // Show the SimulationOver window
    SimulationOver *so = new SimulationOver();
    so->show();
}


void SimulationMenu::on_WinningsButton_clicked()
{
    mMediaPlayer->play();

    QString message = "Report created.";

    // Crear un QMessageBox con un texto personalizado
    QMessageBox::information(nullptr, "Report", message);
}

