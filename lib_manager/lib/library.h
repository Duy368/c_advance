#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "user.h"

int library_borrow(Book *books, size_t bcount,
                   User *users, size_t ucount,
                   unsigned int user_id, unsigned int book_id);

int library_return(Book *books, size_t bcount,
                   User *users, size_t ucount,
                   unsigned int user_id, unsigned int book_id);

// UI
void library_borrow_ui(Book *books, size_t bcount,
                       User *users, size_t ucount);
void library_return_ui(Book *books, size_t bcount,
                       User *users, size_t ucount);

#endif
