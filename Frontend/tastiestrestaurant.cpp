#include "tastiestrestaurant.h"
#include "ui_tastiestrestaurant.h"
#include "simulationmenu.h"
#include "simulationover.h"


TastiestRestaurant::TastiestRestaurant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TastiestRestaurant)
{
    ui->setupUi(this);

    QPixmap KitchenBar(":/Images/KitchenBar.png");
    ui->KitchenBar_pic->setPixmap(KitchenBar);

    QPixmap LogoRestaurant(":/Images/LogoRestaurant.png");
    ui->LogoRestaurant_pic->setPixmap(LogoRestaurant);

    QPixmap RoundTable1(":/Images/RoundTable.png");
    ui->RoundTable1_pic->setPixmap(RoundTable1);

    QPixmap RoundTable2(":/Images/RoundTable.png");
    ui->RoundTable2_pic->setPixmap(RoundTable2);

    QPixmap VerticalTable3(":/Images/VerticalTable.png");
    ui->VerticalTable3_pic->setPixmap(VerticalTable3);

    QPixmap VerticalTable4(":/Images/VerticalTable.png");
    ui->VerticalTable4_pic->setPixmap(VerticalTable4);

    QPixmap VerticalTable5(":/Images/VerticalTable.png");
    ui->VerticalTable5_pic->setPixmap(VerticalTable5);

    QPixmap HorizontalTable6(":/Images/HorizontalTable.png");
    ui->HorizontalTable6_pic->setPixmap(HorizontalTable6);

    QPixmap AngryClients(":/Images/AngryClients.png");
    ui->AngryClients_pic->setPixmap(AngryClients);

    QPixmap Client1(":/Images/Client1.png");
    ui->Sit0_0->setPixmap(Client1);

    QPixmap Client2(":/Images/Client1.png");
    ui->Sit1_0->setPixmap(Client2);

    QPixmap Client3(":/Images/Client1.png");
    ui->Sit2_0->setPixmap(Client3);

    QPixmap Client4(":/Images/Client1.png");
    ui->Sit3_0->setPixmap(Client4);

    QPixmap Client5(":/Images/Client1.png");
    ui->Sit4_0->setPixmap(Client5);

    QPixmap Client6(":/Images/Client1.png");
    ui->Sit5_0->setPixmap(Client6);

    QPixmap Client7(":/Images/Client1.png");
    ui->Sit0_1->setPixmap(Client7);

    QPixmap Client8(":/Images/Client1.png");
    ui->Sit1_1->setPixmap(Client8);

    QPixmap Client9(":/Images/Client1.png");
    ui->Sit2_1->setPixmap(Client9);

    QPixmap Client10(":/Images/Client1.png");
    ui->Sit3_1->setPixmap(Client10);

    QPixmap Client11(":/Images/Client1.png");
    ui->Sit4_1->setPixmap(Client11);

    QPixmap Client12(":/Images/Client1.png");
    ui->Sit5_1->setPixmap(Client12);

    QPixmap Client13(":/Images/Client1.png");
    ui->Sit0_2->setPixmap(Client13);

    QPixmap Client14(":/Images/Client1.png");
    ui->Sit1_2->setPixmap(Client14);

    QPixmap Client15(":/Images/Client1.png");
    ui->Sit2_2->setPixmap(Client15);

    QPixmap Client16(":/Images/Client1.png");
    ui->Sit3_2->setPixmap(Client16);

    QPixmap Client17(":/Images/Client1.png");
    ui->Sit4_2->setPixmap(Client17);

    QPixmap Client18(":/Images/Client1.png");
    ui->Sit5_2->setPixmap(Client18);

    QPixmap Client19(":/Images/Client1.png");
    ui->Sit0_3->setPixmap(Client19);

    QPixmap Client20(":/Images/Client1.png");
    ui->Sit1_3->setPixmap(Client20);

    QPixmap Client21(":/Images/Client1.png");
    ui->Sit2_3->setPixmap(Client21);

    QPixmap Client22(":/Images/Client1.png");
    ui->Sit3_3->setPixmap(Client22);

    QPixmap Client23(":/Images/Client1.png");
    ui->Sit4_3->setPixmap(Client23);

    QPixmap Client24(":/Images/Client1.png");
    ui->Sit5_3->setPixmap(Client24);

    QPixmap Client25(":/Images/Client1.png");
    ui->Sit0_4->setPixmap(Client25);

    QPixmap Client26(":/Images/Client1.png");
    ui->Sit1_4->setPixmap(Client26);

    QPixmap Client27(":/Images/Client1.png");
    ui->Sit2_4->setPixmap(Client27);

    QPixmap Client28(":/Images/Client1.png");
    ui->Sit3_4->setPixmap(Client28);

    QPixmap Client29(":/Images/Client1.png");
    ui->Sit4_4->setPixmap(Client29);

    QPixmap Client30(":/Images/Client1.png");
    ui->Sit5_4->setPixmap(Client30);

    QPixmap Client31(":/Images/Client1.png");
    ui->Sit0_5->setPixmap(Client31);

    QPixmap Client32(":/Images/Client1.png");
    ui->Sit1_5->setPixmap(Client32);

    QPixmap Client33(":/Images/Client1.png");
    ui->Sit2_5->setPixmap(Client33);

    QPixmap Client34(":/Images/Client1.png");
    ui->Sit3_5->setPixmap(Client34);

    QPixmap Client35(":/Images/Client1.png");
    ui->Sit4_5->setPixmap(Client35);

    QPixmap Client36(":/Images/Client1.png");
    ui->Sit5_5->setPixmap(Client36);

    QPixmap Waiter0(":/Images/Waiter.png");
    ui->Waiter0->setPixmap(Waiter0);

    QPixmap Waiter1(":/Images/Waiter.png");
    ui->Waiter1->setPixmap(Waiter1);

    QPixmap Waiter2(":/Images/Waiter.png");
    ui->Waiter2->setPixmap(Waiter2);

    QPixmap Waiter3(":/Images/Waiter.png");
    ui->Waiter3->setPixmap(Waiter3);

    QPixmap Waiter4(":/Images/Waiter.png");
    ui->Waiter4->setPixmap(Waiter4);

    QPixmap Waiter5(":/Images/Waiter.png");
    ui->Waiter5->setPixmap(Waiter5);

    QPixmap WaitingClients(":/Images/WaitingClients.png");
    ui->WaitingClients_pic->setPixmap(WaitingClients);

    QPixmap Dish1(":/Images/Dish1.png");
    ui->Dish0_0->setPixmap(Dish1);

    QPixmap Dish2(":/Images/Dish2.png");
    ui->Dish1_0->setPixmap(Dish2);

    QPixmap Dish3(":/Images/Dish3.png");
    ui->Dish2_0->setPixmap(Dish3);

    QPixmap Dish4(":/Images/Dish3.png");
    ui->Dish3_0->setPixmap(Dish4);

    QPixmap Dish5(":/Images/Dish3.png");
    ui->Dish4_0->setPixmap(Dish5);

    QPixmap Dish6(":/Images/Dish3.png");
    ui->Dish5_0->setPixmap(Dish6);

    QPixmap Dish7(":/Images/Dish3.png");
    ui->Dish0_1->setPixmap(Dish7);

    QPixmap Dish8(":/Images/Dish3.png");
    ui->Dish1_1->setPixmap(Dish8);

    QPixmap Dish9(":/Images/Dish3.png");
    ui->Dish2_1->setPixmap(Dish9);

    QPixmap Dish10(":/Images/Dish3.png");
    ui->Dish3_1->setPixmap(Dish10);

    QPixmap Dish11(":/Images/Dish3.png");
    ui->Dish4_1->setPixmap(Dish11);

    QPixmap Dish12(":/Images/Dish3.png");
    ui->Dish5_1->setPixmap(Dish12);

    QPixmap Dis13(":/Images/Dish3.png");
    ui->Dish0_2->setPixmap(Dis13);

    QPixmap Dish14(":/Images/Dish3.png");
    ui->Dish1_2->setPixmap(Dish14);

    QPixmap Dish15(":/Images/Dish3.png");
    ui->Dish2_2->setPixmap(Dish15);

    QPixmap Dish16(":/Images/Dish3.png");
    ui->Dish3_2->setPixmap(Dish16);

    QPixmap Dish17(":/Images/Dish3.png");
    ui->Dish4_2->setPixmap(Dish17);

    QPixmap Dish18(":/Images/Dish3.png");
    ui->Dish5_2->setPixmap(Dish18);

    QPixmap Dish19(":/Images/Dish3.png");
    ui->Dish0_3->setPixmap(Dish19);

    QPixmap Dish20(":/Images/Dish3.png");
    ui->Dish1_3->setPixmap(Dish20);

    QPixmap Dish21(":/Images/Dish3.png");
    ui->Dish2_3->setPixmap(Dish21);

    QPixmap Dish22(":/Images/Dish3.png");
    ui->Dish3_3->setPixmap(Dish22);

    QPixmap Dish23(":/Images/Dish3.png");
    ui->Dish4_3->setPixmap(Dish23);

    QPixmap Dish24(":/Images/Dish3.png");
    ui->Dish5_3->setPixmap(Dish24);

    QPixmap Dish25(":/Images/Dish3.png");
    ui->Dish0_4->setPixmap(Dish25);

    QPixmap Dish26(":/Images/Dish3.png");
    ui->Dish1_4->setPixmap(Dish26);

    QPixmap Dish27(":/Images/Dish3.png");
    ui->Dish2_4->setPixmap(Dish27);

    QPixmap Dish28(":/Images/Dish3.png");
    ui->Dish3_4->setPixmap(Dish28);

    QPixmap Dish29(":/Images/Dish3.png");
    ui->Dish4_4->setPixmap(Dish29);

    QPixmap Dish30(":/Images/Dish3.png");
    ui->Dish5_4->setPixmap(Dish30);

    QPixmap Dish31(":/Images/Dish3.png");
    ui->Dish0_5->setPixmap(Dish31);

    QPixmap Dish32(":/Images/Dish3.png");
    ui->Dish1_5->setPixmap(Dish32);

    QPixmap Dish33(":/Images/Dish3.png");
    ui->Dish2_5->setPixmap(Dish33);

    QPixmap Dish34(":/Images/Dish3.png");
    ui->Dish3_5->setPixmap(Dish34);

    QPixmap Dish35(":/Images/Dish3.png");
    ui->Dish4_5->setPixmap(Dish35);

    QPixmap Dish36(":/Images/Dish3.png");
    ui->Dish5_5->setPixmap(Dish36);

    // En tu función main() o en algún lugar apropiado antes de llamar a getRandomClient()
    srand(time(nullptr));
}

TastiestRestaurant::~TastiestRestaurant()
{
    delete ui;
}

void TastiestRestaurant::on_ManageSimulation_btn_clicked()
{
    ui->ManageSimulation_btn->setEnabled(false);

    SimulationMenu *sm = new SimulationMenu();
    sm->show();

    // Conectar la señal finished() de la ventana SimulationMenu
    // para habilitar el botón una vez que se cierre la ventana.
    connect(sm, &QDialog::finished, this, [=](){
        ui->ManageSimulation_btn->setEnabled(true);
    });
}

void TastiestRestaurant::closeEvent(QCloseEvent *event)
{
    // Show the SimulationOver window when the close button is clicked
    SimulationOver *so = new SimulationOver();
    so->show();

    // Close the OverBurntMain window
    event->accept();
}

void TastiestRestaurant::on_ButtonTable0_clicked()
{
    QString mensaje = "¡Hola desde un QString!";

    // Crear un QMessageBox con un texto personalizado
    QMessageBox::information(nullptr, "Reporte", mensaje);
}


void TastiestRestaurant::on_ButtonTable1_clicked()
{
    QString mensaje = "¡Hola desde un QString!";

    // Crear un QMessageBox con un texto personalizado
    QMessageBox::information(nullptr, "Reporte", mensaje);
}


void TastiestRestaurant::on_ButtonTable2_clicked()
{
    QString mensaje = "¡Hola desde un QString!";

    // Crear un QMessageBox con un texto personalizado
    QMessageBox::information(nullptr, "Reporte", mensaje);
}


void TastiestRestaurant::on_ButtonTable3_clicked()
{
    QString mensaje = "¡Hola desde un QString!";

    // Crear un QMessageBox con un texto personalizado
    QMessageBox::information(nullptr, "Título del MessageBox", mensaje);
}


void TastiestRestaurant::on_ButtonTable4_clicked()
{
    QString mensaje = "¡Hola desde un QString!";

    // Crear un QMessageBox con un texto personalizado
    QMessageBox::information(nullptr, "Reporte", mensaje);
}


void TastiestRestaurant::on_ButtonTable5_clicked()
{
    QString mensaje = "¡Hola desde un QString!";

    // Crear un QMessageBox con un texto personalizado
    QMessageBox::information(nullptr, "Reporte", mensaje);
}

int TastiestRestaurant::getRandomClient() {
    // Generate a random number between 1 and 2
    int random = rand() % 2 + 1;
    if (random == 1) {
        return 1; // Client1.png
    } else {
        return 2; // Client2.png
    }
}

void TastiestRestaurant::setClientImage(QLabel *label, int client) {
    // Set the label's pixmap to the corresponding client image
    if (client == 1) {
        label->setPixmap(QPixmap(":/Images/Client1.png"));
    } else {
        label->setPixmap(QPixmap(":/Images/Client2.png"));
    }
}

