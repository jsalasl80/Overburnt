#include "Order.h"

Order::Order(int _tableId, int _customerId,  Recipe* _recipe):
    tableId(_tableId),
    customerId(_customerId),
    recipe(_recipe),
    orderState(false),
    preparationTime(calculateTime(recipe->getApproxPrepTime(), PREP_DELAY)),
    eatingTime(calculateTime(recipe->getApproxEatingTime(), EATING_DELAY))
    {};

int Order::getTableId() {
    return tableId;
}

int Order::getCustomerId() {
    return customerId;
}

bool Order::getOrderState() {
    return orderState;
}

int Order::getOrderPrepTime() {
    return recipe -> getApproxPrepTime();
}

int Order::getOrderEatingTime() {
    return recipe -> getApproxEatingTime();
}

Recipe* Order::getRecipe(){
    return recipe;
}
void Order::markAsCompleted() {
    orderState = true;
}
int Order::calculateTime(int baseTime,int delay){
    Random randomGenerator;
    int calculatedTime = baseTime +(baseTime*randomGenerator.generateBinaryRandom(NEGATIVE, POSITIVE)*randomGenerator.generateRandomInRange(0, delay));
    return (calculatedTime <= NONE) ? baseTime : calculatedTime;
}

