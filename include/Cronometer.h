#ifndef Cronometer_H_
#define Cronometer_H_

#include <C12832.h>
#include "Struct.h"

class Cronometer{
    private:
        C12832* lcd;
        Joystick joystick;
        void main();
    public:
        Cronometer(C12832* lcdIn, Joystick joystick);
        void startingPage();
};

#endif // Cronometer_H_