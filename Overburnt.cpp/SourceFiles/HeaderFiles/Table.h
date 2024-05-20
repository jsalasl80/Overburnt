#ifndef TABLE_H
#define TABLE_H
#include "Includes.h"
#include "Constants.h"
#include "Customer.h"
using namespace std;

class Table{
private:
    int id;
    bool status;
    vector<Customer*> customers;
public:
    Table():status(UNOCCUPIED){};

    void seatCustomers(vector<Customer*>);
    void killKarens();
    
    int getId();
    bool getStatus();
    std::vector<Customer*> getCustomers();
    void clearTable();
    bool isOccupied();

};

#endif