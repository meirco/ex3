//
// Created by gil on 20/12/18.
//

#ifndef EX3_EQUAL_H
#define EX3_EQUAL_H


#include "Command.h"

class Equal : public Command {
public:
    int execute(vector<string> vector1) override;

};


#endif //EX3_EQUAL_H
