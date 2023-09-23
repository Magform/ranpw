#include "LCatch.h"

LCatch::LCatch(DataToSave dataToBeSaved,C12832* lcdIn, Joystick joystickPin) : 
    joystick(joystickPin),
    dataToSave(dataToBeSaved){
    lcd = lcdIn;
    highScore = dataToSave.LCatchHighScore->getValue();
}

int LCatch::startingPage(){
    lcd->cls();

    //left arrow
    lcd->line(5,1,5,7,1);
    lcd->line(5,1,2,4,1);
    lcd->line(2,4,5,7,1);

    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(50,0);
    lcd->printf("LCatch");
    lcd->locate(0,10);
    lcd->printf("Press the joystick button corresponding to the number");
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
            lcd->printf("LCatch");
            lcd->locate(25,15);
            lcd->printf("10 points = 1 food");

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
                    lcd->printf("LCatch");
                    lcd->locate(0,10);
                    lcd->printf("1 -> Up");
                    lcd->locate(64,10);
                    lcd->printf("| 2 -> Left");
                    lcd->locate(0,20);
                    lcd->printf("3 -> Right");
                    lcd->locate(64,20);
                    lcd->printf("| 4 -> Down");

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

int LCatch::main(){
    int totalPoints = 0;
    lcd->cls();

    //left arrow
    lcd->line(5,1,5,7,1);
    lcd->line(5,1,2,4,1);
    lcd->line(2,4,5,7,1);

    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(50,0);
    lcd->printf("LCatch");

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
                dataToSave.LCatchHighScore->setValue(highScore);
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
            lcd->printf("LCatch");

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


int LCatch::game(){
    int score = 0;
    lcd->cls();

    lcd->locate(50,0);
    lcd->printf("LCatch");

    lcd->locate(48,12);
    lcd->printf("Score: %d", score);

    bool lost = false;

    while(!lost){
        int randomNumber = rand() % 4;
        if(randomNumber == 0){
            randomAppear(1);
            buttonWait(joystick.up, &score, &lost);
        }else if(randomNumber == 1){
            randomAppear(2);
            buttonWait(joystick.left, &score, &lost);
        }else if(randomNumber == 2){
            randomAppear(3);
            buttonWait(joystick.right, &score, &lost);
        }else if(randomNumber == 3){
            randomAppear(4);
            buttonWait(joystick.down, &score, &lost);
        }

    }

    lcd->cls();

    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(50,0);
    lcd->printf("LCatch");

    lcd->locate(28, 10);
    lcd->printf("YOU HAVE LOST");
    lcd->locate(30,20); 
    lcd->printf("Final Score: %d", score);
    while(1){
        if(joystick.center.read()){
            return score;
        }
    }
}

void LCatch::buttonWait(DigitalIn button, int* score, bool* lost){
    bool find = false;
    int counting = 0;
    static bool pastButtonState = false;
    bool actualButtonState = false;
    while(counting < 400-((*score)*10) && !find){
        actualButtonState = button.read();
        if(actualButtonState && !pastButtonState){
            *score = *score + 1;
            pastButtonState = actualButtonState;
            find = true;
        }
        counting++;
        pastButtonState = actualButtonState;
        ThisThread::sleep_for(1ms);
    }
    if(!find){
        *lost = true;
    }else{
        lcd->fillrect(0,12,127,31,0);
        lcd->locate(48,12);
        lcd->printf("Score: %d", *score);
    }
}

void LCatch::randomAppear(int toAppear){
    int randomX = rand()%10+12;
    int randomY = rand()%2;
    if(randomY == 1){
        randomY = rand()%38;
    }else{
        randomY = rand()%28+90;
    }
    lcd->locate(randomY, randomX);
    lcd->printf("%d", toAppear);
}