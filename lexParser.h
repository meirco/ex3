//
// Created by meir on 19/12/18.
//

#ifndef EX3_LEXPARSER_H
#define EX3_LEXPARSER_H

#include <string>
#include <list>
#include <map>
#include "command.h"

using namespace std;


class lexParser {

public:
    string str;
    list<string>lexerList;
    map<string, command> parserMap;




    lexParser(string str);

    list<string> start(string str);

    void parsering(list<string> list1);

    void fillMap(map<string, command> map1);

};


#endif //EX3_LEXPARSER_H
