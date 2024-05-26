#include "Inventory.h"
using namespace std;

void Inventory::addIngredient(string ingredientName, Ingredient* ingredient){
    inventory.insert(pair<string, Ingredient*>(ingredientName, ingredient));
}

Ingredient* Inventory:: getIngredient(string key){
    return inventory[key];
}

void Inventory:: clearInventory(){
    if (!inventory.empty()){
        for (auto itr = inventory.begin(); itr != inventory.end(); ++itr) {
            delete itr->second;
        }
        inventory.clear();
    }
}

bool Inventory:: getAvailability() const{
    return !locked;
}

void Inventory:: lock(){
    locked = LOCKED;
}

void Inventory::unlock(){
    locked = UNLOCKED;
}

int Inventory::getSize(){
    return inventory.size();
}