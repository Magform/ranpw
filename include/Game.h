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
        Game(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystick, Potentiometer potentiometer, MMA7660* accelerometerP);
};      

inline Game::Game(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystick, Potentiometer potentiometer, MMA7660* accelerometerP) : lcatch(dataToBeSaved, lcdIn, joystick), pong(dataToBeSaved, lcdIn, joystick, accelerometerP), locky(dataToBeSaved, lcdIn,  joystick, potentiometer.up, potentiometer.down){}
#endif //Game_H_