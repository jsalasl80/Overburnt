#ifndef RECIPEREADER_H
#define RECIPEREADER_H

#include "Includes.h"
#include "Constants.h"
#include "CSVReader.h"
#include "Menu.h"
#include "Recipe.h"

using namespace std;

class RecipeReader : private CSVReader{
private:
    Menu *menu;
    void storeRecipe(string recipeName, float recipePrice, int approxPrepTime, int approxEatingTime, vector<string> ingredients, vector<int> ingredientsAmounts);

public:
    RecipeReader(Menu *_menu): CSVReader(RECIPES_CSV), menu(_menu){};

    void setUpMenu();

};

#endif //RECIPEREADER_H