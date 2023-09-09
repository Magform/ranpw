#ifndef Food_H_
#define Food_H_

#include <string>
#include <vector>
#include <memory>

class Food{
    private:
        std::string name;
        int hunger;
    public:
        Food(std::string foodName, int foodHunger);
        std::string getName();
        int getHunger();
        Food randomFood();
};

#endif // Food_H_