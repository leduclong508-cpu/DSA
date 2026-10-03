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
            if(i >= coin && dp[i - coin] + 1 < dp[i]){
                
            }
        }
    }
};

int main(){
    vector<int> coins = {1, 3, 4};
    int S = 6;

    solveCoinChange(coins, S);

    return 0;
}