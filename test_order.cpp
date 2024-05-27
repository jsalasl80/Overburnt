#include <gtest/gtest.h>
#include "Order.h"
#include "Recipe.h"
#include "Customer.h"

class OrderTest : public ::testing::Test {
protected:
    Order* order;
    Customer* customer;
    Recipe* recipe;

    void SetUp() override {
        customer = new Customer(1, "John Doe");
        std::vector<std::string> ingredients = {"Tomato", "Pasta"};
        std::vector<int> amounts = {2, 3};
        recipe = new Recipe("Pasta", 10.0, 15, 10, ingredients, amounts);
        order = new Order(1, 1, recipe, customer);
    }

    void TearDown() override {
        delete order;
        delete recipe;
        delete customer;
    }
};

TEST_F(OrderTest, GetTableId) {
    EXPECT_EQ(order->getTableId(), 1);
}

TEST_F(OrderTest, GetCustomerId) {
    EXPECT_EQ(order->getCustomerId(), 1);
}

TEST_F(OrderTest, GetOrderState) {
    EXPECT_EQ(order->getOrderState(), IN_PREPARATION);
}

TEST_F(OrderTest, GetOrderPrepTime) {
    EXPECT_EQ(order->getOrderPrepTime(), recipe->getApproxPrepTime());
}

TEST_F(OrderTest, GetOrderEatingTime) {
    EXPECT_EQ(order->getOrderEatingTime(), recipe->getApproxEatingTime());
}

TEST_F(OrderTest, GetRecipe) {
    EXPECT_EQ(order->getRecipe(), recipe);
}

TEST_F(OrderTest, GetAssociatedCustomer) {
    EXPECT_EQ(order->getAssociatedCustomer(), customer);
}

TEST_F(OrderTest, MarkAsCompleted) {
    order->markAsCompleted();
    EXPECT_EQ(order->getOrderState(), READY);
}

TEST_F(OrderTest, CalculateTime) {
    int baseTime = 100;
    int delay = 20;
    int calculatedTime = order->calculateTime(baseTime, delay);
    EXPECT_GE(calculatedTime, baseTime - delay);
    EXPECT_LE(calculatedTime, baseTime + delay);
}

