#ifndef Game_H_
#define Game_H_

#include "LCatch.h"
#include "Pong.h"

class Game{
    public:
        LCatch lcatch;
        // Pong pong;
        Game(lcdPin lcdPin, Joystick joystick);
};

inline Game::Game(lcdPin lcdPin, Joystick joystick) : lcatch(lcdPin, joystick){}
#endif //Game_H_