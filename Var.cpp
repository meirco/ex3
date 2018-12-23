//
// Created by gil on 20/12/18.
//

#include <algorithm>
#include <iostream>
#include "Var.h"
#include "DataBase.h"

using namespace std;

int Var::execute(vector<string> vector1) {

    DataBase *dataBase = DataBase::getInstance();

    string copyPathFromVector = " ";

    // vector iterator
    vector<string>:: iterator it;

    // if we found the "bind" str in the vector.
    if(find(vector1.begin(), vector1.end(), bindStr) != vector1.end()) {
        for (it = vector1.begin(); it != vector1.end(); it++) {
            if(*it == "bind") {
                break;
            }
        }
        it++; // go over from the "bind" and start to copy the path.
//        long indexFromBind = std::distance(vector1.begin(), it);
        long indexFromBind = it -vector1.begin(); // TODO this or the above one

        int i;
        // copy the path from the vector to one string
        for (i = 0; i < vector1.size()- indexFromBind  ; i++) {
            copyPathFromVector += it[i];
        }



        // insert the 2 strings of the "var" command into a map and insert 0 to the variable in the second map.
        dataBase->setStringsForPath(vector1[1], copyPathFromVector);
        dataBase->setDoubleForVariable(vector1[1], 0);

    }

    else {

        cout << "aaa";
    }




}
