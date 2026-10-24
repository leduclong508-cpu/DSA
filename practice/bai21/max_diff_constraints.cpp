#include<iostream>

using namespace std;

int max(int a, int b){
    return (b > a) ? b : a;
}

void maxDiff(int arr[], int n){
    int diff = -1;
    if(n == 0) cout << diff;

    int max_value = arr[n-1];

    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > max_value){
            max_value = arr[i];
        }
        else{
            diff = max(diff, max_value - arr[i]);
        }
    }
    cout << "Maximum difference is: " << diff << endl;
    cout << "Elements are: " << max_value << " and " << max_value - diff << endl;
}

int main(){
    int arr[] = { 2, 7, 9, 5, 1, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    maxDiff(arr, n);
 
    return 0;   
}