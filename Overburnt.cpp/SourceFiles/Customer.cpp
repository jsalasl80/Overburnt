#include "Includes.h"
#include "Constants.h"
#include "Customer.h"

Customer::Customer(int id,std::string& name)
    : id(id), name(name), status("waiting"), waitTime(0), eatingTime(0) {}

int Customer::getId()  {
    return id;
}

std::string Customer::getName()  {
    return name;
}

std::string Customer::getStatus()  {
    return status;
}

Order Customer::getOrder()  {
    return order;
}

int Customer::getWaitTime()  {
    return waitTime;
}

int Customer::getEatingTime()  {
    return eatingTime;
}

void Customer::placeOrder( std::vector<int>& menuItems) {
    
}

void Customer::updateStatus( std::string& newStatus) {
    status = newStatus;
}

int Customer::calculateTotalWait()  {
}
