#include "ThreadPoolDeliverers.h"

ThreadPoolDeliverers::ThreadPoolDeliverers(Deliverer **_deliverers, ResultsQueue<Order *> *_ordersToDeliver): 
    ThreadPool(DELIVERERS_AMOUNT),
    deliverers(_deliverers),
    ordersToDeliver(_ordersToDeliver){};

Deliverer *ThreadPoolDeliverers::getAvailableDeliverer(){
    std::promise<bool> availablePromise;
    std::future<bool> availableFuture = availablePromise.get_future();
    bool delivererOccupied;
    Deliverer *ptrDeliverer = nullptr;

    // Check for the first available table, using promise and future
    for (int i = 0; i < DELIVERERS_AMOUNT; ++i){
        thread t(&Deliverer::getAvailability, deliverers[i], std::move(availablePromise));
        delivererOccupied = availableFuture.get();
        t.join();

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
    while (!stop){
        if (deliverersCheckable){
            deliverer = getAvailableDeliverer();
        }

        if (deliverer != nullptr){
            deliverersCheckable = addDelivererToRotation(deliverer);
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