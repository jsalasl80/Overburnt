#include <gtest/gtest.h>
#include "LineCook.h"
#include "Order.h"

TEST(LineCookTest, CookOrder) {
    LineCook lineCook;
    Order order(1, 1, nullptr, nullptr);
    lineCook.cookOrder(&order);
    // Verify that the order was cooked correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
