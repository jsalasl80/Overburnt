#include "CustomerSpawner.h"

CustomerSpawner::CustomerSpawner(CustomersInLine *_customersInLine):
    spawning(SPAWNING),
    customersInLine(_customersInLine)
    {};

void CustomerSpawner::spawnClients(){
    std::string customerName;
    std::vector<Customer*> customers;
    Customer *customer;
    int customerCount;
    int customerId;

    while (spawning){
        customerCount = random.generateRandomInRange(MIN_CUSTOMER_COUNT, MAX_CUSTOMER_COUNT);
        for (int i = 0; i < customerCount; ++i){
            customerName = generateCustomerName();
            customerId = i;
            customer = new Customer(customerId, customerName);
            if (customer){
                customers.push_back(customer);                
            }
        }    

        customersInLine -> addCustomers(customers);
        std::this_thread::sleep_for(std::chrono::milliseconds(SPAWN_RATE));
        
        customers.clear();
    }
}

std::string CustomerSpawner::generateCustomerName(){
    return NAMES[random.generateRandomInRange(0, NAMES_AMOUNTS)] + " " + LAST_NAMES[random.generateRandomInRange(0, NAMES_AMOUNTS)];
}

void CustomerSpawner::stopSpawning(){
    spawning = HALT_SPAWNING;
}