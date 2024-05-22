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
    string ingredientName;
    int amount;
    float unitaryCost;
    
    CSVReader::skipLine();
    while (CSVReader::readInventory(ingredientName, amount, unitaryCost)){
        storeIngredient(ingredientName, amount, unitaryCost);
        ingredientNames.push_back(ingredientName); 
        printf("%s: %i %f\n", ingredientName.c_str(), amount, unitaryCost);
    }

    CSVReader::closeFile();
}

bool InventoryManager::checkIngredientsAvailability(map<string,int>& totalIngredientsAndAmounts){
    std::unique_lock<mutex> ul(inventoryMutex);
    cv.wait(ul, inventory->getAvailability());

    bool allIngredientsAvailable = true;
    Ingredient *ingredient;
    for (auto itr = totalIngredientsAndAmounts.begin(); itr != totalIngredientsAndAmounts.end() && allIngredientsAvailable; ++itr){
        ingredient = inventory -> getIngredient(itr->first);
        allIngredientsAvailable = ingredient -> checkConsumability(itr->second);
    }
    
    if (allIngredientsAvailable){
        //must be sure that all ingredients will be used to update inventory
        updateInventory(totalIngredientsAndAmounts);
    }

    return allIngredientsAvailable;
}

void InventoryManager::updateInventory(map<string,int>& totalIngredientsAndAmounts){
    Ingredient *ingredient;
    for (auto itr = totalIngredientsAndAmounts.begin(); itr != totalIngredientsAndAmounts.end(); ++itr){
        ingredient = inventory -> getIngredient(itr->first);
        ingredient -> consumePortions(itr->second);
        accountant -> updateExpenses(ingredient);
    }
}

void InventoryManager::clearInventory(){
    inventory -> clearInventory();
}

void InventoryManager::reportInventoryState(){
    inventory -> lock();
    std::lock_guard<mutex> lg(inventoryMutex);
    accountant -> setAsReporting();

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