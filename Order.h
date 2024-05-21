#ifndef ORDER_H
#define ORDER_H

#include "Includes.h"
#include "Constants.h"
#include "Recipe.h"

class Order {
private:
    int customerId;
    int preparationTime;// based on formula Tiempo estimado + (Tiempo estimado * BINARY_RANDOM(1,-1) * RANDOM_RANGE(0, PREP_DELAY))
    int tableId;
    bool isReady;
    Recipe recipe;//the recipe assigned to this recipeID, can be removed based on how waiter manages the recipe

public:
    Order(int _customerId) : 
        customerId(_customerId),
         {}


    int getRecipeId();
    int getWaitTime();

    void calculateWaitTime();
    bool isReady();
    void markAsCompleted();
};

#endif // ORDER_H
