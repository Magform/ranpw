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
        Menu(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystick, tempPin tempSensorPin, Potentiometer potentiometer);
};

inline Menu::Menu(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystick,  tempPin tempSensorPin, Potentiometer potentiometer) : 
    bag(dataToBeSaved),
    game(dataToBeSaved, lcdIn, joystick, potentiometer){}

#endif //Menu_H_