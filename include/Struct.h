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

struct dataToSave{
    ConcurrentData* KrakenHealth;
    ConcurrentData* oldKrakenHunger;
    ConcurrentData* oldEgg;
    ConcurrentData* oldPie;
    ConcurrentData* oldLCatchHighScore;
};

#endif //Struct_H_