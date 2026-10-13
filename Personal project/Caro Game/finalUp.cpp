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
            board[i][j] = '_';
        }
    }
}

// NÂNG CẤP: Nhận thêm tọa độ nước đi cuối (last_r, last_c)
void print_board(char board[SIZE][SIZE], int last_r, int last_c){
    printf("\n   ");
    for(int j = 0; j < SIZE; j++){
        printf("%2d ", j);
    }
    printf("\n");

    for(int i = 0; i < SIZE; i++){
        printf("%2d ", i);
        for(int j = 0; j < SIZE; j++){
            // Bôi đỏ nếu đây là ô vừa được đánh
            if (i == last_r && j == last_c) {
                printf(" \033[1;31m%c\033[0m ", board[i][j]);
            } else {
                printf(" %c ", board[i][j]); 
            }
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
long attack_scores[]  = {0, 3, 24, 192, 1536, 12288, 12288};
long defense_scores[] = {0, 1, 9, 81, 729, 6561, 6561};

long evaluate_cell(char board[SIZE][SIZE], int r, int c, char ai_piece, char human_piece) {
    long score = 0;
    int dx[] = {1, 0, 1, 1};
    int dy[] = {0, 1, 1, -1};

    for (int dir = 0; dir < 4; dir++) {
        int ai_count = 0;
        int human_count = 0;

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

        if (ai_count > 5) ai_count = 5;
        if (human_count > 5) human_count = 5;

        score += attack_scores[ai_count];
        score += defense_scores[human_count];
    }
    return score;
}

void ai_move(char board[SIZE][SIZE], char ai_piece, char human_piece, int *best_r, int *best_c) {
    long max_score = -1;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '_') { 
                long current_score = evaluate_cell(board, i, j, ai_piece, human_piece);
                if (current_score > max_score) {
                    max_score = current_score;
                    *best_r = i; 
                    *best_c = j; 
                }
            }
        }
    }
}
// ===================================================

int main(){
    char board[SIZE][SIZE];
    init_board(board);

    int mode = 1;
    printf("=== GAME CARO %dx%d ===\n", SIZE, SIZE);
    printf("Chon che do choi:\n");
    printf("1. Nguoi vs Nguoi (PvP)\n");
    printf("2. Nguoi vs May (BvP)\n");
    printf("Lua chon cua ban (1 hoac 2): ");
    if (scanf("%d", &mode) != 1) mode = 1;
    clear_buffer();

    char player1 = 'X';
    char player2 = 'O'; 
    char current_player = player1;
    
    int moves_count = 0;
    int max_moves = SIZE * SIZE;
    int r = -1, c = -1;             // Biến lưu tọa độ nước đi hiện tại
    int last_r = -1, last_c = -1;   // Biến lưu tọa độ nước đi cuối cùng để in đỏ

    while(moves_count < max_moves){
        // In bàn cờ và truyền vào tọa độ nước đi trước đó để bôi đỏ
        print_board(board, last_r, last_c);

        // NẾU LÀ CHẾ ĐỘ PVP HOẶC LƯỢT CỦA NGƯỜI CHƠI 1
        if (mode == 1 || current_player == player1) {
            printf("Player [%c] turn (Enter row and column): ", current_player); 
            if(scanf("%d %d", &r, &c) != 2){
                printf("Invalid input. Please enter two integers.\n");
                clear_buffer();
                continue;
            }
            clear_buffer();

            if(r < 0 || r >= SIZE || c < 0 || c >= SIZE){
                printf("Invalid move. Out of bounds.\n");
                continue;
            }

            if(board[r][c] != '_'){
                printf("This cell is already taken!\n");
                continue;
            }
        } 
        // NẾU LÀ CHẾ ĐỘ BVP VÀ ĐẾN LƯỢT CỦA MÁY TÍNH
        else {
            printf("AI [%c] is thinking...\n", current_player);
            ai_move(board, player2, player1, &r, &c);
            printf("-> AI plays at: %d %d\n", r, c);
        }

        // Cập nhật bàn cờ
        board[r][c] = current_player;
        moves_count++;
        
        // Cập nhật tọa độ cuối cùng để lượt sau in màu đỏ
        last_r = r;
        last_c = c;

        // Kiểm tra thắng thua
        if(check_win(board, r, c, current_player)){
            print_board(board, last_r, last_c); // In lại lần cuối để thấy quân cờ đỏ chiến thắng
            if (mode == 2 && current_player == player2) {
                printf("GAME OVER! AI wins!\n");
            } else {
                printf("CONGRATS! Player [%c] wins!\n", current_player);
            }
            return 0;
        }

        // Đổi lượt chơi
        current_player = (current_player == player1) ? player2 : player1;
    }

    print_board(board, last_r, last_c);
    printf("It's a tie!\n");

    return 0;
}
