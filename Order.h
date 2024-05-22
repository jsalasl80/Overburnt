#ifndef ORDER_H
#define ORDER_H

#include "Includes.h"
#include "Constants.h"
#include "Recipe.h"
#include "Random.h"

class Order {
private:
    Recipe *recipe;//need some way to translate the number from the customer to a recipe on the menu
    int tableId;
    int customerId;
    bool orderState;
    int preparationTime;
    int eatingTime;

public:
    Order(int _tableId, int _customerId,  Recipe* _recipe);
        

    int getTableId();
    int getCustomerId();
    bool getOrderState();
    int getOrderPrepTime();
    int getOrderEatingTime();
    Recipe* getRecipe();
    
    void markAsCompleted();
    int calculateTime(int baseTime,int delay);
     
};

#endif 
