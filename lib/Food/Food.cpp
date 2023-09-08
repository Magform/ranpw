#include <vector>

#include "Food.h"
#include "Apple.h"
#include "Pie.h"

Food::Food() {
    name = "UNK";
    hunger = 0;
}

const virtual std::string Food::getName(){
    return this->name;
}

const virtual int Food::getHunger(){
    return this->hunger;
}

//Need to be updated if u add some other food tipes
Food Food::randomFood() {

    std::vector<Food*> foodTypes = {new Apple(), new Pie()};

    int randomIndex = rand() % foodTypes.size();
    Food* randomFood = foodTypes[randomIndex];

    Food toReturn;
    toReturn.name = randomFood->getName();
    toReturn.hunger = randomFood->getHunger();
    
    //clean memory
    for (Food* foodType : foodTypes) {
        delete foodType;
    }

    return toReturn;
}