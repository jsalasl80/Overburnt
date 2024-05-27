#include <gtest/gtest.h>
#include "RecipeReader.h"
#include "Menu.h"
#include "Recipe.h"
#include <fstream>
#include <cstdio> // For std::remove

class RecipeReaderTest : public ::testing::Test {
protected:
    Menu* menu;
    RecipeReader* recipeReader;

    void SetUp() override {
        menu = new Menu();
        recipeReader = new RecipeReader(menu);

        // Crear un archivo CSV de prueba
        std::ofstream outFile(RECIPES_CSV);
        outFile << "RecipeName,Price,PrepTime,EatingTime,Ingredients,Amounts\n";
        outFile << "Pasta,10.0,15,10,Tomato:Pasta,2:3\n";
        outFile << "ChickenRice,12.0,20,15,Chicken:Rice,1:2\n";
        outFile.close();
    }

    void TearDown() override {
        delete recipeReader;
        delete menu;
        // Eliminar el archivo de prueba
        std::remove(RECIPES_CSV);
    }
};

TEST_F(RecipeReaderTest, SetUpMenu) {
    recipeReader->setUpMenu();
    EXPECT_EQ(menu->getMenuSize(), 2);

    Recipe* recipe1 = menu->getRecipe(0);
    ASSERT_NE(recipe1, nullptr);
    EXPECT_EQ(recipe1->getRecipeName(), "Pasta");
    EXPECT_FLOAT_EQ(recipe1->getPrice(), 10.0);
    EXPECT_EQ(recipe1->getApproxPrepTime(), 15);
    EXPECT_EQ(recipe1->getApproxEatingTime(), 10);
    EXPECT_EQ(recipe1->getTotalIngredientsStored(), 2);
    EXPECT_EQ(recipe1->getIngredient(0), "Tomato");
    EXPECT_EQ(recipe1->getIngredient(1), "Pasta");

    Recipe* recipe2 = menu->getRecipe(1);
    ASSERT_NE(recipe2, nullptr);
    EXPECT_EQ(recipe2->getRecipeName(), "ChickenRice");
    EXPECT_FLOAT_EQ(recipe2->getPrice(), 12.0);
    EXPECT_EQ(recipe2->getApproxPrepTime(), 20);
    EXPECT_EQ(recipe2->getApproxEatingTime(), 15);
    EXPECT_EQ(recipe2->getTotalIngredientsStored(), 2);
    EXPECT_EQ(recipe2->getIngredient(0), "Chicken");
    EXPECT_EQ(recipe2->getIngredient(1), "Rice");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
