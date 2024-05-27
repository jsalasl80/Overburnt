#include "Customer.h"
using namespace std;

Customer::Customer(int id, const std::string& name)
    : id(id), name(name), orderedMenuItemName(NONE_STRING), status(CustomerStatus::Waiting), waitingTime(NONE_DOUBLE), eatingTime(NONE) {}

int Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}

CustomerStatus Customer::getStatus() const {
    return status;
}

int Customer::orderFromMenu(int availableMenuItems){
    Random random;
    return random.generateRandomInRange(0, availableMenuItems);
}

void Customer::setEatingTime(int time) {
    eatingTime = time;
}

void Customer::setOrderedMenuItem(std::string& itemName){
    orderedMenuItemName = itemName;
    printf("Customer %s ordered %s\n", name.c_str(), orderedMenuItemName.c_str());
}

void Customer:: setWaitingTimeStart(){
    waitingTimeStart = std::chrono::system_clock::now();
}

void Customer:: setEatingTimeStart(){
    eatingTimeStart = std::chrono::system_clock::now();
}

void Customer:: setTotalWaitingTime(){
    waitingTime = getElapsedWaitTime();
}

void Customer::updateStatus(CustomerStatus newStatus) {
    status = newStatus;
}

int Customer::calculateTotalWait() const {
    return waitingTime + eatingTime;
}

void Customer::eat(int eatingTime){
    if(getStatus() == CustomerStatus::WaitingForFood){
        setTotalWaitingTime();
        setEatingTimeStart();
        setEatingTime(eatingTime);
        updateStatus(CustomerStatus::Eating);

        printf("%s eating %s for %i milliseconds\n", name.c_str(), orderedMenuItemName.c_str(), eatingTime);
        std::this_thread::sleep_for(std::chrono::milliseconds(eatingTime));

        updateStatus(CustomerStatus::WaitingToLeave);
    }
}

std::string Customer::toStringStatus(){
    std::string statusString = "Customer " + to_string(id) + ": " + name + "\n";
    if (status == CustomerStatus::Waiting){
        return statusString + "Status: Waiting to order\n";
    }
    else if (status == CustomerStatus::Ordering){
        return statusString + "Status: Ordering\n";
    }
    else if (status == CustomerStatus::WaitingForFood){
        statusString += "Status: Waiting for food\n";
        statusString += "Ordered: " + orderedMenuItemName + "\n";
        statusString += "Elapsed waiting time: " + durationToString(getElapsedWaitTime())  + "\n";
    }
    else if (status == CustomerStatus::Eating){
        statusString += "Status: Eating\n";
        statusString += "Ordered: " + orderedMenuItemName + "\n";
        statusString += "Total waiting time: " + to_string(waitingTime) + "\n";
        statusString += "Elapsed eating time: " + durationToString(getElapsedEatingTime()) + "\n";
    }
    else if (status == CustomerStatus::WaitingToLeave){
        statusString += "Status: Waiting to leave\n";
        statusString += "Ordered: " + orderedMenuItemName + "\n";
        statusString += "Total waiting time: " + to_string(waitingTime) + "\n";
        statusString += "Total eating time: " + to_string(eatingTime / MILLI_TO_SEC_CONV) + " seconds\n";
    }

    return statusString;
}

double Customer::getElapsedWaitTime() const{
    std::chrono::duration<double> elapsed = std::chrono::system_clock::now() - waitingTimeStart;
    return elapsed.count();
}

double Customer::getElapsedEatingTime() const{
    std::chrono::duration<double> elapsed = std::chrono::system_clock::now() - eatingTimeStart;
    return elapsed.count();
}

std::string Customer::durationToString(double duration) const{
    double duration_in_seconds = duration;
    std::stringstream ss;

    // insert the duration value into the stream
    ss << duration_in_seconds << " seconds";

    // extract the string representation of the duration value from the stringstream object
    std::string duration_str = ss.str();

    return duration_str;
}

int Customer::getEatingTime(){
    return eatingTime;
}
double Customer::getWaitingTime(){
    return waitingTime;
}