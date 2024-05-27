// test_customers_inline.cpp

#include <gtest/gtest.h>
#include "CustomersInLine.h"
#include "Customer.h"

class CustomersInLineTest : public ::testing::Test {
protected:
    CustomersInLine* customersInLine;
    Customer* customer1;
    Customer* customer2;

    void SetUp() override {
        customersInLine = new CustomersInLine();
        customer1 = new Customer(1, "John Doe");
        customer2 = new Customer(2, "Jane Doe");
    }

    void TearDown() override {
        delete customersInLine;
        delete customer1;
        delete customer2;
    }
};

TEST_F(CustomersInLineTest, AddCustomers) {
    std::vector<Customer*> customers = {customer1, customer2};
    customersInLine->addCustomers(customers);
    EXPECT_EQ(customersInLine->getCustomersInLine(), 2);
}

TEST_F(CustomersInLineTest, ExtractCustomers) {
    std::vector<Customer*> customers = {customer1, customer2};
    customersInLine->addCustomers(customers);

    std::vector<Customer*> extractedCustomers = customersInLine->extractCustomers();
    EXPECT_EQ(extractedCustomers.size(), 2);
    EXPECT_EQ(customersInLine->getCustomersInLine(), 0);
}

TEST_F(CustomersInLineTest, IsEmpty) {
    EXPECT_TRUE(customersInLine->isEmpty());

    std::vector<Customer*> customers = {customer1, customer2};
    customersInLine->addCustomers(customers);

    EXPECT_FALSE(customersInLine->isEmpty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
