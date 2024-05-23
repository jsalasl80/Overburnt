#include "LineCook.h"

LineCook::LineCook(): state(CHILLING){}

void LineCook::prepareOrder(Order *order){
    state = COOKING;

    this->order = order;
    cookOrder();
    order -> markAsCompleted();
    deliverOrder();

    state = CHILLING;
}

void LineCook::cookOrder(){
    int preparationTime = order -> getOrderPrepTime();
    std::this_thread::sleep_for(std::chrono::milliseconds(preparationTime));
}

void LineCook::deliverOrder(){
    //Enqueue order to waiter threadpool with deliverOrder function and order
}