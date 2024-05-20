#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Includes.h"
#include "Constants.h"
#include "Order.h"

class Customer {
private:
    int id;
    std::string name;
    std::string status;
    Order *order;
    int waitTime;
    int eatingTime;

public:
    Customer(int id, std::string& name):
        id(id), name(name), status(WAITING), waitTime(NONE), eatingTime(NONE){};

    int getId();
    std::string getName();
    std::string getStatus();
    Order* getOrder(); // do we need this 
    int getWaitTime();
    int getEatingTime();

    int placeOrder();
    void updateStatus(std::string newStatus);
    int calculateTotalWait();
};

#endif // CUSTOMER_H
