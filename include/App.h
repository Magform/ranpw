#ifndef App_H_
#define App_H_

#include "Cronometer.h"
#include "Temp.h"

class App{
    public:
        Cronometer cronometer;
        //Temp termometer;
        App(lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin);
};

inline App::App(lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin) : cronometer(lcdPin, joy) {}

#endif // App_H_