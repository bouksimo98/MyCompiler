# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Iinclude -std=c++17

# Directories
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

# Executable name
TARGET = my_program

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up object files and the executable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Clean up object files only
clean_obj:
	rm -rf $(OBJ_DIR)

# Phony targets
.PHONY: all clean clean_obj