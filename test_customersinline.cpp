#include <gtest/gtest.h>
#include "CustomersInLine.h"

TEST(CustomersInLineTest, AddCustomers) {
    CustomersInLine customersInLine;
    Customer customer(1, "John Doe");
    std::vector<Customer*> customers = {&customer};
    customersInLine.addCustomers(customers);
    // Verify that the customer was added correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
