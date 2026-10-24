#include<stdio.h>

void moveZerosToEnd(int arr[], int n){
    int count = 0; // Count non-zero elements

    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            arr[count] = arr[i];
            count++;
        }
    }

    for(int i = count; i < n; i++){
        arr[i] = 0;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    moveZerosToEnd(arr, n);

}