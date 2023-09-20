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

struct ledPin{
    PinName led1;
    PinName led2;
    PinName led3;
    PinName led4;
};

struct tempPin{
    PinName SCL;
    PinName SDA;
};

struct Potentiometer{
    PinName up;
    PinName down;
};

struct DataToSave{
    ConcurrentData* KrakenHealth;
    ConcurrentData* KrakenHunger;
    ConcurrentData* Egg;
    ConcurrentData* Pie;
    ConcurrentData* LCatchHighScore;

    DataToSave() {
        KrakenHealth = new ConcurrentData();
        KrakenHunger = new ConcurrentData();
        Egg = new ConcurrentData();
        Pie = new ConcurrentData();
        LCatchHighScore = new ConcurrentData();
    }
};

#endif //Struct_H_