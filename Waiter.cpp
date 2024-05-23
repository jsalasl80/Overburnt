#include "Waiter.h"

Waiter::Waiter(InventoryManager *_inventoryManager):
    inventoryManager(_inventoryManager){}
    
void Waiter::attendTable(std::promise<bool>&& ordersPromise, vector<Order*>& orders){
    customerOrders = orders;
    Recipe *recipe;
    int tableId;
    int customerId;

    for (Order* order : customerOrders){
        recipe = order -> getRecipe();
        extractIngredientsAndAmounts(recipe);
    }
    
    std::promise<bool> availabilityPromise;
    std::future<bool> availabilityFuture = availabilityPromise.get_future();

    thread t(InventoryManager::checkIngredientsAvailability, *inventoryManager, std::move(availabilityPromise), ordersTotalIngredientsAmounts);
    bool ordersDoable = availabilityFuture.get();
    ordersPromise.set_value(ordersDoable);  
    
    if (ordersDoable){
        sendOrdersToKitchen();
    }

    t.join();
}

void Waiter::extractIngredientsAndAmounts(Recipe* recipe){
    vector<string> ingredients;
    vector<int> ingredientsAmounts;

    ingredients = recipe -> getAllIngredients();
    ingredientsAmounts = recipe -> getAllIngredientsAmounts();

    for (int j = 0; j < ingredients.size(); ++j){
        insertIngredientAmount(ingredients[j], ingredientsAmounts[j]);
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
    for (Order* order : customerOrders){
        //send to kitchen via queue
    }
    customerOrders.clear();
    clearMap();
}

void Waiter::clearMap(){
    ordersTotalIngredientsAmounts.clear();
}