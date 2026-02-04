#ifndef USER_H
#define USER_H

#include <stddef.h>

typedef struct {
    unsigned int id;
    char name[64];
    unsigned int *borrowed_ids;
    size_t borrowed_count;
} User;

// CRUD
int user_add(User **users, size_t *count);
int user_update(User *users, size_t count);
int user_delete(User **users, size_t *count);

User* user_find_by_id(User *users, size_t count, unsigned int id);

// Menu UI
void user_menu(User **users, size_t *count);

#endif
