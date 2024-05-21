#ifndef RECIPEREADER
#define RECIPEREADER

#include "Includes.h"
#include "Constants.h"
#include "CSVReader.h"
#include "Menu.h"
#include "Recipe.h"

using namespace std;

class RecipeReader : private CSVReader{
private:
    Menu *menu;
    void storeRecipe(string, float, int, int, vector<string>, vector<int>);

public:
    RecipeReader(Menu *_menu): CSVReader(RECIPES_CSV), menu(_menu){};

    void setUpMenu();

};


#endif