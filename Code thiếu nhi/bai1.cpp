/*
    Le Duc Long
    Topic: Find a pair in an array with a given sum
    12/09/2026: first edition
    13/09/2026: try another approach using sorting and 2 pointers
*/

// Brute force approach to find a pair in an array with a given sum
/*
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
*/

//Using Sorting 
#include<stdio.h>
#include<algorithm>

void findPair(int arr[], int n, int sum) {
    // Sorting the array in asscending order
    std::sort(arr, arr + n);

    // Using 2 pointers to find the pair
    int left = 0;
    int right = n - 1;

    // Loop until 2 pointers meet
    while(left < right) {
        if(arr[left] + arr[right] == sum) {
            printf("Pair found: (%d, %d)\n", arr[left], arr[right]);
            return;
        }
        // Increment left pointer if sum less than target
        else if(arr[left] + arr[right] < sum) {
            left++;
        }
        // Decrement right pointer if sum greater than target
        else {
            right--;
        }
    }
    printf("No pair found\n");
}

int main() {
    int nums[] = { 8, 7, 2, 5, 3, 1 };
    int target = 10;
    int n = sizeof(nums) / sizeof(nums[0]);
    findPair(nums, n, target);
    return 0;
}