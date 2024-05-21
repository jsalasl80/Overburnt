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
    Customer(int id, const std::string& name);

    int getId() const;
    std::string getName() const;
    CustomerStatus getStatus() const;
    int getOrderNumber() const;
    int getWaitTime() const;
    int getEatingTime() const;

    void placeOrder(const std::vector<int>& menuItems);
    void updateStatus(CustomerStatus newStatus);
    int calculateTotalWait() const;
};

#endif // CUSTOMER_H
