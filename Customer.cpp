#include "Includes.h"
#include "Constants.h"
#include "Customer.h"

Customer::Customer(int _id, const std::string& _name):
    id(_id),
    name(_name),
    status(CustomerStatus::Waiting),
    waitTime(0),
    eatingTime(0) {}

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

void Customer::setOrder(Order* _order){
    order = _order;
}

void Customer::setEatingTime(int time) {
    eatingTime = time;
}

void Customer::updateStatus(CustomerStatus newStatus) {
    status = newStatus;
}

int Customer::calculateTotalWait() const {
    return waitTime + eatingTime;
}

void Customer::eat(){
    if(getStatus() == CustomerStatus::Eating){//puede cambiar eating antes por el waiter
        std::this_thread::sleep_for(std::chrono::seconds(getEatingTime()));
        updateStatus(CustomerStatus::WaitingToLeave);
        delete order;
        //delete aca de la order
    }
}
