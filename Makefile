# Define variables
CC = gcc                     # The C compiler to use
CFLAGS = -Wall -Wextra -Isrc/include
LDFLAGS =                    
TARGET = ii                  

# Source directory relative to the Makefile
SRC_DIR = src

# List of source files with their full paths
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Object files will be placed in the SRC_DIR to keep them with their sources
OBJECTS = $(SOURCES:.c=.o)

# Default target: builds the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to compile .c files into .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: removes generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
