// test_customer.cpp

#include <gtest/gtest.h>
#include "Customer.h"
#include <thread>
#include <chrono>

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

TEST_F(CustomerTest, SetAndGetOrderPrepTime) {
    int orderPrepTime = 15;
    customer->setOrderPrepTime(orderPrepTime);
    EXPECT_EQ(customer->getOrderPrepTime(), orderPrepTime);
}

TEST_F(CustomerTest, SetAndGetOrderEatingTime) {
    int orderEatingTime = 10;
    customer->setOrderEatingTime(orderEatingTime);
    EXPECT_EQ(customer->getOrderEatingTime(), orderEatingTime);
}

TEST_F(CustomerTest, WaitForOrder) {
    customer->setWaitingTimeStart();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    customer->setTotalWaitingTime();
    EXPECT_GE(customer->getWaitingTime(), 0.1);
}

TEST_F(CustomerTest, EatOrder) {
    customer->updateStatus(CustomerStatus::WaitingForFood);
    customer->eat(100);
    EXPECT_EQ(customer->getStatus(), CustomerStatus::WaitingToLeave);
}

TEST_F(CustomerTest, CalculateTotalWait) {
    customer->setWaitingTimeStart();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    customer->setTotalWaitingTime();
    customer->eat(100);
    EXPECT_GE(customer->calculateTotalWait(), 0.15);
}

TEST_F(CustomerTest, ToStringStatus) {
    std::string expected = "Customer 1: John Doe\nStatus: Waiting to order\n";
    EXPECT_EQ(customer->toStringStatus(), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
