//
// Created by gil on 20/12/18.
//

#include <algorithm>
#include <iostream>
#include "Var.h"
#include "DataBase.h"
#include "ShuntingYard.h"

using namespace std;

int Var::execute(vector<string> vector1) {

    DataBase *dataBase = DataBase::getInstance();

    string copyPathFromVector = " ";

    // vector iterator
    vector<string>:: iterator it;

    string left = " ";
    string right = " ";



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
        // we found the '=' index in the vector.
        for (it = vector1.begin(); it != vector1.end(); it++) {
            if(*it == "=") {
                break;
            }
        }
        long equalIndex = it -vector1.begin(); // the '=' index.

        for (int i = 1; i < equalIndex ; i++) {
            left += vector1[i];
            left += " ";
        }

        for (int j = equalIndex + 1; j < vector1.size() ; j++) {
            right += vector1[j];
            right += " ";
        }

        cout<< "aaa";

//        dataBase->setDoubleForVariable(left, ShuntingYard(right));
    }




}
