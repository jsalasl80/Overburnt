// test_customer_spawner.cpp

#include <gtest/gtest.h>
#include "CustomerSpawner.h"
#include "CustomersInLine.h"

class CustomerSpawnerTest : public ::testing::Test {
protected:
    CustomersInLine* customersInLine;
    CustomerSpawner* customerSpawner;

    void SetUp() override {
        customersInLine = new CustomersInLine();
        customerSpawner = new CustomerSpawner(customersInLine);
    }

    void TearDown() override {
        delete customerSpawner;
        delete customersInLine;
    }
};

TEST_F(CustomerSpawnerTest, GenerateCustomerName) {
    std::string name = customerSpawner->generateCustomerName();
    EXPECT_FALSE(name.empty());
}

TEST_F(CustomerSpawnerTest, SpawnClients) {
    std::thread spawnerThread([this] { customerSpawner->spawnClients(); });
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Let it spawn some customers
    customerSpawner->stopSpawning();
    spawnerThread.join();

    EXPECT_GT(customersInLine->getCustomersInLine(), 0);
}

TEST_F(CustomerSpawnerTest, StopSpawning) {
    std::thread spawnerThread([this] { customerSpawner->spawnClients(); });
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Let it spawn some customers
    customerSpawner->stopSpawning();
    spawnerThread.join();

    int countAfterStop = customersInLine->getCustomersInLine();
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Ensure no more customers are spawned
    EXPECT_EQ(countAfterStop, customersInLine->getCustomersInLine());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
