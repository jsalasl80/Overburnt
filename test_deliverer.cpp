#include <gtest/gtest.h>
#include "Deliverer.h"
#include "Order.h"

TEST(DelivererTest, DeliverOrder) {
    Deliverer deliverer;
    Order order(1, 1, nullptr, nullptr);
    deliverer.deliverOrder(&order);
    // Verify that the order was delivered correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
