#include "Includes.h"
#include "Constants.h"
#include "Customer.h"

Customer::Customer(int id, const std::string& name)
    : id(id), name(name), status(CustomerStatus::Waiting), waitTime(0), eatingTime(0) {}

int Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}

CustomerStatus Customer::getStatus() const {
    return status;
}

int Customer::getOrderNumber() const {
    return orderNumber;
}

int Customer::getWaitTime() const {
    return waitTime;
}

int Customer::getEatingTime() const {
    return eatingTime;
}

void Customer::placeOrder(const std::vector<int>& menuItems) {
    // Implementation needed
}

void Customer::updateStatus(CustomerStatus newStatus) {
    status = newStatus;
}

int Customer::calculateTotalWait() const {
    // Implementation needed
}
