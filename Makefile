# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g  # Debugging and warnings

# Directories
SRC_DIR = src
TEST_DIR = tests
INCLUDE_DIR = include
BUILD_DIR = build

# Source files (excluding Main.cpp)
TASK_SRCS = $(SRC_DIR)/Task.cpp $(SRC_DIR)/TaskManager.cpp
TASK_OBJS = $(TASK_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)  # Convert .cpp to .o inside build/

# Test files
TEST_SRCS = $(TEST_DIR)/TaskManager_test.cpp $(TEST_DIR)/Task_test.cpp
TASK_TEST_OBJ = $(BUILD_DIR)/Task.o
TASKMANAGER_TEST_OBJS = $(BUILD_DIR)/Task.o $(BUILD_DIR)/TaskManager.o

# Output executables
TARGET = $(BUILD_DIR)/TaskManagerApp
TASK_TEST_EXEC = $(BUILD_DIR)/Task_test
TASKMANAGER_TEST_EXEC = $(BUILD_DIR)/TaskManager_test

# Default rule: Build everything
all: $(TARGET)

# Build and run the main executable
run: $(TARGET)
	./$(TARGET)

# Build the main executable (Main.cpp + source object files)
$(TARGET): $(TASK_OBJS) $(SRC_DIR)/Main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(SRC_DIR)/Main.cpp $(TASK_OBJS) -o $(TARGET)

# Compile .cpp files to .o object files in build directory (excluding Main.cpp)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Ensure the build directory exists before compiling
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build test executables
build-test: $(TASK_TEST_EXEC) $(TASKMANAGER_TEST_EXEC)

# Task_test only depends on Task.o
$(TASK_TEST_EXEC): $(TASK_TEST_OBJ) $(TEST_DIR)/Task_test.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TEST_DIR)/Task_test.cpp $(TASK_TEST_OBJ) -o $(TASK_TEST_EXEC)

# TaskManager_test depends on both Task.o and TaskManager.o
$(TASKMANAGER_TEST_EXEC): $(TASKMANAGER_TEST_OBJS) $(TEST_DIR)/TaskManager_test.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TEST_DIR)/TaskManager_test.cpp $(TASKMANAGER_TEST_OBJS) -o $(TASKMANAGER_TEST_EXEC)

# Run tests
test: build-test
	$(TASK_TEST_EXEC)
	$(TASKMANAGER_TEST_EXEC)

# Clean only the build files, keep everything else
clean:
	rm -rf $(BUILD_DIR)/*
