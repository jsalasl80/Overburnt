#ifndef TASTIESTRESTAURANT_H
#define TASTIESTRESTAURANT_H
#include "IncludesFrontEnd.h"
#include "ConstantsFrontEnd.h"
#include "../Restaurant.h"
#include "../Random.h"
#include "../Includes.h"
#include "../Constants.h"

namespace Ui {
class TastiestRestaurant;
}

class TastiestRestaurant : public QWidget
{
    Q_OBJECT

public:
    explicit TastiestRestaurant(QWidget *parent = nullptr);
    ~TastiestRestaurant();

    int getRandomClientSkin();
    void setClientImage(QLabel *label, int client);

    int getRandomDish();
    void setDishImage(QLabel *label, int dish);

    void setWaiterImage(QLabel*label);

    void startSimulating();
    void stopSimulating();

    void updateRestaurantState();

    void updateTables();

    void updateCustomers(std::vector<Customer*>& customers, int tableId);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_ManageSimulation_btn_clicked();

    void on_ButtonTable0_clicked();

    void on_ButtonTable1_clicked();

    void on_ButtonTable2_clicked();

    void on_ButtonTable3_clicked();

    void on_ButtonTable4_clicked();

    void on_ButtonTable5_clicked();

    void reportTableState(int tableId);

    void labelUnsatisfiedCounterUpdate();
    void labelCustomersInLineCounterUpdate();

    void setPixMapCustomersLabels();
    void setPixMapWaitersLabels();
    void setPixMapDishesLabels();

private:
    Ui::TastiestRestaurant *ui;

    QMediaPlayer *mMediaPlayer;
    QAudioOutput *mAudioOutput;

    Restaurant *restaurant;
    Table** tables;
    Random *random;
    bool running;

    QVector<QVector<QLabel*>> customersLabels;
    QVector<QLabel*> waiterLabels;
    QVector<QVector<QLabel*>> dishesLabels;


};

#endif // TASTIESTRESTAURANT_H
