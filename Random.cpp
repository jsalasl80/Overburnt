#include "Random.h"

int Random::generateRandomInRange(int start, int end){
    std::uniform_int_distribution<int> dist(start, end);
    return dist(rd);
}

int Random::generateBinaryRandom(int option, int alternative){
    int decider = generateRandomInRange(0, 1);
    return decider == 0? option : alternative;
}
