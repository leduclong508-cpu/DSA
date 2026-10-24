// Find the maximum amount of water that can be trapped within a given set of bars where each bar’s width is 1 unit
#include<iostream>

using namespace std;

int max(int x, int y){
    return (x > y) ? x : y;
}

int min(int x, int y){
    return (x < y) ? x : y;
}

int trapRainWater(int arr[], int n){
    if(n<=2) return 0;

    int water = 0;
    int left[n-1];
    left[0] = 
}