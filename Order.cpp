#include "Order.h"

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
    orderState = READY;
}

