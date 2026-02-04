#include "user.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int user_add(User **users, size_t *count) {
    // TODO
    return 0;
}

int user_update(User *users, size_t count) {
    // TODO
    return 0;
}

int user_delete(User **users, size_t *count) {
    // TODO
    return 0;
}

User* user_find_by_id(User *users, size_t count, unsigned int id) {
    // TODO
    return NULL;
}

void user_menu(User **users, size_t *count) {
    int choice;
    printf("\n--- USER MENU ---\n");
    printf("1. Them nguoi dung\n");
    printf("2. Sua nguoi dung\n");
    printf("3. Xoa nguoi dung\n");
    printf("Chon: ");

    scanf("%d", &choice);
    getchar();

    switch (choice) {
    case 1: user_add(users, count); break;
    case 2: user_update(*users, *count); break;
    case 3: user_delete(users, count); break;
    default: printf("Lua chon khong hop le!\n");
    }
}
