#include <stdio.h>
#include "book.h"
#include "user.h"
#include "library.h"
#include "storage.h"
#include "utils.h"

int main(void) {
    Book *books = NULL;
    size_t book_count = 0;

    User *users = NULL;
    size_t user_count = 0;

    // Load dữ liệu lúc khởi động
    storage_load("books.csv", &books, &book_count,
                 "users.csv", &users, &user_count);

    int choice;

    while (1) {
        printf("\n==== LIBRARY MANAGER ====\n");
        printf("1. Quan ly sach\n");
        printf("2. Quan ly nguoi dung\n");
        printf("3. Muon sach\n");
        printf("4. Tra sach\n");
        printf("5. Luu du lieu & Thoat\n");
        printf("Chon: ");

        scanf("%d", &choice);
        getchar(); // clear '\n'

        switch (choice) {
        case 1:
            book_menu(&books, &book_count);
            break;

        case 2:
            user_menu(&users, &user_count);
            break;

        case 3:
            library_borrow_ui(books, book_count, users, user_count);
            break;

        case 4:
            library_return_ui(books, book_count, users, user_count);
            break;

        case 5:
            storage_save("books.csv", books, book_count,
                         "users.csv", users, user_count);
            printf("Da luu. Thoat...\n");
            return 0;

        default:
            printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}
