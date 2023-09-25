#ifndef Hell_H_
#define Hell_H_

#include "Struct.h"
#include <C12832.h>
#include <MMA7660.h>

class Hell{
    private:
        C12832* lcd;
        MMA7660* accelerometer;
        Joystick joystick;
        int game();
        int randomDungeon(int radius);
    public:
        Hell(C12832* lcdIn, Joystick joystickPin, MMA7660* accelerometerP);
        int startingPage();
};

#endif // Hell_H_