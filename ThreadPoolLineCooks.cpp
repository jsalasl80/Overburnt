#include "ThreadPoolLineCooks.h"

ThreadPoolLineCooks::ThreadPoolLineCooks(LineCook** _lineCooks, ResultsQueue<Order*> *_ordersToDo):
    ThreadPool(LINE_COOKS_AMOUNT),
    lineCooks(_lineCooks),
    running(true),
    ordersToDo(_ordersToDo)
{};

LineCook* ThreadPoolLineCooks::getAvailableLineCook(){
    bool lineCookOccupied;
    LineCook* ptrLineCook = nullptr;

    //Check for the first available table, using promise and future
    for (int i = 0; i < LINE_COOKS_AMOUNT; ++i){
        lineCookOccupied = lineCooks[i] -> getAvailability();

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
    while (running){
        if (lineCooksCheckable){
            lineCook = getAvailableLineCook();
        }
        
        if (lineCook != nullptr){
            lineCooksCheckable = addLineCookToRotation(lineCook);
        }
        else{
            std::this_thread::sleep_for(std::chrono::milliseconds(5*MILLI_TO_SEC_CONV));
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

void ThreadPoolLineCooks::stopRunning(){
    running = false;
}
bool ThreadPoolLineCooks::getRunning(){
    return running;
}