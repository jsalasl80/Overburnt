#include "LineCook.h"

LineCook::LineCook(ResultsQueue<Order*> *_completedOrdersQueue):
    state(CHILLING),
    ordersToDeliver(_completedOrdersQueue)
    {}

void LineCook::prepareOrder(Order *order){
    std::lock_guard<mutex> lg(lineCookMutex);
    this->order = order;
    cookOrder();
    this-> order -> markAsCompleted();
    deliverOrder();
    this -> setState(CHILLING);
}

void LineCook::cookOrder(){
    int preparationTime = order -> getOrderPrepTime();
    std::this_thread::sleep_for(std::chrono::milliseconds(preparationTime));
}

void LineCook::deliverOrder(){
    ordersToDeliver -> enqueue(order);
}

bool LineCook::getAvailability(){
    bool availability = COOKING;
    if (lineCookMutex.try_lock()){
        availability = state;
        lineCookMutex.unlock();
    }
    return availability;
}

void LineCook::setState(bool _state){
    state = _state;
}