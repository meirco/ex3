//
// Created by gil on 20/12/18.
//

#ifndef EX3_WHILE_H
#define EX3_WHILE_H


#include "Command.h"
#include <map>

class While : public Command {
public:
    int execute(map<int, string> map1 ) ;

};


#endif //EX3_WHILE_H
