#include "CSVReader.h"
using namespace std;

void CSVReader::skipLine(){
    fscanf(file, "%*[^\n]\n");
    //*[^\n] indicates to not store anything except new line anywhere.
}

bool CSVReader::readInventory(string& ingredientName, int& amount, float& unitaryCost){
    char buffer[128]; // Buffer to hold the string value from the file

    // Read one line from the CSV file
    if (fscanf(file, " %127[^,],%d,%f", buffer, &amount, &unitaryCost) > 0) {
        ingredientName = buffer;
        return true;
    }
    
    return false;
}

bool CSVReader::readRecipes(string& recipeName, float& price, int& prepTime, int& eatTime, vector<string>& recipeIngredients, vector<int>& ingredientAmounts){
    char recipeNameBuffer[256];
    
    //Read name, price, preptime and eattime first. Note that fscanf() returns amount of stuff it successfully stored in directions
    if(fscanf(file, " %255[^,],%f,%d,%d", recipeNameBuffer, &price, &prepTime, &eatTime) == RECIPE_MAIN_ELEMENTS){
        recipeName = recipeNameBuffer;
        
        readRecipeIngredients(recipeIngredients, ingredientAmounts);

        //Skips end of line
        fscanf(file, "%*[^\n]");
        return true;
    }
    
    return false;
}

void CSVReader::readRecipeIngredients(vector<string>& recipeIngredients, vector<int>& ingredientAmounts){
    recipeIngredients.clear();
    ingredientAmounts.clear();
    
    char ingredient[128]; //Buffer to hold ingredient names
    int amount;

    //While the following stuff i read is a pair composed by ingredient and amount
    while (fscanf(file, ",%128[^,],%d", ingredient, &amount) == INGREDIENT_AND_AMOUNT_PAIR){
        recipeIngredients.push_back(ingredient);
        ingredientAmounts.push_back(amount);
    }
}