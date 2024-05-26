#include <gtest/gtest.h>
#include "Menu.h"
#include "Recipe.h"

TEST(MenuTest, AddRecipe) {
    Menu menu;
    Recipe recipe("Pasta", 10.0, 30, 20, {"Tomato", "Pasta"}, {1, 2});
    menu.addRecipe(&recipe);
    // Verify that the recipe was added correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
