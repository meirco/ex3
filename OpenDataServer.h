//
// Created by gil on 19/12/18.
//

#ifndef EX3_OPENDATASERVER_H
#define EX3_OPENDATASERVER_H


#include <string>
#include <list>
#include "Command.h"

using namespace std;

class OpenDataServer: public Command {
public:
    void execute(list<string> list) override;

};


#endif //EX3_OPENDATASERVER_H
