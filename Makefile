# Makefile for C program with external string list and include folder

# Define variables
CC = gcc                     # The C compiler to use
# Compiler flags:
# -Wall: Enables all common warnings
# -Wextra: Enables extra warnings (good practice)
# -Isrc/include: Tells the compiler to look in the 'src/include' directory for headers
CFLAGS = -Wall -Wextra -Isrc/include
LDFLAGS =                    # Linker flags (none needed for this simple case)
TARGET = ii                  # Name of the final executable (you can change this if you want it named something else)

# Source directory relative to the Makefile
SRC_DIR = src

# List of source files with their full paths
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/curses_data.c

# Object files will be placed in the SRC_DIR to keep them with their sources
# This creates object file names like src/main.o, src/curses_data.o
OBJECTS = $(SOURCES:.c=.o)

# Default target: builds the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to compile .c files into .o files
# This pattern rule explicitly states that an .o file in $(SRC_DIR)
# is built from a .c file with the *same basename* in $(SRC_DIR)
# The key is that the prerequisite must also have the full path.
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: removes generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
