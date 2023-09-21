#include "mbed.h"
#include "Interaction.h"
#include "DataSaver.h"

//To add:
//DataToSave

Interaction inte;

Thread dataSaverThread;
DataToSave toSave;
DataSaver kk("save" ,toSave , &dataSaverThread);

int main(){
    Thread krakenLifeThread;
    Thread menuThread;

    inte.start(&krakenLifeThread);
    
    menuThread.start(callback([&]() {inte.mainWork();}));


    while(1){
    }
    return 0;
}