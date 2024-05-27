#include "CustomersInLine.h"

CustomersInLine::CustomersInLine():
    ResultsQueue(),
    numCustomersInLine(NONE){};

int CustomersInLine::getCustomersInLine(){
    return numCustomersInLine;
}

void CustomersInLine::addCustomers(std::vector<Customer*> customers){
    enqueue(customers);
    numCustomersInLine += customers.size();
}

std::vector<Customer*> CustomersInLine::extractCustomers(){
    std::vector<Customer*> customers = dequeue();
    numCustomersInLine -= customers.size();
    return customers;
}

bool CustomersInLine::isEmpty(){
    return numCustomersInLine == NONE;
}

