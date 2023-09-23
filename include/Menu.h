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
        Menu(DataToSave dataToBeSaved, lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer);
};

inline Menu::Menu(DataToSave dataToBeSaved, lcdPin lcdPin, Joystick joystick,  tempPin tempSensorPin, Potentiometer potentiometer) : 
    bag(dataToBeSaved),
    game(dataToBeSaved, lcdPin, joystick, potentiometer){}

#endif //Menu_H_