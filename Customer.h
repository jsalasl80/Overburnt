#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Includes.h"
#include "Constants.h"
#include "CustomerStatus.h"
#include "Order.h"

class Customer {
private:
    int id;
    std::string name;
    CustomerStatus status;
    Order *order;
    int orderNumber;
    int waitTime;//amount of time waited 
    int eatingTime;// amount of time needed to eat, will be sent to the statistics aswell.


public:
    Customer(int id, const std::string& name);

    int getId() const;
    std::string getName() const;
    CustomerStatus getStatus() const;
    int getOrderNumber() const;
    int getWaitTime() const;
    int getEatingTime() const;

    void setOrder(Order * _order);
    void setEatingTime(int time);

    void updateStatus(CustomerStatus newStatus);
    int calculateTotalWait() const;

    void eat();
};

#endif // CUSTOMER_H
