#include "Deliverer.h"

Deliverer::Deliverer(){
    state = CHILLING;
}

void Deliverer::deliverOrder(Order* order){
    std::lock_guard<mutex> lg(delivererMutex);

    Customer* targetCustomer = order -> getAssociatedCustomer();
    
    int eatingTime = order -> getOrderEatingTime();
    targetCustomer -> eat(eatingTime);

    this -> setState (CHILLING);
}

void Deliverer::getAvailability(std::promise<bool>&& availablePromise){
    //If it is able to lock the mutex, then the chef is available
    if (delivererMutex.try_lock()){
        availablePromise.set_value(state); //In case when a deliverer is assigned, but we come back to check way too soon
        delivererMutex.unlock();
    }
    else{
        availablePromise.set_value(DELIVERING);
    }
}

void Deliverer::setState(bool _state){
    state = _state;
}