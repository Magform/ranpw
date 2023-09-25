#include "Hell.h"

Hell::Hell(C12832* lcdIn, Joystick joystickPin, MMA7660* accelerometerP) : 
    lcd(lcdIn),
    joystick(joystickPin),
    accelerometer(accelerometerP){
}


int Hell::startingPage(){
    lcd->cls();

    //left arrow
    lcd->line(5,1,5,7,1);
    lcd->line(5,1,2,4,1);
    lcd->line(2,4,5,7,1);

    //circle
    lcd->circle(123,4,2,1);

    lcd->locate(40,0);
    lcd->printf("WELCOME TO");
    lcd->locate(53,15);
    lcd->printf("HELL");
    ThisThread::sleep_for(100ms);
    while(1){
        if(joystick.center.read()){
            return game();
        }
        if(joystick.left.read()){
            return 0;
        }
    }
}


int Hell::game(){
    int numberOfDungeon = rand()%5+1;
    for(int i=0; i<numberOfDungeon-1; i++){
        randomDungeon(6);
    }
    //easter Egg
    if(randomDungeon(6)){
        lcd->cls();
        //circle
        lcd->circle(123,4,2,1);

        lcd->locate(0,5);
        lcd->printf("It's not about the gold,");
        lcd->locate(0,15);
        lcd->printf("It's about the glory");
        ThisThread::sleep_for(100ms);
        while(1){
            if(joystick.center.read()){
                return numberOfDungeon;
            }
        }
    }
    return numberOfDungeon;
}


int Hell::randomDungeon(int radius){
    int playerLocationX = 0;
    int playerLocationY = 0;
    int playerSpeed = 6;
    int endingX = rand()%(128-2*radius)+radius;
    int endingY = rand()%(32-2*radius)+radius;
    bool win = false;

    lcd->cls();
    lcd->fillrect(0,0,127,31,1);
    lcd->fillcircle(playerLocationX, playerLocationY, radius, 0);
    lcd->pixel(playerLocationX, playerLocationY, 1);
    lcd->pixel(endingX, endingY, 1);

    while(!win){
        lcd->fillcircle(playerLocationX, playerLocationY, radius, 1);
        playerLocationX -= (int)(accelerometer->x() * playerSpeed);
        playerLocationY += (int)(accelerometer->y() * playerSpeed);

        playerLocationX = min(127-radius, max(0+radius, playerLocationX));
        playerLocationY = min(31-radius, max(0+radius, playerLocationY));

        lcd->fillcircle(playerLocationX, playerLocationY, radius, 0);
        lcd->pixel(playerLocationX, playerLocationY, 1);

        lcd->fillcircle(endingX, endingY,2, 1);

        if(playerLocationX==endingX && playerLocationY==endingY && accelerometer->z()<0){
            return 1;
        }
        if(playerLocationX==endingX && playerLocationY==endingY){
            return 0;
        }
        ThisThread::sleep_for(100ms);
    }
} 