#include "Pong.h"

Pong::Pong(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystickPin, MMA7660* accelerometerP) : 
    lcd(lcdIn),
    dataToSave(dataToBeSaved),
    joystick(joystickPin),
    accelerometer(accelerometerP){
        highScore = dataToSave.PongHighScore->getValue();
}


int Pong::startingPage(){
    lcd->cls();

    //left arrow
    lcd->line(5,1,5,7,1);
    lcd->line(5,1,2,4,1);
    lcd->line(2,4,5,7,1);

    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(50,0);
    lcd->printf("Pong");
    lcd->locate(5,10);
    lcd->printf("Tilt the device");
    lcd->locate(10,20);
    lcd->printf("1 point = 2 food");
    ThisThread::sleep_for(100ms);
    while(1){
        if(joystick.center.read()){
            return main();
        }
        if(joystick.left.read()){
            return 0;
        }
    }
}

int Pong::main(){
    int totalPoints = 0;
    lcd->cls();

    //left arrow
    lcd->line(5,1,5,7,1);
    lcd->line(5,1,2,4,1);
    lcd->line(2,4,5,7,1);

    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(50,0);
    lcd->printf("Pong");

    lcd->locate(35,15);
    lcd->printf("HighScore: %d", highScore);

    bool lastJ = false;
    bool currentJ = false;
    while(1){
        currentJ = joystick.center.read();
        if(currentJ && !lastJ){
            int gamePoint = game();
            if(gamePoint > highScore){
                highScore = gamePoint;
                dataToSave.PongHighScore->setValue(highScore);
                lcd->cls();
                lcd->locate(35,15);
                lcd->printf("NEW HIGHSCORE");
                while(1){
                    if(joystick.center.read()){
                        break;
                    }
                }
            }
            totalPoints += gamePoint;
            int totalPoints = 0;
            lcd->cls();

            //left arrow
            lcd->line(5,1,5,7,1);
            lcd->line(5,1,2,4,1);
            lcd->line(2,4,5,7,1);

            //circle
            lcd->circle(123,4,2,1);

            lcd->locate(50,0);
            lcd->printf("Pong");

            lcd->locate(32,12);
            lcd->printf("HighScore: %d", highScore);
            ThisThread::sleep_for(100ms);
        }
        if(joystick.left.read()){
            return totalPoints;
        }
        lastJ = currentJ;
    }
}

int Pong::game(){
    lcd->cls();

    bool canPoints = true;
    int points = 0;
    float ballSpeedX = int(rand()%2+1);
    float ballSpeedY = 2;
    float ballX = 15;
    float ballY = 63;
    int playerPadPosition = 15;
    float playerSpeed = 4;
    int botPadPosition = 15;
    int padLength = 10;
    bool lost = false;

    while(!lost){
        botPadPosition = (int)ballX;
        drawPlayer(&playerPadPosition, 5, padLength);
        drawPlayer(&botPadPosition, 127-5, padLength);
        drawBall(&ballX, &ballY, &ballSpeedX, &ballSpeedY);
        if(ballY == 1){
            lost = true;
        }
        //Ball bounce on bot slider
        if(ballY >= 127-7){
            ballSpeedY = -ballSpeedY;
            if(ballSpeedY < 2 && points%5 == 0 && points!=0){
                ballSpeedY = -2;
            }
            canPoints = true;
        }
        //Ball bounce on player slider
        if(canPoints && ballY<=7 && ballY > 5 && ballX+1 > playerPadPosition-padLength/2 && ballX-1 < playerPadPosition+padLength/2){
            ballSpeedY = -ballSpeedY;
            if(ballSpeedX > 0 && ballSpeedX < 3){
                ballSpeedX = ballSpeedX + 0.2;
            }
            canPoints = false;
            points++;
            if(points%10 == 0 && padLength > 3){
                padLength --;
            }
        }

        float aY = accelerometer->y();

        playerPadPosition = playerPadPosition + (int)(aY * playerSpeed);

        ThisThread::sleep_for(1ms);
    }
    lcd->cls();

    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(50,0);
    lcd->printf("Pong");

    lcd->locate(32,10);
    lcd->printf("Game over");
    lcd->locate(32,20);
    lcd->printf("Score: %d", points);
    ThisThread::sleep_for(100ms);
    while(1){
        if(joystick.center.read()){
            return points;
        }
    }
}



void Pong::drawPlayer(int* centerX, int centerY, int length){
    lcd->line(centerY ,0 , centerY, 31, 0);
    
    int newXUp  = max(0, min(31-length, *centerX-length/2));
    int newXBot = max(0+length, min(31, *centerX+length/2));

    *centerX = newXBot - length/2;

    lcd->line(centerY, newXUp, centerY, newXBot, 1);
}


void Pong::drawBall(float* ballX, float* ballY, float* ballSpeedX, float* ballSpeedY){
    lcd->fillcircle((int)*ballY, (int)*ballX, 1, 0);
    
    *ballX = *ballX + *ballSpeedX;
    *ballY = *ballY + *ballSpeedY; 

    //ball bounce on edges of the screen
    if(*ballX <= 1.0f || *ballX >= 30.0f){
        *ballSpeedX = -*ballSpeedX;
    }

    *ballX  = max(1.0f, min(30.0f, *ballX));
    *ballY = max(1.0f, min(123.0f, *ballY));

    lcd->fillcircle((int)*ballY, (int)*ballX, 1, 1);
}