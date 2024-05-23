#include "Kitchen.h"

Kitchen::Kitchen(Accountant *accountant){
    inventory = new Inventory();
    inventoryManager = new InventoryManager(inventory, accountant);
}

Kitchen::~Kitchen(){
    delete inventoryManager;
}

void Kitchen::setUpKitchen(){
    inventoryManager -> setUpInventory();
}

void Kitchen::reportCurrentState(){
    inventoryManager -> reportInventoryState();
}

InventoryManager* Kitchen::getInventoryManager(){
    return inventoryManager;
}