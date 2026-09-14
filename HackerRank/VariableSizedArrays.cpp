/*
    Le Duc Long 
    Topic: Variable Sized Arrays
    12/09/2026: first edition
*/

#include <cstdio>
#include <vector>
using namespace std;


int main() {
    // Values of the number of variable-length arrays and the number of queries
    int n, q;
    scanf("%d %d", &n, &q);

    // Create a vector of vectors to hold the variable-length arrays
    vector<vector<int>> a(n);

    for(int i = 0; i < n; i++){
        int k;
        // The first integer k denotes the number of integers in the i-th array
        scanf("%d", &k);
        
        // Resize the i-th array to have k elements
        a[i].resize(k);
        
        for(int j = 0; j < k; j++){
            scanf("%d", &a[i][j]);
        }
    }
    

    // Process each query
    for(int idx = 0; idx < q; idx++){
        int i, j;
        scanf("%d%d", &i, &j);
        printf("%d\n", a[i][j]);
    }
    
    return 0;
}
