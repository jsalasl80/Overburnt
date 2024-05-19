#ifndef INGREDIENT
#define INGREDIENT
#include "Includes.h"
#include "Constants.h"
using namespace std;

class Ingredient{
    private:
        string name;
        int totalPortions;
        int consumedPortions;
        float unitaryCost;

    public:
        Ingredient(string _name, int _totalPortions, float _unitaryCost):
                name(_name),
                totalPortions(_totalPortions),
                unitaryCost(_unitaryCost),
                consumedPortions(NONE){} 
        string toString();

        void consumePortions(int);
        bool checkConsumability(int);

        string getIngredientName();
        int getConsumedPortions();
        float getUnitaryCost();
};
#endif