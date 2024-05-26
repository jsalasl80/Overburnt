#include <gtest/gtest.h>
#include "CSVReader.h"

TEST(CSVReaderTest, ReadInventory) {
    CSVReader reader("bin/ingredientes.csv");
    std::string ingredientName;
    int amount;
    float unitaryCost;
    ASSERT_TRUE(reader.readInventory(ingredientName, amount, unitaryCost));
    // Verify that inventory data was read correctly
}

TEST(CSVReaderTest, ReadRecipes) {
    CSVReader reader("bin/recetas.csv");
    std::string recipeName;
    float price;
    int prepTime;
    int eatTime;
    std::vector<std::string> recipeIngredients;
    std::vector<int> ingredientAmounts;
    ASSERT_TRUE(reader.readRecipes(recipeName, price, prepTime, eatTime, recipeIngredients, ingredientAmounts));
    // Verify that recipe data was read correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
