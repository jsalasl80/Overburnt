#include <gtest/gtest.h>
#include "Ingredient.h"

TEST(IngredientTest, CreateIngredient) {
    Ingredient ingredient("Tomato", 1, 2.0);
    EXPECT_EQ(ingredient.getName(), "Tomato");
    EXPECT_EQ(ingredient.getUnitaryCost(), 2.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
