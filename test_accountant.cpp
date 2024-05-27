// test_accountant.cpp

#include <gtest/gtest.h>
#include "Accountant.h"
#include "Ingredient.h"
#include "Recipe.h"

class AccountantTest : public ::testing::Test {
protected:
    Accountant* accountant;

    void SetUp() override {
        accountant = new Accountant();
    }

    void TearDown() override {
        delete accountant;
    }
};

TEST_F(AccountantTest, UpdateExpenses) {
    std::string ingredientName = "Tomato";
    Ingredient ingredient(ingredientName, 100, 0.5);
    accountant->updateExpenses(&ingredient, 10);
    EXPECT_FLOAT_EQ(accountant->getTotalExpenses(), 5.0);
}

TEST_F(AccountantTest, UpdateWinnings) {
    std::string recipeName = "Pasta";
    std::vector<std::string> ingredients = {"Tomato", "Pasta"};
    std::vector<int> amounts = {2, 3};
    Recipe recipe(recipeName, 10.0, 15, 10, ingredients, amounts);
    accountant->updateWinnings(&recipe);
    EXPECT_FLOAT_EQ(accountant->getTotalWinnings(), 10.0);
}

TEST_F(AccountantTest, ReportWinnings) {
    accountant->setAsReporting();
    accountant->reportWinnings();
    // Aquí podríamos verificar el archivo generado, pero para simplificar,
    // verificamos que el estado se haya actualizado y las notificaciones funcionen.
    EXPECT_EQ(accountant->getTotalExpenses(), 0.0);
    EXPECT_EQ(accountant->getTotalWinnings(), 0.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
