#include "Bag.h"
#include <random>
#include "Struct.h"

Bag::Bag(DataToSave dataToBeSaved): dataToSave(dataToBeSaved){
    Pie = dataToSave.Pie->getValue();
    Egg = dataToSave.Egg->getValue();
}

void Bag::addFood(int foodType){
    if(foodType == 0){
        Pie++;
        dataToSave.Pie->setValue(Pie);
    }
    if(foodType == 1){
        Egg++;
        dataToSave.Egg->setValue(Egg);
    }
}

// Function to use food from the bag
int Bag::useFood(int foodType){
    if(foodType == 0 && Pie > 0){
        Pie--;
        dataToSave.Pie->setValue(Pie);
        return 10;
    }
    if(foodType == 1 && Egg>0){
        Egg--;
        dataToSave.Egg->setValue(Egg);
        return 5;
    }
    return 0;
}


int Bag::getFood(int foodType){
    if(foodType == 0){
        return Pie;
    }
    if(foodType == 1){
        return Egg;
    }
    return 0;
}

void Bag::addRandomFood(){
    int randomInt = rand()%2;
    this->addFood(randomInt);
}