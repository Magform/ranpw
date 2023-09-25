#ifndef App_H_
#define App_H_

#include "Cronometer.h"
#include "Temp.h"

class App{
    public:
        Cronometer cronometer;
        //Temp termometer;
        App(C12832* lcdIn, Joystick joystick, tempPin tempSensorPin);
};

inline App::App(C12832* lcdIn, Joystick joystick, tempPin tempSensorPin) : cronometer(lcdIn, joystick) {}

#endif // App_H_