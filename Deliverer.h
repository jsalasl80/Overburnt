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
    bool getAvailability();
    void setState(bool _state);
};

#endif //DELIVER_H