#ifndef TASTIESTRESTAURANT_H
#define TASTIESTRESTAURANT_H

#include <QPixmap>
#include <QWidget>
#include <QCloseEvent>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <QMediaPlayer>
#include <QAudioOutput>

namespace Ui {
class TastiestRestaurant;
}

class TastiestRestaurant : public QWidget
{
    Q_OBJECT

public:
    explicit TastiestRestaurant(QWidget *parent = nullptr);
    ~TastiestRestaurant();

    int getRandomClient();

    void setClientImage(QLabel *label, int client);

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

private:
    Ui::TastiestRestaurant *ui;

    QMediaPlayer *mMediaPlayer;
    QAudioOutput *mAudioOutput;
};

#endif // TASTIESTRESTAURANT_H
