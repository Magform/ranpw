#ifndef DataSaver_H_
#define DataSaver_H_

#include <fstream>
#include "Struct.h"

class DataSaver{
    public:
        // DataSaver(const char* saveFileName, CDataToSave toSave, Thread* startThread);
        DataSaver();
    private:
        // void pushOldValue();
        // void saveData();
        // void start();
        // std::fstream saveFile; //it's a problem
        // char key = 'm';  //it's a problem
        int oldKrakenHealth = 25;
        int oldKrakenHunger = 25;
        int oldEgg = 0;
        int oldPie = 0;
        int oldLCatchHighScore = 0;
        // CDataToSave dataToSave; //it's a problem
};

#endif //DataSaver_H_