#include <gtest/gtest.h>
#include "Inventory.h"
#include "Ingredient.h"

class InventoryTest : public ::testing::Test {
protected:
    Inventory* inventory;

    void SetUp() override {
        inventory = new Inventory();
    }

    void TearDown() override {
        delete inventory;
    }
};

TEST_F(InventoryTest, AddAndGetIngredient) {
    std::string ingredientName = "Tomato";
    Ingredient* ingredient = new Ingredient(ingredientName, 100, 0.5);
    inventory->addIngredient(ingredientName, ingredient);

    Ingredient* retrievedIngredient = inventory->getIngredient(ingredientName);
    EXPECT_EQ(retrievedIngredient->getIngredientName(), "Tomato");
    EXPECT_EQ(retrievedIngredient->getConsumedPortions(), 0);
    EXPECT_FLOAT_EQ(retrievedIngredient->getUnitaryCost(), 0.5);
}

TEST_F(InventoryTest, GetAvailability) {
    EXPECT_TRUE(inventory->getAvailability());
    inventory->lock();
    EXPECT_FALSE(inventory->getAvailability());
    inventory->unlock();
    EXPECT_TRUE(inventory->getAvailability());
}

TEST_F(InventoryTest, GetSize) {
    EXPECT_EQ(inventory->getSize(), 0);
    std::string ingredientName = "Tomato";
    Ingredient* ingredient = new Ingredient(ingredientName, 100, 0.5);
    inventory->addIngredient(ingredientName, ingredient);
    EXPECT_EQ(inventory->getSize(), 1);
}

TEST_F(InventoryTest, ClearInventory) {
    std::string ingredientName = "Tomato";
    Ingredient* ingredient = new Ingredient(ingredientName, 100, 0.5);
    inventory->addIngredient(ingredientName, ingredient);
    inventory->clearInventory();
    EXPECT_EQ(inventory->getSize(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
