/*
    Le Duc Long
    Topic: Find a pair in an array with a given sum
    12/09/2026: first edition
*/

// Brute force approach to find a pair in an array with a given sum
#include<stdio.h>

void FindPair(int arr[], int n, int sum) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                return;
            }
        }
    }
    printf("No pair found\n");
}

int main(){
    int nums[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int n = sizeof(nums) / sizeof(nums[0]);
    FindPair(nums, n, target);
    return 0;
}