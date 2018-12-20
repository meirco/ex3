//
// Created by meir on 19/12/18.
//

#ifndef EX3_LEXPARSER_H
#define EX3_LEXPARSER_H

#include <string>
#include <list>
#include <map>
#include <vector>
#include "Command.h"

using namespace std;


class lexParser {

public:
    string str;
    vector<string>lexerList;
    map<string, Command*> commandMap;




    lexParser(string str);

    vector<string> start(string str);

    void parsering(vector<string> list1);

    void fillMap(map<string, Command*> map1);

};


#endif //EX3_LEXPARSER_H
