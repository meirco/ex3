//
// Created by meir on 24/12/18.
//

#include "ConditionParser.h"
#include "While.h"
#include "If.h"

int ConditionParser::execute(vector<string> vector1) {

    vector<string>:: iterator it; // iterator of the map line.

    int i, k = 0;
    string wholeCommand = " ";
    for (i = 0; i < vector1.size(); i++) {
        wholeCommand += vector1[i];
        wholeCommand += " ";
        if(vector1[i].find("$") != string::npos) { // $ is the sign '\n' - end line.
            commandLineVector.push_back(wholeCommand); // inserting into the vector the command line.
            k++;
            wholeCommand = " "; // erasing the string before filling it more time.
        }
    }

    //TODO function calling

    /**
     * check what the specific command that we get and send to it the map with the commands.
     */

    if(commandLineVector.at(0).find("while")) {
        While* w = new While();
        w->execute(commandLineVector);
    }


    else if(commandLineMap.begin()->second.find("if") == string::npos) {
        If* ifCommand = new If();
        ifCommand->execute(commandLineVector);

    }


}


