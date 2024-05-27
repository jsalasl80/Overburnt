// test_customer.cpp

#include <gtest/gtest.h>
#include "Customer.h"
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::milliseconds

class CustomerTest : public ::testing::Test {
protected:
    Customer* customer;

    void SetUp() override {
        customer = new Customer(1, "John Doe");
    }

    void TearDown() override {
        delete customer;
    }
};

TEST_F(CustomerTest, GetId) {
    EXPECT_EQ(customer->getId(), 1);
}

TEST_F(CustomerTest, GetName) {
    EXPECT_EQ(customer->getName(), "John Doe");
}

TEST_F(CustomerTest, GetStatus) {
    EXPECT_EQ(customer->getStatus(), CustomerStatus::Waiting);
}

TEST_F(CustomerTest, OrderFromMenu) {
    int menuSize = 5;
    int choice = customer->orderFromMenu(menuSize);
    EXPECT_GE(choice, 0);
    EXPECT_LT(choice, menuSize);
}

TEST_F(CustomerTest, SetAndGetOrderedMenuItem) {
    std::string itemName = "Pizza";
    customer->setOrderedMenuItem(itemName);
    EXPECT_EQ(customer->toStringStatus(), "Customer 1: John Doe\nStatus: Waiting for food\nOrdered: PIZZA\nElapsed waiting time: 0.0 seconds\n");
}

TEST_F(CustomerTest, Eat) {
    customer->updateStatus(CustomerStatus::WaitingForFood);
    customer->eat(1000); // Simulate eating for 1 second
    EXPECT_EQ(customer->getStatus(), CustomerStatus::WaitingToLeave);
}

TEST_F(CustomerTest, ToStringStatus) {
    std::string expected = "Customer 1: John Doe\nStatus: Waiting to order\n";
    EXPECT_EQ(customer->toStringStatus(), expected);

    customer->updateStatus(CustomerStatus::Ordering);
    expected = "Customer 1: John Doe\nStatus: Ordering\n";
    EXPECT_EQ(customer->toStringStatus(), expected);

    customer->updateStatus(CustomerStatus::WaitingForFood);
    expected = "Customer 1: John Doe\nStatus: Waiting for food\nOrdered: \nElapsed waiting time: 0.0 seconds\n";
    EXPECT_EQ(customer->toStringStatus(), expected);

    customer->updateStatus(CustomerStatus::Eating);
    expected = "Customer 1: John Doe\nStatus: Eating\nOrdered: \nTotal waiting time: 0\nElapsed eating time: 0.0 seconds\n";
    EXPECT_EQ(customer->toStringStatus(), expected);

    customer->updateStatus(CustomerStatus::WaitingToLeave);
    expected = "Customer 1: John Doe\nStatus: Waiting to leave\nOrdered: \nTotal waiting time: 0\nTotal eating time: 0 seconds\n";
    EXPECT_EQ(customer->toStringStatus(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
