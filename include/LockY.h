#ifndef LockY_H_
#define LockY_H_

#include "mbed.h"
#include "Struct.h"
#include <C12832.h>

class LockY{
    private:
        C12832 lcd;
        Joystick joystick;
        AnalogIn potentiometerDown;
        AnalogIn potentiometerUP;
        int highScore = 0;
        int main();
        int game();
    public:
        LockY(lcdPin lcdPin, Joystick joystickPin, PinName potenUp, PinName potenDown);
        int startingPage();
};

#endif //LockY_H_