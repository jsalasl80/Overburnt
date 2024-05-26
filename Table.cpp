#include "Table.h"

Table::Table(int id, Menu *menu, InventoryManager* inventoryManager, Accountant *accountant, ResultsQueue<Order*> *ordersToDo, ResultsQueue<int> *_customersUnsatisfied){
    this->id = id;
    this->menu = menu;
    status = UNOCCUPIED;
    waiter = new Waiter(inventoryManager, accountant, ordersToDo);
    customersUnsatisfied = _customersUnsatisfied;
}

Table::~Table(){
    delete waiter;
    clearTableAndOrders();
}

int Table::getId() const {
    return id;
}

std::vector<Customer*> Table::getCustomers() const {
    return customers;
}

void Table:: takeCustomersOrders() {
    Order *order;
    Recipe *recipe;
    int customerChoice;

    for (int customerIndex = 0; customerIndex < customersSeated; ++customerIndex){
        customerChoice = customers[customerIndex] -> orderFromMenu(amountOfItemsInMenu);
        recipe = menu -> getRecipe(customerChoice);
        
        Customer* associatedCustomer = customers[customerIndex];
        order = new Order(id, customerIndex, recipe, associatedCustomer);
        orders.push_back(order);

        setCustomerOrder(customerIndex, recipe);
    }
}

void Table::seatAndAttendCustomers(const std::vector<Customer*>& customers) {
    std::lock_guard<mutex> lg(tableMutex); 
    this->customers = customers;
    customersSeated = customers.size();
    customersDoneEating = NONE;

    takeCustomersOrders();

    std::promise<bool> attendablePromise;
    std::future<bool> attendableFuture = attendablePromise.get_future();

    thread t(&Waiter::attendTable, waiter, std::move(attendablePromise), orders);
    
    bool customersAttendable = attendableFuture.get();

    if (customersAttendable){
        waitForCustomers();
    }
    else{
        int unsatisfiedCustomersCount = customersSeated;
        customersUnsatisfied -> enqueue(unsatisfiedCustomersCount);
    }

    t.join();

    clearTableAndOrders();
}

void Table::waitForCustomers(){
    setUpEatingStatuses();
    while (customersDoneEating != customersSeated){
        for (auto itr = customersEatingStatuses.begin(); itr != customersEatingStatuses.end(); ++itr){
            if (itr -> second == EATING){
                if (itr -> first -> getStatus() == CustomerStatus::WaitingToLeave){
                    itr -> second = FINISHED;
                    ++customersDoneEating;
                }
            }
        }
    }
    customersEatingStatuses.clear();
}

void Table::setUpEatingStatuses(){
    for (int customerIndex = 0; customerIndex < customersSeated; ++customerIndex){
        insertCustomerAndStatus(customers[customerIndex], EATING);
    }
}

void Table::insertCustomerAndStatus (Customer* customer, bool status){
    customersEatingStatuses.insert(pair<Customer*, bool>(customer, status));
}

void Table::setCustomerOrder(int customerIndex, Recipe *recipe){
    string orderedItemName = recipe -> getRecipeName();
    customers[customerIndex] -> setOrderedMenuItem(orderedItemName);
}

string Table::reportCurrentState (){
    string currentState = "Table " + to_string(id) + ": Current State\n";
    for (int i = 0; i < customersSeated; ++i){
        currentState += customers[i] -> toStringStatus(); 
    }
    return currentState;
}

void Table::clearTableAndOrders() {
    if (status == OCCUPIED){
       for (int i = 0; i < customersSeated; ++i){
            delete customers[i];
            delete orders[i];
        }
        customers.clear();
        orders.clear();
        setStatus(UNOCCUPIED);
    }
}

void Table::isOccupied(std::promise<bool>&& occupiedPromise)  {
    if (tableMutex.try_lock()){
        occupiedPromise.set_value(status);
        tableMutex.unlock();
    }
    else{
        occupiedPromise.set_value(OCCUPIED);
    }
}

void Table::setStatus(bool _status){
    status = _status;
}