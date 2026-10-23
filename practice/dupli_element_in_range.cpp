#include<iostream>

using namespace std;

int find_duplicate(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        int sum =+ arr[i];
    }
    int expected_sum = (n-1) * n / 2;
    return sum - expected_sum;
}

int main()
{
    int nums[] = { 1, 2, 3, 4, 4 };
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "The duplicate element is " << find_duplicate(nums, n);
 
    return 0;
}