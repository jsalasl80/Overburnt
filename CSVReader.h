#ifndef CSVREADER_H
#define CSVREADER_H

#include "Includes.h"
#include "Constants.h"
using namespace std;

class CSVReader {
protected:
    FILE* CSVFile;

private:
    void readRecipeIngredients(vector<string>&, vector<int>&);

public:
    CSVReader(const char*);
    
    void skipLine();
    bool readInventory(string&, int&, float&);
    bool readRecipes(string&, float&, int&, int&, vector<string>&, vector<int>&);
    void normalizeIngredientName(string&);
    void closeFile();
};

#endif
