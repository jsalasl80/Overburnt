#include <gtest/gtest.h>
#include "Accountant.h"
#include "Recipe.h"
#include "Ingredient.h"

TEST(AccountantTest, UpdateWinnings) {
    Accountant accountant;
    Recipe recipe("Pasta", 10.0, 30, 20, {"Tomato", "Pasta"}, {1, 2});
    accountant.updateWinnings(&recipe);
    // Verify that winnings were updated correctly
}

TEST(AccountantTest, UpdateExpenses) {
    Accountant accountant;
    std::string ingredientName = "Tomato";
    Ingredient ingredient(ingredientName, 1, 2.0);
    accountant.updateExpenses(&ingredient, 3);
    // Verify that expenses were updated correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
