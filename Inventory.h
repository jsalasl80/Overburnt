#ifndef INVENTORY_H
#define INVENTORY_H

#include "Includes.h"
#include "Constants.h"
#include "Ingredient.h"
using namespace std;

class Inventory{
private:
    unordered_map<string, Ingredient*> inventory;
    bool locked;

public:
    Inventory(): inventory(), locked(UNLOCKED){};
    ~Inventory(){
        clearInventory();
    }
    
    void addIngredient(string ingredientName, Ingredient* ingredient);
    Ingredient* getIngredient(string ingredientName);
    void clearInventory();
    bool getAvailability() const;
    void lock();
    void unlock();
    int getSize();

};

#endif //INVENTORY_H