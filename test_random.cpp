#include <gtest/gtest.h>
#include "Random.h"

TEST(RandomTest, GetRandomNumber) {
    Random random;
    int number = random.getRandomNumber(1, 10);
    EXPECT_GE(number, 1);
    EXPECT_LE(number, 10);
    // Verify that the random number is within the range
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
