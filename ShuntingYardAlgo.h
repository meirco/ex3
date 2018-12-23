//
// Created by Gil on 18/12/18.
//

#include <map>
#include "Expression.h"
#include "stack"

using namespace std;

#ifndef UNTITLED8_SHUNTINGYARD_H
#define UNTITLED8_SHUNTINGYARD_H

class ShuntingYard {
    map<char, int> precedences;
public:

    ShuntingYard();
    void initializeMap();

    int precedence(char operation);

    virtual Expression *createExpression(string tokens);
    Expression* applyOp(Expression* val1,Expression*  val2,char operation);
};

#endif //EX3_SHUNTINGYARDALGO_H
