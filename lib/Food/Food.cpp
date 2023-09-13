//For doxygen-style documentation see Food.h

#include <vector>
#include <memory>

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

//Need to be updated if other food is added
//In particular foodTypes need also the new Constructor
//PS. This function can be upgraded using smartpointers
Food Food::randomFood() {

    //Vector that contains all types of food that we want to be able to generate
    std::vector<Food*> foodTypes = {new Egg(), new Pie()};

    int randomIndex = rand() % foodTypes.size();
    Food* randomFood = foodTypes[randomIndex];

    Food toReturn(randomFood->getName(), randomFood->getHunger());
    
    //clean memory alocated with pointers
    for (Food* foodType : foodTypes) {
        delete foodType;
    }
    delete randomFood;

    return toReturn;
}