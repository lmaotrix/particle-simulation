# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -IC:/libs/SDL2-2.28.5/i686-w64-mingw32/include -Dmain=SDL_main
LDFLAGS = -L"C:/libs/SDL2-2.28.5/i686-w64-mingw32/lib" -lmingw32 -lSDL2main -lSDL2 -lm -mwindows -Wl,--subsystem,windows

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files and object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

# Target executable
TARGET = $(BUILD_DIR)/particle_simulator.exe

# Default target
all: $(TARGET) copy_dll

# Rule to compile the final executable (linking)
$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

# Rule to compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the build directory exists (Windows style)
$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# Copy SDL2.dll from SDL2 bin folder to build directory so your app runs
copy_dll:
	copy /Y C:\libs\SDL2-2.28.5\i686-w64-mingw32\bin\SDL2.dll $(BUILD_DIR)\

# Clean up
clean:
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)

# Phony targets
.PHONY: all clean copy_dll
