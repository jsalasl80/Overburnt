#ifndef CSVREADER_H
#define CSVREADER_H

#include "Includes.h"
#include "Constants.h"
using namespace std;

class CSVReader {
protected:
    FILE* CSVFile;

private:
    void readRecipeIngredients(vector<string>& recipeIngredients, vector<int>& ingredientsAmounts);

public:
    CSVReader(const char *filename);
    
    void skipLine();
    bool readInventory(string& ingredientName, int& amount, float& unitaryCost);
    bool readRecipes(string& recipeName, float& price, int& prepTime, int& eatTime, vector<string>& recipeIngredients, vector<int>& ingredientsAmounts);
    void normalizeIngredientName(string& ingredientName);
    void closeFile();
};

#endif //CSVREADER_H