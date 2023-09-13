#ifndef Menu_H_
#define Menu_H_

#include "Bag.h"
#include "Credits.h"
#include "App.h"
#include "Game.h"

class Menu{
    public:
        Credits credits;
        Bag bag;
        App app;
        Game game;
        Menu(lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin);
};

inline Menu::Menu(lcdPin lcdPin, Joystick joystick,  tempPin tempSensorPin) : 
    app(lcdPin, joystick, tempSensorPin), game(&lcdPin, &joystick){}

#endif //Menu_H_