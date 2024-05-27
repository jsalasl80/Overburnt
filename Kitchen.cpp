#include "Kitchen.h"

Kitchen::Kitchen(Accountant *accountant, ResultsQueue<Order*> *ordersToDo){
    inventory = new Inventory();
    inventoryManager = new InventoryManager(inventory, accountant);

    ordersToDeliver = new ResultsQueue<Order*>();
    setLineCooks();
    threadPoolLineCooks = new ThreadPoolLineCooks(lineCooks, ordersToDo);

    setDeliverers();
    ResultsQueue<Order *> *pOrdersToDeliver = ordersToDeliver;
    threadPoolDeliverers = new ThreadPoolDeliverers(deliverers, pOrdersToDeliver);
}

Kitchen::~Kitchen(){
    printf("Kitchen Destructor called\n");
    delete inventoryManager;
    delete ordersToDeliver;
    deleteDeliverers();
    deleteLineCooks();
}

void Kitchen::startOperating(){
    inventoryManager -> setUpInventory();
    std::thread poolLineCooks(&ThreadPoolLineCooks::run, threadPoolLineCooks);
    std::thread poolDeliverers(&ThreadPoolDeliverers::run, threadPoolDeliverers);
    if (poolLineCooks.joinable()){
        poolLineCooks.join();
    }

    if (poolDeliverers.joinable()){
        poolDeliverers.join();
    }
    delete threadPoolLineCooks;
    delete threadPoolDeliverers;
}

void Kitchen::stopOperating(){
    threadPoolDeliverers -> stopRunning();
    threadPoolLineCooks -> stopRunning();
    
}

void Kitchen::reportCurrentState(){
    inventoryManager -> reportInventoryState();
}

void Kitchen::setLineCooks(){
    lineCooks = new LineCook*[LINE_COOKS_AMOUNT];
    for(int i = 0; i < LINE_COOKS_AMOUNT; i++){
        lineCooks[i] = new LineCook(ordersToDeliver);
    }
}

void Kitchen::deleteLineCooks(){
    for(int i = 0; i < LINE_COOKS_AMOUNT; i++){
        delete lineCooks[i];
    }
    delete[] lineCooks;
}

void Kitchen::setDeliverers(){
    deliverers = new Deliverer*[DELIVERERS_AMOUNT];
    for(int i = 0; i < DELIVERERS_AMOUNT; i++){
        deliverers[i] = new Deliverer();
    }
}

void Kitchen::deleteDeliverers(){
    for(int i = 0; i < DELIVERERS_AMOUNT; i++){
        delete deliverers[i];
    }
    delete [] deliverers;
}

InventoryManager* Kitchen::getInventoryManager(){
    return inventoryManager;
}