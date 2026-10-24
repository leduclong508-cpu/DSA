/*
    Le Duc Long
    Topic: Check if there is a subarray with 0 sum
    13/09/2026: first edition, wrong coding, need to fix it
    24/10/2026: second edition, using brute force approach to find subarray with 0 sum
*/

// Brute force approach to find subarray with 0 sum.
// Note: The problem deals with subarrays that are continuous.
#include <iostream>

using namespace std;

bool hasZeroSumSubarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        // Duyệt mọi đoạn liên tiếp bắt đầu từ i đến j
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum == 0) {
                cout << "Subarray with 0 sum found from index " << i << " to " << j << "\n";
                return true;
            }
        }
    }
    cout << "No subarray with 0 sum exists\n";
    return false;
}

int main() {
    int nums[] = { 3, 4, -7, 3, 1, -4, -2, -2 };
    int n = sizeof(nums) / sizeof(nums[0]);

    hasZeroSumSubarray(nums, n);

    return 0;
}