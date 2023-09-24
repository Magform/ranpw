#include <cstdlib>  // For rand function
#include <algorithm> // For std::max and std::min

#include "mbed.h"
#include "Kraken.h"

Kraken::Kraken(DataToSave dataToBeSaved){
    dataToSave = dataToBeSaved;
    health.setValue(dataToSave.KrakenHealth->getValue());
    hunger.setValue(dataToSave.KrakenHunger->getValue());
}

Kraken::Kraken(){
    health.setValue(25);
    hunger.setValue(25);
}

int Kraken::getHealth(){
    return health.getValue();
}

int Kraken::getHunger(){
    return hunger.getValue();
}

// This function is intended to be run in a different thread.
// Every 1-5 minutes, it loses 1-5 hunger points. If hunger reaches 0, it loses 1-3 health points.
// Every 1 minute, it recovers 1 health point if hunger is greater than 20.
void Kraken::live(){
    int checkNumber = 0;
    
    int minutesHunger = rand() % 5 + 1;
    while(1){

        if(checkNumber == minutesHunger){
            checkNumber = 0;
            minutesHunger = rand() % 5 + 1;
            int hungerLoss = rand() % 5 + 1;
            hunger.addValue(-hungerLoss);
            if(hunger.getValue() <= 0){
                int healthLoss = rand() % 3 + 1;
                health.addValue(-healthLoss);
                if(health.getValue() <= 0){
                    //Death (to be configured...)
                }
            }
        }

        if (hunger.getValue() >= 20) {
            health.addValue(1);
        }

        // Ensure hunger and health values stay within bounds (0-25)
        hunger.setValue(std::max(0, std::min(25, hunger.getValue())));
        health.setValue(std::max(0, std::min(25, health.getValue())));

        //push value to DataSaver
        dataToSave.KrakenHealth->setValue(health.getValue());
        dataToSave.KrakenHunger->setValue(hunger.getValue());

        checkNumber++;
        ThisThread::sleep_for(60s);
    }
}

void Kraken::addHunger(int hungerToAdd){
    hunger.addValue(hungerToAdd);
    hunger.setValue(std::max(0, std::min(25, hunger.getValue())));

    dataToSave.KrakenHunger->setValue(hunger.getValue());
}

void Kraken::addHealth(int healthToAdd){
    health.addValue(healthToAdd);
    health.setValue(std::max(0, std::min(25, health.getValue())));

    dataToSave.KrakenHealth->setValue(health.getValue());
}