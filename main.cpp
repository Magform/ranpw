#include "mbed.h"
#include "Interaction.h"

int main(){

    Interaction inte;
    Thread krakenLife;
    Thread menu;
    inte.start(&krakenLife);
    
    menu.start(callback([&]() {inte.mainWork();}));
    while(1){
    }
    return 0;
}