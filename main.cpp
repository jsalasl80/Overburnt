#include "Includes.h"
#include "Constants.h"

#include "InventoryManager.h"
#include "Menu.h"
#include "RecipeReader.h"
#include "Customer.h"
#include "CustomerSpawner.h"
#include "ResultsQueue.h"
#include "Order.h"
#include "Waiter.h"
#include "Kitchen.h"
#include "Restaurant.h"
using namespace std;

void prueba();

int main(){
    //prueba();
    Restaurant *restaurant = new Restaurant();
    thread (&Restaurant::startRestaurantSimulation, restaurant).detach();  
    this_thread::sleep_for(std::chrono::seconds(20));
    restaurant -> stopRestaurantSimulation();
    delete restaurant;

    return 0;
}
