#ifndef Page_H_
#define Page_H_

#include "Kraken.h"
#include "Menu.h"
#include "Struct.h"

class Page{
    public:
        Kraken kraken;
        Menu menu;
        Page(DataToSave dataToBeSaved,C12832* lcdIn, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer);

};

inline Page::Page(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer) : kraken(dataToBeSaved), menu(dataToBeSaved, lcdIn, joystick, tempSensorPin, potentiometer) {}


#endif //Page_H_