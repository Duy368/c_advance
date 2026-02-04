#include "storage.h"
#include <stdio.h>
#include <stdlib.h>

int storage_save(const char *fb, Book *books, size_t bcount,
                 const char *fu, User *users, size_t ucount)
{
    // TODO: ghi CSV
    return 0;
}

int storage_load(const char *fb, Book **books, size_t *bcount,
                 const char *fu, User **users, size_t *ucount)
{
    // TODO: parse CSV
    return 0;
}
