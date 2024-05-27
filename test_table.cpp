// test_table.cpp

#include <gtest/gtest.h>
#include "Table.h"
#include "Menu.h"
#include "InventoryManager.h"
#include "Accountant.h"
#include "ResultsQueue.h"
#include "CustomersInLine.h"
#include "Customer.h"
#include "RecipeReader.h"
#include "ThreadPoolTables.h"  // Include the ThreadPoolTables header file

class TableTest : public ::testing::Test {
protected:
    Table* table;
    Menu* menu;
    Inventory* inventory;
    InventoryManager* inventoryManager;
    Accountant* accountant;
    ResultsQueue<Order*>* ordersToDo;
    ResultsQueue<int>* customersUnsatisfied;
    CustomersInLine* customersInLine;
    std::vector<Customer*> customers;
    Table** tables;  // Declare tables as a pointer to an array of Table pointers
    ThreadPoolTables* threadPoolTables;  // Declare threadPoolTables

    void SetUp() override {
        menu = new Menu();
        inventory = new Inventory();
        accountant = new Accountant();
        inventoryManager = new InventoryManager(inventory, accountant);
        ordersToDo = new ResultsQueue<Order*>();
        customersUnsatisfied = new ResultsQueue<int>();
        customersInLine = new CustomersInLine();

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

        RecipeReader recipeReader(menu);  // Declare RecipeReader object
        recipeReader.setUpMenu();  // Call setUpMenu method

        tables = new Table*[2];
        for (int i = 0; i < 2; ++i) {
            tables[i] = new Table(i, menu, inventoryManager, accountant, ordersToDo, customersUnsatisfied);
        }

        threadPoolTables = new ThreadPoolTables(tables, customersInLine);

        customers.push_back(new Customer(1, "John Doe"));
    }

    void TearDown() override {
        delete threadPoolTables;
        for (int i = 0; i < 2; ++i) {
            delete tables[i];
        }
        delete[] tables;
        delete menu;
        delete inventoryManager;
        delete accountant;
        delete ordersToDo;
        delete customersUnsatisfied;
        delete customersInLine;

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
