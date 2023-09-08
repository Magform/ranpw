#ifndef Apple_H_
#define Apple_H_

#include <string>

#include "Food.h"

class Apple : public Food{
    private:
        std::string name = "Apple";
        int hunger = 5;
};

#endif // Apple_H_