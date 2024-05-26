#include "CustomersInLine.h"

CustomersInLine::CustomersInLine():
    ResultsQueue(),
    numCustomersInLine(NONE){};

int CustomersInLine::getCustomersInLine(){
    return numCustomersInLine;
}

void CustomersInLine::addCustomers(std::vector<Customer*> customers){
    std::lock_guard<std::mutex> lg(customerCounterMutex);
    printf("%i customers added to line\n", customers.size());
    enqueue(customers);
    numCustomersInLine += customers.size();
}

std::vector<Customer*> CustomersInLine::extractCustomers(){
    std::lock_guard<std::mutex> lg(customerCounterMutex);
    std::vector<Customer*> customers = dequeue();
    numCustomersInLine -= customers.size();
    return customers;
}

bool CustomersInLine::isEmpty(){
    return numCustomersInLine == NONE;
}

