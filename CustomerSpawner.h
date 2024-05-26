#ifndef CUSTOMERSPAWNER_H
#define CUSTOMERSPAWNER_H

#include "Includes.h"
#include "Constants.h"
#include "Random.h"
#include "Customer.h"
#include "CustomersInLine.h"

class CustomerSpawner{
private:
    Random random;
    bool spawning;
    CustomersInLine *customersInLine;

public:
    CustomerSpawner(CustomersInLine *customersInLine);
    void spawnClients();
    std::string generateCustomerName();
    void stopSpawning();

};
#endif