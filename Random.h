#ifndef RANDOM
#define RANDOM
#include "Includes.h"
#include "Constants.h"

class Random{
private:
    std::random_device rd;
public:
    Random(){};
    int generateRandomInRange(int, int);
    int generateBinaryRandom(int, int);
};

#endif