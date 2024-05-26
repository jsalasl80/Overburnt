#include <gtest/gtest.h>
#include "InventoryManager.h"
#include "Inventory.h"
#include "Ingredient.h"

TEST(InventoryManagerTest, RestockInventory) {
    Inventory inventory;
    InventoryManager manager(&inventory);
    Ingredient ingredient("Tomato", 1, 2.0);
    manager.restockIngredient(&ingredient, 10);
    // Verify that the inventory was restocked correctly
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
