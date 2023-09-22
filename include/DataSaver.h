#ifndef DataSaver_H_
#define DataSaver_H_

#include "mbed.h"
#include <File.h>
#include "Struct.h"

class DataSaver{
    public:
        DataSaver(const char* saveFileNameP, DataToSave toSave, Thread* startThread);
    private:
        void pushOldValue();
        void saveData();
        void start();
        FILE* saveFile;
        char key = 'm';
        int oldKrakenHealth = 25;
        int oldKrakenHunger = 25;
        int oldEgg = 0;
        int oldPie = 0;
        int oldLCatchHighScore = 0;
        int oldPongHighScore = 0;
        int oldLockYHighScore = 0;
        const char* saveFileName = nullptr;
        DataToSave dataToSave;
};

#endif //DataSaver_H_