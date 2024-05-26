
#include <gtest/gtest.h>
#include "Customer.h"
#include "Menu.h"
#include "RecipeReader.h"
#include "Kitchen.h"

// Prueba para verificar la creación de un cliente
TEST(CustomerTest, CreateCustomer) {
    Customer customer(1, "John Doe");
    EXPECT_EQ(customer.getId(), 1);
    EXPECT_EQ(customer.getName(), "John Doe");
}

// Prueba para verificar la adición de una receta al menú
TEST(MenuTest, AddRecipe) {
    Menu menu;
    Recipe recipe("Pasta", 10.0, 30, 20, {"Tomato", "Pasta"}, {1, 2});
    menu.storeRecipe(&recipe);
    EXPECT_EQ(menu.getMenuSize(), 1);
    EXPECT_EQ(menu.getRecipe(0)->getRecipeName(), "Pasta");
}

// Prueba para verificar la lectura de recetas desde un archivo CSV
TEST(RecipeReaderTest, ReadRecipes) {
    Menu menu;
    RecipeReader recipeReader(&menu);
    recipeReader.setUpMenu();
    EXPECT_GT(menu.getMenuSize(), 0);
}

// Prueba para verificar la operación de la cocina
TEST(KitchenTest, StartKitchen) {
    Accountant accountant;
    ResultsQueue<Order*> ordersToDo;
    Kitchen kitchen(&accountant, &ordersToDo);
    EXPECT_NO_THROW(kitchen.startOperating());
    kitchen.stopOperating();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
