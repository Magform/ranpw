#ifndef App_H_
#define App_H_

#include "Cronometer.h"
#include "Temp.h"

class App{
    public:
        Cronometer cronometer;
        Temp termometer;
        App(C12832* lcdIn, Joystick joystick, LM75B* tempSensorIn);
};

inline App::App(C12832* lcdIn, Joystick joystick, LM75B* tempSensorIn) : cronometer(lcdIn, joystick), termometer(lcdIn, joystick, tempSensorIn) {}

#endif // App_H_