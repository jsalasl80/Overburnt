#include <gtest/gtest.h>
#include "Recipe.h"

class RecipeTest : public ::testing::Test {
protected:
    Recipe* recipe;

    void SetUp() override {
        std::vector<std::string> ingredients = {"Tomato", "Pasta"};
        std::vector<int> amounts = {2, 3};
        recipe = new Recipe("Pasta", 10.0, 15, 10, ingredients, amounts);
    }

    void TearDown() override {
        delete recipe;
    }
};

TEST_F(RecipeTest, GetRecipeName) {
    EXPECT_EQ(recipe->getRecipeName(), "Pasta");
}

TEST_F(RecipeTest, GetPrice) {
    EXPECT_FLOAT_EQ(recipe->getPrice(), 10.0);
}

TEST_F(RecipeTest, GetApproxPrepTime) {
    EXPECT_EQ(recipe->getApproxPrepTime(), 15);
}

TEST_F(RecipeTest, GetApproxEatingTime) {
    EXPECT_EQ(recipe->getApproxEatingTime(), 10);
}

TEST_F(RecipeTest, GetTotalIngredientsStored) {
    EXPECT_EQ(recipe->getTotalIngredientsStored(), 2);
}

TEST_F(RecipeTest, GetIngredient) {
    EXPECT_EQ(recipe->getIngredient(0), "Tomato");
    EXPECT_EQ(recipe->getIngredient(1), "Pasta");
}

TEST_F(RecipeTest, GetIngredientAmount) {
    EXPECT_EQ(recipe->getIngredientAmount(0), 2);
    EXPECT_EQ(recipe->getIngredientAmount(1), 3);
}

TEST_F(RecipeTest, ToStringIngredients) {
    EXPECT_EQ(recipe->toStringIngredients(), "\nTomato: 2 Pasta: 3 ");
}

TEST_F(RecipeTest, ToString) {
    EXPECT_EQ(recipe->toString(), "Pasta $10.000000");
}

