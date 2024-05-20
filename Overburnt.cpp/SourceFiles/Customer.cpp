#include "HeaderFiles/Customer.h"

int Customer::getId()  {
    return id;
}

std::string Customer::getName()  {
    return name;
}

//do we need this tho. we do need a toString
std::string Customer::getStatus()  {
    return status;
}

Order *Customer::getOrder()  {
    return order;
}

int Customer::getWaitTime()  {
    return waitTime;
}

int Customer::getEatingTime()  {
    return eatingTime;
}

int Customer::placeOrder() {
    //generate random number from 0 to total amount of menu items - 1
}

void Customer::updateStatus(std::string newStatus) {
    status = newStatus;
}

int Customer::calculateTotalWait()  {
}
