/**
 * @file Pie.h
 * @brief This file contains the declaration of the Pie class.
 */

#ifndef Pie_H_
#define Pie_H_

#include <string>
#include "Food.h"

/**
 * @class Pie
 * @brief Represents a pie as a type of Food.
 *
 * The Pie class inherits from the Food class and provides specific
 * name and humger.
 */
class Pie : public Food{
private:
    std::string name = "Pie";
    int hunger = 10;
public:
    /**
     * @brief Constructor for creating a Pie object.
     *
     * Initializes the Pie object with its name and hunger value.
     */
    Pie();

    /**
     * @brief Get the name of the pie.
     *
     * @return The name of the pie as a string.
     */
    std::string getName();

    /**
     * @brief Get the hunger satisfaction value provided by the pie.
     *
     * @return The hunger satisfaction value as an integer.
     */
    int getHunger();
};

/**
 * @brief Constructor for creating a Pie object.
 *
 * Initializes the Pie object with its name and hunger value.
 */
inline Pie::Pie() : Food("Pie", 10) {}

#endif // Pie_H_