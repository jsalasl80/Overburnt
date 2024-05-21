#ifndef RANDOM
#define RANDOM
#include "Includes.h"
#include "Constants.h"
using namespace std;

class Random{
private:
    random_device rd;
public:
    Random(){};
    int generateRandomInRange(int, int);
    int generateBinaryRandom(int, int);
};

#endif