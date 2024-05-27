#include "simulationover.h"
#include "ui_simulationover.h"
#include "tastiestrestaurant.h"

static TastiestRestaurant *tastiestRestaurantInstance = nullptr;

SimulationOver::SimulationOver(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SimulationOver)
{
    ui->setupUi(this);

    mMediaPlayer = new QMediaPlayer(this);
    mAudioOutput = new QAudioOutput(this);
    mMediaPlayer->setAudioOutput(mAudioOutput);
    mMediaPlayer->setSource(QUrl("qrc:/Music/PopSound.mp3"));

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
        tastiestRestaurantInstance = new TastiestRestaurant(nullptr);
        tastiestRestaurantInstance->show();
    } else {
        tastiestRestaurantInstance->show();
    }

    this->accept();
}

