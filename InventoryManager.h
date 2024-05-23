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
    void storeIngredient(string ingredientName, int amount, float unitaryCost);
    Accountant *accountant;

public:
    InventoryManager(Inventory *_inventory, Accountant* _accountant);
    ~InventoryManager();
    
    void setUpInventory();

    void checkIngredientsAvailability(std::promise<bool>&& availabilityPromise, map<string,int>& totalIngredientsAndAmounts);
    void updateInventory(map<string,int>& totalIngredientsAndAmounts);
    
    void clearInventory();

    void reportInventoryState();
    
    //TESTING PURPOSES
    bool useIngredient(string ingredientName, int amount); 
    Ingredient* getIngredient(string ingredientName);
};

#endif