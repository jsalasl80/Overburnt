#ifndef FILEWRITER
#define FILEWRITER
#include "Includes.h"
#include "Constants.h"
using namespace std;

class FileWriter{
protected:
    string fileName;

public:
    FileWriter(string _fileName):
        fileName (CSV_DIRECTORY+_fileName){}

    void appendLine(string);
    void wipeAndRestartFile(string);
};
#endif
