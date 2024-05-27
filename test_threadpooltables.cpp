#include <gtest/gtest.h>
#include "ThreadPoolTables.h"
#include "Table.h"
#include "Menu.h"
#include "InventoryManager.h"
#include "Accountant.h"
#include "ResultsQueue.h"
#include "CustomersInLine.h"
#include "Customer.h"
#include "RecipeReader.h"

class ThreadPoolTablesTest : public ::testing::Test {
protected:
    ThreadPoolTables* threadPoolTables;
    Table** tables;
    Menu* menu;
    Inventory* inventory;
    InventoryManager* inventoryManager;
    Accountant* accountant;
    ResultsQueue<Order*>* ordersToDo;
    ResultsQueue<int>* customersUnsatisfied;
    CustomersInLine* customersInLine;
    std::vector<Customer*> customers;

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

        RecipeReader recipeReader(menu);
        recipeReader.setUpMenu();

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
    }
};

TEST_F(ThreadPoolTablesTest, AddCustomersToLine) {
    customersInLine->addCustomers(customers);
    EXPECT_EQ(customersInLine->getCustomersInLine(), 1);
}

TEST_F(ThreadPoolTablesTest, RunAndStop) {
    std::thread poolThread(&ThreadPoolTables::run, threadPoolTables);
    customersInLine->addCustomers(customers);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Espera para asegurar que los hilos se inicien
    threadPoolTables->stopRunning();
    poolThread.join();

    EXPECT_EQ(customersInLine->getCustomersInLine(), 0); // Verificar que los clientes en la fila fueron atendidos
}

