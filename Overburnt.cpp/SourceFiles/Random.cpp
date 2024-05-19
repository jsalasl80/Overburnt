#include "HeaderFiles/Random.h"

int Random::generateRandomInRange(int start, int end){
    uniform_int_distribution<int> dist(start, end);
    return dist(rd);
}

int Random::generateBinaryRandom(int option, int alternative){
    int decider = generateRandomInRange(0, 1);
    return decider == 0? option : alternative;
}

int main (){
    Random random;
    for (int i = 0; i < 30; ++i){
        printf("In range: %d Binary: %d\n", random.generateRandomInRange(1,6), random.generateBinaryRandom(-1, 1));
    }
    return 0;
}