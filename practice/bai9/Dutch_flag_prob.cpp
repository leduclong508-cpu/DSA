#include<iostream>

using namespace std;

void countSort(int arr[], int n){
    int zeros = 0, twos = 0, ones = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == 0) zeros++;
        else if(arr[i] == 2) twos++;
    }

    ones = n - zeros - twos;

    for(int i = 0; i < zeros; i++){
        arr[i] = 0;
    }
    for(int i = zeros; i < zeros + ones; i++){
        arr[i] = 1;
    }
    for(int i = zeros + ones; i < n; i++){
        arr[i] = 2;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int A[] = {0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 0}; 
    int n = sizeof(A)/sizeof(A[0]);

    countSort(A, n); 

    return 0;
}