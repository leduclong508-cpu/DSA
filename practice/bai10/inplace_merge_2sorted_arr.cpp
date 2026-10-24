/*
    24/10/2026:
    first edition: wrong coding, i assume that inplace merge means to merge 2 sorted arrays
using extra space, but it should be done without using extra space.
    second edition:
*/
#include<iostream>

using namespace std;

// Wrong 
/*
void inplace_merge(int arr1[], int arr2[], int n1, int n2){
    int i = 0, j = 0, k = 0;
    int len = n1 + n2;
    int arr[len];

    while((i < n1) && (j < n2)){
        if(arr1[i] <= arr2[j]){
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }

    while(i < n1){
        arr[k++] = arr1[i++];
    }

    while(j < n2){
        arr[k++] = arr2[j++];
    }

    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
}
*/

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// It feels like insertion sort
void inplace_merge(int arr1[], int arr2[], int n1, int n2){
    for(int i = 0; i < n1; i++){
        if(arr1[i] > arr2[0]){
            swap(&arr1[i], &arr2[0]);

            int first = arr2[0]; // Save the swapped element

            // Move all elements of arr2 that are smaller than first to one position ahead
            int k;
            for(k = 1; k < n2 && arr2[k] < first; k++){
                arr2[k - 1] = arr2[k];
            }
            arr2[k - 1] = first; // Place first at its correct position
        }
    }
}

int main()
{
    int X[] = { 1, 4, 7, 8, 10 };
    int Y[] = { 2, 3, 9 };
 
    int n1 = sizeof(X) / sizeof(X[0]);
    int n2 = sizeof(Y) / sizeof(Y[0]);
 
    inplace_merge(X, Y, n1, n2);
 
    cout << "X: "; printArray(X, n1);
    cout << "Y: "; printArray(Y, n2);

    return 0;
}