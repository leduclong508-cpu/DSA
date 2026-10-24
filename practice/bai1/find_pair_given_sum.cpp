/*
    Le Duc Long
    Topic: Find a pair in an array with a given sum
    12/09/2026: first edition
    13/09/2026: try another approach using sorting and 2 pointers
    15/09/2026: using sorting without its library
    - Using divide and conquer method to sort the array
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

//Using Sorting with its library
/*
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
*/

//Using Sorting without its library
#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // The pivot is placed at the end of the array
    
    // 'i' is the boundary of the "smaller elements" zone. Initialized outside the array.
    int i = low - 1; 
    
    for(int j = low; j < high; j++) {
        // 'j' probes forward to find elements smaller than or equal to the pivot
        if(arr[j] <= pivot) {
            i++; // Expand the boundary
            swap(&arr[i], &arr[j]); // Move the smaller element to the front
        }
    }

    // Place the pivot in its correct middle position (dividing the array)
    swap(&arr[i + 1], &arr[high]);

    // Report the pivot's exact index back to the recursive function
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        // Partition the array and get the index of the boundary of values
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); // Recursively sort the left sub-array
        quickSort(arr, pi + 1, high); // Recursively sort the right sub-array
    }
}
void findPair(int arr[], int n, int sum) {
    // Sorting the array in asscending order
    quickSort(arr, 0, n - 1);

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

