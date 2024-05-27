#include <gtest/gtest.h>
#include "Deliverer.h"
#include "Order.h"
#include "Customer.h"
#include "Recipe.h"

class DelivererTest : public ::testing::Test {
protected:
    Deliverer* deliverer;
    Customer* customer;
    Recipe* recipe;
    Order* order;

    void SetUp() override {
        deliverer = new Deliverer();
        customer = new Customer(1, "John Doe");
        std::vector<std::string> ingredients = {"Tomato", "Pasta"};
        std::vector<int> amounts = {2, 3};
        recipe = new Recipe("Pasta", 10.0, 15, 10, ingredients, amounts);
        order = new Order(1, 1, recipe, customer);
    }

    void TearDown() override {
        delete deliverer;
        delete order;
        delete recipe;
        delete customer;
    }
};

TEST_F(DelivererTest, DeliverOrder) {
    deliverer->deliverOrder(order);
    EXPECT_EQ(customer->getStatus(), CustomerStatus::WaitingToLeave);
}

TEST_F(DelivererTest, GetAvailability) {
    EXPECT_TRUE(deliverer->getAvailability());
    deliverer->setState(DELIVERING);
    EXPECT_FALSE(deliverer->getAvailability());
}

TEST_F(DelivererTest, SetState) {
    deliverer->setState(DELIVERING);
    EXPECT_FALSE(deliverer->getAvailability());
    deliverer->setState(CHILLING);
    EXPECT_TRUE(deliverer->getAvailability());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
