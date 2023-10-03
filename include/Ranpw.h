#ifndef Ranpw_H_
#define Ranpw_H_

#include "mbed.h"
#include <C12832.h>
#include <MMA7660.h>
#include <LM75B.h>
#include <vector>
#include "Bag.h"
#include "Kraken.h"
#include "Struct.h"

//Class that manages the main screen and all interactions with the user on it
class Ranpw{
    private:
        Bag bag;
        LM75B tempSensor;
        C12832 lcd;
        MMA7660 accelerometer;
        Joystick joystick;
        DataToSave dataToSave;
        Kraken kraken;
        void printMonitor(int selected, vector<char*> options, bool reload = false, bool submenu = false);
        void execute(int selected);
        void slider(vector<char*> options, std::function<void(int)> toRun, bool submenu = false);
        void useFood(int selected);
        void useApp(int selected);
        void useGame(int selected);
    public:
        Ranpw(DataToSave dataToBeSaved);
        void start(Thread *krakenLife);
        void mainWork();
};

#endif //Ranpw_H_