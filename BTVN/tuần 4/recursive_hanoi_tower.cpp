/*
    01/10/2026: code using recursive function
    02/10/2026: code using non-recursive function
    04/10/2026: code using recursive function to print the steps to solve the Tower of Hanoi problem

*/

// Using recursive function
/*
#include<stdio.h>

int HanoiTower(int n){
    if(n == 1){
        return 1;
    }
    return 2 * HanoiTower(n - 1) + 1;
}

// Recursive function to print the steps to solve the Tower of Hanoi problem
void HanoiTowerMoves(int n, char source, char auxiliary, char destination){
    if(n == 1){
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    // Step 1: Move n-1 disk from source to auxiliary
    HanoiTowerMoves(n - 1, source, destination, auxiliary);

    // Step 2: Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Step 3: Move the n-1 disk from auxiliary to destination
    HanoiTowerMoves(n - 1, auxiliary, source, destination);
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int moves = HanoiTower(n);
    printf("The minimum number of moves required to solve the Tower of Hanoi with %d disks is: %d\n", n, moves);
    return 0;
}
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

