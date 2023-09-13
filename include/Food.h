/**
 * @file Food.h
 * @brief This file contains the declaration of the Food class.
 */

#ifndef Food_H_
#define Food_H_

#include <string>


/**
 * @class Food
 * @brief Represents a generic food item.
 *
 * The Food class provides a template for creating different food items
 * with different name and hunger satisfaction.
 */
class Food {
private:
    std::string name;
    int hunger;

public:
    /**
     * @brief Constructor for creating a Food object.
     *
     * Initializes the Food object with a specified name and hunger value.
     *
     * @param foodName The name of the food item.
     * @param foodHunger The hunger satisfaction provided by the food.
     */
    Food(std::string foodName, int foodHunger);

    /**
     * @brief Get the name of the food.
     *
     * @return The name of the food as a string.
     */
    std::string getName();

    /**
     * @brief Get the hunger satisfaction value provided by the food.
     *
     * @return The hunger satisfaction as an integer.
     */
    int getHunger();

    /**
     * @brief Generate a random Food object.
     *
     * This static method creates a random Food object with a name and hunger value 
     * taken from one of the subclasses configured within it.
     *
     * If additional subclasses are created this method need to be updated.
     *
     * @return A randomly generated Food object.
     */
    static Food randomFood();
};

#endif // Food_H_