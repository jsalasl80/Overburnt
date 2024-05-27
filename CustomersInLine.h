#ifndef CUSTOMERSINLINE_H
#define CUSTOMERSINLINE_H
#include "Includes.h"
#include "Constants.h"
#include "Customer.h"
#include "ResultsQueue.h"

class CustomersInLine : private ResultsQueue<std::vector<Customer*>>{
private:
    std::mutex customerCounterMutex;
    int numCustomersInLine;
public:
    CustomersInLine();
    void addCustomers(std::vector<Customer*> customers);
    std::vector<Customer*> extractCustomers();
    int getCustomersInLine();
    bool isEmpty();
};

#endif //CUSTOMERSINLINE.H