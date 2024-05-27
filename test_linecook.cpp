#include <gtest/gtest.h>
#include "LineCook.h"
#include "Order.h"
#include "Recipe.h"
#include "Customer.h"
#include "ResultsQueue.h"

class LineCookTest : public ::testing::Test {
protected:
    LineCook* lineCook;
    ResultsQueue<Order*>* ordersToDeliver;
    Customer* customer;
    Recipe* recipe;
    Order* order;

    void SetUp() override {
        ordersToDeliver = new ResultsQueue<Order*>();
        lineCook = new LineCook(ordersToDeliver);

        customer = new Customer(1, "John Doe");
        std::vector<std::string> ingredients = {"Tomato", "Pasta"};
        std::vector<int> amounts = {2, 3};
        recipe = new Recipe("Pasta", 10.0, 15, 10, ingredients, amounts);
        order = new Order(1, 1, recipe, customer);
    }

    void TearDown() override {
        delete lineCook;
        delete ordersToDeliver;
        delete order;
        delete recipe;
        delete customer;
    }
};

TEST_F(LineCookTest, PrepareOrder) {
    lineCook->prepareOrder(order);
    EXPECT_EQ(order->getOrderState(), READY);
    EXPECT_FALSE(lineCook->getAvailability()); // LineCook should be chilling after preparing the order
}

TEST_F(LineCookTest, GetAvailability) {
    EXPECT_TRUE(lineCook->getAvailability());
    lineCook->setState(COOKING);
    EXPECT_FALSE(lineCook->getAvailability());
}

TEST_F(LineCookTest, SetState) {
    lineCook->setState(COOKING);
    EXPECT_FALSE(lineCook->getAvailability());
    lineCook->setState(CHILLING);
    EXPECT_TRUE(lineCook->getAvailability());
}

TEST_F(LineCookTest, DeliverOrder) {
    lineCook->prepareOrder(order);
    Order* deliveredOrder = ordersToDeliver->dequeue();
    EXPECT_EQ(deliveredOrder->getOrderState(), READY);
    EXPECT_EQ(deliveredOrder, order);
}

