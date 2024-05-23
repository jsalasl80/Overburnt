#ifndef TABLE_H
#define TABLE_H

#include "Includes.h"
#include "Constants.h"
#include "Customer.h"
#include "CustomerStatus.h"
#include "Menu.h"
#include "Order.h"
#include "Waiter.h"
#include "InventoryManager.h"
using namespace std;

class Table {
private:
    int id;
    bool status; // UNOCCUPIED = false, OCCUPIED = true
    
    vector<Customer*> customers;
    map<Customer*, bool> customersEatingStatuses;
    int customersSeated;
    int customersDoneEating;

    Menu *menu;
    int amountOfItemsInMenu;

    Waiter *waiter;
    vector<Order*> orders;
    
    void takeCustomersOrders();
    void setCustomerOrder(int customerIndex, Recipe *recipe);
    void setStatus(bool _status);

    void setUpEatingStatuses();
    void insertCustomerAndStatus (Customer* customer, bool status);
    void waitForCustomers();

public:
    Table(int id, Menu *_menu, InventoryManager* inventoryManager);
    ~Table();

    int getId() const;
    vector<Customer*> getCustomers() const;
    bool isOccupied() const;

    int seatAndAttendCustomers(const vector<Customer*>& customers);

    void deliverOrder(int customerId);
    string reportCurrentState();
    
    void clearTableAndOrders();
};

#endif // TABLE_H
