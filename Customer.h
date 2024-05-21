#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Includes.h"
#include "Constants.h"
#include "CustomerStatus.h"


class Customer {
private:
    int id;
    std::string name;
    CustomerStatus status;
    int orderNumber;
    int waitTime;
    int eatingTime;

public:
    Customer(int id,  std::string& name);

    int getId();
    std::string getName();
    CustomerStatus getStatus();
    int getOrderNumber();
    int getWaitTime();
    int getEatingTime();
    

    void placeOrder(std::vector<int>& menuItems);
    void updateStatus(CustomerStatus newStatus);
    int calculateTotalWait();
};

#endif // CUSTOMER_H
