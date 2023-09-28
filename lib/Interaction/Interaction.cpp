#include "Interaction.h"
#include "mbed.h"
#include <chrono>
#include "Bitmap.h"

//All Games
#include "Hell.h"
#include "LCatch.h"
#include "LockY.h"
#include "Pong.h"
//All apps
#include "Cronometer.h"

Interaction::Interaction(DataToSave dataToBeSaved) : 
    bag(dataToBeSaved),
    lcd(p5, p7, p6, p8, p11), 
    accelerometer(p28, p27),
    joystick{p13, p15, p16, p12, p14},
    dataToSave(dataToBeSaved),
    kraken(dataToSave)
    {
}

void Interaction::start(Thread *krakenLife){
    lcd.cls();
    lcd.locate(50, 10);
    lcd.printf("RANPW");
    ThisThread::sleep_for(std::chrono::milliseconds(500));
    
    //print Kraken or tombstone
    if(kraken.getHealth()>0){
       lcd.print_bm(getKrakenBitmap(), 0,0);
    }else{
        lcd.print_bm(getTombstoneBitmap(), 0,0);
    }
    lcd.copy_to_lcd();

    lcd.cls();
    //Separation Line
    lcd.line(90,0,90,32,1);

    //Down arrow
    lcd.line(109,30,114,25,1);
    lcd.line(109,30,104,25,1);
    lcd.line(104,25,114,25,1);

    //Write first data
    lcd.locate(95,12);
    lcd.printf("Bag");

    //Health bar
    lcd.locate(53, 2);
    lcd.printf("Health");
    lcd.rect(53,12,80,15,1);
    lcd.fillrect(52,12,54 + kraken.getHealth(),15,1);

    //Hunger bar
    lcd.locate(53, 17);
    lcd.printf("Hunger");
    lcd.rect(53,27,80,30,1);
    lcd.fillrect(52,27,54 + kraken.getHunger(),30,1);

    //Start a thread with the Kraken life, so kraken health and Hunger can always change
    krakenLife->start(callback([&]() {kraken.live();}));
}

//Class that implement manage all the option that can be choose in the left slider so it needs all the option, the function to be runned when something is selected and if it's a sub menu or not
void Interaction::slider(vector<char*> options, std::function<void(int)> toRun, bool submenu) {
    int selected = 0;
    lcd.locate(0,0);
    ThisThread::sleep_for(std::chrono::milliseconds(100));
    //call printMonitor to print the whole screen
    printMonitor(selected, options, true, submenu);
    while (1) {
        if (this->joystick.down) {
            selected++;
        }
        if (this->joystick.up) {
            selected--;
        }
        if(submenu && this->joystick.left){
            return;
        }
        selected = min(int(options.size()-1), max(selected, 0));
        if (this->joystick.center) {
            toRun(selected);
            if(!submenu){
                printMonitor(selected, options, true, submenu);
            }
            if(submenu){
                return;
            }
        }
        printMonitor(selected, options, false, submenu);
        ThisThread::sleep_for(std::chrono::milliseconds(10));
    }
}

//Function that print whole screen
void Interaction::printMonitor(int selected, vector<char*> options, bool reload, bool submenu){
    static int oldSelected;
    static int oldHealth;
    static int oldHunger;
    if(reload ||oldSelected != selected || kraken.getHealth() != oldHealth || kraken.getHunger() != oldHunger){
        lcd.cls();

        //print Kraken or tombstone
        if(kraken.getHealth()>0){
            lcd.print_bm(getKrakenBitmap(), 0,0);
        }else{
            lcd.print_bm(getTombstoneBitmap(), 0,0);
        }
        lcd.copy_to_lcd();

        //Separation Line
        lcd.line(90,0,90,32,1);
        
        if(submenu){
            lcd.line(95,1,95,7,1);
            lcd.line(95,1,92,4,1);
            lcd.line(92,4,95,7,1);
        }
        //Up arrow
        if(selected != 0){
            lcd.line(109,3,114,8,1);
            lcd.line(109,3,104,8,1);
            lcd.line(104,8,114,8,1);
        }

        //Down arrow
        if(selected != int(options.size()-1)){
            lcd.line(109,30,114,25,1);
            lcd.line(109,30,104,25,1);
            lcd.line(104,25,114,25,1);
        }
        
        //Write slider option
        lcd.locate(95,12);
        lcd.printf("%s", options[selected]);

        //Health bar
        lcd.locate(53, 2);
        lcd.printf("Health");
        lcd.rect(53,12,80,15,1);
        lcd.fillrect(52,12,54 + kraken.getHealth(),15,1);

        //Hunger bar
        lcd.locate(53, 17);
        lcd.printf("Hunger");
        lcd.rect(53,27,80,30,1);
        lcd.fillrect(52,27,54 + kraken.getHunger(),30,1);

        oldSelected = selected;
        oldHealth = kraken.getHealth();
        oldHunger = kraken.getHunger();
    }
}

//Main menu
void Interaction::mainWork(){
    slider({"Bag", "Games", "Apps", "Credits"}, [this](int selected) { this->execute(selected); });
}

void Interaction::execute(int selected){
    if(selected == 0){
        lcd.cls();
        while(1){
            if(this->joystick.left){
                return;
            }

            char eggN[10] = "Egg: ";
            char pieN[10] = "Pie: ";
            char eggCountStr[10];
            char pieCountStr[10];
            snprintf(eggCountStr, sizeof(eggCountStr), "%d", bag.getFood(1));
            snprintf(pieCountStr, sizeof(pieCountStr), "%d", bag.getFood(0));
            strcat(eggN, eggCountStr);
            strcat(pieN, pieCountStr);

            this->slider({eggN, pieN}, [this](int selected) { this->useFood(selected); }, true);
        }
        
    }
    if(selected == 1){
        lcd.cls();
        while(1){
            if(this->joystick.left){
                return;
            }
            this->slider({"LCatch", "Pong", "LockY"}, [this](int selected) { this->useGame(selected); }, true);
        }
    }
    if(selected == 2){
        lcd.cls();
        while(1){
            if(this->joystick.left){
                return;
            }
            this->slider({"Cron"}, [this](int selected) { this->useApp(selected); }, true);
        }
    }
    if(selected == 3){
        lcd.cls();
        //Left Arrow
        lcd.line(3,16,10,12,1);
        lcd.line(3,16,10,20,1);
        lcd.line(10,12,10,20,1);
        //Credits
        lcd.locate(50, 2);
        lcd.printf("Magform");
        lcd.locate(30, 12);
        lcd.printf("Nicolas Ferraresso");
        while(1){
            if(this->joystick.left){
                return;
            }
        }
    }
}


void Interaction::useFood(int selected){
    if(selected == 0){
        kraken.addHunger(bag.useFood(1));
    }
    if(selected == 1){
        kraken.addHunger(bag.useFood(0));
    }
}

void Interaction::useApp(int selected){
    if(selected == 0){
        Cronometer cronometer(&lcd, joystick);
        cronometer.startingPage();
    }
}

void Interaction::useGame(int selected){
    if(kraken.getHealth()==0){
        Hell gell(&lcd, joystick, &accelerometer);
        kraken.addHealth(gell.startingPage());
    }
    if(selected == 0){
        LCatch lcatch(dataToSave, &lcd, joystick);
        int addFood = lcatch.startingPage()/10;
        for(int i = 0; i < addFood; i++){
            bag.addRandomFood();
        }
    }
    if(selected == 1){
        Pong pong(dataToSave, &lcd, joystick, &accelerometer);
        int addFood = pong.startingPage()*2;
        for(int i = 0; i < addFood; i++){
           bag.addRandomFood();
        }
    }
    if(selected == 2){
        LockY locky(dataToSave, &lcd, joystick, p19, p20);
        int addFood = locky.startingPage()/100;
        for(int i = 0; i < addFood; i++){
            bag.addRandomFood();
        }
    }
}