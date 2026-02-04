/* Variable definitions */
CC = gcc
CFLAGS = -g -Wall -Wextra
TARGET = memory_lab
SRC = memory_lab.c

/* Default rule */
all: $(TARGET)

/* Linking and compilation */
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

/* Clean up build files */
clean:
	rm -f $(TARGET)

/* Shortcuts for testing with GDB */
debug_stack: $(TARGET)
	gdb --args ./$(TARGET) stack_overflow

debug_leak: $(TARGET)
	gdb --args ./$(TARGET) memory_leak

.PHONY: all clean debug_stack debug_leak