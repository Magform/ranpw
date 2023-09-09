#ifndef App_H_
#define App_H_

#include "Cronometer.h"

class App{
    public:
        Cronometer cronometer;
        App(lcdPin lcdPin, Joystick joystick);
};

inline App::App(lcdPin lcdPin, Joystick joystick) : cronometer(lcdPin, joystick) {}

#endif // App_H_