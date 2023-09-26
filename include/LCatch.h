#ifndef LCatch_H_
#define LCatch_H_

#include "Struct.h"
#include <C12832.h>

class LCatch{
    private:
        DataToSave dataToSave;
        Joystick joystick;
        C12832* lcd;
        int highScore;
        int main();
        int game();
        void randomAppear(int toAppear);
        void buttonWait(DigitalIn button, int* score, bool* lost);
    public:
        LCatch(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystickPin);
        int startingPage();
};

#endif //LCatch_H_