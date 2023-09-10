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
        Menu(lcdPin lcdPin, Joystick joystick);
};

inline Menu::Menu(lcdPin lcdPin, Joystick joystick) : 
    app(lcdPin, joystick), game(lcdPin, joystick){}

#endif //Menu_H_