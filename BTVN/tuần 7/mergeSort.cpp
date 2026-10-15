#include<stdio.h>

using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    //Seperating the array into two temporary arrays L and R
    int L[n1], R[n2];

    // Copying the elements to the temporary arrays L and R
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 +j];
    }

    // Reseting the index to point to the first index of array L, R and sorted array accordingly
    int i = 0, j = 0, k = left;
    
    // Checking the condition and sort the elements
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Filling the remaining elements
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void separate(int arr[], int left, int right, int n){
    if(left < right){
        int mid = (left + right) / 2;
        separate(arr, left, mid, n);
        separate(arr, mid + 1, right, n);
        merge(arr, left, mid, right);

        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void mergeSort(int arr[], int n){
    separate(arr, 0, n - 1, n);
}

int main(){
    int a[13] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, n);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}