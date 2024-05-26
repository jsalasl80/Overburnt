#ifndef THREADPOOLDELIVERERS_H
#define THREADPOOLDELIVERERS_H

#include "Includes.h"
#include "Constants.h"
#include "ThreadPool.h"
#include "ResultsQueue.h"

#include "Deliverer.h"

class ThreadPoolDeliverers : public ThreadPool {
private:
    Deliverer** deliverers;
    ResultsQueue<Order*> *ordersToDeliver;
public:
    ThreadPoolDeliverers(Deliverer** _deliverers, ResultsQueue<Order*> *_ordersToDeliver);
    Deliverer* getAvailableDeliverer();
    void run();
    bool addDelivererToRotation(Deliverer *deliverer);
};

#endif //THREADPOOLDELIVERERS_H