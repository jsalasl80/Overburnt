#include <gtest/gtest.h>
#include "Customer.h"
#include <thread>

// Test Fixture for Customer
class CustomerTest : public ::testing::Test {
protected:
    void SetUp() override {
        customer = new Customer(1, "TestCustomer");
    }

    void TearDown() override {
        delete customer;
    }

    Customer* customer;
};

// Test constructor and getters
TEST_F(CustomerTest, ConstructorAndGetters) {
    EXPECT_EQ(customer->getId(), 1);
    EXPECT_EQ(customer->getName(), "TestCustomer");
    EXPECT_EQ(customer->getStatus(), CustomerStatus::Waiting);
}

// Test orderFromMenu method
TEST_F(CustomerTest, OrderFromMenu) {
    int menuItemIndex = customer->orderFromMenu(5);
    EXPECT_GE(menuItemIndex, 0);
    EXPECT_LT(menuItemIndex, 5);
}

// Test setEatingTime and getEatingTime methods
TEST_F(CustomerTest, EatingTime) {
    customer->setEatingTime(500);
    EXPECT_EQ(customer->getEatingTime(), 500);
}

// Test setOrderedMenuItem method
TEST_F(CustomerTest, SetOrderedMenuItem) {
    std::string itemName = "Pizza";
    customer->setOrderedMenuItem(itemName);
    // Manually check the console output for verification
}

// Test waiting time methods
TEST_F(CustomerTest, WaitingTime) {
    customer->setWaitingTimeStart();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    double elapsedWaitTime = customer->getElapsedWaitTime();
    EXPECT_GT(elapsedWaitTime, 0.1);
}

// Test eating time methods
TEST_F(CustomerTest, EatingTimeElapsed) {
    customer->setEatingTimeStart();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    double elapsedEatingTime = customer->getElapsedEatingTime();
    EXPECT_GT(elapsedEatingTime, 0.1);
}

// Test updateStatus method
TEST_F(CustomerTest, UpdateStatus) {
    customer->updateStatus(CustomerStatus::Eating);
    EXPECT_EQ(customer->getStatus(), CustomerStatus::Eating);
}

// Test calculateTotalWait method
TEST_F(CustomerTest, CalculateTotalWait) {
    customer->setWaitingTimeStart();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    customer->setTotalWaitingTime();
    customer->setEatingTime(200);
    EXPECT_GT(customer->calculateTotalWait(), 0.1);
}

// Test eat method
TEST_F(CustomerTest, Eat) {
    std::string itemName = "Pizza";
    customer->setOrderedMenuItem(itemName);
    customer->updateStatus(CustomerStatus::WaitingForFood);
    customer->eat(100);
    EXPECT_EQ(customer->getStatus(), CustomerStatus::WaitingToLeave);
}

// Test toStringStatus method
TEST_F(CustomerTest, ToStringStatus) {
    std::string status = customer->toStringStatus();
    EXPECT_NE(status.find("Customer 1: TestCustomer"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
