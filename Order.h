#ifndef ORDER_H
#define ORDER_H

#include "Includes.h"
#include "Constants.h"
#include "Recipe.h"

class Order {
private:
    Recipe *recipe;
    int tableId;
    int customerId;
    bool orderState;
    int preparationTime;
    int eatingTime;

public:
    Order(int _tableId, int _customerId,  Recipe* _recipe):
        tableId(_tableId),
        customerId(_customerId),
        recipe(_recipe),
        orderState(false)
        {};

    int getTableId();
    int getCustomerId();
    bool getOrderState();
    int getOrderPrepTime();
    int getOrderEatingTime();
    Recipe* getRecipe();
    
    void markAsCompleted();
    
    
};

#endif 
