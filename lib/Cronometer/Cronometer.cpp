#include "Cronometer.h"

std::string microsecondsToString(std::chrono::microseconds input);

Cronometer::Cronometer(C12832* lcdIn, Joystick joystickPin) : 
    lcd(lcdIn),
    joystick(joystickPin){
}

void Cronometer::startingPage(){
    lcd->cls();

    //left arrow
    lcd->line(5,1,5,7,1);
    lcd->line(5,1,2,4,1);
    lcd->line(2,4,5,7,1);

    lcd->locate(50,0);
    lcd->printf("Cronometer");
    lcd->locate(0,10);
    lcd->printf("Start/Stop -> Joystick central button");
    ThisThread::sleep_for(100ms);
    while(1){
        if(joystick.center.read()){
            main();
            return;
        }
        if(joystick.left.read()){
            return;
        }
    }
}

void Cronometer::main(){
    //use one time per click
    bool button_state = false;
    bool last_button_state = false;
    
    Timer timer;
    bool started = false;
    lcd->cls();

    //left arrow
    lcd->line(5,1,5,7,1);
    lcd->line(5,1,2,4,1);
    lcd->line(2,4,5,7,1);

    lcd->locate(40,14);
    lcd->printf("00:00:00.000");

    lcd->locate(50,0);
    lcd->printf("Cronometer");
    while(1){
        button_state = joystick.center.read();
        if(button_state && !last_button_state && !started){
            timer.start();
            started = true;
        }else if(button_state && !last_button_state && started){
            timer.stop();
            lcd->locate(40,14);
            lcd->printf("%s", microsecondsToString(timer.elapsed_time()).c_str());
            started = false;
        }else if(started){
            lcd->fillrect(0,10,127,31,0);
            lcd->locate(40,14);
            lcd->printf("%s", microsecondsToString(timer.elapsed_time()).c_str());
        }else if(joystick.left.read()){
            return;
        }
        last_button_state = button_state;
    }
}


//convert a std::chrono:microseconds to a string like hh:mm:ss:msms

std::string microsecondsToString(std::chrono::microseconds input){

    long long milliseconds = input.count() / 1000 ;

    long long hours = milliseconds / 3600000;
    milliseconds %= 3600000;
    long long minutes = milliseconds / 60000;
    milliseconds %= 60000;
    long long seconds = milliseconds / 1000;
    milliseconds %= 1000;

    std::string toReturn = std::to_string(hours)+":"+std::to_string(minutes)+":"+std::to_string(seconds)+"."+std::to_string(milliseconds);
    
    return toReturn;
}