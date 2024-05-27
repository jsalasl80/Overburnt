#include <gtest/gtest.h>
#include "Ingredient.h"

class IngredientTest : public ::testing::Test {
protected:
    Ingredient* ingredient;

    void SetUp() override {
        std::string name = "Tomato";
        ingredient = new Ingredient(name, 100, 0.5);
    }

    void TearDown() override {
        delete ingredient;
    }
};

TEST_F(IngredientTest, GetIngredientName) {
    EXPECT_EQ(ingredient->getIngredientName(), "Tomato");
}

TEST_F(IngredientTest, GetConsumedPortions) {
    EXPECT_EQ(ingredient->getConsumedPortions(), 0);
}

TEST_F(IngredientTest, GetUnitaryCost) {
    EXPECT_FLOAT_EQ(ingredient->getUnitaryCost(), 0.5);
}

TEST_F(IngredientTest, ConsumePortions) {
    ingredient->consumePortions(10);
    EXPECT_EQ(ingredient->getConsumedPortions(), 10);
    EXPECT_EQ(ingredient->checkConsumability(90), true);
    EXPECT_EQ(ingredient->checkConsumability(91), false);
}

TEST_F(IngredientTest, CheckConsumability) {
    EXPECT_TRUE(ingredient->checkConsumability(50));
    EXPECT_FALSE(ingredient->checkConsumability(101));
}

TEST_F(IngredientTest, ToString) {
    EXPECT_EQ(ingredient->toString(), "Tomato: 100");
    ingredient->consumePortions(10);
    EXPECT_EQ(ingredient->toString(), "Tomato: 90");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
