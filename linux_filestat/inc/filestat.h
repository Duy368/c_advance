#ifndef FILESTAT_H
#define FILESTAT_H

#include <sys/stat.h>

void print_file_type(mode_t mode);
int get_file_info(const char *path);

#endif