#include <gtest/gtest.h>
#include "ThreadPoolDeliverers.h"
#include "Deliverer.h"
#include "Order.h"
#include "ResultsQueue.h"
#include "Customer.h"
#include "Recipe.h"

class ThreadPoolDeliverersTest : public ::testing::Test {
protected:
    ThreadPoolDeliverers* threadPoolDeliverers;
    ResultsQueue<Order*>* ordersToDeliver;
    Deliverer** deliverers;
    Customer* customer;
    Recipe* recipe;
    Order* order;

    void SetUp() override {
        ordersToDeliver = new ResultsQueue<Order*>();

        customer = new Customer(1, "John Doe");
        std::vector<std::string> ingredients = {"Tomato", "Pasta"};
        std::vector<int> amounts = {2, 3};
        recipe = new Recipe("Pasta", 10.0, 15, 10, ingredients, amounts);
        order = new Order(1, 1, recipe, customer);

        // Crear Deliverers
        deliverers = new Deliverer*[DELIVERERS_AMOUNT];
        for (int i = 0; i < DELIVERERS_AMOUNT; ++i) {
            deliverers[i] = new Deliverer();
        }

        threadPoolDeliverers = new ThreadPoolDeliverers(deliverers, ordersToDeliver);
    }

    void TearDown() override {
        delete threadPoolDeliverers;
        delete ordersToDeliver;
        delete order;
        delete recipe;
        delete customer;

        for (int i = 0; i < DELIVERERS_AMOUNT; ++i) {
            delete deliverers[i];
        }
        delete[] deliverers;
    }
};

TEST_F(ThreadPoolDeliverersTest, EnqueueOrder) {
    ordersToDeliver->enqueue(order);
    EXPECT_FALSE(ordersToDeliver->isEmpty());
    Order* dequeuedOrder = ordersToDeliver->dequeue();
    EXPECT_EQ(dequeuedOrder, order);
}

TEST_F(ThreadPoolDeliverersTest, GetAvailableDeliverer) {
    Deliverer* availableDeliverer = threadPoolDeliverers->getAvailableDeliverer();
    ASSERT_NE(availableDeliverer, nullptr);
    EXPECT_EQ(availableDeliverer->getState(), DELIVERING);
}

TEST_F(ThreadPoolDeliverersTest, RunAndStop) {
    std::thread poolThread(&ThreadPoolDeliverers::run, threadPoolDeliverers);
    ordersToDeliver->enqueue(order);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Espera para asegurar que los hilos se inicien
    threadPoolDeliverers->stopRunning();
    poolThread.join();

    // Ensure that the deliverer state has changed to DELIVERING
    for (int i = 0; i < DELIVERERS_AMOUNT; ++i) {
        if (!deliverers[i]->getAvailability()) {
            EXPECT_EQ(deliverers[i]->getState(), DELIVERING);
        }
    }
}

TEST_F(ThreadPoolDeliverersTest, AddDelivererToRotation) {
    Deliverer* deliverer = threadPoolDeliverers->getAvailableDeliverer();
    ordersToDeliver->enqueue(order);
    bool added = threadPoolDeliverers->addDelivererToRotation(deliverer);
    EXPECT_TRUE(added);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
