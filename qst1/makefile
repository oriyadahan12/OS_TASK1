# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra
DEBUG_FLAGS = -g

# Source file
SRC = q1.c

# Targets
TARGET = q1
DEBUG_TARGET = q1_dbg

# Default target 

all: $(TARGET) $(DEBUG_TARGET)

# Build the target without debug information
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Build the target with debug information
$(DEBUG_TARGET): $(SRC)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(DEBUG_TARGET) $(SRC)

# Clean the build files
clean:
	rm -f $(TARGET) $(DEBUG_TARGET)
