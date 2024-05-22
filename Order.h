#ifndef ORDER_H
#define ORDER_H

#include "Includes.h"
#include "Constants.h"
#include "Recipe.h"
#include "Random.h"

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
        orderState(false){
        preparationTime = calculateTime(recipe->getApproxPrepTime(),PREP_DELAY);
        eatingTime = calculateTime(recipe->getApproxEatingTime(),EATING_DELAY);
        };

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
