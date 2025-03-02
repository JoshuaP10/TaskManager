# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g  # Debugging and warnings

# Directories
SRC_DIR = .
BUILD_DIR = build

# Source files
TASK_SRCS = Task.cpp TaskManager.cpp
TASK_OBJS = $(TASK_SRCS:%.cpp=$(BUILD_DIR)/%.o)  # Convert .cpp to .o inside build/

# Test files
TEST_SRCS = TaskManager_test.cpp Task_test.cpp
TASK_TEST_OBJ = $(BUILD_DIR)/Task.o
TASKMANAGER_TEST_OBJS = $(BUILD_DIR)/Task.o $(BUILD_DIR)/TaskManager.o

# Output executables
TARGET = Main
TASK_TEST_EXEC = $(BUILD_DIR)/Task_test
TASKMANAGER_TEST_EXEC = $(BUILD_DIR)/TaskManager_test

# Default rule: Build everything
all: $(TARGET)

# Build and run the main executable
run: $(TARGET)
	./$(BUILD_DIR)/$(TARGET)

# Build the main executable (directly compile Main.cpp)
$(TARGET): $(TASK_OBJS) Main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) Main.cpp $(TASK_OBJS) -o $(BUILD_DIR)/$(TARGET)

# Compile .cpp files to .o object files in build directory (excluding Main.cpp)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the build directory exists before compiling
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build test executables
build-test: $(TASK_TEST_EXEC) $(TASKMANAGER_TEST_EXEC)

# Task_test only depends on Task.o
$(TASK_TEST_EXEC): $(TASK_TEST_OBJ) Task_test.cpp
	$(CXX) $(CXXFLAGS) Task_test.cpp $(TASK_TEST_OBJ) -o $(TASK_TEST_EXEC)

# TaskManager_test depends on both Task.o and TaskManager.o
$(TASKMANAGER_TEST_EXEC): $(TASKMANAGER_TEST_OBJS) TaskManager_test.cpp
	$(CXX) $(CXXFLAGS) TaskManager_test.cpp $(TASKMANAGER_TEST_OBJS) -o $(TASKMANAGER_TEST_EXEC)

# Run tests
test: build-test
	$(BUILD_DIR)/Task_test
	$(BUILD_DIR)/TaskManager_test

# Clean only the build files, keep everything else
clean:
	rm -rf $(BUILD_DIR)/*
