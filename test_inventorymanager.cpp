#include <gtest/gtest.h>
#include "InventoryManager.h"
#include "Inventory.h"
#include "Accountant.h"
#include "Ingredient.h"

class InventoryManagerTest : public ::testing::Test {
protected:
    Inventory* inventory;
    Accountant* accountant;
    InventoryManager* inventoryManager;

    void SetUp() override {
        inventory = new Inventory();
        accountant = new Accountant();
        inventoryManager = new InventoryManager(inventory, accountant);

        // Crear un archivo CSV de prueba
        std::ofstream outFile(INVENTORY_CSV);
        outFile << "Ingredient,Amount,UnitaryCost\n";
        outFile << "Tomato,100,0.5\n";
        outFile << "Pasta,200,1.2\n";
        outFile.close();
    }

    void TearDown() override {
        delete inventoryManager;
        delete accountant;
        // Eliminar el archivo de prueba
        std::remove(INVENTORY_CSV);
    }
};

TEST_F(InventoryManagerTest, SetUpInventory) {
    inventoryManager->setUpInventory();
    EXPECT_EQ(inventory->getSize(), 2);

    Ingredient* ingredient = inventory->getIngredient("Tomato");
    ASSERT_NE(ingredient, nullptr);
    EXPECT_EQ(ingredient->getIngredientName(), "Tomato");
    EXPECT_EQ(ingredient->getConsumedPortions(), 0);
    EXPECT_FLOAT_EQ(ingredient->getUnitaryCost(), 0.5);
}

TEST_F(InventoryManagerTest, CheckIngredientsAvailability) {
    inventoryManager->setUpInventory();

    std::map<std::string, int> ingredientsNeeded = {
        {"Tomato", 50},
        {"Pasta", 150}
    };

    bool available = inventoryManager->checkIngredientsAvailability(ingredientsNeeded);
    EXPECT_TRUE(available);

    ingredientsNeeded = {
        {"Tomato", 101}
    };

    available = inventoryManager->checkIngredientsAvailability(ingredientsNeeded);
    EXPECT_FALSE(available);
}

TEST_F(InventoryManagerTest, UpdateInventory) {
    inventoryManager->setUpInventory();

    std::map<std::string, int> ingredientsUsed = {
        {"Tomato", 50},
        {"Pasta", 150}
    };

    inventoryManager->updateInventory(ingredientsUsed);

    Ingredient* tomato = inventory->getIngredient("Tomato");
    ASSERT_NE(tomato, nullptr);
    EXPECT_EQ(tomato->getConsumedPortions(), 50);
    EXPECT_EQ(tomato->checkConsumability(50), true);

    Ingredient* pasta = inventory->getIngredient("Pasta");
    ASSERT_NE(pasta, nullptr);
    EXPECT_EQ(pasta->getConsumedPortions(), 150);
    EXPECT_EQ(pasta->checkConsumability(50), true);
    EXPECT_EQ(pasta->checkConsumability(51), false);
}

TEST_F(InventoryManagerTest, ClearInventory) {
    inventoryManager->setUpInventory();
    inventoryManager->clearInventory();
    EXPECT_EQ(inventory->getSize(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
