#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000  // Sức chứa tối đa của từ điển
#define MAX_LENGTH 50   // Độ dài tối đa của 1 từ

int main() {
    // Mảng 2 chiều lưu trữ danh sách từ vựng đọc được từ file
    char dictionary[MAX_WORDS][MAX_LENGTH];
    int word_count = 0;

    // 1. MỞ VÀ ĐỌC FILE
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Loi: Khong tim thay file words.txt!\n");
        return 1;
    }

    // Đọc từng dòng cho đến khi hết file (EOF) hoặc đầy mảng
    while (fgets(dictionary[word_count], MAX_LENGTH, file) != NULL && word_count < MAX_WORDS) {
        // Hàm fgets sẽ lấy luôn cả ký tự xuống dòng '\n', ta cần xóa nó đi
        dictionary[word_count][strcspn(dictionary[word_count], "\n")] = '\0';
        
        // Chỉ lưu những dòng có chứa ký tự (bỏ qua dòng trống)
        if (strlen(dictionary[word_count]) > 0) {
            word_count++;
        }
    }
    fclose(file);

    if (word_count == 0) {
        printf("Loi: File words.txt dang bi trong!\n");
        return 1;
    }

    // 2. CHỌN TỪ NGẪU NHIÊN TỪ KHO
    srand((unsigned int)time(NULL));
    int random_index = rand() % word_count;
    char *secret_word = dictionary[random_index];

    // In ra kiểm tra
    printf("Da tai thanh cong %d tu vung tu file.\n", word_count);
    printf("Tu bi mat duoc chon la: %s\n", secret_word);

    // ... (Phần code vòng lặp game Hangman sẽ tiếp tục ở đây) ...

    return 0;
}