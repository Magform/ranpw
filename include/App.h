//Why is this class disabled?
/*
We decide to disable this class to provide better optimization, 
It is therefore preferable to initialize the class only when needed, 
thus avoiding it remaining initialized if not in use.

The same reasoning could be made for the Game.h class but, for now,
to keep the code tidier and more easily understandable,we decided 
to leave it implemented
*/

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