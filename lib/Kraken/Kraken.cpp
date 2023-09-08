#include <cstdlib>  // For rand function
#include <algorithm> // For std::max and std::min

#include "mbed.h"
#include "Kraken.h"

Kraken::Kraken() {
    health = 25;
    hunger = 25;
}

int Kraken::getHealth(){
    return health;
}

int Kraken::getHunger(){
    return hunger;
}

// This function is intended to be run in a different thread.
// Every 1-5 minutes, it loses 1-5 hunger points. If hunger reaches 0, it loses 1-3 health points.
// Every 1 minute, it recovers 1 health point if hunger is greater than 15.
void Kraken::live(){
    int checkNumber = 0;
    
    int minutesHunger = rand() % 5 + 1;

    while(1){

        if(checkNumber == minutesHunger){
            checkNumber = 0;
            minutesHunger = rand() % 5 + 1;
            int hungerLoss = rand() % 5 + 1;
            hunger -= hungerLoss;
            if(hunger <= 0){
                int healthLoss = rand() % 3 + 1;
                health -= healthLoss;
                if(health <= 0){
                    //Death (to be configured...)
                }
            }
        }

        if (hunger >= 20) {
            health += 1;
        }

        // Ensure hunger and health values stay within bounds (0-25)
        hunger = std::max(0, std::min(25, hunger));
        health = std::max(0, std::min(25, health));

        checkNumber++;
        ThisThread::sleep_for(6s);
    }
}

int Kraken::addHunger(int hunger){
    this->hunger += hunger;
    hunger = std::max(0, std::min(25, hunger));
}