#ifndef WAITER_H
#define WAITER_H

#include "Includes.h"
#include "Constants.h"
#include "InventoryManager.h"
#include "Order.h"


class Waiter{
private:
    InventoryManager *inventoryManager;
    map<string, int> ordersTotalIngredientsAmounts;
    vector<Order*> customerOrders;

public:
    Waiter(InventoryManager* _inventoryManager);
    
    void attendTable(std::promise<bool>&& ordersPromise, vector<Order*>& orders);
    void extractIngredientsAndAmounts(Recipe* recipe);

    void insertIngredientAmount(string ingredientName, int ingredientAmount);
    void sendOrdersToKitchen();

    void deliverOrder(Order* order);
    
    void clearMap();
};
#endif