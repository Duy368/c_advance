#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

void safe_readline(char *buffer, size_t size);
void trim_newline(char *str);
unsigned int generate_next_id(void);

#endif

