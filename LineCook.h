#ifndef LINECOOK_H
#define LINECOOK_H

#include "Includes.h"
#include "Constants.h"
#include "Order.h"
#include "Waiter.h"
#include "ResultsQueue.h"

class LineCook{
private:
    Order *order;
    bool state;
    ResultsQueue<Order*> *ordersToDeliver;

    mutex lineCookMutex;

public:
    LineCook(ResultsQueue<Order*> *_completedOrdersQueue);
    void prepareOrder(Order *order);
    void cookOrder();
    void deliverOrder();
    void getAvailability(std::promise<bool>&& availablePromise);
    void setState(bool _state);
};

#endif //LINECOOK_H