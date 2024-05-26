#include "Deliverer.h"

Deliverer::Deliverer(){
    state = CHILLING;
}

void Deliverer::deliverOrder(Order* order){
    std::lock_guard<mutex> lg(delivererMutex);
    
    Customer* targetCustomer = order -> getAssociatedCustomer();
    printf("Deliverer delivering to %s\n",targetCustomer -> getName().c_str());
    
    int eatingTime = order -> getOrderEatingTime();
    targetCustomer -> eat(eatingTime);

    this -> setState (CHILLING);
}

bool Deliverer::getAvailability(){
    bool availability = COOKING;
    if (delivererMutex.try_lock()){
        availability = state;
        delivererMutex.unlock();
    }
    return availability;
}

void Deliverer::setState(bool _state){
    state = _state;
}