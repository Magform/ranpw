#ifndef Page_H_
#define Page_H_

#include "Kraken.h"
#include "Menu.h"

class Page{
    public:
        Kraken kraken;
        Menu menu;
        Page(lcdPin lcdPin, Joystick joystick);

};

inline Page::Page(lcdPin lcdPin, Joystick joystick) : menu(lcdPin, joystick) {}


#endif //Page_H_