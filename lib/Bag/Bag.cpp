#include "Bag.h"
#include <algorithm>
#include <utility>

// Function to add food to the bag
void Bag::addFood(Food& food) {
    foods.push_back(food);
}

// Function to use food from the bag
bool Bag::useFood(Food& toUse) {
    for (auto it = foods.begin(); it != foods.end(); ++it) {
        if (it->getName() == toUse.getName()) {
            foods.erase(it);
            return true;
        }
    }

    return false;
}

// Function to get details of the food in the bag as a string
std::vector<std::pair<std::string, int>> Bag::getFood() {
    std::vector<std::pair<std::string, int>> aviableFoodVector;

    for (Food& food : foods) {

        bool inVector = false;
        for (std::pair<std::string, int>& aviableFood : aviableFoodVector) {
            if (aviableFood.first == food.getName()) {
                aviableFood.second++;
                inVector = true;
                break;
            }
        }

        // If it's not in the vector, add a new pair
        if (!inVector) {
            aviableFoodVector.emplace_back(food.getName(), 1);
        }
    }

    return aviableFoodVector;
}