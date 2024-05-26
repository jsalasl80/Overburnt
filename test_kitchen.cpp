#include <gtest/gtest.h>
#include "Kitchen.h"
#include "Recipe.h"

TEST(KitchenTest, PrepareRecipe) {
    Kitchen kitchen;
    Recipe recipe("Pasta", 10.0, 30, 20, {"Tomato", "Pasta"}, {1, 2});
    kitchen.prepareRecipe(&recipe);
    // Verify that the recipe was prepared correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
