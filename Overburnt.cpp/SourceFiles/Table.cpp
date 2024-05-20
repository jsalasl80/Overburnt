#include "HeaderFiles/Table.h"

int Table::getId() {
    return id;
}

bool Table::getStatus() {
    return status;
}

std::vector<Customer*> Table::getCustomers() {
    return customers;
}

void Table::seatCustomers(std::vector<Customer*> customers) {
    this->customers = customers;
    status = OCCUPIED;
}

void Table::clearTable() {
    customers.clear();
    status = UNOCCUPIED;
}

bool Table::isOccupied() {
    return status;
}
