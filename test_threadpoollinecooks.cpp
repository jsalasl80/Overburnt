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
    ResultsQueue<Order*>* ordersToPrepare;
    LineCook** lineCooks;
    Customer* customer;
    Recipe* recipe;
    Order* order;

    void SetUp() override {
        ordersToPrepare = new ResultsQueue<Order*>();

        customer = new Customer(1, "John Doe");
        std::vector<std::string> ingredients = {"Tomato", "Pasta"};
        std::vector<int> amounts = {2, 3};
        recipe = new Recipe("Pasta", 10.0, 15, 10, ingredients, amounts);
        order = new Order(1, 1, recipe, customer);

        // Crear LineCooks
        lineCooks = new LineCook*[2];
        for (int i = 0; i < 2; ++i) {
            lineCooks[i] = new LineCook(ordersToPrepare);
        }

        threadPoolLineCooks = new ThreadPoolLineCooks(lineCooks, ordersToPrepare);
    }

    void TearDown() override {
        delete threadPoolLineCooks;
        delete ordersToPrepare;
        delete order;
        delete recipe;
        delete customer;

        for (int i = 0; i < 2; ++i) {
            delete lineCooks[i];
        }
        delete[] lineCooks;
    }
};

TEST_F(ThreadPoolLineCooksTest, EnqueueOrder) {
    threadPoolLineCooks->enqueueOrder(order);
    EXPECT_FALSE(ordersToPrepare->isEmpty());
    Order* dequeuedOrder = ordersToPrepare->dequeue();
    EXPECT_EQ(dequeuedOrder, order);
}

TEST_F(ThreadPoolLineCooksTest, PrepareOrders) {
    threadPoolLineCooks->enqueueOrder(order);

    std::thread prepareThread(&ThreadPoolLineCooks::prepareOrders, threadPoolLineCooks);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Espera para asegurar que los hilos se inicien
    threadPoolLineCooks->stopPreparing();
    prepareThread.join();

    EXPECT_EQ(order->getOrderState(), READY);
}

TEST_F(ThreadPoolLineCooksTest, StopPreparing) {
    threadPoolLineCooks->enqueueOrder(order);

    std::thread prepareThread(&ThreadPoolLineCooks::prepareOrders, threadPoolLineCooks);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Espera para asegurar que los hilos se inicien
    threadPoolLineCooks->stopPreparing();
    prepareThread.join();

    EXPECT_FALSE(ordersToPrepare->isEmpty()); // Debería haber detenido la preparación antes de que se vacíe
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
