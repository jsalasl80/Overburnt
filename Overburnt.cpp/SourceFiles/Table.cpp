#include "Includes.h"
#include "Constants.h"
#include "Table.h"

Table::Table(int id) : id(id), status("free") {}

int Table::getId() const {
    return id;
}

std::string Table::getStatus() const {
    return status;
}

std::vector<Customer> Table::getCustomers() const {
    return customers;
}

void Table::seatCustomers(const std::vector<Customer>& customers) {
    this->customers = customers;
    status = "occupied";
}

void Table::clearTable() {
    customers.clear();
    status = "free";
}

bool Table::isOccupied() const {
    return status == "occupied";
}
