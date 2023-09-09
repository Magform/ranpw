#ifndef Kraken_H_
#define Kraken_H_

#include "ConcurrentData.h"

class Kraken{
    private:
        ConcurrentData health;
        ConcurrentData hunger;
    public:
        Kraken();
        int getHealth();
        int getHunger();
        void live();
        void addHunger(int hungerToAdd);
};

#endif //Kraken_H_