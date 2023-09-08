#ifndef GUI_H_
#define GUI_H_

#include "mbed.h"
#include <C12832.h>
#include "Page.h"

struct Joystick{
    DigitalIn left;
    DigitalIn up;
    DigitalIn right;
    DigitalIn down;
    DigitalIn center;
};

class Interaction{
    private:
        Page mainPage;
        C12832 lcd;
        Joystick joystick; 
        DigitalIn potentiometerBottom;
        DigitalIn potentiometerUp;
        // WiFi
        // Speacker
        // Acceleroment
        // TEmperatre
        void printMonitor(int selected, vector<char*> options, bool reload = false, bool submenu = false);
        void execute(int selected);
        void slider(vector<char*> options, std::function<void(int)> toRun, bool submenu = false);
        void useFood(int selected);
    public:
        Interaction();
        void start(Thread *krakenLife);
        void mainWork();
};

#endif //GUI_H_