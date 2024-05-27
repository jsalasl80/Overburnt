#ifndef OVERBURNT_H
#define OVERBURNT_H

#include <QMainWindow>
#include <QPixmap>
#include <QCloseEvent>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class OverBurntMain;
}
QT_END_NAMESPACE

class OverBurntMain : public QMainWindow
{
    Q_OBJECT

public:
    OverBurntMain(QWidget *parent = nullptr);
    ~OverBurntMain();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_ButtonMenu_clicked();

private:
    Ui::OverBurntMain *ui;

    QMediaPlayer *mMediaPlayer;
    QAudioOutput *mAudioOutput;

    QMediaPlayer *nMediaPlayer;
    QAudioOutput *nAudioOutput;
};
#endif // OVERBURNT_H
