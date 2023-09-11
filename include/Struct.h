#ifndef Struct_H_
#define Struct_H_

#include "mbed.h"
#include "ConcurrentData.h"

struct Joystick {
    DigitalIn left;
    DigitalIn up;
    DigitalIn right;
    DigitalIn down;
    DigitalIn center;
};

struct lcdPin{
    PinName MOSI;
    PinName SCK;
    PinName RESET;
    PinName A0;
    PinName nCS;
};

struct CDataToSave{
    ConcurrentData* KrakenHealth;
    ConcurrentData* KrakenHunger;
    ConcurrentData* Egg;
    ConcurrentData* Pie;
    ConcurrentData* LCatchHighScore;

    CDataToSave() {
        KrakenHealth = new ConcurrentData();
        KrakenHunger = new ConcurrentData();
        Egg = new ConcurrentData();
        Pie = new ConcurrentData();
        LCatchHighScore = new ConcurrentData();
    }
};

#endif //Struct_H_