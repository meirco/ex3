//
// Created by gil on 20/12/18.
//

#ifndef EX3_IF_H
#define EX3_IF_H


#include "Command.h"

class If : public Command {
public:
    int execute(vector<string> vector1) override;

};


#endif //EX3_IF_H
