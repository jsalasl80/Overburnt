#include "Waiter.h"

bool Waiter::attendTable(Table* table){
    //vector<int> orders = table->getOrders();
    //int* orders = table->getOrders();
    vector<int> orders;
    Recipe *recipe;
    Order *order;
    int tableId;
    int customerId;

    vector<string> ingredients;
    vector<int> ingredientsAmounts;

    bool ordersDoable;

    for (int i = 0; i < orders.size(); ++i){
        recipe = menu -> getRecipe(orders[i]);

        tableId = table -> getId();
        customerId = i;

        order = new Order(tableId, customerId, recipe);
        addOrder(order);
        ingredients = recipe -> getAllIngredients();
        ingredientsAmounts = recipe -> getAllIngredientsAmounts();

        for (int j = 0; j < ingredients.size(); ++j){
            insertIngredientAmount(ingredients[j], ingredientsAmounts[j]);
        }

        ordersDoable = inventoryManager -> checkIngredientsAvailability(ordersTotalIngredientsAmounts);
    }
    
}

void Waiter::addOrder(Order *order){
    orders.enqueue(order);
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
    while (!orders.isEmpty()){
        Order *order = customerOrders.dequeue();
        //kitchenThreadpool.enqueue(order);
    }
}

void deliveOrder(Order* order){
    //deliver order to customer
    int tableId;
    int customerId;
    
}

void Waiter::clearMap(){
    ordersTotalIngredientsAmounts.clear();
}