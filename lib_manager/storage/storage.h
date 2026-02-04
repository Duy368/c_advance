#ifndef STORAGE_H
#define STORAGE_H

#include "book.h"
#include "user.h"

int storage_save(const char *fb, Book *books, size_t bcount,
                 const char *fu, User *users, size_t ucount);

int storage_load(const char *fb, Book **books, size_t *bcount,
                 const char *fu, User **users, size_t *ucount);

#endif
