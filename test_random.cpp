#include <gtest/gtest.h>
#include "Random.h"

class RandomTest : public ::testing::Test {
protected:
    Random* random;

    void SetUp() override {
        random = new Random();
    }

    void TearDown() override {
        delete random;
    }
};

TEST_F(RandomTest, GenerateRandomInRange) {
    int start = 1;
    int end = 10;
    for (int i = 0; i < 100; ++i) {
        int result = random->generateRandomInRange(start, end);
        EXPECT_GE(result, start);
        EXPECT_LE(result, end);
    }
}

TEST_F(RandomTest, GenerateBinaryRandom) {
    int option = 1;
    int alternative = 2;
    bool optionSeen = false;
    bool alternativeSeen = false;
    for (int i = 0; i < 100; ++i) {
        int result = random->generateBinaryRandom(option, alternative);
        if (result == option) {
            optionSeen = true;
        } else if (result == alternative) {
            alternativeSeen = true;
        }
    }
    EXPECT_TRUE(optionSeen);
    EXPECT_TRUE(alternativeSeen);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
