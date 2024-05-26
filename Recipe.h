#ifndef RECIPE_H
#define RECIPE_H
#include "Includes.h"

using namespace std;

class Recipe{
private:
    string recipeName;
    float price;
    int approxPrepTime;
    int approxEatingTime;
    vector<string> ingredients;
    vector<int> ingredientsAmounts;

public:
    Recipe(string _recipeName, float _recipePrice, int _approxPrepTime, int _approxEatingTime, vector<string> _ingredients, vector<int> _ingredientsAmounts):
        recipeName(_recipeName),
        price(_recipePrice),
        approxPrepTime(_approxPrepTime),
        approxEatingTime(_approxEatingTime),
        ingredients (_ingredients),
        ingredientsAmounts (_ingredientsAmounts){};

    int getTotalIngredientsStored();

    //Extracts ingredients and amounts via index, to avoid having to return the entire vector
    string getIngredient(int index);
    int getIngredientAmount(int index);

    string getRecipeName();
    float getPrice();
    int getApproxEatingTime();
    int getApproxPrepTime();

    //TESTING PURPOSES
    string toString();
    string toStringIngredients();
};

#endif //RECIPE_H