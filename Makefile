# Paths to Google Test
GTEST_DIR = /usr/src/gtest
GTEST_LIB_DIR = /usr/local/lib
GTEST_SRC = $(GTEST_DIR)/src/gtest-all.cc
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h

# Include directories for Google Test
INCLUDES = -I$(GTEST_DIR) -I$(GTEST_DIR)/include

# Compiler and linker configurations
CXX = g++
CXXFLAGS = -Wall -g -std=c++11 $(INCLUDES)
GTEST_FLAGS = -L$(GTEST_LIB_DIR) -lgtest -lgtest_main -lpthread

# Define targets
TARGET = Trials.cpp
OBJECTS = Accountant.o CSVReader.o Customer.o CustomersInLine.o CustomerSpawner.o Deliverer.o FileWriter.o Ingredient.o Inventory.o InventoryManager.o Kitchen.o LineCook.o Menu.o Order.o Random.o Recipe.o RecipeReader.o Restaurant.o ResultsQueue.o Table.o ThreadPoolDeliverer.o ThreadPoolLineCooks.o ThreadPoolTables.o Waiter.o Trials.o

# Google Test objects
GTEST_OBJECTS = gtest-all.o

# Test sources and objects
TEST_SOURCES = test_accountant.cpp test_csvreader.cpp test_customer.cpp test_customersinline.cpp test_customerspawner.cpp test_deliverer.cpp test_filewriter.cpp test_ingredient.cpp test_inventory.cpp test_inventorymanager.cpp test_kitchen.cpp test_linecook.cpp test_menu.cpp test_order.cpp test_random.cpp test_recipe.cpp test_recipereader.cpp test_restaurant.cpp test_resultsqueue.cpp test_table.cpp test_threadpooldeliverer.cpp test_threadpoollinecooks.cpp test_threadpooltables.cpp test_waiter.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_EXEC = run_tests

# Compile Google Test
$(GTEST_OBJECTS): $(GTEST_SRC) $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(GTEST_SRC) -o $(GTEST_OBJECTS)

# Link the main program
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Link the test program
$(TEST_EXEC): $(TEST_OBJECTS) $(GTEST_OBJECTS) $(filter-out Trials.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

# Generic rule for building objects from cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run tests
run_tests: $(TEST_EXEC)
	./$(TEST_EXEC)

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(TEST_EXEC) $(OBJECTS) $(TEST_OBJECTS) $(GTEST_OBJECTS)

# Specify phony rules
.PHONY: clean run_tests
