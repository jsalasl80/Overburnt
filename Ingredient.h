#ifndef INGREDIENT_H
#define INGREDIENT_H

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
    Ingredient(string&, int, float); 
    string toString();

    void consumePortions(int);
    bool checkConsumability(int);

    string getIngredientName();
    int getConsumedPortions();
    float getUnitaryCost();
};
#endif