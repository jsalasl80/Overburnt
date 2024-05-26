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

void prueba(){
    Menu *menu = new Menu();
    RecipeReader *recipeReader = new RecipeReader(menu);
    Inventory *inventory = new Inventory();
    Accountant *accountant = new Accountant();
    InventoryManager *manager = new InventoryManager(inventory, accountant);
    manager -> setUpInventory();
    
    for (int i = 0; i < 7; ++i){
        bool success = manager -> useIngredient("HUEVOS", 2);
        if (success){
            printf("\nSuccessful Use!\n");
        }
        else{
            printf("Failed\n");
        }
    }
    
    Ingredient* eggs = manager -> getIngredient("HUEVOS");
    printf("%s: %iunits used C$%f\n", eggs->getIngredientName().c_str(), eggs->getConsumedPortions(), eggs->getUnitaryCost());
    
    recipeReader -> setUpMenu();
    
    Recipe* arrozConCam = menu -> getRecipe(3);
    printf("\n%s\n", arrozConCam -> toString().c_str());

    manager -> clearInventory();

    delete manager;
    delete menu;
    delete recipeReader;
    delete accountant;
}