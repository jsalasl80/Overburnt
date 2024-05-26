#include <gtest/gtest.h>
#include "Waiter.h"
#include "Order.h"

TEST(WaiterTest, TakeOrder) {
    Waiter waiter;
    Order order(1, 1, nullptr, nullptr);
    waiter.takeOrder(&order);
    // Verify that the order was taken correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
