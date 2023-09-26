#ifndef ConcurrentData_H_
#define ConcurrentData_H_

#include "mbed.h"

// A class for safely passing data between different threads, preventing concurrency issues on variables.

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

#endif // ConcurrentData_H_