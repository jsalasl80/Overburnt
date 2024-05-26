#include <gtest/gtest.h>
#include "ThreadPoolTables.h"
#include "Order.h"

TEST(ThreadPoolTablesTest, AddTable) {
    ThreadPoolTables pool;
    pool.addTable();
    // Verify that the table was added correctly
}

TEST(ThreadPoolTablesTest, AssignOrder) {
    ThreadPoolTables pool;
    Order order(1, 1, nullptr, nullptr);
    pool.assignOrder(&order);
    // Verify that the order was assigned correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
