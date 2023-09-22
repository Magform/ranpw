#include "DataSaver.h"

#include "Struct.h"

int charOccurrency(char* str, char target);
void encryptDecrypt(char *input, char key);

DataSaver::DataSaver(const char* saveFileNameP, DataToSave toSave, Thread* startThread)
    : saveFile(), dataToSave(toSave) {

        LocalFileSystem local("local");

        //string concatenation to add /local/ in our fileName
        char* tmpSaveFileName = new char[strlen("/local/") + strlen(saveFileNameP) + 1];
        strcpy(tmpSaveFileName, "/local/");
        strcat(tmpSaveFileName, saveFileNameP);
        saveFileName = tmpSaveFileName;

        saveFile =  fopen(saveFileName, "r");
        if(saveFile == NULL){
            saveData();
        }else{
            
            // obtain file size:
            fseek (saveFile , 0 , SEEK_END);
            long lSize = ftell (saveFile);
            rewind (saveFile);

            // allocate memory to contain the whole file and load file:
            char* data = (char*) malloc (sizeof(char)*lSize);
            fread(data,1,lSize,saveFile);
            // terminate
            fclose(saveFile);
            
            //decrypt data
            encryptDecrypt(data, key);

            //check if data is valid
            if (charOccurrency(data, '|') == 6) {
                char* value = strtok(data, "|");
                oldKrakenHealth = std::stoi(value);
                value = strtok(nullptr, "|");
                oldKrakenHunger = std::stoi(value);
                value = strtok(nullptr, "|");
                oldEgg = std::stoi(value);
                value = strtok(nullptr, "|");
                oldPie = std::stoi(value);
                value = strtok(nullptr, "|");
                oldLCatchHighScore = std::stoi(value);
                value = strtok(nullptr, "|");
                oldPongHighScore = std::stoi(value);
                value = strtok(nullptr, "|");
                oldLockYHighScore = std::stoi(value);
            } else {
                saveData();
            }

            free (data);
        }

        pushOldValue();

        //start thread to always check for new data
        startThread->start(callback([&]() {this->start();}));
    }


void DataSaver::start() {
    while(1){
        int KrakenHealth = dataToSave.KrakenHealth->getValue();
        int KrakenHunger = dataToSave.KrakenHunger->getValue();
        int Egg = dataToSave.Egg->getValue();
        int Pie = dataToSave.Pie->getValue();
        int LCatchHighScore = dataToSave.LCatchHighScore->getValue();
        int PongHighScore = dataToSave.PongHighScore->getValue();
        int LockYHighScore = dataToSave.LockYHighScore->getValue();

        if(KrakenHealth != oldKrakenHealth || KrakenHunger != oldKrakenHunger || Egg != oldEgg || Pie != oldPie || LCatchHighScore != oldLCatchHighScore || PongHighScore != oldPongHighScore || LockYHighScore != oldLockYHighScore){
            oldKrakenHealth = KrakenHealth;
            oldKrakenHunger = KrakenHunger;
            oldEgg = Egg;
            oldPie = Pie;
            oldLCatchHighScore = LCatchHighScore;
            oldPongHighScore = PongHighScore;
            oldLockYHighScore = LockYHighScore;
            saveData();
        }
        ThisThread::sleep_for(100ms);
    }
}


void DataSaver::saveData() {
    saveFile = fopen(saveFileName,"w");
    std::string data = to_string(oldKrakenHealth) + '|' +
                      to_string(oldKrakenHunger) + '|' +
                      to_string(oldEgg) + '|' +
                      to_string(oldPie) + '|' +
                      to_string(oldLCatchHighScore) + '|' +
                      to_string(oldPongHighScore) + '|' + 
                      to_string(oldLockYHighScore);

    char* dataChar = strdup(data.c_str());
    encryptDecrypt(dataChar, key);
    fprintf(saveFile, dataChar);
    free(dataChar);
    fclose(saveFile);
}

void DataSaver::pushOldValue(){
    dataToSave.KrakenHealth->setValue(oldKrakenHealth);
    dataToSave.KrakenHunger->setValue(oldKrakenHunger);
    dataToSave.Egg->setValue(oldEgg);
    dataToSave.Pie->setValue(oldPie);
    dataToSave.LCatchHighScore->setValue(oldLCatchHighScore);
    dataToSave.PongHighScore->setValue(oldPongHighScore);
    dataToSave.LockYHighScore->setValue(oldLockYHighScore);
}


//util function
void encryptDecrypt(char *input, char key) {
    size_t len = strlen(input);
    for (size_t i = 0; i < len; i++) {
        input[i] ^= key;
    }
}


int charOccurrency(char* str, char target) {
    int quantity = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            quantity ++;
        }
    }
    return quantity;
}

