//
// Created by meir on 22/12/18.
//

#include "DataBase.h"







const map<string, double> &DataBase::getSymboleTable() const {
    return symboleTable;
}

const map<string, string> &DataBase::getVarPath() const {
    return varPath;
}


