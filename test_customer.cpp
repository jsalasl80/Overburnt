#include <gtest/gtest.h>
#include "Customer.h"

// Test fixture for Customer class
class CustomerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // You can do set-up work for each test here.
        customer = new Customer(1, "Test Customer");
    }

    void TearDown() override {
        // You can do clean-up work that doesn't throw exceptions here.
        delete customer;
    }

    // Class members can be used in tests.
    Customer* customer;
};

// Test constructor
TEST_F(CustomerTest, ConstructorTest) {
    EXPECT_EQ(customer->getId(), 1);
    EXPECT_EQ(customer->getName(), "Test Customer");
    EXPECT_EQ(customer->getStatus(), CustomerStatus::Waiting);
}

// Test getId
TEST_F(CustomerTest, GetIdTest) {
    EXPECT_EQ(customer->getId(), 1);
}

// Test getName
TEST_F(CustomerTest, GetNameTest) {
    EXPECT_EQ(customer->getName(), "Test Customer");
}

// Test getStatus
TEST_F(CustomerTest, GetStatusTest) {
    EXPECT_EQ(customer->getStatus(), CustomerStatus::Waiting);
}

// Test set and get eating time
TEST_F(CustomerTest, SetAndGetEatingTimeTest) {
    customer->setEatingTime(5000);
    EXPECT_EQ(customer->getEatingTime(), 5000);
}

// Test setOrderedMenuItem and orderFromMenu
TEST_F(CustomerTest, SetOrderedMenuItemTest) {
    std::string item = "Pizza";
    customer->setOrderedMenuItem(item);
    EXPECT_EQ(customer->getStatus(), CustomerStatus::Ordering);
}

// Test setWaitingTimeStart and getElapsedWaitTime
TEST_F(CustomerTest, SetWaitingTimeStartTest) {
    customer->setWaitingTimeStart();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    EXPECT_GT(customer->getElapsedWaitTime(), 0);
}

// Test setEatingTimeStart and getElapsedEatingTime
TEST_F(CustomerTest, SetEatingTimeStartTest) {
    customer->setEatingTimeStart();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    EXPECT_GT(customer->getElapsedEatingTime(), 0);
}

// Test updateStatus
TEST_F(CustomerTest, UpdateStatusTest) {
    customer->updateStatus(CustomerStatus::Eating);
    EXPECT_EQ(customer->getStatus(), CustomerStatus::Eating);
}

// Test calculateTotalWait
TEST_F(CustomerTest, CalculateTotalWaitTest) {
    customer->setWaitingTimeStart();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    customer->setTotalWaitingTime();
    customer->setEatingTime(5000);
    EXPECT_GT(customer->calculateTotalWait(), 5000);
}

// Test toStringStatus
TEST_F(CustomerTest, ToStringStatusTest) {
    std::string expected = "Customer 1: Test Customer\nStatus: Waiting to order\n";
    EXPECT_EQ(customer->toStringStatus(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
