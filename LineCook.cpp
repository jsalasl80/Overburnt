#include "LineCook.h"

LineCook::LineCook(ResultsQueue<Order*> *_completedOrdersQueue):
    state(CHILLING),
    ordersToDeliver(_completedOrdersQueue)
    {}

void LineCook::prepareOrder(Order *order){
    std::lock_guard<mutex> lg(lineCookMutex);
    printf("Line cook preparing order\n");
    this->order = order;
    cookOrder();
    order -> markAsCompleted();
    deliverOrder();
    this -> setState(CHILLING);
    printf("Line cook chilling\n");
}

void LineCook::cookOrder(){
    int preparationTime = order -> getOrderPrepTime();
    printf("Preparing %s for %i milliseconds\n", order->getRecipe() -> getRecipeName().c_str(), preparationTime);
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