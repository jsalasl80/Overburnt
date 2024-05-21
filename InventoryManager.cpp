#include "InventoryManager.h"
#include "Constants.h"
using namespace std;

void InventoryManager::storeIngredient(string ingredientName, int amount, float unitaryCost){
    Ingredient* ingredient = new Ingredient(ingredientName, amount, unitaryCost);
    inventory->insert(ingredientName, ingredient);
}

void InventoryManager::setUpInventory(){
    string ingredientName;
    int amount;
    float unitaryCost;
    
    CSVReader::skipLine();
    while (CSVReader::readInventory(ingredientName, amount, unitaryCost)){
        storeIngredient(ingredientName, amount, unitaryCost);
        ingredientNames.push_back(ingredientName); 
        printf("%s: %i %f\n", ingredientName.c_str(), amount, unitaryCost);
    }
}

//TESTING PURPOSES
bool InventoryManager::useIngredient(string ingredientName, int amount){
    bool useSuccess = false;

    Ingredient* ingredient = inventory -> getElement(ingredientName);

    if(ingredient->checkConsumability(amount)){
        ingredient->consumePortions(amount);
    }

    return useSuccess;
}

//TESTING PURPOSES
Ingredient* InventoryManager::getIngredient(string ingredientName){
    return inventory -> getElement(ingredientName);
}

//MUTEX/THREAD MANAGEMENT PENDING
bool InventoryManager::checkIngredientsAvailability(map<string,int> totalIngredientsAndAmounts){
    bool allIngredientsAvailable = true;
    Ingredient *ingredient;
    for (auto itr = totalIngredientsAndAmounts.begin(); itr != totalIngredientsAndAmounts.end() && allIngredientsAvailable; ++itr){
        ingredient = inventory -> getElement(itr->first);
        allIngredientsAvailable = ingredient -> checkConsumability(itr->second);
    }
    return allIngredientsAvailable;
}

//MUTEX/THREAD MANAGEMENT PENDING
void InventoryManager::updateInventory(map<string,int> totalIngredientsAndAmounts){
    Ingredient *ingredient;
    for (auto itr = totalIngredientsAndAmounts.begin(); itr != totalIngredientsAndAmounts.end(); ++itr){
        ingredient = inventory -> getElement(itr->first);
        ingredient -> consumePortions(itr->second);
    }
}

void InventoryManager::clearInventory(){
    inventory -> clearMap();
}

//WINNINGS PENDING (maybe add condition variables and notification to other threads here)
void InventoryManager::reportInventoryState(){
    inventory -> lock(); 

    FileWriter::wipeAndRestartFile(REPORT_HEADER_MESSAGE);
    
    Ingredient* ingredient;
    string message;

    for (int i = 0; i < ingredientNames.size(); ++i){
        ingredient = inventory -> getElement(ingredientNames[i]);
        message = ingredient -> toString() + "\n";
        FileWriter::appendLine(message);
    }

    inventory -> unlock();
}