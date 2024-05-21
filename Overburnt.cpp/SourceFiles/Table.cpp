#include "Includes.h"
#include "Constants.h"
#include "Table.h"

Table::Table(int id) : id(id), status("free") {}

int Table::getId() {
    return id;
}

std::string Table::getStatus() {
    return status;
}

Customer[] Table::getCustomers(){
    return customers;
}

void Table::seatCustomers(Customer[] customers) {
    this->customers = customers;//tbd, must be changed
    status = "occupied";
}

void Table::clearTable() {
    customers.clear();
    status = "free";
}

bool Table::isOccupied() {
    return status == "occupied";
}
