#include "Accountant.h"
using namespace std;

Accountant::Accountant():
    FileWriter(REPORT_TXT),
    status(ACCOUNTING),
    totalExpenses(NONE_FLOAT),
    totalWinnings(NONE_FLOAT){}

void Accountant::updateWinnings(Recipe* recipe){
    std::unique_lock<mutex> ul(winningsMutex);
    cv.wait(ul, status == ACCOUNTING);
    int newWinnings = recipe -> getPrice();
    totalWinnings += newWinnings;
}

void Accountant::updateExpenses(Ingredient* ingredient){
    int newExpenses = ingredient -> getConsumedPortions() * ingredient -> getUnitaryCost();
    totalExpenses += newExpenses;
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