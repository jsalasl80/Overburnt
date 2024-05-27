#include <gtest/gtest.h>
#include "ThreadPoolDeliverer.h"
#include "Order.h"
#include "ResultsQueue.h"
#include "Deliverer.h"
#include "Customer.h"
#include "Recipe.h"

class ThreadPoolDelivererTest : public ::testing::Test {
protected:
    ThreadPoolDeliverer* threadPoolDeliverer;
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
        deliverers = new Deliverer*[2];
        for (int i = 0; i < 2; ++i) {
            deliverers[i] = new Deliverer();
        }

        threadPoolDeliverer = new ThreadPoolDeliverer(deliverers, ordersToDeliver);
    }

    void TearDown() override {
        delete threadPoolDeliverer;
        delete ordersToDeliver;
        delete order;
        delete recipe;
        delete customer;

        for (int i = 0; i < 2; ++i) {
            delete deliverers[i];
        }
        delete[] deliverers;
    }
};

TEST_F(ThreadPoolDelivererTest, EnqueueOrder) {
    threadPoolDeliverer->enqueueOrder(order);
    EXPECT_FALSE(ordersToDeliver->isEmpty());
    Order* dequeuedOrder = ordersToDeliver->dequeue();
    EXPECT_EQ(dequeuedOrder, order);
}

TEST_F(ThreadPoolDelivererTest, DeliverOrders) {
    threadPoolDeliverer->enqueueOrder(order);

    std::thread deliverThread(&ThreadPoolDeliverer::deliverOrders, threadPoolDeliverer);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Espera para asegurar que los hilos se inicien
    threadPoolDeliverer->stopDelivering();
    deliverThread.join();

    EXPECT_EQ(customer->getStatus(), CustomerStatus::WaitingToLeave);
}

TEST_F(ThreadPoolDelivererTest, StopDelivering) {
    threadPoolDeliverer->enqueueOrder(order);

    std::thread deliverThread(&ThreadPoolDeliverer::deliverOrders, threadPoolDeliverer);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Espera para asegurar que los hilos se inicien
    threadPoolDeliverer->stopDelivering();
    deliverThread.join();

    EXPECT_FALSE(ordersToDeliver->isEmpty()); // Debería haber detenido la entrega antes de que se vacíe
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
