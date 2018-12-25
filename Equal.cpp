//
// Created by gil on 20/12/18.
//

#include <iostream>
#include "Equal.h"
#include "DataBase.h"
#include "ShuntingYard.h"
#include "DoubleFactory.h"

int Equal::execute(vector<string> vector1) {

    int flag = 0;

    // vector iterator
    vector<string>:: iterator it;

    DataBase* dataBase = DataBase::getInstance();

    ShuntingYard shuntingYard;

    DoubleFactory doubleFactory;

    string left = " ";
    string right = " ";

    // checking where is the '=' sign
    for (it = vector1.begin(); it != vector1.end(); it++) {
        if(*it == "=") {
            break;
        }
    }
    long equalIndex = it -vector1.begin(); // the '=' index.

    /**
     * arrange the string , the right and the left.
     */
    for (int i = 1; i < equalIndex ; i++) {
        left += vector1[i];
        left += " ";
    }

    for (int j = equalIndex + 1; j < vector1.size() ; j++) {
        right += vector1[j];
//            right += " ";
    }

    // making the right string 'double' string

    string strDoubleVar = doubleFactory.convertToDouble(right);

    if(strDoubleVar.at(0) == ' ') {
        if(strDoubleVar.at(1) == '-') {
            strDoubleVar.replace(strDoubleVar.find(' '), 1, "0");
        }
    }


    Expression* expression = shuntingYard.evaluate(strDoubleVar);
    double valueNew = expression->calculate();
    string var = vector1[0];

    delete expression;

    dataBase->setDoubleForVariable(var, valueNew);

    return valueNew; // maybe not needed.TODO check it.
}
