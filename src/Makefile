# Makefile for the C program that reads a file line by line

# Define the C compiler to use
CC = gcc

# Define the name of the executable
TARGET = insult_insert.vim

# Define the source file
SRC = insult_insert.c

# Define compiler flags
# -Wall: Enables all common warnings
# -Wextra: Enables extra warnings (more than -Wall)
# -std=c11: Specifies the C standard to use
# -O2: Optimization level 2
CFLAGS = -Wall -Wextra -std=c11 -O2

# Default target: builds the executable
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

# Rule to run the program
# The `.` before `/$(TARGET)` ensures it runs from the current directory
run: $(TARGET)
	./$(TARGET)

# Rule to clean up compiled files
clean:
	rm -f $(TARGET)

# Phony targets to prevent conflicts with files of the same name
.PHONY: all run clean
