#ifndef Egg_H_
#define Egg_H_

#include <string>

#include "Food.h"

class Egg : public Food{
    private:
        std::string name = "Egg";
        int hunger = 5;
    public:
        Egg();
        std::string getName();
        int getHunger();
};

inline Egg::Egg() : Food("Egg", 5) {}

#endif // Egg_H_