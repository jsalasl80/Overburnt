#include <gtest/gtest.h>
#include "ThreadPoolDeliverer.h"
#include "Order.h"

TEST(ThreadPoolDelivererTest, AddDeliverer) {
    ThreadPoolDeliverer pool;
    pool.addDeliverer();
    // Verify that the deliverer was added correctly
}

TEST(ThreadPoolDelivererTest, AssignOrder) {
    ThreadPoolDeliverer pool;
    Order order(1, 1, nullptr, nullptr);
    pool.assignOrder(&order);
    // Verify that the order was assigned correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
