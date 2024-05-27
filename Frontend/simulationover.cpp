#include "simulationover.h"
#include "ui_simulationover.h"
#include "tastiestrestaurant.h"

// Declarar una variable estática para almacenar la instancia de TastiestRestaurant
static TastiestRestaurant *tastiestRestaurantInstance = nullptr;

SimulationOver::SimulationOver(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SimulationOver)
{
    ui->setupUi(this);

    mMediaPlayer = new QMediaPlayer(this);
    mAudioOutput = new QAudioOutput(this);
    // Configura el reproductor de medios
    mMediaPlayer->setAudioOutput(mAudioOutput);
    mMediaPlayer->setSource(QUrl("qrc:/Music/PopSound.mp3"));
    mAudioOutput->setVolume(5); // Ajusta el volumen según sea necesario

    QPixmap FoodSimulationOver(":/Images/FoodSimulationOver.png");
    ui->FoodSimulationOver_pic->setPixmap(FoodSimulationOver);

    QPixmap TitleSimulationOver(":/Images/TitleSimulationOver.png");
    ui->TitleSimulationOver_pic->setPixmap(TitleSimulationOver);

    QPixmap LogoRestaurant(":/Images/LogoRestaurant.png");
    ui->LogoRestaurant_pic->setPixmap(LogoRestaurant);

    QPixmap CatImage(":/Images/CatImage.png");
    ui->CatImage_pic->setPixmap(CatImage);

    connect(ui->RestartButton, &QPushButton::clicked, this, &SimulationOver::on_RestartButton_clicked);

}

SimulationOver::~SimulationOver()
{
    delete ui;
}

void SimulationOver::closeEvent(QCloseEvent *event)
{
    // Close the OverBurntMain window
    event->accept();
}

void SimulationOver::on_ShutDownButton_clicked()
{
    mMediaPlayer->play();

    exit(0);
}


void SimulationOver::on_RestartButton_clicked()
{
    mMediaPlayer->play();

    if (!tastiestRestaurantInstance) {
        // Si no hay una instancia de TastiestRestaurant, crear una nueva
        tastiestRestaurantInstance = new TastiestRestaurant(nullptr);
        tastiestRestaurantInstance->show();
    } else {
        // Si ya existe una instancia de TastiestRestaurant, simplemente mostrarla
        tastiestRestaurantInstance->show();
    }

    // Cerrar la ventana actual
    this->accept();
}

