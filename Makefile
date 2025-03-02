# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g  # Debugging and warnings
LDFLAGS_GUI = `pkg-config --libs gtkmm-3.0`
GTK_CXXFLAGS = `pkg-config --cflags gtkmm-3.0`

# Directories
SRC_DIR = src
TEST_DIR = tests
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
TASK_SRCS = $(SRC_DIR)/Task.cpp $(SRC_DIR)/TaskManager.cpp
TASK_OBJS = $(TASK_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)  # Convert .cpp to .o inside build/

# CLI files
CLI_SRCS = $(SRC_DIR)/CLI.cpp
CLI_OBJS = $(CLI_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# GUI files
GUI_SRCS = $(SRC_DIR)/GUI.cpp $(SRC_DIR)/Main.cpp
GUI_OBJS = $(GUI_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Test files
TEST_SRCS = $(TEST_DIR)/TaskManager_test.cpp $(TEST_DIR)/Task_test.cpp
TASK_TEST_OBJ = $(BUILD_DIR)/Task.o
TASKMANAGER_TEST_OBJS = $(BUILD_DIR)/Task.o $(BUILD_DIR)/TaskManager.o

# Output executables
CLI_TARGET = $(BUILD_DIR)/TaskManagerCLI
GUI_TARGET = $(BUILD_DIR)/TaskManagerGUI
TASK_TEST_EXEC = $(BUILD_DIR)/Task_test
TASKMANAGER_TEST_EXEC = $(BUILD_DIR)/TaskManager_test

# Default rule: Build everything
all: $(CLI_TARGET) $(GUI_TARGET)

# Build the CLI application (NO GTKmm)
$(CLI_TARGET): $(TASK_OBJS) $(CLI_OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(CLI_OBJS) $(TASK_OBJS) -o $(CLI_TARGET)

# Build the GUI application (WITH GTKmm)
$(GUI_TARGET): $(TASK_OBJS) $(GUI_OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(GTK_CXXFLAGS) -I$(INCLUDE_DIR) $(GUI_OBJS) $(TASK_OBJS) -o $(GUI_TARGET) $(LDFLAGS_GUI)

# Compile CLI files (without GTKmm)
$(BUILD_DIR)/CLI.o: $(SRC_DIR)/CLI.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Compile GUI files (WITH GTKmm)
$(BUILD_DIR)/GUI.o: $(SRC_DIR)/GUI.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(GTK_CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/Main.o: $(SRC_DIR)/Main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(GTK_CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Compile other .cpp files to .o object files (without GTKmm)
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

# Run CLI version
run-cli: $(CLI_TARGET)
	./$(CLI_TARGET)

# Run GUI version
run-gui: $(GUI_TARGET)
	./$(GUI_TARGET)

# Run tests
test: build-test
	$(TASK_TEST_EXEC)
	$(TASKMANAGER_TEST_EXEC)

# Clean only the build files, keep everything else
clean:
	rm -rf $(BUILD_DIR)/*
