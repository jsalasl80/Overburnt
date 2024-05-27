#include "overburnt.h"
#include "ui_overburnt.h"
#include "tastiestrestaurant.h"
#include "simulationover.h"

OverBurntMain::OverBurntMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OverBurntMain)
{
    ui->setupUi(this);

    QPixmap FoodMenu(":/Images/FoodMenu.png");
    ui->FoodMenu_pic->setPixmap(FoodMenu);

    QPixmap TitleMenu(":/Images/TitleMenu.png");
    ui->TitleMenu_pic->setPixmap(TitleMenu);

    QPixmap LogoRestaurant(":/Images/LogoRestaurant.png");
    ui->LogoRestaurant_pic->setPixmap(LogoRestaurant);

    QPixmap ChopsticksLMenu(":/Images/ChopsticksLMenu.png");
    ui->ChopsticksLMenu_pic->setPixmap(ChopsticksLMenu);

    QPixmap ChopsticksRMenu(":/Images/ChopsticksRMenu.png");
    ui->ChopsticksRMenu_pic->setPixmap(ChopsticksRMenu);

    mMediaPlayer = new QMediaPlayer(this);
    mAudioOutput = new QAudioOutput(this);
    mMediaPlayer->setAudioOutput(mAudioOutput);
    mMediaPlayer->setSource(QUrl("qrc:/Music/BackgroundMusic.mp3"));
    mMediaPlayer->play();
}

OverBurntMain::~OverBurntMain()
{
    delete ui;
    delete mMediaPlayer;
    delete nMediaPlayer;
}

void OverBurntMain::on_ButtonMenu_clicked()
{
    nMediaPlayer = new QMediaPlayer(this);
    nAudioOutput = new QAudioOutput(this);
    nMediaPlayer->setAudioOutput(nAudioOutput);
    nMediaPlayer->setSource(QUrl("qrc:/Music/PopSound.mp3"));
    nMediaPlayer->play();

    this->hide();

    TastiestRestaurant *tr = new TastiestRestaurant();

    tr->show();
}

void OverBurntMain::closeEvent(QCloseEvent *event)
{
    SimulationOver *so = new SimulationOver();
    so->show();

    event->accept();
}
