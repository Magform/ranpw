#ifndef Page_H_
#define Page_H_

#include "Kraken.h"
#include "Menu.h"

class Page{
    public:
        Kraken kraken;
        Menu menu;
        Page(lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer);

};

inline Page::Page(lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer) : menu(lcdPin, joystick, tempSensorPin, potentiometer) {}


#endif //Page_H_