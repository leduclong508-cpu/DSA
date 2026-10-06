// Using recursive function
// 04/10/2026: code using recursive function to print the steps to solve the Tower of Hanoi problem

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
    HanoiTowerMoves(n, 'A', 'B', 'C');
    return 0;
}