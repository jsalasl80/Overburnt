#include "FileWriter.h"

FileWriter::FileWriter(string _fileName):
    fileName (CSV_DIRECTORY+_fileName){}

void FileWriter::appendLine(string line){
    file.open(fileName, ios::app);
    if(file.is_open()){
        file << line;
        file.close();
    }
}

void FileWriter::wipeAndRestartFile(string openingLine){
    file.open(fileName, ios::trunc | ios::out | ios::in);
    if(file.is_open()){
        file << openingLine;
        file.close();
    }
}

