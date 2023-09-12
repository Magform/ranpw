#ifndef Temp_H_
#define Temp_H_

#include <C12832.h>
#include "Struct.h"
#include <LM75B.h>


class Temp{
    private:
        C12832 lcd;
        Joystick joystick;
        void main();
        LM75B tempSensor;
    public:
        Temp(lcdPin lcdPin, Joystick joystick, tempPin tempSensorPin);
        void startingPage();
};

#endif //Temp_H_