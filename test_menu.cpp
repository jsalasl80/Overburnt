#include <gtest/gtest.h>
#include "Menu.h"
#include "Recipe.h"

class MenuTest : public ::testing::Test {
protected:
    Menu* menu;
    Recipe* recipe1;
    Recipe* recipe2;

    void SetUp() override {
        menu = new Menu();
        std::vector<std::string> ingredients1 = {"Tomato", "Pasta"};
        std::vector<int> amounts1 = {2, 3};
        recipe1 = new Recipe("Pasta", 10.0, 15, 10, ingredients1, amounts1);

        std::vector<std::string> ingredients2 = {"Chicken", "Rice"};
        std::vector<int> amounts2 = {1, 2};
        recipe2 = new Recipe("Chicken Rice", 12.0, 20, 15, ingredients2, amounts2);

        menu->storeRecipe(recipe1);
        menu->storeRecipe(recipe2);
    }

    void TearDown() override {
        delete menu; // The Menu destructor will take care of deleting recipes
    }
};

TEST_F(MenuTest, StoreRecipe) {
    EXPECT_EQ(menu->getMenuSize(), 2);
}

TEST_F(MenuTest, GetRecipe) {
    Recipe* retrievedRecipe1 = menu->getRecipe(0);
    ASSERT_NE(retrievedRecipe1, nullptr);
    EXPECT_EQ(retrievedRecipe1->getRecipeName(), "Pasta");

    Recipe* retrievedRecipe2 = menu->getRecipe(1);
    ASSERT_NE(retrievedRecipe2, nullptr);
    EXPECT_EQ(retrievedRecipe2->getRecipeName(), "Chicken Rice");
}

TEST_F(MenuTest, GetMenuSize) {
    EXPECT_EQ(menu->getMenuSize(), 2);
}

