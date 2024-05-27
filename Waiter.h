#ifndef WAITER_H
#define WAITER_H

#include "Includes.h"
#include "Constants.h"
#include "InventoryManager.h"
#include "Order.h"
#include "ResultsQueue.h"
#include "Accountant.h"

class Waiter{
private:
    InventoryManager *inventoryManager;
    std::map<string, int> ordersTotalIngredientsAmounts;
    vector<Order*> customersOrders;
    ResultsQueue<Order*> *ordersToDo;
    Accountant *accountant;

public:
    Waiter(InventoryManager* _inventoryManager, Accountant *_accountant, ResultsQueue<Order*> *_ordersToDo);
    
    void attendTable(std::promise<bool>&& ordersPromise, vector<Order*>& orders);
    bool attendTable(vector<Order*>& orders);

    void extractIngredientsAndAmounts(Recipe* recipe);

    const std::map<std::string,int> getOrdersTotalIngredientsAmounts() const;
    void insertIngredientAmount(string ingredientName, int ingredientAmount);
    void sendOrdersToKitchen();
    void addWinnings();

    void clearMap();
    void clearOrders();
};
#endif