//
// Created by meir on 24/12/18.
//

#include "ConditionParser.h"

int ConditionParser::execute(vector<string> vector1) {

    map<int, string>:: iterator it; // iterator of the map line.

    int i, k = 0;
    string wholeCommand = " ";
    for (i = 0; i < vector1.size(); i++) {
        wholeCommand += vector1[i];
        wholeCommand += " ";
        if(vector1[i].find("$") != string::npos) { // $ is the sign '\n' - end line.
            commandLineMap[k] = wholeCommand; // inserting into the map the command line.
            k++;
            wholeCommand = " "; // erasing the string before filling it more time.
        }
    }

}
