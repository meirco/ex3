#include <iostream>
#include <list>
#include "fstream"
#include "map"
#include "LexParser.h"
#include "command.h"

using namespace std;

map<string, command> commandMap;
list<string> lexeredList;

int main() {

    string line, afterLex;
    ifstream myFile;
    myFile.open("test.txt");
    if(myFile.is_open()) {
        while(!myFile.eof()) {
            getline(myFile, line);
            lexParser *lexer1 = new lexParser(line);


        }
    }
    else {
        cout<< "Error opening file";
    }











    return 0;
}