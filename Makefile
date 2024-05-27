# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -I/path/to/gtest/include -I.
LDFLAGS = -L/path/to/gtest/lib -lgtest -lgtest_main -pthread

# Directorios
SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

# Archivos fuente y de prueba
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)

# Objetos
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp, $(BIN_DIR)/%.o, $(TEST_SRCS))

# Ejecutables
EXECUTABLE = $(BIN_DIR)/restaurant_simulation
TEST_EXECUTABLE = $(BIN_DIR)/run_tests

# Todas las pruebas
TESTS = test_accountant test_csvreader test_customer test_customersinline \
        test_customerspawner test_deliverer test_filewriter test_ingredient \
        test_inventory test_inventorymanager test_kitchen test_linecook \
        test_menu test_order test_random test_recipe test_recipereader \
        test_restaurant test_resultsqueue test_table test_threadpooldeliverer \
        test_threadpoollinecooks test_threadpooltables test_waiter test_threadpooldeliverers

# Compilar todo
all: $(EXECUTABLE) $(TEST_EXECUTABLE)

# Compilar el ejecutable principal
$(EXECUTABLE): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compilar el ejecutable de pruebas
$(TEST_EXECUTABLE): $(TEST_OBJS) $(OBJS)
	$(CXX) $(TEST_OBJS) $(OBJS) -o $@ $(LDFLAGS)

# Regla genérica para compilar archivos .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ejecutar las pruebas
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

# Limpiar los archivos compilados
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(EXECUTABLE) $(TEST_EXECUTABLE)

# Compilar y ejecutar pruebas individuales
$(TESTS): %: $(TEST_DIR)/%.cpp $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $(BIN_DIR)/$@ $(LDFLAGS)
	./$(BIN_DIR)/$
