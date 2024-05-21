#ifndef LOCKABLEMAP
#define LOCKABLEMAP

#include "Includes.h"
#include "Constants.h"
#include "Ingredient.h"

using namespace std;

template <typename First, class Second> 
class LockableMap{
private:
    map<First, Second> storage;
    bool locked;

public:
    LockableMap(): storage(), locked(UNLOCKED){};
    ~LockableMap(){
        clearMap();
    }
    
    void insert(First, Second);
    Second getElement(First);
    void clearMap();
    bool getAvailability() const;
    void lock();
    void unlock();
    int getSize();

};

#endif