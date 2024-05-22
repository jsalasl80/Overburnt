#include "Ingredient.h"
using namespace std;

Ingredient::Ingredient(string& _name, int _totalPortions, float _unitaryCost):
    name(_name),
    totalPortions(_totalPortions),
    unitaryCost(_unitaryCost),
    consumedPortions(NONE){} 

string Ingredient::toString(){
    return name + ": " + to_string(totalPortions);
}

void Ingredient::consumePortions(int consumedQuantity){
    totalPortions -= consumedQuantity;
    consumedPortions += consumedQuantity;
}

bool Ingredient::checkConsumability(int consumedQuantity){
    return totalPortions - consumedQuantity >= 0;
}

string Ingredient::getIngredientName(){
    return name;
}

int Ingredient::getConsumedPortions(){
    return consumedPortions;
}

float Ingredient::getUnitaryCost(){
    return unitaryCost;
}