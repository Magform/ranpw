#include "Bag.h"
#include <random>
void Bag::addFood(int foodType){
    if(foodType == 0){
        Pie++;
    }
    if(foodType == 1){
        Egg++;
    }
}

// Function to use food from the bag
int Bag::useFood(int foodType){
    if(foodType == 0 && Pie > 0){
        Pie--;
        return 10;
    }
    if(foodType == 1 && Egg>0){
        Egg--;
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