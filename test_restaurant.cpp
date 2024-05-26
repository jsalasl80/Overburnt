#include <gtest/gtest.h>
#include "Restaurant.h"

TEST(RestaurantTest, OpenRestaurant) {
    Restaurant restaurant;
    restaurant.openRestaurant();
    // Verify that the restaurant opened correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
