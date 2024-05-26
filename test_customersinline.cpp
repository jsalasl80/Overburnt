#include <gtest/gtest.h>
#include "CustomersInLine.h"

TEST(CustomersInLineTest, AddCustomer) {
    CustomersInLine customersInLine;
    Customer customer(1, "John Doe");
    customersInLine.addCustomer(&customer);
    // Verify that the customer was added correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
