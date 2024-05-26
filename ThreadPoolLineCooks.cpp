#include "ThreadPoolLineCooks.h"

ThreadPoolLineCooks::ThreadPoolLineCooks(LineCook** _lineCooks, ResultsQueue<Order*> *_ordersToDo):
    ThreadPool(LINE_COOKS_AMOUNT),
    lineCooks(_lineCooks),
    ordersToDo(_ordersToDo)
{};

LineCook* ThreadPoolLineCooks::getAvailableLineCook(){
    std::promise<bool> availablePromise;
    std::future<bool> availableFuture = availablePromise.get_future();
    bool lineCookOccupied;
    LineCook* ptrLineCook = nullptr;

    //Check for the first available table, using promise and future
    for (int i = 0; i < LINE_COOKS_AMOUNT; ++i){
        thread t(&LineCook::getAvailability, lineCooks[i], std::move(availablePromise));
        lineCookOccupied = availableFuture.get();
        t.join();

        if (!lineCookOccupied){
            ptrLineCook = lineCooks[i];
            ptrLineCook -> setState(COOKING);
            break;
        }
    }
    return ptrLineCook;
}

void ThreadPoolLineCooks::run(){
    bool lineCooksCheckable = true; //Represents the need to go get an available line cook
    LineCook *lineCook = nullptr;
    while (!stop){
        if (lineCooksCheckable){
            lineCook = getAvailableLineCook();
        }
        
        if (lineCook != nullptr){
            lineCooksCheckable = addLineCookToRotation(lineCook);
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(MILLI_TO_SEC_CONV));

    }
}

bool ThreadPoolLineCooks::addLineCookToRotation(LineCook *lineCook){
    bool addedToRotation = NOT_ADDED;
    Order* order;

    if (!ordersToDo -> isEmpty()){
        order = ordersToDo -> dequeue();

        enqueue(&LineCook::prepareOrder, lineCook, order);

        addedToRotation = ADDED;
    }

    return addedToRotation;
}