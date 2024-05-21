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
    Order order;
    int waitTime;
    int eatingTime;

public:
    Customer(int id,  std::string& name);

    int getId();
    std::string getName();
    std::string getStatus();
    Order getOrder();
    int getWaitTime();
    int getEatingTime();

    void placeOrder(std::vector<int>& menuItems);
    void updateStatus(std::string& newStatus);
    int calculateTotalWait();
};

#endif // CUSTOMER_H
