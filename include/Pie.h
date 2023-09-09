#ifndef Pie_H_
#define Pie_H_

#include <string>

#include "Food.h"

class Pie : public Food{
    private:
        std::string name = "Pie";
        int hunger = 10;
    public:
        Pie();
};

inline Pie::Pie() : Food("Pie", 10) {}

#endif // Pie_H_