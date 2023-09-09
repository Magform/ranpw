#include "ConcurrentData.h"

ConcurrentData::ConcurrentData(int initialData) {
    data = initialData;
}

int ConcurrentData::getValue() {
    dataMutex.lock();
    int toReturn = data;
    dataMutex.unlock();
    return toReturn;
}

void ConcurrentData::setValue(int newData) {
    dataMutex.lock();
    data = newData;
    dataMutex.unlock();
}

void ConcurrentData::addValue(int toAdd){
    dataMutex.lock();
    data += toAdd;
    dataMutex.unlock();
}