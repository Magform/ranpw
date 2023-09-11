#include "DataSaver.h"

#include "Struct.h"

int charOccurrency(char* str, char target);
void encryptDecrypt(char *input, char key);

// DataSaver::DataSaver(const char* saveFileName, CDataToSave toSave, Thread* startThread)
//     : saveFile(saveFileName), oldKrakenHealth(25), oldKrakenHunger(25), oldEgg(0), oldPie(0), oldLCatchHighScore(0), dataToSave(toSave) {
//     if (saveFile.is_open()) {
//         char* data;
//         saveFile >> data;
//         if (!saveFile.fail()) {
//             encryptDecrypt(data, key);
//             if (charOccurrency(data, '|') == 4) {
//                 char* value = strtok(data, "|");
//                 oldKrakenHealth = std::stoi(value);
//                 value = strtok(nullptr, "|");
//                 oldKrakenHunger = std::stoi(value);
//                 value = strtok(nullptr, "|");
//                 oldEgg = std::stoi(value);
//                 value = strtok(nullptr, "|");
//                 oldPie = std::stoi(value);
//                 value = strtok(nullptr, "|");
//                 oldLCatchHighScore = std::stoi(value);
//                 pushOldValue();
//             } else {
//                 saveData();
//                 pushOldValue();
//             }
//         } else {
//             saveData();
//             pushOldValue();
//         }
//     } else {
//         saveData();
//         pushOldValue();
//     }
//     startThread->start(callback([&]() {this->start();}));
// }

// DataSaver::DataSaver(const char* saveFileName, CDataToSave toSave, Thread* startThread){}
DataSaver::DataSaver(){}
// void DataSaver::saveData(){}
// void DataSaver::pushOldValue(){}

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

// void DataSaver::saveData() {
//     std::string data = to_string(oldKrakenHealth) + '|' +
//                       to_string(oldKrakenHunger) + '|' +
//                       to_string(oldEgg) + '|' +
//                       to_string(oldPie) + '|' +
//                       to_string(oldLCatchHighScore) + '|';

//     char* dataChar = strdup(data.c_str());
//     encryptDecrypt(dataChar, key);
//     saveFile << dataChar << std::endl;
//     free(dataChar);
// }

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

