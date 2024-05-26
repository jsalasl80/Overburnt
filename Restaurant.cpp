#include "Restaurant.h"

Restaurant::Restaurant(){
    menu = new Menu();
    recipeReader = new RecipeReader(menu);
    accountant = new Accountant();

    customersInLine = new CustomersInLine();
    customerSpawner = new CustomerSpawner(customersInLine);

    ordersToDo = new ResultsQueue<Order*>();

    customersUnsatisfied = new ResultsQueue<int>();
    
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
    
    tSpawner.join();
    tKitchen.join();
    poolTables.join();
    tUnsatisfaction.join();

    delete threadPoolTables;
    printf("Simulation Ended");
}

void Restaurant::stopRestaurantSimulation(){
    printf("A total of %d unsatisfied customers registered", customersUnsatisfiedCount);
    customerSpawner -> stopSpawning();
    reportRestaurantCurrentState();
    kitchen -> stopOperating();

    threadPoolTables -> stopRunning();
    simulating = HALT_SIMULATING;
}

void Restaurant::updateUnsatisfactionCount(){
    while (simulating){
        bool empty = customersUnsatisfied -> isEmpty();
        if (!empty){
            customersUnsatisfiedCount += customersUnsatisfied -> dequeue();

            checkUnsatisfactionCount();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(MILLI_TO_SEC_CONV));
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