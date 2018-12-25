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
#include "Print.h"
#include "Var.h"
#include "ConditionParser.h"
#include "DataBase.h"
#include "Equal.h"

using namespace std;





lexParser::lexParser(string str) {
    this->str = str;
    lexerList = start(str);
    parsering(lexerList);

}



vector<string> lexParser:: start (string str) {
    int s; // help us to get all the operators.

    string correctStr, command;
    regex reg("[A-Za-z]+");
    regex reg2("[A-Za-z0-9]*");
    regex reg3("[/^(\\+|\\-|-|\\*|\\/|}|{|=|>|<|>=|<=|==|.|,|-|&|\\||%|!|\\^|\\(|\\))$/]");
    regex reg4("[0-9]+");
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
                string aa = str;
                if(regex_match(aa.substr(0,1), reg3)) {
                    lexerList.push_back(str.substr(0,1));
                }
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
            // getting the operators.
            else if(regex_match(str.substr(l,1), reg3)) {

                // in case that the operator is in the beginning
                if(l == 0) {
                    // 2 operators at the beginning
                    if(regex_match(str.substr(l+1, 1), reg3)) {
                        lexerList.push_back(str.substr(0,2));
                        str.erase(0,2);
                        break;
                    }
                    else {
                        // one operator
                        lexerList.push_back(str.substr(0,1));
                        str.erase(0,1);
                        break;
                    }
                }


                // if their is 2 operators.
                if(regex_match(str.substr(l+1,1), reg3)) {
                    l++;
                    if(str.at(l-2) != ' ') {
                        lexerList.push_back(str.substr(0, l-1)); // printing the string before the operator.
                        str.erase(0, l-1);
                        lexerList.push_back(str.substr(0,2));
                        str.erase(0, 2);
                        break;
                    }
                }
                // if their is 1 operator. //TODO check if their is no whitespace after the operators.
                else if(str.at(l-1) != ' ') {
                    lexerList.push_back(str.substr(0, l)); // printing the string before the operator.
                    str.erase(0, l);
                    lexerList.push_back(str.substr(0,1));
                    str.erase(0, 1);
                    break;
                }
            }
        }
    }
    return lexerList;
}


void lexParser:: parsering(vector<string> lexeredList) {

    int index = 0;
    DataBase* dataBase = DataBase::getInstance();

//    commandMap.insert(pair<string, Command*>("sleep", (Command*)new Sleep()));
//    commandMap.insert(pair<string, Command*>("while", (Command*)new ConditionParser()));
//    commandMap.insert(pair<string, Command*>("print", (Command*)new Print()));
    commandMap.insert(pair<string, Command*>("var", (Command*)new Var()));


//    commandMap.insert(pair<string, Command*>("openDataServer", (Command*)new OpenDataServer()));
    

    // when we need to go to equal command.
    if(dataBase->getStrDoubleMap().find(lexeredList[0]) != dataBase->getStrDoubleMap().end()) {
        commandMap.insert(pair<string, Command*>("equal", (Command*)new Equal()));

    }




    Command *c = commandMap.at(commandMap.begin()->first);
    if(c != NULL) {
        index += c->execute(lexeredList); // getting the specific line.

    }



}
