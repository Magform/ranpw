#ifndef Page_H_
#define Page_H_

#include "Kraken.h"
#include "Menu.h"
#include "Struct.h"

class Page{
    public:
        Kraken kraken;
        Menu menu;

        Page(DataToSave dataToBeSaved,C12832* lcdIn, Joystick joystick, Potentiometer potentiometer, MMA7660* accelerometerP);

};

inline Page::Page(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystick, Potentiometer potentiometer, MMA7660* accelerometerP) : kraken(dataToBeSaved), menu(dataToBeSaved, lcdIn, joystick, potentiometer, accelerometerP) {}

#endif //Page_H_