#include <stdio.h>

#define SIZE 10
#define WIN_COUNT 5

void clear_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void init_board(char board[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = '-';
        }
    }
}

void print_board(char board[SIZE][SIZE]){
    printf("\n   ");
    for(int j = 0; j < SIZE; j++){
        printf("%2d ", j);
    }
    printf("\n");

    for(int i = 0; i < SIZE; i++){
        printf("%2d ", i);
        for(int j = 0; j < SIZE; j++){
            printf(" %c ", board[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
}

int check_win(char board[SIZE][SIZE], int r, int c, char player){
    int dx[] = {1, 0, 1, 1};
    int dy[] = {0, 1, 1, -1};

    for(int dir = 0; dir < 4; dir++){
        int count = 1;

        int nx = r + dx[dir];
        int ny = c + dy[dir];

        while(nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == player){
            count++;
            nx += dx[dir];
            ny += dy[dir];
        }

        nx = r - dx[dir];
        ny = c - dy[dir];
        while(nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == player){
            count++;
            nx -= dx[dir];
            ny -= dy[dir];
        }

        if(count >= WIN_COUNT){
            return 1;
        }
    }
    return 0;
}

// ================== THUẬT TOÁN AI ==================

// Bảng điểm định giá nước đi
// Tấn công được ưu tiên cao hơn phòng thủ một chút
long attack_scores[]  = {0, 3, 24, 192, 1536, 12288, 12288};
long defense_scores[] = {0, 1, 9, 81, 729, 6561, 6561};

// Hàm chấm điểm tiềm năng của một ô trống
long evaluate_cell(char board[SIZE][SIZE], int r, int c, char ai_piece, char human_piece) {
    long score = 0;
    int dx[] = {1, 0, 1, 1};
    int dy[] = {0, 1, 1, -1};

    for (int dir = 0; dir < 4; dir++) {
        int ai_count = 0;
        int human_count = 0;

        // Đếm số quân AI liên tiếp theo hướng hiện tại (Tấn công)
        for (int step = 1; step < 5; step++) {
            int nx = r + dx[dir] * step;
            int ny = c + dy[dir] * step;
            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) break;
            if (board[nx][ny] == ai_piece) ai_count++;
            else break; 
        }
        for (int step = 1; step < 5; step++) {
            int nx = r - dx[dir] * step;
            int ny = c - dy[dir] * step;
            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) break;
            if (board[nx][ny] == ai_piece) ai_count++;
            else break;
        }

        // Đếm số quân của người chơi liên tiếp theo hướng hiện tại (Phòng ngự)
        for (int step = 1; step < 5; step++) {
            int nx = r + dx[dir] * step;
            int ny = c + dy[dir] * step;
            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) break;
            if (board[nx][ny] == human_piece) human_count++;
            else break;
        }
        for (int step = 1; step < 5; step++) {
            int nx = r - dx[dir] * step;
            int ny = c - dy[dir] * step;
            if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) break;
            if (board[nx][ny] == human_piece) human_count++;
            else break;
        }

        // Khống chế mảng tránh lỗi out of bounds
        if (ai_count > 5) ai_count = 5;
        if (human_count > 5) human_count = 5;

        // Cộng dồn điểm
        score += attack_scores[ai_count];
        score += defense_scores[human_count];
    }
    return score;
}

// AI tìm tọa độ có điểm cao nhất để đánh
void ai_move(char board[SIZE][SIZE], char ai_piece, char human_piece, int *best_r, int *best_c) {
    long max_score = -1;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') { 
                long current_score = evaluate_cell(board, i, j, ai_piece, human_piece);
                if (current_score > max_score) {
                    max_score = current_score;
                    *best_r = i; // Lưu lại hàng tốt nhất
                    *best_c = j; // Lưu lại cột tốt nhất
                }
            }
        }
    }
}
// ===================================================

int main(){
    char board[SIZE][SIZE];
    init_board(board);

    char human = 'X';
    char ai = 'O';
    char current_player = human; // Người chơi đánh trước
    
    int moves_count = 0;
    int max_moves = SIZE * SIZE;
    int r = 0, c = 0;

    printf("=== GAME CARO %dx%d (PLAYER vs AI) ===\n", SIZE, SIZE); 
    
    while(moves_count < max_moves){
        print_board(board);

        // Chia luồng logic giữa Người và Máy
        if (current_player == human) {
            printf("Your turn [%c] (Enter row and column, with a space): ", current_player); 
            if(scanf("%d %d", &r, &c) != 2){
                printf("Invalid input. Please enter two integers.\n");
                clear_buffer();
                continue;
            }
            clear_buffer();

            if(r < 0 || r >= SIZE || c < 0 || c >= SIZE){
                printf("Invalid move. Please enter row and column between 0 and %d.\n", SIZE-1);
                continue;
            }

            if(board[r][c] != '-'){
                printf("This cell is already taken! Please choose another one.\n");
                continue;
            }
        } else {
            // Lượt của máy tính
            printf("AI [%c] is thinking...\n", current_player);
            ai_move(board, ai, human, &r, &c);
            printf("-> AI plays at: %d %d\n", r, c);
        }

        // Cập nhật bàn cờ (dùng chung cho cả Máy và Người)
        board[r][c] = current_player;
        moves_count++;

        // Kiểm tra thắng thua
        if(check_win(board, r, c, current_player)){
            print_board(board);
            if (current_player == human) {
                printf("CONGRATS! You win!\n");
            } else {
                printf("GAME OVER! AI wins!\n");
            }
            return 0;
        }

        // Đổi lượt chơi
        current_player = (current_player == human) ? ai : human;
    }

    print_board(board);
    printf("It's a tie!\n");

    return 0;
}