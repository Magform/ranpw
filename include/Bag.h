#ifndef Bag_H_
#define Bag_H_

#include <vector>
#include <string>
#include "Food.h"

class Bag {
private:
   std::vector<Food> foods;
public:
    void addFood(Food& food);
    int useFood(std::string foodName);
    std::vector<std::pair<std::string, int>> getFood();
};

#endif // Bag_H_
