//
// Created by meir on 22/12/18.
//

#include "DataBase.h"

using namespace std;


DataBase* DataBase :: instance = nullptr;

DataBase *DataBase::getInstance() {
    if(!instance) {
        instance = new DataBase;
    }
    return instance;
}


// set one variable with its path.
void DataBase:: setStringsForPath(string variable, string path) {
    this->varPath[variable] = path;

}
// set one variable with its value.
void DataBase:: setDoubleForVariable(string variable, double value) {
    this->strDoubleMap[variable] = value;
}

void DataBase::setXmlMap(string variable, double value) {
    this->xmlMap[variable] =value;
}

// the map getters.
 map<string, string> &DataBase::getVarPath()  {
    return varPath;
}

 map<string, double> &DataBase::getStrDoubleMap()  {
    return strDoubleMap;
}

map<string, double >& DataBase::getXmlMap() {
    return xmlMap;
}

DataBase::DataBase() {}






