//
// Created by meir on 19/12/18.
//

#include "LexParser.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include "OpenDataServer.h"
#include "Connect.h"
#include "Sleep.h"

using namespace std;





lexParser::lexParser(string str) {
    this->str = str;
    lexerList = start(str);
    parsering(lexerList);

}



vector<string> lexParser:: start (string str) {
    string correctStr, command;
    regex reg("[A-Za-z]+");
    regex reg2("[A-Za-z0-9]*");
    regex reg3("[/^(\\+|-|\\*|\\/|=|>|<|>=|<=|.|,| - |&|\\||%|!|\\^|\\(|\\))$/]");
    int i = 0;
    int j = 0;
    int count = 0;
    int length = str.length();

    // correctStr has the string from the beginning without nothing before.

    while (str.length() > 0) {
        i = 0;
        j = 1;
        for (j = 1; j < str.length(); j++, i++) {
            if (((regex_match(str.substr(0, 1), reg2) != 0) && (str.substr(0, 1) != " ") && (str.at(0) != ' '))
                || regex_match(str.substr(0, 1), reg3) != 0) {
                break;
            } else {
                str.erase(0, 1);
            }
        }
        while(str.at(0) == ' ') {
            str.erase(0, 1);
        }



        int index = 0;
        int l = 0;
        for (l = 0; l <= str.length(); ++l) {
            if ((str.at(l) == ' ')  || (l == str.length() - 1)) {
                if(l == str.length() - 1) {
                    lexerList.push_back(str);
                    str.erase(0, l+1);
                    break;
                }
                lexerList.push_back(str.substr(0, l));
//                index = l;
                str.erase(0, l);
                break;
            }
        }
    }
    return lexerList;
}


void lexParser:: parsering(vector<string> lexeredList) {
//    fillMap(commandMap);
    commandMap.insert(pair<string, Command*>("sleep", (Command*)new Sleep()));
//    commandMap.insert(pair<string, Command*>("openDataServer", (Command*)new OpenDataServer()));


    int index = 0;
    Command *c = commandMap.at(lexeredList.at(index));
    if(c != NULL) {
        index += c->execute(lexeredList); // getting the specific line.

    }



}


void lexParser::fillMap(map<string, Command*> strToCommand) {
    strToCommand.insert(pair<string, Command*>("sleep", (Command*)new Sleep()));
    cout<< "sleep2";


}
