#ifndef Menu_H_
#define Menu_H_

#include "Bag.h"
#include "App.h"
#include "Game.h"

class Menu{
    public:
        Bag bag;
        //App app;
        Game game;
        Menu(lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer);
};

inline Menu::Menu(lcdPin lcdPin, Joystick joystick,  tempPin tempSensorPin, Potentiometer potentiometer) : 
    game(lcdPin, joystick, potentiometer){}

#endif //Menu_H_