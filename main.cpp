#include "mbed.h"
#include "Interaction.h"
#include "DataSaver.h"


//To add:
//Locky in App
//Temp in App
//DataToSave

Interaction inte;

int main(){
    Thread krakenLifeThread;
    Thread menuThread;
    //Thread dataSaverThread;

    DataToSave toSave;

    inte.start(&krakenLifeThread);
    
    menuThread.start(callback([&]() {inte.mainWork();}));

    //DataSaver test;
    //DataSaver kk("test" ,toSave , &dataSaverThread);

    while(1){
    }
    return 0;
}