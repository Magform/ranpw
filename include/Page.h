#ifndef Page_H_
#define Page_H_

#include "Kraken.h"
#include "Menu.h"
#include "Struct.h"

class Page{
    public:
        Kraken kraken;
        Menu menu;
        Page(DataToSave dataToBeSaved,lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer);

};

inline Page::Page(DataToSave dataToBeSaved, lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer) : kraken(dataToBeSaved), menu(dataToBeSaved, lcdPin, joystick, tempSensorPin, potentiometer) {}


#endif //Page_H_