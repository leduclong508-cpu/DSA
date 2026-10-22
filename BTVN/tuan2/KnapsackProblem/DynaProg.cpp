/* 
  Dynamic Programming approach to solve the Knapsack problem
if the goods can not be divined into smaller parts 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Food{
    string name;
    double weight;
    double calories;
};

void knapsack(const vector<Food>& foods, int weightLimit){
    vector<double> dp(weightLimit + 1, 0);
    for(const auto& food : foods){
        for(int w = weightLimit; w >= food.weight; -- w){
            dp[w] = max(dp[w], dp[w - food.weight] + food.calories);
        }
    }

    cout << "Maximum calories that can be carried in the knapsack: " << dp[weightLimit] << endl;
}

int main() {
    vector<Food> foods = {
        {"Peanut butter", 20, 117800},
        {"Rice", 300, 1122000},
        {"Wheat flour", 400, 1444000},
        {"Strawberry jam", 50, 130000},
        {"Beans (can)", 300, 690000},
        {"Potatoes", 800, 1501600},
        {"Tomatoes (can)", 300, 237000}
    };

    int weightLimit = 1000; // Phải là số nguyên

    knapsack(foods, weightLimit);
    return 0;
}