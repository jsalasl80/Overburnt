#ifndef LINECOOK_H
#define LINECOOK_H

#include "Includes.h"
#include "Constants.h"
#include "Order.h"
#include "Waiter.h"

class LineCook{
private:
    Order *order;
    bool state;
public:
    LineCook();
    void prepareOrder(Order *order);
    void cookOrder();
    void deliverOrder();
};

#endif //LINECOOK_H
