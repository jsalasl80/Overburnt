#include "InventoryManager.h"
using namespace std;

InventoryManager::InventoryManager(Inventory *_inventory, Accountant* _accountant):
    CSVReader(INVENTORY_CSV),
    FileWriter(REPORT_TXT),
    inventory(_inventory),
    accountant(_accountant){}

InventoryManager::~InventoryManager(){
    delete inventory;
}

void InventoryManager::storeIngredient(string ingredientName, int amount, float unitaryCost){
    Ingredient* ingredient = new Ingredient(ingredientName, amount, unitaryCost);
    inventory->addIngredient(ingredientName, ingredient);
}

void InventoryManager::setUpInventory(){
    inventory -> lock();
    std::lock_guard<mutex> lg(inventoryMutex);

    string ingredientName;
    int amount;
    float unitaryCost;
    
    CSVReader::skipLine();
    while (CSVReader::readInventory(ingredientName, amount, unitaryCost)){
        storeIngredient(ingredientName, amount, unitaryCost);
        ingredientNames.push_back(ingredientName); 
        //printf("%s: %i %f\n", ingredientName.c_str(), amount, unitaryCost);
    }

    CSVReader::closeFile();
    inventory -> unlock();
    cv.notify_one();
}

void InventoryManager::checkIngredientsAvailability(std::promise<bool>&& availabilityPromise, map<string,int>& totalIngredientsAndAmounts){
    std::unique_lock<mutex> ul(inventoryMutex);
    bool inventoryAvailable = inventory-> getAvailability();
    if (!inventoryAvailable){
        cv.wait(ul, [this](){
        return inventory->getAvailability();}
        );
    }
    bool allIngredientsAvailable = true;

    Ingredient *ingredient;
    for (auto itr = totalIngredientsAndAmounts.begin(); itr != totalIngredientsAndAmounts.end() && allIngredientsAvailable; ++itr){
        ingredient = inventory -> getIngredient(itr->first);
        if (ingredient) allIngredientsAvailable = ingredient -> checkConsumability(itr->second);
    }

    availabilityPromise.set_value(allIngredientsAvailable);
    
    if (allIngredientsAvailable){
        updateInventory(totalIngredientsAndAmounts);
    }
}

void InventoryManager::updateInventory(std::map<string, int>& totalIngredientsAndAmounts){
    Ingredient *ingredient;
    int portionsUsed;
    for (auto itr = totalIngredientsAndAmounts.begin(); itr != totalIngredientsAndAmounts.end(); ++itr){
        ingredient = inventory -> getIngredient(itr->first);
        if (ingredient){
            portionsUsed = itr -> second;
            ingredient -> consumePortions(portionsUsed);
            accountant -> updateExpenses(ingredient, portionsUsed);
        }
    }
}

void InventoryManager::clearInventory(){
    inventory -> clearInventory();
}

void InventoryManager::reportInventoryState(){
    inventory -> lock();
    accountant -> setAsReporting();
    std::lock_guard<mutex> lg(inventoryMutex);
    FileWriter::wipeAndRestartFile(REPORT_HEADER_MESSAGE);
    
    Ingredient* ingredient;
    string message;

    for (int i = 0; i < ingredientNames.size(); ++i){
        ingredient = inventory -> getIngredient(ingredientNames[i]);
        message = ingredient -> toString() + "\n";
        FileWriter::appendLine(message);
    }

    accountant -> reportWinnings();
    inventory -> unlock();

    cv.notify_one();
}

//TESTING PURPOSES
bool InventoryManager::useIngredient(string ingredientName, int amount){
    bool useSuccess = false;

    Ingredient* ingredient = inventory -> getIngredient(ingredientName);

    if(ingredient->checkConsumability(amount)){
        ingredient->consumePortions(amount);
        useSuccess = true;
    }

    return useSuccess;
}

//TESTING PURPOSES
Ingredient* InventoryManager::getIngredient(string ingredientName){
    return inventory -> getIngredient(ingredientName);
}