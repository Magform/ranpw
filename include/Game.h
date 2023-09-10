#ifndef Game_H_
#define Game_H_

#include "LCatch.h"

class Game{
    public:
        LCatch lcatch;
        Game(lcdPin lcdPin, Joystick joystick);
};

inline Game::Game(lcdPin lcdPin, Joystick joystick) : lcatch(lcdPin, joystick) {}

#endif //Game_H_