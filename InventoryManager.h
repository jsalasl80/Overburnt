#ifndef INVENTORYMANAGER
#define INVENTORYMANAGER
#include "Includes.h"
#include "Constants.h"

#include "FileWriter.h"
#include "Ingredient.h"
#include "CSVReader.h"
#include "LockableMap.h"

using namespace std;

class InventoryManager : private CSVReader, private FileWriter{
private:
    LockableMap<string, Ingredient*> *inventory;
    vector<string> ingredientNames; //Optimizable
    void storeIngredient(string, int, float);

public:
    InventoryManager(LockableMap<string, Ingredient*> *_inventory) : CSVReader(INVENTORY_CSV), FileWriter(REPORT_TXT), inventory(_inventory){}

    ~InventoryManager(){
        delete inventory;
    }
    
    void setUpInventory();

    //for testing purposes
    bool useIngredient(string, int); 
    Ingredient* getIngredient(string);

    //Must add lock and unlock slash mutex stuff cuz race conditions
    bool checkIngredientsAvailability(map<string,int>);
    void updateInventory(map<string,int>);
    
    void clearInventory();

    //Must add the winnings part (in development)
    void reportInventoryState();
};

#endif