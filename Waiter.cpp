#include "Waiter.h"

Waiter::Waiter(InventoryManager *_inventoryManager, Accountant *_accountant, ResultsQueue<Order*> *_ordersToDo):
    inventoryManager(_inventoryManager),
    ordersToDo(_ordersToDo),
    accountant(_accountant)
    {}
    
void Waiter::attendTable(std::promise<bool>&& ordersPromise, vector<Order*>& orders){
    printf("Waiter attending table\n");
    customersOrders = orders;
    Recipe *recipe;
    int tableId;
    int customerId;

    for (Order* order : customersOrders){
        recipe = order -> getRecipe();
        extractIngredientsAndAmounts(recipe);
        printf("Waiter extracted orders\n");
    }

    std::promise<bool> availabilityPromise;
    std::future<bool> availabilityFuture = availabilityPromise.get_future();

    std::thread([&]() { 
        inventoryManager->checkIngredientsAvailability(std::move(availabilityPromise), ordersTotalIngredientsAmounts); 
        }).detach();

    bool ordersDoable = availabilityFuture.get();
    ordersPromise.set_value(ordersDoable);  

    if (ordersDoable){
        sendOrdersToKitchen();
        addWinnings();
        printf("Orders sent to kitchen\n");
    }

    clearOrders();
    clearMap(); 

    printf("Waiter chilling\n");
}

bool Waiter::attendTable(vector<Order*>& orders){
    printf("Waiter attending table\n");
    customersOrders = orders;
    Recipe *recipe;
    int tableId;
    int customerId;

    for (Order* order : customersOrders){
        recipe = order -> getRecipe();
        extractIngredientsAndAmounts(recipe);
        printf("Waiter extracted orders\n");
    }

    bool ordersDoable = inventoryManager -> checkIngredientsAvailability(ordersTotalIngredientsAmounts);

    if (ordersDoable){
        sendOrdersToKitchen();
        addWinnings();
        printf("Orders sent to kitchen\n");
    }

    clearOrders();
    clearMap(); 

    printf("Waiter chilling\n");

    return ordersDoable;
}

void Waiter::extractIngredientsAndAmounts(Recipe* recipe){
    int totalIngredientsStored = recipe -> getTotalIngredientsStored();
    string ingredient;
    int amount;
    for (int index = 0; index < totalIngredientsStored; ++index){
        ingredient = recipe ->getIngredient(index);
        amount = recipe -> getIngredientAmount(index);
        insertIngredientAmount(ingredient, amount);
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