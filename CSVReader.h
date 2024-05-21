#ifndef CSVREADER
#define CSVREADER

#include "Includes.h"
#include "Constants.h"
using namespace std;

class CSVReader {
protected:
    FILE* file;

private:
    void readRecipeIngredients(vector<string>&, vector<int>&);

public:
    CSVReader(const char* filename) {
        file = fopen(filename, READ_MODE);
        if (!file) {
            cerr << "Failed to open file" << endl;
            exit(1);
        }
    }

    ~CSVReader() {
        if (file) {
            fclose(file);
        }
    }
    
    void skipLine();
    bool readInventory(string&, int&, float&);
    bool readRecipes(string&, float&, int&, int&, vector<string>&, vector<int>&);
};

#endif
