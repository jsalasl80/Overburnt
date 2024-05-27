#ifndef SIMULATIONOVER_H
#define SIMULATIONOVER_H

#include <QDialog>
#include <QPixmap>
#include <QCloseEvent>
#include <QMediaPlayer>
#include <QAudioOutput>

namespace Ui {
class SimulationOver;
}

class SimulationOver : public QDialog
{
    Q_OBJECT

public:
    explicit SimulationOver(QWidget *parent = nullptr);
    ~SimulationOver();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_ShutDownButton_clicked();

    void on_RestartButton_clicked();

signals:
    void aboutToClose();

private:
    Ui::SimulationOver *ui;

    QMediaPlayer *mMediaPlayer;
    QAudioOutput *mAudioOutput;
};

#endif // SIMULATIONOVER_H
