#include<stdio.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int n){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    
    while(i <= j){
        while(i <= high && arr[i] <= pivot) i++;
        while(j > low && arr[j] > pivot) j--;

        if(i < j) swap(&arr[i], &arr[j]);

        for(int k = 0; k < n; k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high, int n){
    if(low < high){
        int p_index = partition(arr, low, high, n);
        quickSort(arr, low, p_index - 1, n);
        quickSort(arr, p_index + 1, high, n);
    }
}

int main(){
    int a[13] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n-1, n);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}