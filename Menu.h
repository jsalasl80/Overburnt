#ifndef MENU_H
#define MENU_H
#include "Includes.h"
#include "Constants.h"
#include "Recipe.h"

class Menu{
private:
    vector<Recipe*> menu;
public:
    Menu(){};
    ~Menu(){
        for(int i = 0; i < menu.size(); i++){
            delete menu[i];
        }
    };

    void storeRecipe(Recipe* recipe);
    Recipe* getRecipe(int index);
    int getMenuSize();
};

#endif //MENU_H