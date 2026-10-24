#include<iostream>

using namespace std;

void equilibrium_index(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    int left_sum = 0;
    for(int i = 0; i < n; i++){
        if(left_sum == sum - left_sum - arr[i]){
            cout << "Equilibrium index is " << i << endl;
            return;
        }
        left_sum += arr[i];
    }
    cout << "No equilibrium index found" << endl;
}

int main(){
    int A[] = { 0, -3, 5, -4, -2, 3, 1, 0 };
    int n = sizeof(A) / sizeof(A[0]);
 
    equilibrium_index(A, n);
 
    return 0;
}