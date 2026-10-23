// I solve this problem supposing that the array contains only positive integers.

/*
 I consider using sliding window technique to approach this problem.
The idea is to maintain a window of elements that add up to the target sum.
If the sum of the current window is less than the target, we expand the window by moving the right pointer to the right.
If the sum exceeds the target, we shrink the window by moving the left pointer to the right. We continue this process
until we find a subarray that adds up to the target sum or until we have traversed the entire array.
*/

#include<iostream>

using namespace std;

void subArrSlideWindow(int arr[], int n, int target){
    int current_sum = 0;
    int left = 0, right = 0;

    for(; right < n; right++){
        current_sum += arr[right];

        while(current_sum > target && left <= right){
            current_sum -= arr[left];
            left++;
        }

        if(current_sum == target){
            cout << "Subarray found from index " << left << " to " << right << endl;
            return;
        }
    }

    cout << "No subarray found with the given sum." << endl;
}

int main(){
    int nums[] = { 2, 6, 0, 9, 7, 3, 1, 4, 1, 10 };
    int target = 15;
 
    int n = sizeof(nums)/sizeof(nums[0]);
 
    subArrSlideWindow(nums, n, target);
 
    return 0;
}
