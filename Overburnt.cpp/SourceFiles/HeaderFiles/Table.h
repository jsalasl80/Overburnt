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

    int getId();
    bool getStatus();
    vector<Customer> getCustomers() ;

    void seatCustomers( vector<Customer>& customers);
    void clearTable();
    bool isOccupied() ;
};

#endif // TABLE_H
