#include "LockY.h"
#include <random>

int floatToLine(float toAngle, bool second = false);
bool decimalCheck(float numberOne, float numberTwo, int decimalPlaces);
float rand01();

LockY::LockY(DataToSave dataToBeSaved, C12832* lcdIn, Joystick joystickPin, PinName potenUp, PinName potenDown) : 
    lcd(lcdIn),
    joystick(joystickPin),
    dataToSave(dataToBeSaved),
    potentiometerUP(potenUp),
    potentiometerDown(potenDown){
        highScore = dataToSave.LockYHighScore->getValue();
}


int LockY::startingPage(){
    lcd->cls();

    //left arrow
    lcd->line(5,1,5,7,1);
    lcd->line(5,1,2,4,1);
    lcd->line(2,4,5,7,1);

    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(50,0);
    lcd->printf("LockY");
    lcd->locate(0,10);
    lcd->printf("Use the two potentiometer to crack the safe");
    ThisThread::sleep_for(100ms);
    while(1){
        if(joystick.center.read()){
            lcd->cls();

            //left arrow
            lcd->line(5,1,5,7,1);
            lcd->line(5,1,2,4,1);
            lcd->line(2,4,5,7,1);

            //circle
            lcd->circle(123,4,2,1);

            lcd->locate(50,0);
            lcd->printf("LockY");
            lcd->locate(25,10);
            lcd->printf("100 points = 1 food");

            ThisThread::sleep_for(100ms);
            while(1){
                if(joystick.center.read()){
                    lcd->cls();

                    //left arrow
                    lcd->line(5,1,5,7,1);
                    lcd->line(5,1,2,4,1);
                    lcd->line(2,4,5,7,1);

                    //circle
                    lcd->circle(123,4,2,1);

                    lcd->locate(50,0);
                    lcd->printf("LockY");
                    lcd->locate(25,10);
                    lcd->printf("Points = 1000/second");
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
                if(joystick.left.read()){
                    return 0;
                }
            }
        }
        if(joystick.left.read()){
            return 0;
        }
    }
}


int LockY::main(){
    int totalPoints = 0;
    lcd->cls();

    //left arrow
    lcd->line(5,1,5,7,1);
    lcd->line(5,1,2,4,1);
    lcd->line(2,4,5,7,1);

    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(50,0);
    lcd->printf("LockY");

    lcd->locate(32,12);
    lcd->printf("HighScore: %d", highScore);

    bool lastJ = false;
    bool currentJ = false;
    while(1){
        currentJ = joystick.center.read();
        if(currentJ && !lastJ){
            int gamePoint = game();
            if(gamePoint > highScore){
                highScore = gamePoint;
                dataToSave.LockYHighScore->setValue(highScore);
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
            lcd->printf("LockY");

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


int LockY::game(){
    lcd->cls();

    lcd->locate(50,0);
    lcd->printf("LockY");

    Timer timer;
    timer.start();
    bool win = false;

    float leftSafe = rand01();
    float rightSafe = rand01();

    lcd->line(0,15,127,15,1);
    //safe
    lcd->line(floatToLine(leftSafe), 15, floatToLine(leftSafe, true), 15, 0);
    lcd->line(floatToLine(rightSafe), 15, floatToLine(rightSafe, true), 15, 0);

    while(!win){
        //Take data from the 2 potentiometer
        float pot1 = potentiometerDown.read();
        float pot2 = potentiometerUP.read();

        //decoder
        lcd->line(0,16,127,16,0);
        lcd->line(0,14,127,14,0);
        lcd->line(floatToLine(pot1), 16, floatToLine(pot1, true), 16, 1);
        lcd->line(floatToLine(pot2), 14, floatToLine(pot2, true), 14, 1);

        if((decimalCheck(pot1, leftSafe, 2) && decimalCheck(pot2, rightSafe, 2))||(decimalCheck(pot2, leftSafe, 2) && decimalCheck(pot1, rightSafe, 2))){
            win = true;
        }

        ThisThread::sleep_for(10ms);
    }
    timer.stop();

    lcd->cls();


    int score = (int)(1000/((timer.elapsed_time()).count()/1000000));
    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(50,0);
    lcd->printf("LockY");

    lcd->locate(28, 10);
    lcd->printf("YOU HAVE WIN");
    lcd->locate(30,20); 
    lcd->printf("Final Score: %d", score);
    while(1){
        if(joystick.center.read()){
            return score;
        }
    }
}


int floatToLine(float toAngle, bool second){
    if(second){
        int toReturn = (int)(toAngle * 100)+10;
        return toReturn;
    }
    return (int)(toAngle * 100);
}


bool decimalCheck(float numberOne, float numberTwo, int decimalPlaces) {
    float factor = std::pow(10, decimalPlaces);
    int rounded1 = (int)(numberOne * factor);
    int rounded2 = (int)(numberTwo * factor);

    return rounded1 == rounded2;
}

float rand01(){
    float toReturn = (float)rand()/RAND_MAX;
    return toReturn;
}