#ifndef FILEWRITER_H
#define FILEWRITER_H
#include "Includes.h"
#include "Constants.h"
using namespace std;

class FileWriter{
protected:
    string fileName;
    fstream file;

public:
    FileWriter(string);

    void appendLine(string);
    void wipeAndRestartFile(string);
};
#endif
