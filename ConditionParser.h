//
// Created by meir on 24/12/18.
//

#ifndef EX3_CONDITIONPARSER_H
#define EX3_CONDITIONPARSER_H


#include <map>
#include "Command.h"

class ConditionParser : public Command {
public:

    map<int, string> commandLineMap;

    vector<string> commandLineVector;

    int execute(vector<string> vector1) override;

};


#endif //EX3_CONDITIONPARSER_H
