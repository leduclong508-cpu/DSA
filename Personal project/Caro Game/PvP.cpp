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

int main(){
    char board[SIZE][SIZE];
    init_board(board);

    char current_player = 'X';
    int moves_count = 0;
    int max_moves = SIZE * SIZE;
    int r, c;

    // Sửa 1: Thêm \n
    printf("=== GAME CARO %dx%d ===\n", SIZE, SIZE); 
    
    while(moves_count < max_moves){
        print_board(board);

        printf("%c turn (Enter row and column, with a space): ", current_player); 
        
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

        // Sửa 3 (Lỗi nghiêm trọng): Kiểm tra ô cờ đã bị đánh chưa
        if(board[r][c] != '_'){
            printf("This cell is already taken! Please choose another one.\n");
            continue;
        }

        board[r][c] = current_player;
        moves_count++;

        if(check_win(board, r, c, current_player)){
            print_board(board);
            printf("CONGRATS! %c wins!\n", current_player);
            return 0;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    print_board(board);
    printf("It's a tie!\n");

    return 0;
}