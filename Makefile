# TL,DR: This makefile is designed specifically for Linux systems. if you are using windows make sure to use `makefile.win` instead.

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files and object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

# Target executable (Linux binary, no .exe)
TARGET = $(BUILD_DIR)/particle_simulator

# Default target
all: $(TARGET)


# Rule to compile the final executable (linking)
$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

# Rule to compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)


# Phony targets
.PHONY: all clean

