/*
    01/10/2026: code using recursive function
    02/10/2026: code using non-recursive function

*/

// Using non-recursive function
#include <stdio.h>

int HanoiTower(int n){
    int moves = 0;
    for(int i = 1; i <=n; i++){
        moves = 2 * moves + 1;
    }
    return moves;
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int moves = HanoiTower(n);
    printf("The minimum number of moves required to solve the Tower of Hanoi with %d disks is: %d\n", n, moves);
    return 0;
}

