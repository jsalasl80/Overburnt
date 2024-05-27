#include <gtest/gtest.h>
#include "Waiter.h"
#include "InventoryManager.h"
#include "Accountant.h"
#include "ResultsQueue.h"
#include "Recipe.h"
#include "Order.h"

// Test fixture for the Waiter class
class WaiterTest : public ::testing::Test {
protected:
    Waiter* waiter;
    Inventory* inventory;
    InventoryManager* inventoryManager;
    Accountant* accountant;
    ResultsQueue<Order*>* ordersToDo;
    Recipe* recipe;
    std::vector<Order*> orders;

    virtual void SetUp() {
        // Create instances for the test
        inventory = new Inventory();
        accountant = new Accountant();
        inventoryManager = new InventoryManager(inventory, accountant);
        ordersToDo = new ResultsQueue<Order*>();
        waiter = new Waiter(inventoryManager, accountant, ordersToDo);

        // Set up a test recipe
        std::vector<std::string> ingredients = {"Tomato", "Pasta"};
        std::vector<int> amounts = {2, 3};
        recipe = new Recipe("Pasta", 10.0, 15, 10, ingredients, amounts);

        // Create a test order
        Customer* customer = new Customer(1, "John Doe");
        Order* order = new Order(1, 1, recipe, customer);
        orders.push_back(order);
    }

    virtual void TearDown() {
        // Clean up after each test
        delete waiter;
        delete inventoryManager;
        delete inventory;
        delete accountant;
        delete ordersToDo;
        delete recipe;
        for (Order* order : orders) {
            delete order->getAssociatedCustomer();
            delete order;
        }
    }
};

TEST_F(WaiterTest, AttendTableSuccess) {
    // Test attendTable with successful orders
    std::promise<bool> ordersPromise;
    std::future<bool> ordersFuture = ordersPromise.get_future();
    waiter->attendTable(std::move(ordersPromise), orders);

    bool ordersDoable = ordersFuture.get();
    EXPECT_TRUE(ordersDoable);
}

TEST_F(WaiterTest, AttendTableFailure) {
    // Test attendTable with failed orders (not enough ingredients)
    // Manually reduce inventory to cause failure
    inventoryManager->clearInventory();
    std::promise<bool> ordersPromise;
    std::future<bool> ordersFuture = ordersPromise.get.future();
    waiter->attendTable(std::move(ordersPromise), orders);

    bool ordersDoable = ordersFuture.get();
    EXPECT_FALSE(ordersDoable);
}

TEST_F(WaiterTest, ExtractIngredientsAndAmounts) {
    // Test extractIngredientsAndAmounts
    waiter->extractIngredientsAndAmounts(recipe);

    std::map<std::string, int> expected = {{"Tomato", 2}, {"Pasta", 3}};
    for (const auto& ingredient : expected) {
        EXPECT_EQ(waiter->ordersTotalIngredientsAmounts[ingredient.first], ingredient.second);
    }
}

TEST_F(WaiterTest, SendOrdersToKitchen) {
    // Test sendOrdersToKitchen
    waiter->sendOrdersToKitchen();
    EXPECT_FALSE(ordersToDo->isEmpty());
    EXPECT_EQ(ordersToDo->dequeue(), orders[0]);
}

TEST_F(WaiterTest, AddWinnings) {
    // Test addWinnings
    float initialWinnings = accountant->getTotalWinnings();
    waiter->addWinnings();
    EXPECT_GT(accountant->getTotalWinnings(), initialWinnings);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
