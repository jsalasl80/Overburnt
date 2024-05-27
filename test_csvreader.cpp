#include <gtest/gtest.h>
#include "CSVReader.h"
#include <cstdio> // For std::remove

class CSVReaderTest : public ::testing::Test {
protected:
    CSVReader* csvReader;
    const char* testFilename = "test_inventory.csv";

    void SetUp() override {
        // Crear un archivo CSV de prueba
        std::ofstream outFile(testFilename);
        outFile << "Ingredient,Amount,UnitaryCost\n";
        outFile << "Tomato,100,0.5\n";
        outFile << "Pasta,200,1.2\n";
        outFile.close();
        csvReader = new CSVReader(testFilename);
    }

    void TearDown() override {
        delete csvReader;
        std::remove(testFilename); // Eliminar el archivo de prueba después de las pruebas
    }
};

TEST_F(CSVReaderTest, ReadInventory) {
    std::string ingredientName;
    int amount;
    float unitaryCost;

    bool result = csvReader->readInventory(ingredientName, amount, unitaryCost);
    EXPECT_TRUE(result);
    EXPECT_EQ(ingredientName, "TOMATO");
    EXPECT_EQ(amount, 100);
    EXPECT_FLOAT_EQ(unitaryCost, 0.5);

    result = csvReader->readInventory(ingredientName, amount, unitaryCost);
    EXPECT_TRUE(result);
    EXPECT_EQ(ingredientName, "PASTA");
    EXPECT_EQ(amount, 200);
    EXPECT_FLOAT_EQ(unitaryCost, 1.2);

    result = csvReader->readInventory(ingredientName, amount, unitaryCost);
    EXPECT_FALSE(result); // No hay más datos que leer
}

