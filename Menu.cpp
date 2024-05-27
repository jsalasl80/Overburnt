#include "Menu.h"

void Menu::storeRecipe(Recipe* recipe){
    menu.push_back(recipe);
    ++menuSize;
}

Recipe* Menu::getRecipe(int index){
    return menu[index];
}

int Menu::getMenuSize(){
    return menuSize;
}
