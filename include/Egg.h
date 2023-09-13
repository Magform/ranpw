/**
 * @file Egg.h
 * @brief This file contains the declaration of the Egg class.
 */

#ifndef Egg_H_
#define Egg_H_

#include <string>
#include "Food.h"

/**
 * @class Egg
 * @brief Represents an egg as a type of Food.
 *
 * The Egg class inherits from the Food class and provides specific
 * name and humger.
 */
class Egg : public Food {
private:
    std::string name = "Egg";
    int hunger = 5;

public:
    /**
     * @brief Constructor for creating an Egg object.
     *
     * Initializes the Egg object with its name and hunger value.
     */
    Egg();

    /**
     * @brief Get the name of the egg.
     *
     * @return The name of the egg as a string.
     */
    std::string getName();

    /**
     * @brief Get the hunger satisfaction value provided by the egg.
     *
     * @return The hunger satisfaction value as an integer.
     */
    int getHunger();
};

/**
 * @brief Constructor for creating an Egg object.
 *
 * Initializes the Egg object with its name and hunger value.
 */
inline Egg::Egg() : Food("Egg", 5) {}

#endif // Egg_H_
