// Finding the minimum number of coins needed to make a certain amount of change 
/*
 Using dynamic Programming
 03/10/2026:

*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;

void solveCoinChange(vector<int>& coins, int S){
    vector<int> dp(S + 1, S + 1);
    dp[0] = 0;

    vector<int> trace(S + 1, -1); // -1, sentinel value, signify unreachable state for loop 

    for(int i = 1; i <= S; i++){
        for(int coin : coins){
            // Check if the weight of the coin is less than or equal to the current amount i
            if(i >= coin && dp[i - coin] + 1 < dp[i]){
                dp[i] = dp[i - coin] + 1;
                trace[i] = coin;
            }
        }
    }
    
    if(dp[S] > S){
        return; // No solution exists
    }

    unordered_map<int, int> cointCount;
    int currentAmount = S;

    while(currentAmount > 0){
        int used_coint = trace[currentAmount];
        cointCount[used_coint]++; 
        currentAmount -= used_coint;
    }

    
};

int main(){
    vector<int> coins = {1, 3, 4};
    int S = 6;

    solveCoinChange(coins, S);

    return 0;
}