#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Includes.h"
#include "Constants.h"
#include "Menu.h"
#include "Kitchen.h"
#include "CustomerSpawner.h"
#include "Table.h"

#include "ThreadPoolTables.h"
#include "CustomersInLine.h"
#include "ResultsQueue.h"

class Restaurant{
private:
    CustomerSpawner *customerSpawner;
    Kitchen *kitchen;
    Menu *menu;
    RecipeReader *recipeReader;
    Table **tables;
    Accountant *accountant;

    ThreadPoolTables *threadPoolTables;

    CustomersInLine *customersInLine;
    ResultsQueue<Order*> *ordersToDo;
    ResultsQueue<int> *customersUnsatisfied;

    int customersUnsatisfiedCount;
    bool simulating;

public:
    Restaurant();
    ~Restaurant();

    void startRestaurantSimulation();
    void stopRestaurantSimulation();
    void updateUnsatisfactionCount();
    void checkUnsatisfactionCount();

    void setTables();
    void cleanTables();

    string getTableState(int);
    Table** getTables();
    void reportRestaurantCurrentState();
    int getUnsatisfactionCount();
    int getCustomersInLineCount();
    
};

#endif