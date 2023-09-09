#ifndef Cronometer_H_
#define Cronometer_H_

#include <C12832.h>

struct Joystick {
    DigitalIn left;
    DigitalIn up;
    DigitalIn right;
    DigitalIn down;
    DigitalIn center;
};

struct lcdPin{
    PinName p1;
    PinName p2;
    PinName p3;
    PinName p4;
    PinName p5;
};

class Cronometer{
    private:
        C12832 lcd;
        Joystick joystick;
        void main();
    public:
        Cronometer(lcdPin lcdPin, Joystick joystick);
        void startingPage();
};

#endif // Cronometer_H_