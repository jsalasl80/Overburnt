# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -isystem /usr/src/googletest/googletest -pthread

# Directories
SRC_DIR = overburnt
TEST_DIR = overburnt
BUILD_DIR = build

# Sources and tests
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TESTS = $(wildcard $(TEST_DIR)/test_*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJS = $(TESTS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d) $(TEST_OBJS:.o=.d)

# Target executable
TARGET = test_runner

# Include directories
INCLUDES = -I$(SRC_DIR) -I$(TEST_DIR)

# Google Test library
GTEST_LIB = /usr/src/gtest/libgtest.a /usr/src/gtest/libgtest_main.a

# Rules
all: $(TARGET)

$(TARGET): $(OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIB) -lpthread

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
