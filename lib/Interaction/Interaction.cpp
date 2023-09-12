#include "Interaction.h"
#include "mbed.h"
#include <chrono>
#include "Egg.h"
#include "Pie.h"

char krakenBTM[]  = {
    //Some Kraken Bitmap
  };

Interaction::Interaction() : 
    lcd(p5, p7, p6, p8, p11), 
    joystick{p13, p15, p16, p12, p14},
    potentiometerBottom(p19),
    potentiometerUp(p20),
    mainPage({p5, p7, p6, p8, p11}, {p13, p15, p16, p12, p14}, {p28, p27})
    {
}

void Interaction::start(Thread *krakenLife){
    lcd.cls();
    lcd.locate(50, 10);
    lcd.printf("RANPW");
    ThisThread::sleep_for(std::chrono::milliseconds(500));
    Bitmap krakenImageBitmap{25, 25 , 1 , krakenBTM};
    lcd.cls();
    lcd.print_bm(krakenImageBitmap,5 , 5);
    lcd.copy_to_lcd();
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
    lcd.fillrect(52,12,54 + this->mainPage.kraken.getHealth(),15,1);

    //Hunger bar
    lcd.locate(53, 17);
    lcd.printf("Hunger");
    lcd.rect(53,27,80,30,1);
    lcd.fillrect(52,27,54 + this->mainPage.kraken.getHunger(),30,1);

    krakenLife->start(callback([&]() {this->mainPage.kraken.live();}));
}

void Interaction::mainWork(){
    slider({"Bag", "Games", "Apps", "Credits"}, [this](int selected) { this->execute(selected); });
}

void Interaction::slider(vector<char*> options, std::function<void(int)> toRun, bool submenu) {
    int selected = 0;
    lcd.locate(0,0);
    ThisThread::sleep_for(std::chrono::milliseconds(100));
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


void Interaction::printMonitor(int selected, vector<char*> options, bool reload, bool submenu){
    static int oldSelected;
    static int oldHealth;
    static int oldHunger;
    if(reload ||oldSelected != selected || this->mainPage.kraken.getHealth() != oldHealth || this->mainPage.kraken.getHunger() != oldHunger){
        lcd.cls();
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
        
        //Write first data
        lcd.locate(95,12);
        lcd.printf("%s", options[selected]);

        //Health bar
        lcd.locate(53, 2);
        lcd.printf("Health");
        lcd.rect(53,12,80,15,1);
        lcd.fillrect(52,12,54 + this->mainPage.kraken.getHealth(),15,1);

        //Hunger bar
        lcd.locate(53, 17);
        lcd.printf("Hunger");
        lcd.rect(53,27,80,30,1);
        lcd.fillrect(52,27,54 + this->mainPage.kraken.getHunger(),30,1);

        oldSelected = selected;
        oldHealth = this->mainPage.kraken.getHealth();
        oldHunger = this->mainPage.kraken.getHunger();
    }
}


void Interaction::execute(int selected){
    if(selected == 0){
        lcd.cls();
        while(1){
            if(this->joystick.left){
                return;
            }
            int EggNumber = 0;
            int PieNumber = 0;
            for (std::pair<std::string, int>& aviableFood : this->mainPage.menu.bag.getFood()) {
                if (aviableFood.first == "Egg") {
                    EggNumber = aviableFood.second;
                }
                if (aviableFood.first == "Pie") {
                    PieNumber = aviableFood.second;
                }
            }
            this->slider({const_cast<char*>(("Egg " + std::to_string(EggNumber)).c_str()), const_cast<char*>(("Pie " + std::to_string(PieNumber)).c_str())}, [this](int selected) { this->useFood(selected); }, true);
        }
        
    }
    if(selected == 1){
        lcd.cls();
        while(1){
            if(this->joystick.left){
                return;
            }
            this->slider({"LCatch", "Pong"}, [this](int selected) { this->useGame(selected); }, true);
        }
    }
    if(selected == 2){
        lcd.cls();
        while(1){
            if(this->joystick.left){
                return;
            }
            this->slider({"Cron", "Temp"}, [this](int selected) { this->useApp(selected); }, true);
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
        lcd.printf(this->mainPage.menu.credits.getAlias());
        lcd.locate(30, 12);
        lcd.printf(this->mainPage.menu.credits.getName());
        while(1){
            if(this->joystick.left){
                return;
            }
        }
    }
}


void Interaction::useFood(int selected){
    if(selected == 0){
        this->mainPage.kraken.addHunger(this->mainPage.menu.bag.useFood("Egg"));
    }
    if(selected == 1){
        this->mainPage.kraken.addHunger(this->mainPage.menu.bag.useFood("Pie"));
    }
}

void Interaction::useApp(int selected){
    if(selected == 0){
         this->mainPage.menu.app.cronometer.startingPage();
    }
    if(selected == 0){
        // this->mainPage.menu.app.termometer.startingPage();
    }
}

void Interaction::useGame(int selected){
    if(selected == 0){
        int addFood = this->mainPage.menu.game.lcatch.startingPage()/10;
        for(int i = 0; i < addFood; i++){
            Food tmpFood("UNK", 0);
            tmpFood = tmpFood.randomFood();
            this->mainPage.menu.bag.addFood(tmpFood);
        }
    }
    // if(selected == 1){
    //     int addFood = this->mainPage.menu.game.pong.startingPage()*2;
    //     for(int i = 0; i < addFood; i++){
    //         Food tmpFood("UNK", 0);
    //         tmpFood = tmpFood.randomFood();
    //         this->mainPage.menu.bag.addFood(tmpFood);
    //     }
    // }
}