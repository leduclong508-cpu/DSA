/*
    Le Duc Long
    Topic: Check if a subarray with 0 sum exists
    13/09/2026: first edition
*/

// Brute force approach to find subarray with 0 sum.
// Note: The problem deals with subarrays that are continuous.
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
    int nums[] = {3, 4, -7, 3, 1, -4, -2, -2};
    int target = 10;
    int n = sizeof(nums) / sizeof(nums[0]);
    FindPair(nums, n, target);
    return 0;
}