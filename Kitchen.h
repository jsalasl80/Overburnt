#ifndef KITCHEN_H
#define KITCHEN_H

#include "Includes.h"
#include "Constants.h"
#include "RecipeReader.h"
#include "InventoryManager.h"
#include "ThreadPoolLineCooks.h"
#include "ThreadPoolDeliverers.h"
#include "ResultsQueue.h"

class Kitchen {
private:
    InventoryManager *inventoryManager;
    Inventory *inventory;

    ResultsQueue<Order*> *ordersToDeliver;
    ThreadPoolLineCooks *threadPoolLineCooks;
    ThreadPoolDeliverers *threadPoolDeliverers;

    LineCook** lineCooks;
    Deliverer** deliverers;


public:
    Kitchen(Accountant* accountant, ResultsQueue<Order*> *ordersToDo);
    ~Kitchen();
    void startOperating();
    void stopOperating();
    
    void reportCurrentState();

    void setLineCooks();
    void deleteLineCooks();

    void setDeliverers();
    void deleteDeliverers();

    InventoryManager* getInventoryManager();
};

#endif //KITCHEN_H