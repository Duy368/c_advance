#include "utils.h"
#include <stdio.h>
#include <string.h>

void safe_readline(char *buffer, size_t size) {
	    fgets(buffer, size, stdin);
	        buffer[strcspn(buffer, "\n")] = 0;
}

void trim_newline(char *str) {
	    str[strcspn(str, "\n")] = 0;
}

unsigned int generate_next_id(void) {
	    static unsigned int id = 1;
	        return id++;
}

