#include <gtest/gtest.h>
#include "Table.h"
#include "Menu.h"
#include "InventoryManager.h"
#include "Accountant.h"
#include "ResultsQueue.h"
#include "Customer.h"

class TableTest : public ::testing::Test {
protected:
    Table* table;
    Menu* menu;
    Inventory* inventory;
    InventoryManager* inventoryManager;
    Accountant* accountant;
    ResultsQueue<Order*>* ordersToDo;
    ResultsQueue<int>* customersUnsatisfied;
    std::vector<Customer*> customers;

    void SetUp() override {
        menu = new Menu();
        inventory = new Inventory();
        accountant = new Accountant();
        inventoryManager = new InventoryManager(inventory, accountant);
        ordersToDo = new ResultsQueue<Order*>();
        customersUnsatisfied = new ResultsQueue<int>();

        // Crear un archivo CSV de prueba
        std::ofstream outFile(INVENTORY_CSV);
        outFile << "Ingredient,Amount,UnitaryCost\n";
        outFile << "Tomato,100,0.5\n";
        outFile << "Pasta,200,1.2\n";
        outFile.close();

        std::ofstream recipesFile(RECIPES_CSV);
        recipesFile << "RecipeName,Price,PrepTime,EatingTime,Ingredients,Amounts\n";
        recipesFile << "Pasta,10.0,15,10,Tomato:Pasta,2:3\n";
        recipesFile.close();

        RecipeReader recipeReader(menu);
        recipeReader.setUpMenu();

        table = new Table(1, menu, inventoryManager, accountant, ordersToDo, customersUnsatisfied);
        customers.push_back(new Customer(1, "John Doe"));
    }

    void TearDown() override {
        delete table;
        delete menu;
        delete inventoryManager;
        delete accountant;
        delete ordersToDo;
        delete customersUnsatisfied;

        for (auto customer : customers) {
            delete customer;
        }

        // Eliminar los archivos de prueba
        std::remove(INVENTORY_CSV);
        std::remove(RECIPES_CSV);
    }
};

TEST_F(TableTest, GetId) {
    EXPECT_EQ(table->getId(), 1);
}

TEST_F(TableTest, IsOccupied) {
    EXPECT_FALSE(table->isOccupied());
}

TEST_F(TableTest, SeatAndAttendCustomers) {
    table->seatAndAttendCustomers(customers);
    EXPECT_TRUE(table->isOccupied());
}

TEST_F(TableTest, ClearTableAndOrders) {
    table->seatAndAttendCustomers(customers);
    table->clearTableAndOrders();
    EXPECT_FALSE(table->isOccupied());
}

TEST_F(TableTest, ReportCurrentState) {
    table->seatAndAttendCustomers(customers);
    std::string state = table->reportCurrentState();
    EXPECT_FALSE(state.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
