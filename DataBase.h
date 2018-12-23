//
// Created by meir on 22/12/18.
//

#ifndef EX3_DATABASE_H
#define EX3_DATABASE_H

#include <map>
#include <vector>

using namespace std;


class DataBase {
public:
    DataBase();

    const map<string, double> &getSymboleTable() const;

    const map<string, string> &getVarPath() const;

private:

    map<string, double >symboleTable;
    map<string, string>varPath;

};


#endif //EX3_DATABASE_H
