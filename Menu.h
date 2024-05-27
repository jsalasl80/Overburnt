#ifndef MENU
#define MENU
#include "Includes.h"
#include "Constants.h"
#include "Recipe.h"

class Menu{
private:
    vector<Recipe*> menu;
    int menuSize;
public:
    Menu():menuSize(NONE){};
    ~Menu(){
        for(int i = 0; i < menuSize; i++){
            delete menu[i];
        }
    };

    void storeRecipe(Recipe*);
    Recipe* getRecipe(int);
    int getMenuSize();
};

#endif