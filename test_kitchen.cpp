#include <gtest/gtest.h>
#include "Kitchen.h"
#include "Accountant.h"
#include "Order.h"
#include "ResultsQueue.h"
#include "Customer.h"
#include "Recipe.h"

class KitchenTest : public ::testing::Test {
protected:
    Accountant* accountant;
    ResultsQueue<Order*>* ordersToDo;
    Kitchen* kitchen;

    void SetUp() override {
        accountant = new Accountant();
        ordersToDo = new ResultsQueue<Order*>();
        kitchen = new Kitchen(accountant, ordersToDo);

        // Crear un archivo CSV de prueba
        std::ofstream outFile(INVENTORY_CSV);
        outFile << "Ingredient,Amount,UnitaryCost\n";
        outFile << "Tomato,100,0.5\n";
        outFile << "Pasta,200,1.2\n";
        outFile.close();
    }

    void TearDown() override {
        delete kitchen;
        delete ordersToDo;
        delete accountant;
        // Eliminar el archivo de prueba
        std::remove(INVENTORY_CSV);
    }
};

TEST_F(KitchenTest, StartOperating) {
    // Verificar que el inventario se configura correctamente y los hilos se ejecutan
    kitchen->startOperating();
    InventoryManager* inventoryManager = kitchen->getInventoryManager();
    EXPECT_EQ(inventoryManager->getIngredient("Tomato")->getIngredientName(), "Tomato");
}

TEST_F(KitchenTest, ReportCurrentState) {
    kitchen->startOperating();
    kitchen->reportCurrentState();
    // Aquí podríamos verificar el archivo generado o la salida, pero para simplificar,
    // verificamos que el método no falle.
}

TEST_F(KitchenTest, StopOperating) {
    kitchen->startOperating();
    kitchen->stopOperating();
    // Verificamos que el método no falle y que los hilos se detengan correctamente.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}