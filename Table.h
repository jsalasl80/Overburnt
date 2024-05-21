#ifndef TABLE_H
#define TABLE_H

#include "Includes.h"
#include "Constants.h"
#include <vector>
#include "Customer.h"

using namespace std;

class Table {
private:
    int id;
    bool status; // false = empty, true = occupied
    vector<Customer> customers;

public:
    Table(int id);

    int getId() const;
    bool getStatus() const;
    vector<Customer> getCustomers() const;

    void seatCustomers(const vector<Customer>& customers);
    void clearTable();
    bool isOccupied() const;
};

#endif // TABLE_H
