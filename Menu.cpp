#include "Menu.h"

void Menu::storeRecipe(Recipe* recipe){
    menu.push_back(recipe);
}

Recipe* Menu::getRecipe(int index){
    return menu[index];
}
int Menu::getMenuSize(){
    return menu.size();
}