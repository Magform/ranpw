#ifndef Kraken_H_
#define Kraken_H_

#include "ConcurrentData.h"
#include "Struct.h"

class Kraken{
    private:
        ConcurrentData health;
        ConcurrentData hunger;
        DataToSave dataToSave;
    public:
        Kraken(DataToSave dataToBeSaved);
        Kraken();
        int getHealth();
        int getHunger();
        void live();
        void addHunger(int hungerToAdd);
        void addHealth(int healthToAdd);
};

#endif //Kraken_H_