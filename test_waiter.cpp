#include <gtest/gtest.h>
#include "Waiter.h"
#include "InventoryManager.h"
#include "Accountant.h"
#include "Order.h"
#include "ResultsQueue.h"
#include "Customer.h"
#include "Recipe.h"

class WaiterTest : public ::testing::Test {
protected:
    Waiter* waiter;
    InventoryManager* inventoryManager;
    Accountant* accountant;
    ResultsQueue<Order*>* ordersToDo;
    Customer* customer;
    Recipe* recipe;
    Order* order;

    void SetUp() override {
        // Crear archivos CSV de prueba
        std::ofstream inventoryFile(INVENTORY_CSV);
        inventoryFile << "Ingredient,Amount,UnitaryCost\n";
        inventoryFile << "Tomato,100,0.5\n";
        inventoryFile << "Pasta,200,1.2\n";
        inventoryFile.close();

        std::ofstream recipesFile(RECIPES_CSV);
        recipesFile << "RecipeName,Price,PrepTime,EatingTime,Ingredients,Amounts\n";
        recipesFile << "Pasta,10.0,15,10,Tomato:Pasta,2:3\n";
        recipesFile.close();

        accountant = new Accountant();
        Inventory* inventory = new Inventory();
        inventoryManager = new InventoryManager(inventory, accountant);
        inventoryManager->setUpInventory();

        ordersToDo = new ResultsQueue<Order*>();

        waiter = new Waiter(inventoryManager, accountant, ordersToDo);

        customer = new Customer(1, "John Doe");
        std::vector<std::string> ingredients = {"Tomato", "Pasta"};
        std::vector<int> amounts = {2, 3};
        recipe = new Recipe("Pasta", 10.0, 15, 10, ingredients, amounts);
        order = new Order(1, 1, recipe, customer);
    }

    void TearDown() override {
        delete waiter;
        delete ordersToDo;
        delete order;
        delete recipe;
        delete customer;
        delete inventoryManager;
        delete accountant;

        // Eliminar los archivos de prueba
        std::remove(INVENTORY_CSV);
        std::remove(RECIPES_CSV);
    }
};

TEST_F(WaiterTest, AttendTable) {
    std::promise<bool> promiseObj;
    std::future<bool> futureObj = promiseObj.get_future();
    std::vector<Order*> orders = {order};

    std::thread attendThread(&Waiter::attendTable, waiter, std::move(promiseObj), orders);
    bool result = futureObj.get();
    attendThread.join();

    EXPECT_TRUE(result);
    EXPECT_EQ(order->getOrderState(), IN_PREPARATION);
}

TEST_F(WaiterTest, ExtractIngredientsAndAmounts) {
    std::map<std::string, int> ingredientsMap = waiter->extractIngredientsAndAmounts(order);

    EXPECT_EQ(ingredientsMap["Tomato"], 2);
    EXPECT_EQ(ingredientsMap["Pasta"], 3);
}

TEST_F(WaiterTest, SendOrdersToKitchen) {
    waiter->sendOrdersToKitchen({order});
    EXPECT_FALSE(ordersToDo->isEmpty());
}

TEST_F(WaiterTest, AddWinnings) {
    float initialWinnings = accountant->getTotalWinnings();
    waiter->addWinnings({order});
    EXPECT_GT(accountant->getTotalWinnings(), initialWinnings);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
