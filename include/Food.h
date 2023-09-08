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
        const virtual std::string getName();
        const virtual int getHunger();
        Food randomFood();
};

#endif // Food_H_