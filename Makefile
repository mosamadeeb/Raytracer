# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O3
SRC_DIR = .
STRUCTURES_DIR = Structures
IO_DIR = IO
OBJ_DIR = obj
BIN_DIR = .

# Gather all .cpp files in SRC_DIR, STRUCTURES_DIR, and IO_DIR
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(STRUCTURES_DIR)/*.cpp) $(wildcard $(IO_DIR)/*.cpp)

# Replace .cpp extension with .o for all source files
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Target executable
TARGET = $(BIN_DIR)/Raytracer

# Default rule
all: $(TARGET)

# Rule to create the target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to create .o files from .cpp files
$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the project
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean