#include <gtest/gtest.h>
#include "Restaurant.h"
#include <fstream>
#include <cstdio> // For std::remove

class RestaurantTest : public ::testing::Test {
protected:
    Restaurant* restaurant;

    void SetUp() override {
        // Crear archivos CSV de prueba
        std::ofstream inventoryFile(INVENTORY_CSV);
        inventoryFile << "Ingredient,Amount,UnitaryCost\n";
        inventoryFile << "Tomato,100,0.5\n";
        inventoryFile << "Pasta,200,1.2\n";
        inventoryFile.close();

        std::ofstream recipesFile(RECIPES_CSV);
        recipesFile << "RecipeName,Price,PrepTime,EatingTime,Ingredients,Amounts\n";
        recipesFile << "Pasta,10.0,15,10,Tomato:Pasta,2:3\n";
        recipesFile.close();

        restaurant = new Restaurant();
    }

    void TearDown() override {
        delete restaurant;
        // Eliminar los archivos de prueba
        std::remove(INVENTORY_CSV);
        std::remove(RECIPES_CSV);
    }
};

TEST_F(RestaurantTest, StartRestaurantSimulation) {
    // Verificar que la simulación del restaurante se inicia correctamente
    std::thread t(&Restaurant::startRestaurantSimulation, restaurant);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Espera para asegurar que los hilos se inicien
    restaurant->stopRestaurantSimulation();
    t.join();
    EXPECT_EQ(restaurant->getUnsatisfactionCount(), 0);
}

TEST_F(RestaurantTest, StopRestaurantSimulation) {
    std::thread t(&Restaurant::startRestaurantSimulation, restaurant);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Espera para asegurar que los hilos se inicien
    restaurant->stopRestaurantSimulation();
    t.join();
    EXPECT_EQ(restaurant->getUnsatisfactionCount(), 0);
}

TEST_F(RestaurantTest, GetTableState) {
    std::string state = restaurant->getTableState(0);
    EXPECT_FALSE(state.empty()); // El estado de la tabla no debe estar vacío
}

TEST_F(RestaurantTest, GetCustomersInLineCount) {
    EXPECT_EQ(restaurant->getCustomersInLineCount(), 0);
}

TEST_F(RestaurantTest, UpdateUnsatisfactionCount) {
    restaurant->updateUnsatisfactionCount();
    EXPECT_EQ(restaurant->getUnsatisfactionCount(), 0);
}

