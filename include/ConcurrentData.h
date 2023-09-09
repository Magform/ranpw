#pragma once

#include "mbed.h"

class ConcurrentData {
private:
    int data;
    Mutex dataMutex;

public:
    ConcurrentData(int initialData = 0.0);
    void addValue(int toAdd);
    int getValue();
    void setValue(int newData);
};
