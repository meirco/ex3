//
// Created by meir on 24/12/18.
//

#include <iostream>
#include "DoubleFactory.h"

DoubleFactory::DoubleFactory( string str) : str(str) {

    convertToDouble(str); // we have a string with double only and operators.






}


double DoubleFactory :: convertToDouble(string str) {
    vector<string> vec;

    string check = " ";
    string afterCheck = " ";


    regex reg3("[/^(\\+|\\-|-|\\*|\\/|||||,|-|||!|||))$/]");
    int i, j=0;
    for (i = 0; i < str.length() ; i++) {
        if(regex_match(str.substr(i, 1), reg3)) {
            check = str.substr(j, i - j);
            if (dataBase->getStrDoubleMap().find(check) != dataBase->getStrDoubleMap().end()) {
                int getValue = dataBase->getStrDoubleMap()[check];
                afterCheck += std::to_string(getValue);
                afterCheck += str.substr(i, 1);
            }
            else if (dataBase->getStrDoubleMap().find(check) == dataBase->getStrDoubleMap().end()) {
                afterCheck += check;
                afterCheck += str.substr(i, 1);
            }
            j = i+1;
        }
    }
    afterCheck += str.substr(j, i-j);
//    vec.push_back(str.substr(j, i - j));// we have all the variables in vector.

cout << afterCheck;



}
