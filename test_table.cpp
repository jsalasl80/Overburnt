#include <gtest/gtest.h>
#include "Table.h"
#include "Order.h"

TEST(TableTest, SeatCustomer) {
    Table table(1);
    table.seatCustomer();
    // Verify that the customer was seated correctly
}

TEST(TableTest, ServeOrder) {
    Table table(1);
    Order order(1, 1, nullptr, nullptr);
    table.serveOrder(&order);
    // Verify that the order was served correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
