#ifndef Menu_H_
#define Menu_H_

#include "Bag.h"
#include "App.h"
#include "Game.h"

class Menu{
    public:
        Bag bag;
        //App app;  // This is disable, for more info about this see App.h or documentation
        Game game;
        Menu(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystick,  Potentiometer potentiometer, MMA7660* accelerometerP);
};

inline Menu::Menu(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystick, Potentiometer potentiometer, MMA7660* accelerometerP) : 
    bag(dataToBeSaved),
    game(dataToBeSaved, lcdIn, joystick, potentiometer, accelerometerP){}

#endif //Menu_H_