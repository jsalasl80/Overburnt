#include "Includes.h"
#include "Constants.h"
#include "Table.h"

Table::Table(int id) : id(id), status(false) {}

int Table::getId() const {
    return id;
}

bool Table::getStatus() const {
    return status;
}

std::vector<Customer> Table::getCustomers() const {
    return customers;
}
void Table::setStatus(bool _status){
    status = _status;
}

void Table::seatCustomers(const std::vector<Customer>& customers) {
    this->customers = customers;
    setStatus(true);
}

void Table::clearTable() {
    customers.clear();
    status = "free";
}

bool Table::isOccupied() const {
    return status == "occupied";
}
