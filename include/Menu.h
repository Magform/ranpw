#ifndef Menu_H_
#define Menu_H_

#include "Bag.h"
#include "Credits.h"
#include "App.h"

class Menu{
    public:
        Credits credits;
        Bag bag;
        App app;
        Menu(lcdPin lcdPin, Joystick joystick);
};

inline Menu::Menu(lcdPin lcdPin, Joystick joystick) : app(lcdPin, joystick) {}

#endif //Menu_H_