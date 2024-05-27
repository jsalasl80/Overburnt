#include <gtest/gtest.h>
#include "ResultsQueue.h"

class ResultsQueueTest : public ::testing::Test {
protected:
    ResultsQueue<int>* queue;

    void SetUp() override {
        queue = new ResultsQueue<int>();
    }

    void TearDown() override {
        delete queue;
    }
};

TEST_F(ResultsQueueTest, IsEmpty) {
    EXPECT_TRUE(queue->isEmpty());
}

TEST_F(ResultsQueueTest, Enqueue) {
    queue->enqueue(1);
    EXPECT_FALSE(queue->isEmpty());
}

TEST_F(ResultsQueueTest, Dequeue) {
    queue->enqueue(1);
    queue->enqueue(2);
    int first = queue->dequeue();
    EXPECT_EQ(first, 1);
    EXPECT_FALSE(queue->isEmpty());
    int second = queue->dequeue();
    EXPECT_EQ(second, 2);
    EXPECT_TRUE(queue->isEmpty());
}

TEST_F(ResultsQueueTest, EnqueueAndDequeueMultipleItems) {
    for (int i = 0; i < 10; ++i) {
        queue->enqueue(i);
    }
    for (int i = 0; i < 10; ++i) {
        int value = queue->dequeue();
        EXPECT_EQ(value, i);
    }
    EXPECT_TRUE(queue->isEmpty());
}

