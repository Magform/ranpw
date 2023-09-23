#ifndef LCatch_H_
#define LCatch_H_

#include "Struct.h"
#include <C12832.h>

class LCatch{
    private:
        DataToSave dataToSave;
        C12832 lcd;
        Joystick joystick;
        int highScore;
        int main();
        int game();
        void randomAppear(int toAppear);
        void buttonWait(DigitalIn button, int* score, bool* lost);
    public:
        LCatch(DataToSave dataToBeSaved, lcdPin lcdPin, Joystick joystickPin);
        int startingPage();
};

#endif //LCatch_H_