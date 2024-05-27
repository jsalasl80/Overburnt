#ifndef SIMULATIONMENU_H
#define SIMULATIONMENU_H

#include "IncludesFrontEnd.h"
#include "tastiestrestaurant.h"

namespace Ui {
class SimulationMenu;
}

class SimulationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SimulationMenu(QWidget *parent = nullptr, TastiestRestaurant *tastiest = nullptr, Restaurant *restaurant = nullptr);
    ~SimulationMenu();


private slots:
    void on_ReturnButton_clicked();

    void on_EndButton_clicked();

    void on_WinningsButton_clicked();

private:
    Ui::SimulationMenu *ui;

    QMediaPlayer *mMediaPlayer;
    QAudioOutput *mAudioOutput;
    Restaurant *restaurant;
    TastiestRestaurant *tastiest;
};

#endif // SIMULATIONMENU_H
