#include "Includes.h"
#include "Constants.h"
#include "Customer.h"

Customer::Customer(int id,std::string& name)
    : id(id), name(name), status(CustomerStatus::Waiting), waitTime(0), eatingTime(0) {}

int Customer::getId()  {
    return id;
}

std::string Customer::getName()  {
    return name;
}

CustomerStatus Customer::getStatus()  {
    return status;
}

int Customer::getOrderNumber()  {
    return orderNumber;
}

int Customer::getWaitTime()  {
    return waitTime;
}

int Customer::getEatingTime()  {
    return eatingTime;
}

void Customer::placeOrder( std::vector<int>& menuItems) {
    
}

void Customer::updateStatus(CustomerStatus newStatus) {
    status = newStatus;
}

int Customer::calculateTotalWait()  {
}
