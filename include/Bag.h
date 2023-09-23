#ifndef Bag_H_
#define Bag_H_

#include "Struct.h"

class Bag {
private:
    int Pie = 0;    //Food type 0
    int Egg = 0;    //Food type 1
    DataToSave dataToSave;
public:
    Bag(DataToSave dataToBeSaved);
    void addFood(int foodType);
    int useFood(int foodType);
    int getFood(int foodType);
    void addRandomFood();
};

#endif // Bag_H_
