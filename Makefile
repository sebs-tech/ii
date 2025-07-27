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

# --- Installation Variables ---
# DESTDIR allows for staged installs (e.g., for creating .deb packages)
# If DESTDIR is not set, it defaults to an empty string.
DESTDIR ?=

# Installation directory for executables
# /usr/local/bin is recommended for locally compiled software
BINDIR = $(DESTDIR)/usr/local/bin

# Installation directory for man pages (if you had them)
# MANDIR = $(DESTDIR)/usr/local/man/man1

# Default target: builds the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to compile .c files into .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Install target: copies the executable to BINDIR
install: all
	@echo "Installing $(TARGET) to $(BINDIR)..."
	@mkdir -p $(BINDIR)
	@cp $(TARGET) $(BINDIR)/
	@chmod 755 $(BINDIR)/$(TARGET)
	@echo "$(TARGET) installed successfully."

# Uninstall target: removes the installed executable
uninstall:
	@echo "Uninstalling $(TARGET) from $(BINDIR)..."
	@rm -f $(BINDIR)/$(TARGET)
	@echo "$(TARGET) uninstalled."


# Clean target: removes generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean install uninstall
