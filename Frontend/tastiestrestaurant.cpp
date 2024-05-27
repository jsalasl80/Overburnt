#include "tastiestrestaurant.h"
#include "ui_tastiestrestaurant.h"
#include "simulationmenu.h"
#include "simulationover.h"

TastiestRestaurant::TastiestRestaurant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TastiestRestaurant)
{
    ui->setupUi(this);

    restaurant = new Restaurant();
    tables = restaurant -> getTables();
    random = new Random();

    mMediaPlayer = new QMediaPlayer(this);
    mAudioOutput = new QAudioOutput(this);
    mMediaPlayer->setAudioOutput(mAudioOutput);
    mMediaPlayer->setSource(QUrl("qrc:/Music/PopSound.mp3"));

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

    customersLabels = {{ui->Sit0_0, ui->Sit1_0, ui->Sit2_0, ui->Sit3_0, ui->Sit4_0, ui->Sit5_0},
                        {ui->Sit0_1, ui->Sit1_1, ui->Sit2_1, ui->Sit3_1, ui->Sit4_1, ui->Sit5_1},
                        {ui->Sit0_2, ui->Sit1_2, ui->Sit2_2, ui->Sit3_2, ui->Sit4_3, ui->Sit5_4},
                        {ui->Sit0_3, ui->Sit1_3, ui->Sit2_3, ui->Sit3_3, ui->Sit4_3, ui->Sit5_3},
                        {ui->Sit0_4, ui->Sit1_4, ui->Sit2_4, ui->Sit3_4, ui->Sit4_4, ui->Sit5_4},
                        {ui->Sit0_5, ui->Sit1_5, ui->Sit2_5, ui->Sit3_5, ui->Sit4_5, ui->Sit5_5}};

    waiterLabels = {ui->Waiter0, ui->Waiter1, ui->Waiter2, ui->Waiter3, ui->Waiter4, ui->Waiter5};

    dishesLabels = {{ui->Dish0_0, ui->Dish1_0, ui->Dish2_0, ui->Dish3_0, ui->Dish4_0, ui->Dish5_0},
                      {ui->Dish0_1, ui->Dish1_1, ui->Dish2_1, ui->Dish3_1, ui->Dish4_1, ui->Dish5_1},
                      {ui->Dish0_2, ui->Dish1_2, ui->Dish2_2, ui->Dish3_2, ui->Dish4_3, ui->Dish5_4},
                      {ui->Dish0_3, ui->Dish1_3, ui->Dish2_3, ui->Dish3_3, ui->Dish4_3, ui->Dish5_3},
                      {ui->Dish0_4, ui->Dish1_4, ui->Dish2_4, ui->Dish3_4, ui->Dish4_4, ui->Dish5_4},
                      {ui->Dish0_5, ui->Dish1_5, ui->Dish2_5, ui->Dish3_5, ui->Dish4_5, ui->Dish5_5}};

    setPixMapCustomersLabels();
    setPixMapWaitersLabels();
    setPixMapDishesLabels();

    startSimulating();
}

void TastiestRestaurant::setPixMapCustomersLabels(){
    QPixmap Client(EMPTY);
    for (auto labelVector : this->customersLabels){
        for (auto label : labelVector){
            label->setPixmap(Client);
        }
    }
}

void TastiestRestaurant::setPixMapWaitersLabels(){
    QPixmap Waiter(EMPTY);
    for (auto label : this->waiterLabels){
        label->setPixmap(Waiter);
    }
}

void TastiestRestaurant::setPixMapDishesLabels(){
    QPixmap Dish(EMPTY);
    for (auto labelVector : this->customersLabels){
        for (auto label : labelVector){
            label->setPixmap(Dish);
        }
    }
}

TastiestRestaurant::~TastiestRestaurant()
{
    delete ui;
    delete mMediaPlayer;
    delete random;
}

void TastiestRestaurant::startSimulating(){
    std::thread t(&Restaurant::startRestaurantSimulation, restaurant);
    updateRestaurantState();
    if (t.joinable()){
        t.join();
    }
}

void TastiestRestaurant::stopSimulating(){
    running = false;
}

void TastiestRestaurant::updateRestaurantState(){
    while (running){
        labelUnsatisfiedCounterUpdate();
        labelCustomersInLineCounterUpdate();

        std::this_thread::sleep_for(std::chrono::milliseconds(MILLI_TO_SEC_CONV));
    }
}

void TastiestRestaurant::updateTables(){
    bool tableOccupied;
    Table *table;
    for (int i = 0; i < TABLES_AMOUNT; ++i){
        table = tables[i];
        tableOccupied = table -> isOccupied();
        if (tableOccupied){
            std::vector<Customer*> customers = table -> getCustomers();
            updateCustomers(customers, i);
        }
    }
}

void TastiestRestaurant::updateCustomers(std::vector<Customer*>& customers, int tableId){
    int customerSkin;
    int dishAppearance;
    for (size_t i = 0; i < customers.size(); ++i){
        customerSkin = getRandomClientSkin();
        setClientImage (customersLabels[tableId][i], customerSkin);
        if (customers[i]-> getStatus() == CustomerStatus::Ordering){
            setWaiterImage(waiterLabels[tableId]);
        }
        if (customers[i]-> getStatus() == CustomerStatus::Eating){
            dishAppearance = getRandomDish();
            setDishImage(dishesLabels[tableId][i], dishAppearance);
        }

    }
}

void TastiestRestaurant::on_ManageSimulation_btn_clicked()
{
    mMediaPlayer->play();

    ui->ManageSimulation_btn->setEnabled(false);

    SimulationMenu *sm = new SimulationMenu(nullptr, this, restaurant);
    sm->show();

    connect(sm, &QDialog::finished, this, [=](){
        ui->ManageSimulation_btn->setEnabled(true);
    });
}

void TastiestRestaurant::closeEvent(QCloseEvent *event)
{
    SimulationOver *so = new SimulationOver();
    so->show();

    event->accept();
}

void TastiestRestaurant::labelUnsatisfiedCounterUpdate(){
    int unsatisfactionCount = restaurant -> getUnsatisfactionCount();
    QString unsatisfactionStr = QString::fromStdString(to_string(unsatisfactionCount));
    ui -> CountAngryClients -> setText(unsatisfactionStr);
}

void TastiestRestaurant::labelCustomersInLineCounterUpdate(){
    int customersInLine = restaurant -> getCustomersInLineCount();
    QString customersInLineStr = QString::fromStdString(to_string(customersInLine));
    ui -> CountWaitingClients -> setText(customersInLineStr);
}

void TastiestRestaurant::reportTableState(int tableId){
    Table* table = tables[tableId];
    QString message = QString::fromStdString(table -> reportCurrentState());
    QMessageBox::information(nullptr, "Table Report", message);
}

void TastiestRestaurant::on_ButtonTable0_clicked()
{
    reportTableState(0);
}


void TastiestRestaurant::on_ButtonTable1_clicked()
{
    reportTableState(1);
}


void TastiestRestaurant::on_ButtonTable2_clicked()
{
    reportTableState(2);
}


void TastiestRestaurant::on_ButtonTable3_clicked()
{
    reportTableState(3);
}


void TastiestRestaurant::on_ButtonTable4_clicked()
{
    reportTableState(4);
}


void TastiestRestaurant::on_ButtonTable5_clicked()
{
    reportTableState(5);
}

int TastiestRestaurant::getRandomClientSkin() {
    return random -> generateBinaryRandom(CLIENT_TYPE_1, CLIENT_TYPE_2);
}

void TastiestRestaurant::setClientImage(QLabel *label, int client) {
    if (client == CLIENT_TYPE_1) {
        label->setPixmap(QPixmap(":/Images/Client1.png"));
    } else {
        label->setPixmap(QPixmap(":/Images/Client2.png"));
    }
}

int TastiestRestaurant::getRandomDish(){
    return random -> generateRandomInRange(DISH_TYPE_1, DISH_TYPE_12);
}

void TastiestRestaurant::setDishImage(QLabel *label, int dish){
    if (dish == DISH_TYPE_1){
        label -> setPixmap(QPixmap(":/Images/Dish1.png"));
    }
    else if (dish == DISH_TYPE_2){
        label -> setPixmap(QPixmap(":/Images/Dish2.png"));
    }
    else if (dish == DISH_TYPE_3){
        label -> setPixmap(QPixmap(":/Images/Dish3.png"));
    }
    else if (dish == DISH_TYPE_4){
        label -> setPixmap(QPixmap(":/Images/Dish4.png"));
    }
    else if (dish == DISH_TYPE_5){
        label -> setPixmap(QPixmap(":/Images/Dish5.png"));
    }
    else if (dish == DISH_TYPE_6){
        label -> setPixmap(QPixmap(":/Images/Dish6.png"));
    }
    else if (dish == DISH_TYPE_7){
        label -> setPixmap(QPixmap(":/Images/Dish7.png"));
    }
    else if (dish == DISH_TYPE_8){
        label -> setPixmap(QPixmap(":/Images/Dish8.png"));
    }
    else if (dish == DISH_TYPE_9){
        label -> setPixmap(QPixmap(":/Images/Dish9.png"));
    }
    else if (dish == DISH_TYPE_10){
        label -> setPixmap(QPixmap(":/Images/Dish10.png"));
    }
    else if (dish == DISH_TYPE_11){
        label -> setPixmap(QPixmap(":/Images/Dish11.png"));
    }
    else if (dish == DISH_TYPE_12){
        label -> setPixmap(QPixmap(":/Images/Dish12.png"));
    }
}

void TastiestRestaurant::setWaiterImage(QLabel*label){
    label->setPixmap(QPixmap("::/Images/Waiter.png"));
}
