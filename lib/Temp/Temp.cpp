#include "Temp.h"

#define dataDelay 500 //How meny time between two data

float roundDecimal(float toRound, int decimalPlace);

Temp::Temp(C12832* lcdIn, Joystick joystickIn, LM75B* tempSensorIn) : 
    lcd(lcdIn),
    joystick(joystickIn),
    tempSensor(tempSensorIn){
}

void Temp::startingPage(){
    while(1){
        main();
        if(joystick.left.read()){
            return;
        }
    }
}

void Temp::main(int newMinTemp, bool restart){
    if(tempSensor->open()){
        static int minTemp = 0;
        static int maxTemp = 0;
        if(time==0 || restart){
            minTemp = newMinTemp;
            if(newMinTemp == -280){
                minTemp = tempSensor->temp()-1;
            }
            maxTemp = minTemp+3;

            //Print GUI
            lcd->cls();
            lcd->locate(0,0);
            lcd->printf("%d", maxTemp);
            lcd->locate(0, 23);
            lcd->printf("%d", minTemp);
            lcd->line(11,0,11,31,1);
            lcd->line(11,31,89,31,1);
            lcd->line(90,0,90,31,1);
            lcd->locate(100, 5);
            lcd->printf("Temp: ");

            //left arrow
            lcd->line(95,1,95,7,1);
            lcd->line(95,1,92,4,1);
            lcd->line(92,4,95,7,1);
        }

        float temp = tempSensor->temp();
        //load one data  every 0.5s
        if(time%dataDelay==0){
            //Get and print new temp value
            lcd->locate(95, 15);
            lcd->fillrect(95,15,127,25,0);
            int wholePart = (int)temp;
            int decimalPart = (int)((temp-wholePart)*1000);
            lcd->printf("%d,%d", wholePart, decimalPart);
            lcd->pixel(11+(time/dataDelay), maxTemp*10-(int)(temp*10),1);
            ThisThread::sleep_for(10ms);
        }
        time++;
        if(time == 79*dataDelay || temp < minTemp || temp > maxTemp){
            time = 0;
        }

    }else{

        lcd->fillrect(0,10,127,20,0);
        lcd->locate(0,10);
        lcd->printf("Error reading sensor");
    }
}


float roundDecimal(float toRound, int decimalPlace){
    float multiplier = std::pow(10.0f, decimalPlace);
    float roundedValue = std::round( toRound * multiplier) / multiplier;
    return roundedValue;
}

