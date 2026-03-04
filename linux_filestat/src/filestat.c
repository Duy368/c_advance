#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "filestat.h"

void print_file_type(mode_t mode)
{
    if (S_ISREG(mode))
        printf("File Type: Regular File\n");
    else if (S_ISDIR(mode))
        printf("File Type: Directory\n");
    else if (S_ISLNK(mode))
        printf("File Type: Symbolic Link\n");
    else
        printf("File Type: Other\n");
}

int get_file_info(const char *path)
{
    struct stat file_stat;

    if (lstat(path, &file_stat) == -1)
    {
        perror("lstat");
        return -1;
    }

    printf("File Path: %s\n", path);

    print_file_type(file_stat.st_mode);

    printf("Size: %ld bytes\n", file_stat.st_size);

    char time_buffer[100];
    struct tm *time_info;

    time_info = localtime(&file_stat.st_mtime);
    strftime(time_buffer, sizeof(time_buffer),
             "%Y-%m-%d %H:%M:%S", time_info);

    printf("Last Modified: %s\n", time_buffer);

    return 0;
}