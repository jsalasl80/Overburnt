#ifndef KITCHEN_H
#define KITCHEN_H

#include "Includes.h"
#include "Constants.h"
#include "RecipeReader.h"
#include "InventoryManager.h"
#include "LineCook.h"

class Kitchen {
private:
    InventoryManager *inventoryManager;
    Inventory *inventory;
    
public:
    Kitchen(Accountant*);
    ~Kitchen();
    void setUpKitchen();
    void reportCurrentState();
    InventoryManager* getInventoryManager();
};

#endif //KITCHEN_H