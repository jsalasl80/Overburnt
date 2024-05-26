#include <gtest/gtest.h>
#include "Order.h"

TEST(OrderTest, CreateOrder) {
    Order order(1, 1, nullptr, nullptr);
    EXPECT_EQ(order.getOrderId(), 1);
    EXPECT_EQ(order.getTableId(), 1);
    // Verify that the order was created correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
