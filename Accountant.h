#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "Includes.h"
#include "Constants.h"
#include "FileWriter.h"
#include "Ingredient.h"
#include "Recipe.h"
using namespace std;

class Accountant : public FileWriter{
private:
    std::condition_variable cv;
    mutex winningsMutex;
    //Note: since the inventory manager is the one that calls accountant
    //      to update the expenses, it doesn't need a mutex. If the inventory manager is reporting
    //      then the accountant is reporting too. No conflict should happen over there.

    bool status; //for condition variable: reporting and accounting
    float totalExpenses;
    float totalWinnings;

public:
    Accountant();

    void updateExpenses(Ingredient* ingredient, int amountUsed);
    void updateWinnings(Recipe* recipe);

    void setAsReporting();
    void reportWinnings();
};

#endif //ACCOUNTANT_H