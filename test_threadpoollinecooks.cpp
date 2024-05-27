// test_threadpoollinecooks.cpp

#include <gtest/gtest.h>
#include "ThreadPoolLineCooks.h"
#include "LineCook.h"
#include "Order.h"
#include "ResultsQueue.h"
#include "Customer.h"
#include "Recipe.h"

class ThreadPoolLineCooksTest : public ::testing::Test {
protected:
    ThreadPoolLineCooks* threadPoolLineCooks;
    ResultsQueue<Order*>* ordersToDo;
    ResultsQueue<Order*>* completedOrders;
    LineCook** lineCooks;
    Customer* customer;
    Recipe* recipe;
    Order* order;

    void SetUp() override {
        ordersToDo = new ResultsQueue<Order*>();
        completedOrders = new ResultsQueue<Order*>();

        customer = new Customer(1, "John Doe");
        std::vector<std::string> ingredients = {"Tomato", "Pasta"};
        std::vector<int> amounts = {2, 3};
        recipe = new Recipe("Pasta", 10.0, 15, 10, ingredients, amounts);
        order = new Order(1, 1, recipe, customer);

        // Create LineCooks
        lineCooks = new LineCook*[LINE_COOKS_AMOUNT];
        for (int i = 0; i < LINE_COOKS_AMOUNT; ++i) {
            lineCooks[i] = new LineCook(completedOrders);
        }

        threadPoolLineCooks = new ThreadPoolLineCooks(lineCooks, ordersToDo);
    }

    void TearDown() override {
        delete threadPoolLineCooks;
        delete ordersToDo;
        delete completedOrders;
        delete order;
        delete recipe;
        delete customer;

        for (int i = 0; i < LINE_COOKS_AMOUNT; ++i) {
            delete lineCooks[i];
        }
        delete[] lineCooks;
    }
};

TEST_F(ThreadPoolLineCooksTest, GetAvailableLineCook) {
    LineCook* availableLineCook = threadPoolLineCooks->getAvailableLineCook();
    ASSERT_NE(availableLineCook, nullptr);
    EXPECT_EQ(availableLineCook->getState(), COOKING);
}

TEST_F(ThreadPoolLineCooksTest, AddLineCookToRotation) {
    LineCook* lineCook = threadPoolLineCooks->getAvailableLineCook();
    ordersToDo->enqueue(order);
    bool added = threadPoolLineCooks->addLineCookToRotation(lineCook);
    EXPECT_TRUE(added);
}

TEST_F(ThreadPoolLineCooksTest, RunAndStop) {
    std::thread poolThread(&ThreadPoolLineCooks::run, threadPoolLineCooks);
    ordersToDo->enqueue(order);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait to ensure threads start
    threadPoolLineCooks->stopRunning();
    poolThread.join();

    for (int i = 0; i < LINE_COOKS_AMOUNT; ++i) {
        if (!lineCooks[i]->getAvailability()) {
            EXPECT_EQ(lineCooks[i]->getState(), COOKING);
        }
    }
}

TEST_F(ThreadPoolLineCooksTest, StopRunning) {
    std::thread poolThread(&ThreadPoolLineCooks::run, threadPoolLineCooks);
    ordersToDo->enqueue(order);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait to ensure threads start
    threadPoolLineCooks->stopRunning();
    poolThread.join();

    EXPECT_FALSE(threadPoolLineCooks->getRunning);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
