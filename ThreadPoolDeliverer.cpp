#include "ThreadPoolDeliverers.h"

ThreadPoolDeliverers::ThreadPoolDeliverers(Deliverer **_deliverers, ResultsQueue<Order *> *_ordersToDeliver): 
    ThreadPool(DELIVERERS_AMOUNT),
    deliverers(_deliverers),
    ordersToDeliver(_ordersToDeliver),
    running(true)
    {};

Deliverer *ThreadPoolDeliverers::getAvailableDeliverer(){
    bool delivererOccupied;
    Deliverer *ptrDeliverer = nullptr;

    // Check for the first available deliverer
    for (int i = 0; i < DELIVERERS_AMOUNT; ++i){
        delivererOccupied = deliverers[i] -> getAvailability();

        if (!delivererOccupied){
            ptrDeliverer = deliverers[i];
            ptrDeliverer->setState(DELIVERING);
            break;
        }
    }
    return ptrDeliverer;
}

void ThreadPoolDeliverers::run()
{
    bool deliverersCheckable = true; // Represents the need to go get an available deliverer
    Deliverer *deliverer = nullptr;
    while (running){
        if (deliverersCheckable){
            deliverer = getAvailableDeliverer();
        }

        if (deliverer != nullptr){
            printf("Deliverer selected\n");
            deliverersCheckable = addDelivererToRotation(deliverer);
        }
        else{
            std::this_thread::sleep_for(std::chrono::milliseconds(5*MILLI_TO_SEC_CONV));
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(MILLI_TO_SEC_CONV));
    }
}

bool ThreadPoolDeliverers::addDelivererToRotation(Deliverer *deliverer){
    bool addedToRotation = NOT_ADDED;
    Order* order;
    if (!ordersToDeliver -> isEmpty()){
        order = ordersToDeliver -> dequeue();

        enqueue(&Deliverer::deliverOrder, deliverer, order);

        addedToRotation = ADDED;
    }

    return addedToRotation;
}

void ThreadPoolDeliverers::stopRunning(){
    running = false;
}