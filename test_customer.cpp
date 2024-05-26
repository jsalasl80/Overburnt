#include <gtest/gtest.h>
#include "Customer.h"

TEST(CustomerTest, CreateCustomer) {
    Customer customer(1, "John Doe");
    EXPECT_EQ(customer.getId(), 1);
    EXPECT_EQ(customer.getName(), "John Doe");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
