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
#include "Accountant.h"
#include "ResultsQueue.h"
using namespace std;

class Table {
private:
    int id;
    bool status; // UNOCCUPIED = false, OCCUPIED = true
    
    vector<Customer*> customers;
    map<Customer*, bool> customersEatingStatuses;
    int customersSeated;
    int customersDoneEating;
    ResultsQueue<int> *customersUnsatisfied;

    Menu *menu;
    int amountOfItemsInMenu;

    Waiter *waiter;
    vector<Order*> orders;

    mutex tableMutex;
    
    void takeCustomersOrders();
    void setCustomerOrder(int customerIndex, Recipe *recipe);
    
    void setUpEatingStatuses();
    void insertCustomerAndStatus (Customer* customer, bool status);
    void waitForCustomers();

public:
    Table(int id, Menu *_menu, InventoryManager* inventoryManager, Accountant *accountant, ResultsQueue<Order*> *ordersToDo, ResultsQueue<int> *_customersUnsatisfied);
    ~Table();

    int getId() const;
    vector<Customer*> getCustomers() const;
    void isOccupied(std::promise<bool>&& occupiedPromise); //For tables threadpool to determine if is assignable

    void seatAndAttendCustomers(const vector<Customer*>& customers);

    string reportCurrentState();
    
    void clearTableAndOrders();
    void setStatus(bool _status);
};

#endif // TABLE_H
