#include <gtest/gtest.h>
#include "Recipe.h"

TEST(RecipeTest, CreateRecipe) {
    Recipe recipe("Pasta", 10.0, 30, 20, {"Tomato", "Pasta"}, {1, 2});
    EXPECT_EQ(recipe.getName(), "Pasta");
    EXPECT_EQ(recipe.getPrice(), 10.0);
    // Verify that the recipe was created correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
