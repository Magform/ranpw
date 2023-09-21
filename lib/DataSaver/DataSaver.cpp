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
            
        }

        
    }















    // char* data;
    // saveFile >> data;
    // if (!saveFile.fail()) {
    //     encryptDecrypt(data, key);
    //     if (charOccurrency(data, '|') == 4) {
    //         char* value = strtok(data, "|");
    //         oldKrakenHealth = std::stoi(value);
    //         value = strtok(nullptr, "|");
    //         oldKrakenHunger = std::stoi(value);
    //         value = strtok(nullptr, "|");
    //         oldEgg = std::stoi(value);
    //         value = strtok(nullptr, "|");
    //         oldPie = std::stoi(value);
    //         value = strtok(nullptr, "|");
    //         oldLCatchHighScore = std::stoi(value);
    //         pushOldValue();
    //     } else {
    //         saveData();
    //         pushOldValue();
    //     }
    // } else {
    //     saveData();
    //     pushOldValue();
    // }

    // startThread->start(callback([&]() {this->start();}));
// }


// void DataSaver::start() {
//     while(1){
//         int KrakenHealth = dataToSave.KrakenHealth->getValue();
//         int KrakenHunger = dataToSave.KrakenHunger->getValue();
//         int Egg = dataToSave.Egg->getValue();
//         int Pie = dataToSave.Pie->getValue();
//         int LCatchHighScore = dataToSave.LCatchHighScore->getValue();

//         if(KrakenHealth != oldKrakenHealth || KrakenHunger != oldKrakenHunger || Egg != oldEgg || Pie != oldPie || LCatchHighScore != oldLCatchHighScore){
//             oldKrakenHealth = KrakenHealth;
//             oldKrakenHunger = KrakenHunger;
//             oldEgg = Egg;
//             oldPie = Pie;
//             oldLCatchHighScore = LCatchHighScore;
//             saveData();
//         }
//         ThisThread::sleep_for(100ms);
//     }
// }

void DataSaver::saveData() {
    saveFile = fopen(saveFileName,"w");
    std::string data = to_string(oldKrakenHealth) + '|' +
                      to_string(oldKrakenHunger) + '|' +
                      to_string(oldEgg) + '|' +
                      to_string(oldPie) + '|' +
                      to_string(oldLCatchHighScore) + '|';

    char* dataChar = strdup(data.c_str());
    encryptDecrypt(dataChar, key);
    fprintf(saveFile, dataChar);
    free(dataChar);
    fclose(saveFile);
}

// void DataSaver::pushOldValue(){
//     dataToSave.KrakenHealth->setValue(oldKrakenHealth);
//     dataToSave.KrakenHunger->setValue(oldKrakenHunger);
//     dataToSave.Egg->setValue(oldEgg);
//     dataToSave.Pie->setValue(oldPie);
//     dataToSave.LCatchHighScore->setValue(oldLCatchHighScore);
// }


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

