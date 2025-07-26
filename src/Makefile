# Makefile for C program with external string list and include folder

# Define variables
CC = gcc                 # The C compiler to use
CFLAGS = -Wall -Wextra -Iinclude # Compiler flags:
                         # -Wall: Enables all common warnings
                         # -Wextra: Enables extra warnings (good practice)
                         # -Iinclude: Tells the compiler to look in the 'include' directory for headers
LDFLAGS =                # Linker flags (none needed for this simple case)
TARGET = ii              # Name of the final executable
SOURCES = main.c curses_data.c # All source files
OBJECTS = $(SOURCES:.c=.o) # Automatically generate object file names (.o) from source files (.c)

# Default target: builds the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to compile .c files into .o files
# This is a pattern rule: applies to any .c file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: removes generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean

