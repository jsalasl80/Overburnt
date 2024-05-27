#include "Deliverer.h"

Deliverer::Deliverer(){
    state = CHILLING;
}

void Deliverer::deliverOrder(Order* order){
    std::lock_guard<mutex> lg(delivererMutex);
    
    Customer* targetCustomer = order -> getAssociatedCustomer();
    if (targetCustomer){
        printf("Deliverer delivering to %s\n",targetCustomer -> getName().c_str());
    
        int eatingTime = order -> getOrderEatingTime();
        targetCustomer -> eat(eatingTime);
    }
    
    this -> setState (CHILLING);
}

bool Deliverer::getAvailability(){
    return state;
}

void Deliverer::setState(bool _state){
    state = _state;
}

bool Deliverer::getState(){
    return state;
}