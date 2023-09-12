#include "Temp.h"

float roundDecimal(float toRound, int decimalPlace);

Temp::Temp(lcdPin lcdPin, Joystick joystickPin, tempPin tempSensorPin) : 
    lcd(lcdPin.MOSI, lcdPin.SCK, lcdPin.RESET, lcdPin.A0, lcdPin.nCS),
    joystick(joystickPin),
    tempSensor(tempSensorPin.SDA, tempSensorPin.SCL){
}

void Temp::startingPage(){
    lcd.cls();

    //left arrow
    lcd.line(5,1,5,7,1);
    lcd.line(5,1,2,4,1);
    lcd.line(2,4,5,7,1);

    lcd.locate(50,0);
    lcd.printf("Temp");
    lcd.locate(0,10);
    while(1){
        main();
        if(joystick.left.read()){
            return;
        }
    }
}

void Temp::main(){
    static float oldTemperature = 0.0f;
    if(tempSensor.open()){
        float temperature = tempSensor.temp();
        temperature = roundDecimal(temperature, 4);
        if(temperature != oldTemperature){
            lcd.fillrect(0,10,127,20,0);
            lcd.locate(0,10);
            lcd.printf("Temperature: %.4f", temperature);
        }
        oldTemperature = temperature;
    }else{
        lcd.fillrect(0,10,127,20,0);
        lcd.locate(0,10);
        lcd.printf("Error reading sensor");
    }

}

float roundDecimal(float toRound, int decimalPlace){
    float multiplier = std::pow(10.0f, decimalPlace);
    float roundedValue = std::round( toRound * multiplier) / multiplier;
    return roundedValue;
}