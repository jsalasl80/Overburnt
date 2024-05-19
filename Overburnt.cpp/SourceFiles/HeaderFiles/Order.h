#ifndef ORDER_H
#define ORDER_H

#include "Includes.h"
#include "Constants.h"
#include "Recipe.h"

class Order {
private:
    Recipe recipeId;
    int waitTime;

public:
    Order(int recipeId) : recipeId(recipeId) {}

    int getRecipeId();
    int getWaitTime();

    void calculateWaitTime();
    bool isReady();
    void markAsCompleted();
};

#endif // ORDER_H
