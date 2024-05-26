#include <gtest/gtest.h>
#include "CustomerSpawner.h"

TEST(CustomerSpawnerTest, SpawnCustomer) {
    CustomerSpawner spawner;
    Customer* customer = spawner.spawnCustomer();
    ASSERT_NE(customer, nullptr);
    // Verify that the customer was spawned correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
