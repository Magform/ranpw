#ifndef DataSaver_H_
#define DataSaver_H_

#include "mbed.h"
#include <File.h>
#include "Struct.h"

//Class that takes care of saving all the necessary data in a text file and reloading it at startup
class DataSaver{
    public:
        DataSaver(const char* saveFileNameP, DataToSave toSave, Thread* startThread);
    private:
        void pushOldValue();
        void saveData();
        void start();
        FILE* saveFile;
        const char* saveFileName = nullptr;
        //initialzie all old data with default value
        int oldKrakenHealth = 25;
        int oldKrakenHunger = 25;
        int oldEgg = 0;
        int oldPie = 0;
        int oldLCatchHighScore = 0;
        int oldPongHighScore = 0;
        int oldLockYHighScore = 0;
        DataToSave dataToSave;
};

#endif //DataSaver_H_