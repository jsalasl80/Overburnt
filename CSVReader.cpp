#include "CSVReader.h"
using namespace std;

CSVReader::CSVReader(const char* filename) {
    cerr << "Attempting to open file: " << filename << endl;
    CSVFile = fopen(filename, READ_MODE);
    if (!CSVFile) {
        cerr << "Failed to open file: " << filename << endl;
        exit(1);
    }
}

void CSVReader::skipLine(){
    fscanf(CSVFile, "%*[^\n]\n");
    //*[^\n] indicates to not store anything except new line anywhere.
}

bool CSVReader::readInventory(string& ingredientName, int& amount, float& unitaryCost){
    char buffer[128]; // Buffer to hold the string value from the file

    // Read one line from the CSV file
    if (fscanf(CSVFile, " %127[^,],%d,%f", buffer, &amount, &unitaryCost) > 0) {
        ingredientName = buffer;
        normalizeIngredientName(ingredientName);
        return true;
    }
    
    return false;
}

bool CSVReader::readRecipes(string& recipeName, float& price, int& prepTime, int& eatTime, vector<string>& recipeIngredients, vector<int>& ingredientAmounts){
    char recipeNameBuffer[256];
    
    //Read name, price, preptime and eattime first. Note that fscanf() returns amount of stuff it successfully stored in directions
    if(fscanf(CSVFile, " %255[^,],%f,%d,%d", recipeNameBuffer, &price, &prepTime, &eatTime) == RECIPE_MAIN_ELEMENTS){
        recipeName = recipeNameBuffer;
        
        readRecipeIngredients(recipeIngredients, ingredientAmounts);

        //Skips end of line
        fscanf(CSVFile, "%*[^\n]");
        return true;
    }
    
    return false;
}

void CSVReader::readRecipeIngredients(vector<string>& recipeIngredients, vector<int>& ingredientAmounts){
    recipeIngredients.clear();
    ingredientAmounts.clear();
    
    char ingredient[128]; //Buffer to hold ingredient names
    int amount;
    string ingredientName;

    //While the following stuff i read is a pair composed by ingredient and amount
    while (fscanf(CSVFile, ",%128[^,],%d", ingredient, &amount) == INGREDIENT_AND_AMOUNT_PAIR){
        ingredientName = ingredient;
        normalizeIngredientName(ingredientName);
        recipeIngredients.push_back(ingredientName);
        ingredientAmounts.push_back(amount);
    }
}

void CSVReader::normalizeIngredientName(string& ingredientName){
    transform(ingredientName.begin(), ingredientName.end(), ingredientName.begin(), ::toupper);
}

void CSVReader::closeFile(){
    if (CSVFile) {
        fclose(CSVFile);
    }
}