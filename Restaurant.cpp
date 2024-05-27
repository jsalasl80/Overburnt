#include "Restaurant.h"

Restaurant::Restaurant(){
    menu = new Menu();
    recipeReader = new RecipeReader(menu);
    accountant = new Accountant();

    customersInLine = new CustomersInLine();
    customerSpawner = new CustomerSpawner(customersInLine);

    ordersToDo = new ResultsQueue<Order*>();

    customersUnsatisfied = new ResultsQueue<int>();
    customersUnsatisfiedCount = NONE;
    
    kitchen = new Kitchen(accountant, ordersToDo);

    setTables();
    threadPoolTables = new ThreadPoolTables(tables, customersInLine);

    simulating = true;
}

Restaurant::~Restaurant(){
    delete kitchen;
    delete menu;
    delete recipeReader;
    delete accountant;
    delete customerSpawner;
    cleanTables();
}

void Restaurant::startRestaurantSimulation(){
    std::thread tKitchen (&Kitchen::startOperating, kitchen);
    recipeReader -> setUpMenu();

    std::thread tSpawner(&CustomerSpawner::spawnClients, customerSpawner);
    std::thread poolTables(&ThreadPoolTables::run, threadPoolTables);
    std::thread tUnsatisfaction(&Restaurant::updateUnsatisfactionCount, this);

    joinThread(tSpawner);
    joinThread(tKitchen);
    joinThread(poolTables);
    joinThread(tUnsatisfaction);

    delete threadPoolTables;
}

void Restaurant::joinThread(std::thread& thread){
    if (thread.joinable()){
        thread.join();
    }
}

void Restaurant::stopRestaurantSimulation(){
    simulating = HALT_SIMULATING;
    threadPoolTables -> stopRunning();
    printf("A total of %d unsatisfied customers registered", customersUnsatisfiedCount);
    customerSpawner -> stopSpawning();
    reportRestaurantCurrentState();
    kitchen -> stopOperating();
}

void Restaurant::updateUnsatisfactionCount(){
    bool empty;
    while (simulating){
        empty = customersUnsatisfied -> isEmpty();
        if (!empty){
            customersUnsatisfiedCount += customersUnsatisfied -> dequeue();

            checkUnsatisfactionCount();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(SPAWN_RATE));
    }
}

void Restaurant::checkUnsatisfactionCount(){
    if(customersUnsatisfiedCount > MAX_UNSATISFIED_CUSTOMERS){
        printf("More than 100 unsatisfied clients registered, closing restaurant for today\n");
        stopRestaurantSimulation();
    }
}

void Restaurant::setTables(){
    tables = new Table*[TABLES_AMOUNT];
    Menu *pMenu = menu;
    InventoryManager *inventoryManager = kitchen -> getInventoryManager();
    
    ResultsQueue<int> *pCustomersUnsatisfied = customersUnsatisfied;
    for (int i = 0; i < TABLES_AMOUNT; ++ i){
        tables[i] = new Table(i, pMenu, inventoryManager, accountant, ordersToDo, pCustomersUnsatisfied);
    }
}

void Restaurant::cleanTables(){
    for (int i = 0; i < TABLES_AMOUNT; ++ i){
        delete tables[i];
    }
    delete[] tables;
}

string Restaurant::getTableState(int tableId){
    return tables[tableId] -> reportCurrentState();
}

Table** Restaurant::getTables(){
    return tables;
}

void Restaurant::reportRestaurantCurrentState(){
    kitchen -> reportCurrentState();
}

int Restaurant::getUnsatisfactionCount(){
    return customersUnsatisfiedCount;
}

int Restaurant::getCustomersInLineCount(){
    return customersInLine -> getCustomersInLine();
}