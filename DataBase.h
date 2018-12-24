//
// Created by meir on 22/12/18.
//

#ifndef EX3_DATABASE_H
#define EX3_DATABASE_H

#include <map>
#include <vector>

using namespace std;


class DataBase {

private:

    map<string, string>varPath;

    map<string, double>strDoubleMap;

    map<string,double > xmlMap;


public:
    DataBase();

    static DataBase *instance;

    static DataBase *getInstance();

    void setStringsForPath(string variable, string path);

    void setDoubleForVariable(string variable, double value);

    void setXmlMap(string variable, double value);

    void initializeXmlMap();

    map<string, string> &getVarPath() ;

     map<string, double> &getStrDoubleMap() ;

    map<string, double > &getXmlMap();




};


#endif //EX3_DATABASE_H
