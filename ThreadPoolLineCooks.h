#ifndef THREADPOOLLINECOOKS_H
#define THREADPOOLLINECOOKS_H

#include "Includes.h"
#include "Constants.h"
#include "ThreadPool.h"
#include "ResultsQueue.h"

#include "LineCook.h"

class ThreadPoolLineCooks : private ThreadPool {
private:
    LineCook** lineCooks;
    ResultsQueue<Order*> *ordersToDo;
    bool running;
public:
    ThreadPoolLineCooks(LineCook** _lineCooks, ResultsQueue<Order*> *_ordersToDo);
    LineCook* getAvailableLineCook();
    void run();
    bool addLineCookToRotation(LineCook *cook);
    void stopRunning();
};

#endif //THREADPOOLLINECOOKS_H