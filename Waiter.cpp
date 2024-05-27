#include "Waiter.h"

Waiter::Waiter(InventoryManager *_inventoryManager, Accountant *_accountant, ResultsQueue<Order*> *_ordersToDo):
    inventoryManager(_inventoryManager),
    ordersToDo(_ordersToDo),
    accountant(_accountant)
    {}
    
void Waiter::attendTable(std::promise<bool>&& ordersPromise, vector<Order*>& orders){
    clearMap(); 
    customersOrders = orders;
    Recipe *recipe;

    for (Order* order : customersOrders){
        recipe = order -> getRecipe();
        extractIngredientsAndAmounts(recipe);
    }

    std::promise<bool> availabilityPromise;
    std::future<bool> availabilityFuture = availabilityPromise.get_future();

    std::thread t([&]() { 
        inventoryManager->checkIngredientsAvailability(std::move(availabilityPromise), ordersTotalIngredientsAmounts); 
        });

    bool ordersDoable = availabilityFuture.get();
    ordersPromise.set_value(ordersDoable);  

    if (ordersDoable){
        sendOrdersToKitchen();
        addWinnings();
    }
    
    if (t.joinable()){
        t.join();
    }
    
    clearOrders();
}

void Waiter::extractIngredientsAndAmounts(Recipe* recipe){
    if (recipe){
        int totalIngredientsStored = recipe -> getTotalIngredientsStored();
        string ingredient;
        int amount;
        for (int index = 0; index < totalIngredientsStored; ++index){
            ingredient = recipe ->getIngredient(index);
            amount = recipe -> getIngredientAmount(index);
            insertIngredientAmount(ingredient, amount);
        }
    }
    
}

void Waiter::insertIngredientAmount(string ingredientName, int amount){
    if (ordersTotalIngredientsAmounts.find(ingredientName) == ordersTotalIngredientsAmounts.end()){
        ordersTotalIngredientsAmounts[ingredientName] = amount;
    }
    else{
        ordersTotalIngredientsAmounts[ingredientName] += amount;
    }
}

void Waiter::sendOrdersToKitchen(){
    for (Order* order : customersOrders){
        ordersToDo->enqueue(order);
    }
}

void Waiter::addWinnings(){
    for (Order* order : customersOrders){
        Recipe *recipe = order -> getRecipe();
        accountant -> updateWinnings(recipe);
    }
}

void Waiter::clearMap(){
    ordersTotalIngredientsAmounts.clear();
}

void Waiter::clearOrders(){
    customersOrders.clear();
}