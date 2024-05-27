#include "Accountant.h"
using namespace std;

Accountant::Accountant():
    FileWriter(REPORT_TXT),
    status(ACCOUNTING),
    totalExpenses(NONE_FLOAT),
    totalWinnings(NONE_FLOAT){}

void Accountant::updateWinnings(Recipe* recipe){
    std::unique_lock<mutex> ul(winningsMutex);
    //Only if accountant is reporting do we have to wait for it to stop
    //Otherwise it gets blocked here since it needs a notify to work
    if (status == REPORTING){
        cv.wait(ul, [this](){
            return status == ACCOUNTING;
        });
    }
    
    float newWinnings = recipe -> getPrice();
    totalWinnings += newWinnings;
    printf("New winnings: %f, Current winnings: %f\n", newWinnings, totalWinnings);
}

void Accountant::updateExpenses(Ingredient* ingredient, int amountUsed){
    std::unique_lock<mutex> ul(winningsMutex);
    int newExpenses = amountUsed * (ingredient -> getUnitaryCost());
    totalExpenses += newExpenses;
    printf("Total expenses %f\n", totalExpenses);
}

void Accountant::setAsReporting(){
    status = REPORTING;
}

void Accountant::reportWinnings(){
    std::lock_guard<mutex> lg(winningsMutex);

    float currentWinnings = totalWinnings - totalExpenses;
    string currentWinningsMessage = "\nCurrent winnings: $" + to_string(currentWinnings);
    FileWriter::appendLine(currentWinningsMessage);
    status = ACCOUNTING;

    cv.notify_one();
}
float Accountant::getTotalExpenses(){
    return totalExpenses;
}
float Accountant::getTotalWinnings(){
    return totalWinnings;
}