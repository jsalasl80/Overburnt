#ifndef RECIPE
#define RECIPE
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
    string toStringIngredients();

    //Both of the following take indexes as parameters for the purpose of extracting them and 
    string getIngredient(int);
    int getIngredientAmount(int);

    string getRecipeName();
    float getPrice();
    int getApproxEatingTime();
    int getApproxPrepTime();
    vector<string> getAllIngredients();
    vector<int> getAllIngredientsAmounts();
    string toString();

};

#endif