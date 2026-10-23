#include<iostream>

using namespace std;

void kadane(int arr[], int n){
    int max_sum = arr[0];
    int current_sum = arr[0];

    int start = 0, end = 0, temp_start = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > current_sum + arr[i]){
            current_sum = arr[i];
            temp_start = i;
        }
        else{
            current_sum += arr[i];
        }

        if(current_sum > max_sum){
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }

    cout << "Subarray with the largest sum is:" << endl;
    for(int i = start; i <= end; i++){
        std::cout << arr[i] << " ";
    }
    cout << endl << "With sum: " << max_sum << endl;
}