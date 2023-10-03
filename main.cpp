#include "mbed.h"
#include "Ranpw.h"
#include "DataSaver.h"

Thread dataSaverThread;
DataToSave toSave;
DataSaver dataSaver("save.txt" ,toSave , &dataSaverThread);

Ranpw ranpw(toSave);

int main(){
    Thread krakenLifeThread;
    Thread menuThread;

    ranpw.start(&krakenLifeThread);
    
    menuThread.start(callback([&]() {ranpw.mainWork();}));


    while(1){
    }
    return 0;
}