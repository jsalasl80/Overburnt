#ifndef ORDER_H
#define ORDER_H

#include "Includes.h"
#include "Constants.h"
#include "Recipe.h"
#include "Customer.h"
#include "Random.h"

class Order {
private:
    int tableId;
    int customerId;
    Recipe *recipe;
    Customer *associatedCustomer;
    bool orderState;
    int preparationTime;
    int eatingTime;

public:
    Order(int _tableId, int _customerId,  Recipe* _recipe, Customer *_associatedCustomer);
        
    int getTableId() const;
    int getCustomerId() const;
    bool getOrderState() const;
    int getOrderPrepTime() const;
    int getOrderEatingTime() const;
    Recipe* getRecipe() const;
    Customer* getAssociatedCustomer() const;

    void markAsCompleted();
    int calculateTime(int baseTime, int delay);
     
};

#endif //ORDER_H
