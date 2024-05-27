#ifndef SIMULATIONMENU_H
#define SIMULATIONMENU_H

#include <QDialog>
#include <QPixmap>
#include <QMessageBox>

namespace Ui {
class SimulationMenu;
}

class SimulationMenu : public QDialog
{
    Q_OBJECT

public:
    explicit SimulationMenu(QWidget *parent = nullptr);
    ~SimulationMenu();


private slots:
    void on_ReturnButton_clicked();

    void on_EndButton_clicked();

    void on_WinningsButton_clicked();

private:
    Ui::SimulationMenu *ui;

};

#endif // SIMULATIONMENU_H
