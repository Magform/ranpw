#ifndef Pong_H_
#define Pong_H_

#include "Struct.h"
#include <C12832.h>

class Pong{
    private:
        C12832 lcd;
        Joystick joystick;
        int highScore;
        int main();
        int game();
        void drawPlayer(int* centerX, int centerY, int length);
        void drawBall(float* ballX, float* ballY, float* ballSpeedX, float* ballSpeedY);
    public:
        Pong(lcdPin lcdPin, Joystick joystickPin);
        int startingPage();
};

#endif // Pong_H_