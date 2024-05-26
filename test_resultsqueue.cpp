#include <gtest/gtest.h>
#include "ResultsQueue.h"
#include "Order.h"

TEST(ResultsQueueTest, AddOrder) {
    ResultsQueue resultsQueue;
    Order order(1, 1, nullptr, nullptr);
    resultsQueue.addOrder(&order);
    // Verify that the order was added correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
