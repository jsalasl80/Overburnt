# Compiler and linker configurations
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
GTEST_FLAGS = -lgtest -lgtest_main -pthread

# Define targets
TARGET = Trials 
OBJECTS = Trials.o Accountant.o CSVReader.o Customer.o CustomersInLine.o CustomerSpawner.o Deliverer.o FileWriter.o Ingredient.o Inventory.o InventoryManager.o Kitchen.o LineCook.o Menu.o Order.o Random.o Recipe.o RecipeReader.o Restaurant.o ResultsQueue.o Table.o ThreadPoolDeliverer.o ThreadPoolLineCooks.o ThreadPoolTables.o Waiter.o
TEST_SOURCES = basic_test.cpp
TEST_OBJECTS = basic_test.o
TEST_EXEC = run_tests

# Link the main program
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Link the test program
$(TEST_EXEC): $(TEST_OBJECTS) $(filter-out main.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

# Generic rule for building objects from cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
run_tests: $(TEST_EXEC)
	./$(TEST_EXEC)

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(TEST_EXEC) $(OBJECTS) $(TEST_OBJECTS)

# Specify phony rules
.PHONY: clean test
