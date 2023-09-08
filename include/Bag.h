#ifndef Bag_H_
#define Bag_H_

#include <vector>
#include "Food.h"

class Bag {
private:
    std::vector<Food> foods;
public:
    void addFood(Food& food);
    bool useFood(Food& toUse);
    std::string getFood();
};

#endif // Bag_H_
