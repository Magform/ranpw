#ifndef Termometer_H_
#define Termometer_H_

#include <C12832.h>
#include "Struct.h"
#include <LM75B.h>


class Termometer{
    private:
        C12832* lcd;
        Joystick joystick;
        LM75B* tempSensor;
        int time = 0;
        void main(int minTemp = -280, bool restart = false);
    public:
        Termometer(C12832* lcdIn, Joystick joystickIn, LM75B* tempSensorIn);
        void startingPage();
};

#endif //Termometer_H_