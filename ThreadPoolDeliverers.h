#ifndef THREADPOOLDELIVERERS_H
#define THREADPOOLDELIVERERS_H

#include "Includes.h"
#include "Constants.h"
#include "ThreadPool.h"
#include "ResultsQueue.h"

#include "Deliverer.h"

class ThreadPoolDeliverers : private ThreadPool {
private:
    Deliverer** deliverers;
    ResultsQueue<Order*> *ordersToDeliver;
    bool running;
public:
    ThreadPoolDeliverers(Deliverer** _deliverers, ResultsQueue<Order*> *_ordersToDeliver);
    Deliverer* getAvailableDeliverer();
    void run();
    bool addDelivererToRotation(Deliverer *deliverer);
    void stopRunning();
};

#endif //THREADPOOLDELIVERERS_H