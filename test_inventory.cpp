#include <gtest/gtest.h>
#include "Inventory.h"
#include "Ingredient.h"

TEST(InventoryTest, AddIngredient) {
    Inventory inventory;
    Ingredient ingredient("Tomato", 1, 2.0);
    inventory.addIngredient(&ingredient);
    // Verify that the ingredient was added correctly
}

TEST(InventoryTest, UseIngredient) {
    Inventory inventory;
    Ingredient ingredient("Tomato", 1, 2.0);
    inventory.addIngredient(&ingredient);
    ASSERT_TRUE(inventory.useIngredient("Tomato", 1));
    // Verify that the ingredient was used correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
