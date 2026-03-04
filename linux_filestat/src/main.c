#include <stdio.h>
#include <stdlib.h>
#include "filestat.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (get_file_info(argv[1]) != 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}