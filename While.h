//
// Created by gil on 20/12/18.
//

#ifndef EX3_WHILE_H
#define EX3_WHILE_H


#include "Command.h"

class While : public Command {
public:
    int execute(vector<string> vector1) override;

};


#endif //EX3_WHILE_H
