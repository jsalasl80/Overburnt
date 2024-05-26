#include "LineCook.h"

LineCook::LineCook(ResultsQueue<Order*> *_completedOrdersQueue):
    state(CHILLING),
    ordersToDeliver(_completedOrdersQueue)
    {}

void LineCook::prepareOrder(Order *order){
    std::lock_guard<mutex> lg(lineCookMutex);
    this->order = order;
    cookOrder();
    order -> markAsCompleted();
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

void LineCook::getAvailability(std::promise<bool>&& availablePromise){
    //If it is able to lock the mutex, then the chef is available
    if (lineCookMutex.try_lock()){
        availablePromise.set_value(state); //In case we entered to check again but this line cook was already deployed
        lineCookMutex.unlock();
    }
    else{
        availablePromise.set_value(COOKING);
    }
}

void LineCook::setState(bool _state){
    state = _state;
}