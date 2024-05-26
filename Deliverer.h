#ifndef DELIVERER_H
#define DELIVERER_H

#include "Includes.h"
#include "Constants.h"
#include "Order.h"
#include "Customer.h"

class Deliverer{
private: 
    bool state;
    mutex delivererMutex;
public:
    Deliverer();
    void deliverOrder(Order* orderToDeliver);
    void getAvailability(std::promise<bool>&& availablePromise);
    void setState(bool _state);
};

#endif //DELIVERER_H