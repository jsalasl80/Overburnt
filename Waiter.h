#ifndef WAITER_H
#define WAITER_H

#include "Includes.h"
#include "Constants.h"
#include "InventoryManager.h"
#include "Table.h"
#include "Order.h"
#include "Menu.h"
#include "Kitchen.h"

class Waiter{
private:
    InventoryManager *inventoryManager;
    Menu *menu;
    map<string, int> ordersTotalIngredientsAmounts;
    queue<Order*> customerOrders;

public:
    Waiter(InventoryManager *_inventoryManager, Menu *_menu):
        inventoryManager(_inventoryManager),
        menu(_menu){};
    
    bool attendTable(Table*);
    void addOrder(Order*);

    void insertIngredientAmount(string, int);
    void sendOrdersToKitchen();
    void deliverOrder(Order*);
    
    void clearMap();
};
#endif