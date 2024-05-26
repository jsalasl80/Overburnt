#include "Order.h"

Order::Order(int _tableId, int _customerId,  Recipe* _recipe, Customer *_associatedCustomer):
    tableId(_tableId),
    customerId(_customerId),
    recipe(_recipe),
    associatedCustomer(_associatedCustomer),
    orderState(IN_PREPARATION),
    preparationTime(calculateTime(recipe->getApproxPrepTime(), PREP_DELAY)),
    eatingTime(calculateTime(recipe->getApproxEatingTime(), EATING_DELAY))
    {};

int Order::getTableId() const{
    return tableId;
}

int Order::getCustomerId() const{
    return customerId;
}

bool Order::getOrderState() const{
    return orderState;
}

int Order::getOrderPrepTime() const{
    return recipe -> getApproxPrepTime();
}

int Order::getOrderEatingTime() const{
    return recipe -> getApproxEatingTime();
}

Recipe* Order::getRecipe() const{
    return recipe;
}

Customer* Order::getAssociatedCustomer() const{
    return associatedCustomer;
}

void Order::markAsCompleted(){
    orderState = READY;
}

int Order::calculateTime(int baseTime, int delay){
    Random randomGenerator;
    int calculatedTime = baseTime +(baseTime*randomGenerator.generateBinaryRandom(NEGATIVE, POSITIVE)*randomGenerator.generateRandomInRange(0, delay));
    return (calculatedTime <= NONE) ? baseTime : calculatedTime;
}
