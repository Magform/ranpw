#ifndef Temp_H_
#define Temp_H_

#include <C12832.h>
#include "Struct.h"
#include <LM75B.h>


class Temp{
    private:
        C12832* lcd;
        Joystick joystick;
        LM75B* tempSensor;
        int time = 0;
        void main(int minTemp = -280, bool restart = false);
    public:
        Temp(C12832* lcdIn, Joystick joystickIn, LM75B* tempSensorIn);
        void startingPage();
};

#endif //Temp_H_