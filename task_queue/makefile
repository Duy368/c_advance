/* Variable definitions */
CC = gcc
CFLAGS = -g -Wall -Wextra
TARGET = task_queue
SRC = task_queue.c

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