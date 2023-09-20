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
        Menu(lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer);
};

inline Menu::Menu(lcdPin lcdPin, Joystick joystick,  tempPin tempSensorPin, Potentiometer potentiometer) : 
    app(lcdPin, joystick, tempSensorPin), game(lcdPin, joystick, potentiometer){}

#endif //Menu_H_