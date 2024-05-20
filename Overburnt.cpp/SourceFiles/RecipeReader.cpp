#include "HeaderFiles/RecipeReader.h"

void RecipeReader::storeRecipe(string recipeName, float recipePrice, int approxPrepTime, int approxEatingTime, vector<string> ingredients, vector<int> ingredientsAmounts){
    Recipe *recipe = new Recipe(recipeName, recipePrice, approxPrepTime, approxEatingTime, ingredients, ingredientsAmounts);
    menu -> storeRecipe(recipe);
}

void RecipeReader::setUpMenu(){
    string recipeName;
    float recipePrice;
    int approxPrepTime;
    int approxEatingTime;
    vector<string> ingredients;
    vector<int> ingredientsAmounts;
    
    CSVReader::skipLine();
    while (CSVReader::readRecipes(recipeName, recipePrice, approxPrepTime, approxEatingTime, ingredients, ingredientsAmounts)){
        storeRecipe(recipeName, recipePrice, approxPrepTime, approxEatingTime, ingredients, ingredientsAmounts);
        printf("%s: %f, Prep: %d, Eat: %d\n", recipeName.c_str(), recipePrice, approxPrepTime, approxEatingTime);
    }
}