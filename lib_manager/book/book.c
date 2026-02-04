#include "book.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int book_add(Book **books, size_t *count) {
    // TODO: implement thêm sách
    return 0;
}

int book_update(Book *books, size_t count) {
    // TODO
    return 0;
}

int book_delete(Book **books, size_t *count) {
    // TODO
    return 0;
}

void book_list(Book *books, size_t count) {
    // TODO: list toàn bộ sách
}

Book* book_find_by_id(Book *books, size_t count, unsigned int id) {
    // TODO
    return NULL;
}

void book_menu(Book **books, size_t *count) {
    int choice;
    printf("\n--- BOOK MENU ---\n");
    printf("1. Them sach\n");
    printf("2. Sua sach\n");
    printf("3. Xoa sach\n");
    printf("4. Danh sach sach\n");
    printf("Chon: ");

    scanf("%d", &choice);
    getchar();

    switch (choice) {
    case 1: book_add(books, count); break;
    case 2: book_update(*books, *count); break;
    case 3: book_delete(books, count); break;
    case 4: book_list(*books, *count); break;
    default: printf("Lua chon khong hop le!\n");
    }
}
