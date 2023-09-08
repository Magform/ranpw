#include "Bag.h"
#include <algorithm>
#include <utility>

// Function to add food to the bag
void Bag::addFood(Food& food) {
    foods.push_back(food);
}

// Function to use food from the bag
bool Bag::useFood(Food& toUse) {
    auto it = std::find(foods.begin(), foods.end(), toUse);
    
    if (it != foods.end()) {
        foods.erase(it);
        return true;
    }

    return false;
}

// Function to get details of the food in the bag as a string
std::string Bag::getFood() {
    std::vector<std::pair<int, std::string>> aviableFoodVector;

    for (Food& food : foods) {

        bool inVector = false;
        for (std::pair<int, std::string>& aviableFood : aviableFoodVector) {
            if (aviableFood.second == food.getName()) {
                inVector = true;
                break;
            }
        }

        // If it's not in the vector, add a new pair
        if (!inVector) {
            aviableFoodVector.emplace_back(food.getHunger(), food.getName());
        }
    }

    // Create a string to store the data
    std::string result;
    result += "Name - Quantity\n";
    for (std::pair<int, std::string>& aviableFood : aviableFoodVector) {
        result += aviableFood.second + " - " + std::to_string(aviableFood.first)+"\n";
    }

    return result;
}