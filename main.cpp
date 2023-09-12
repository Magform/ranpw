#include "mbed.h"
#include "Interaction.h"

//Known porblem
// it'seem that I cant make 2 game and I dont knwo way
// for some reason initializing DataSaver bring same problem


int main(){

    Interaction inte;
    Thread krakenLifeThread;
    Thread menuThread;
    // //Thread dataSaverThread;

    DataToSave toSave;

    inte.start(&krakenLifeThread);
    
    menuThread.start(callback([&]() {inte.mainWork();}));

    // //DataSaver kk("test" ,toSave , &dataSaverThread);

    while(1){
    }
    return 0;
}