#ifndef Game_H_
#define Game_H_

#include "LCatch.h"
#include "Pong.h"
#include "LockY.h"

class Game{
    public:
        LCatch lcatch;
        Pong pong;
        LockY locky;
        Game(lcdPin lcdPin, Joystick joystick, Potentiometer potentiometer);
};      

inline Game::Game(lcdPin lcdPin, Joystick joystick, Potentiometer potentiometer) : lcatch(lcdPin, joystick), pong(lcdPin, joystick), locky(lcdPin,  joystick, potentiometer.up, potentiometer.down){}
#endif //Game_H_