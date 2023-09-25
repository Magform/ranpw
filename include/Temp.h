#ifndef Temp_H_
#define Temp_H_

#include <C12832.h>
#include "Struct.h"
#include <LM75B.h>


class Temp{
    private:
        C12832* lcd;
        Joystick joystick;
        void main();
        LM75B* tempSensor;
    public:
        Temp(C12832* lcdIn, Joystick joystickIn, LM75B* tempSensorIn);
        void startingPage();
};

#endif //Temp_H_