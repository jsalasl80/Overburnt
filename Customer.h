#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Includes.h"
#include "Constants.h"
#include "CustomerStatus.h"
#include "Random.h"

class Customer {
private:
    int id;
    std::string name;
    std::string orderedMenuItemName;
    CustomerStatus status;
    double waitingTime;//amount of time waited 
    int eatingTime;// amount of time needed to eat, will be sent to the statistics as well.
    std::chrono::time_point<std::chrono::system_clock> waitingTimeStart, eatingTimeStart;
    
    double getElapsedWaitTime() const;
    double getElapsedEatingTime() const;
    std::string durationToString(double) const;

public:
    Customer(int id, const std::string& name);

    int getId() const;
    std::string getName() const;
    CustomerStatus getStatus() const;
    int getEatingTime();
    double getWaitingTime();

    int orderFromMenu(int availableMenuItems);

    void setEatingTime(int time);
    void setOrderedMenuItem(std::string& itemName);
    void setWaitingTimeStart();
    void setEatingTimeStart();
    void setTotalWaitingTime();

    void updateStatus(CustomerStatus newStatus);
    int calculateTotalWait() const;

    void eat(int eatingTime);
    
    std::string toStringStatus();
};

#endif // CUSTOMER_H
