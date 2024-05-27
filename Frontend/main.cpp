#include "overburnt.h"
#include"ui_tastiestrestaurant.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OverBurntMain w;

    QMediaPlayer *player;

    w.show();
    return a.exec();
}
