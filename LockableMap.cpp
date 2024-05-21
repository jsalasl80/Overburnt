#include "LockableMap.h"
using namespace std;

template <typename First, typename Second> 
void LockableMap<First, Second>::insert(First key, Second value){
    storage.insert(pair<First, Second>(key, value));
}

template <typename First, typename Second> 
Second LockableMap<First, Second>:: getElement(First key){
    return storage[key];
}

template <typename First, typename Second> 
void LockableMap<First, Second>:: clearMap(){
    if (!storage.empty()){
        for (auto itr = storage.begin(); itr != storage.end(); ++itr) {
            delete itr->second;
        }

        storage.clear();
    }
}

template <typename First, typename Second> 
bool LockableMap<First, Second>:: getAvailability() const{
    return !locked;
}

template <typename First, typename Second> 
void LockableMap<First, Second>:: lock(){
    locked = LOCKED;
}

template <typename First, typename Second> 
void LockableMap<First, Second>::unlock(){
    locked = UNLOCKED;
}

template <typename First, typename Second> 
int LockableMap<First, Second>::getSize(){
    return storage.size();
}

template class LockableMap<string, Ingredient*>;