#include<iostream>
#include<algorithm>

using namespace std;

void max_product(int arr[], int n){
    if(n < 2){
        cout << "No pairs exist";
        return;
    }

    std::sort(arr, arr + n);

    if((arr[n-1] * arr[n-2]) > (arr[0] * arr[1])){
        cout << "Max product is " << arr[n-1] * arr[n-2];
    }
    else{
        cout << "Max product is " << arr[0] * arr[1];
    }
}

int main()
{
    int arr[] = { -10, -3, 5, 6, -20 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    max_product(arr, n);
 
    return 0;
}