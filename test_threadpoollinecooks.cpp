#include <gtest/gtest.h>
#include "ThreadPoolLineCooks.h"
#include "Order.h"

TEST(ThreadPoolLineCooksTest, AddLineCook) {
    ThreadPoolLineCooks pool;
    pool.addLineCook();
    // Verify that the line cook was added correctly
}

TEST(ThreadPoolLineCooksTest, AssignOrder) {
    ThreadPoolLineCooks pool;
    Order order(1, 1, nullptr, nullptr);
    pool.assignOrder(&order);
    // Verify that the order was assigned correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
