// Finding the most amount of calories in a knapsack with a weight limit
// Specifically, in 1000 Kg

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Food{
    string name;
    double weight;
    double calories;
    double ratio; // calories per weight
};

bool compare_ratio(const Food& a, const Food& b){
    return a.ratio > b.ratio;
}

void knapsack(vector<Food>& foods, double weightLimit){
    for(auto& food : foods){
        food.ratio = food.calories / food.weight;
    }

    sort(foods.begin(), foods.end(), compare_ratio);

    double currentWeight = 0;
    double totalCalories = 0;

    cout << "Selected foods for the knapsack:" << endl;

    for(const auto& food : foods){
        if(currentWeight + food.weight <= weightLimit){
            currentWeight += food.weight;
            totalCalories += food.calories;
            cout << "Food: " << food.name << ", Weight: " << food.weight << ", Calories: " << food.calories << endl;
        } else {
            double remainingWeight = weightLimit - currentWeight;
            totalCalories += food.ratio * remainingWeight;
            cout << "Food: " << food.name << ", Weight: " << remainingWeight << ", Calories: " << food.ratio * remainingWeight << endl;
            break;
        }
    }

    cout << "Total Calories: " << totalCalories << endl;
}

int main(){
    vector<Food> foods = {
        {"Peanut butter", 20, 117800, 5890},
        {"Rice", 300, 1122000, 3740},
        {"Wheat flour", 400, 1444000, 3610},
        {"Strawberry jam", 50, 130000, 2600},
        {"Beans (can)", 300, 690000, 2300},
        {"Potatoes", 800, 1501600, 1877},
        {"Tomatoes (can)", 300, 237000, 790}
    };

    double weightLimit = 1000; // in Kg

    knapsack(foods, weightLimit);
    return 0;
}