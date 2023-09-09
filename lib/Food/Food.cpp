#include <vector>

#include "Food.h"
#include "Egg.h"
#include "Pie.h"

Food::Food(std::string foodName, int foodHunger)
    : name(foodName), hunger(foodHunger) {

}

std::string Food::getName(){
    return this->name;
}

int Food::getHunger(){
    return this->hunger;
}

//Need to be updated if u add some other food tipes
Food Food::randomFood() {

    std::vector<Food*> foodTypes = {new Egg(), new Pie()};

    int randomIndex = rand() % foodTypes.size();
    Food* randomFood = foodTypes[randomIndex];

    Food toReturn(randomFood->getName(), randomFood->getHunger());
    
    //clean memory
    for (Food* foodType : foodTypes) {
        delete foodType;
    }

    return toReturn;
}