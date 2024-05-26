#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "Includes.h"
#include "Constants.h"
#include "FileWriter.h"
#include "Ingredient.h"
#include "CSVReader.h"
#include "Inventory.h"
#include "Accountant.h"
using namespace std;

class InventoryManager : private CSVReader, private FileWriter {
private:
    std::condition_variable cv;
    std::mutex inventoryMutex;

    Inventory *inventory;
    vector<string> ingredientNames; //Optimizable
    void storeIngredient(string, int, float);
    Accountant *accountant;

public:
    InventoryManager(Inventory*, Accountant*);
    ~InventoryManager();
    
    void setUpInventory();

    void checkIngredientsAvailability(std::promise<bool>&&, map<string,int>&);
    bool checkIngredientsAvailability(map<string,int>&);
    
    void updateInventory(map<string,int>&);
    
    void clearInventory();

    void reportInventoryState();
    
    //TESTING PURPOSES
    bool useIngredient(string, int); 
    Ingredient* getIngredient(string);
};

#endif