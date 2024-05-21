#include "Ingredient.h"
#include "Includes.h"
using namespace std;

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