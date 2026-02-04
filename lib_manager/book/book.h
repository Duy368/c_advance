#ifndef BOOK_H
#define BOOK_H

#include <stddef.h> // Để sử dụng size_t

// Định nghĩa cấu trúc Book
typedef struct {
    unsigned int id;
    char title[100];
    char author[50];
    float price;
    int quantity;
} Book;

// --- Các nguyên mẫu hàm (Function Prototypes) ---

// Thêm một sách mới (sử dụng con trỏ cấp 2 để có thể realloc mảng)
int book_add(Book **books, size_t *count);

// Cập nhật thông tin sách dựa trên danh sách hiện có
int book_update(Book *books, size_t count);

// Xóa sách khỏi danh sách
int book_delete(Book **books, size_t *count);

// Hiển thị danh sách toàn bộ sách
void book_list(Book *books, size_t count);

// Tìm kiếm sách theo ID
Book* book_find_by_id(Book *books, size_t count, unsigned int id);

// Menu điều khiển các chức năng về sách
void book_menu(Book **books, size_t *count);

#endif // BOOK_H