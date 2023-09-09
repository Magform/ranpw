#ifndef Interaction_H_
#define Interaction_H_

#include "mbed.h"
#include <C12832.h>
#include "Page.h"

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
        void useApp(int selected);
    public:
        Interaction();
        void start(Thread *krakenLife);
        void mainWork();
};

#endif //Interaction_H_