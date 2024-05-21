#include "HeaderFiles/FileWriter.h"

void FileWriter::appendLine(string line){
    fstream file;
    file.open(fileName, ios::app);

    if(file.is_open()){
        file << line;
        file.close();
    }
}

void FileWriter::wipeAndRestartFile(string openingLine){
    fstream file;
    file.open(fileName, ios::trunc | ios::out | ios::in);
    if(file.is_open()){
        file << openingLine;
        file.close();
    }
}

