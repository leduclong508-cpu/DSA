#include <stdio.h>
 
// Function to sort a binary array in linear time
int sortBinary(int A[], int n)
{
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0) {
            zeros++;
        }
    }
 
    int j = 0;
    while (zeros--) {
        A[j++] = 0;
    }
 
    while (j < n) {
        A[j++] = 1;
    }
     
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}
 
int main(void)
{
    int A[] = { 0, 0, 1, 0, 1, 1, 0, 1, 0, 0 };
    int n = sizeof(A)/sizeof(A[0]);
 
    sortBinary(A, n);
 
    return 0;
}