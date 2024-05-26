#include "Recipe.h"

int Recipe::getTotalIngredientsStored(){
    return ingredients.size();
}

string Recipe::getIngredient(int index){
    return ingredients[index];
}

int Recipe::getIngredientAmount(int index){
    return ingredientsAmounts[index];
}

string Recipe::getRecipeName(){
    return recipeName;
}

float Recipe::getPrice(){
    return price;
}

int Recipe::getApproxEatingTime(){
    return approxEatingTime;
}

int Recipe::getApproxPrepTime(){
    return approxPrepTime;
}

string Recipe::toStringIngredients(){
    string message = "\n";
    for (int i = 0; i < static_cast<int>(ingredients.size()); ++i){
        message += ingredients[i] + ": " + to_string(ingredientsAmounts[i]) + " ";
    }
    return message;
}

string Recipe::toString(){
    return recipeName + " $" + to_string(price);
}