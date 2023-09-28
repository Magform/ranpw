#ifndef Interaction_H_
#define Interaction_H_

#include "mbed.h"
#include <C12832.h>
#include <MMA7660.h>
#include <vector>
#include "Bag.h"
#include "Kraken.h"
#include "Struct.h"

//Class that manages the main screen and all interactions with the user on it
class Interaction{
    private:
        Bag bag;
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
        Interaction(DataToSave dataToBeSaved);
        void start(Thread *krakenLife);
        void mainWork();
};

#endif //Interaction_H_