# Compiler and linker configurations
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
GTEST_FLAGS = -lgtest -lgtest_main -pthread

# Define targets
TARGET = Restaurant
OBJECTS = Accountant.o CSVReader.o Customer.o CustomersInLine.o CustomerSpawner.o Deliverer.o FileWriter.o Ingredient.o Inventory.o InventoryManager.o Kitchen.o LineCook.o Menu.o Order.o Random.o Recipe.o RecipeReader.o Restaurant.o ResultsQueue.o Table.o ThreadPoolDeliverers.o ThreadPoolLineCooks.o ThreadPoolTables.o Waiter.o
TEST_SOURCES = test_accountant.cpp test_csvreader.cpp test_customer.cpp test_customersinline.cpp test_customerspawner.cpp test_deliverer.cpp test_filewriter.cpp test_ingredient.cpp test_inventory.cpp test_inventorymanager.cpp test_kitchen.cpp test_linecook.cpp test_menu.cpp test_order.cpp test_random.cpp test_recipe.cpp test_recipereader.cpp test_restaurant.cpp test_resultsqueue.cpp test_table.cpp test_threadpooldeliverers.cpp test_threadpoollinecooks.cpp test_threadpooltables.cpp test_waiter.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_EXEC = run_tests

# Link the main program
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Link the test program
$(TEST_EXEC): $(TEST_OBJECTS) $(filter-out $(TARGET).o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

# Generic rule for building objects from cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(TEST_EXEC) $(OBJECTS) $(TEST_OBJECTS)

# Specify phony rules
.PHONY: clean test
