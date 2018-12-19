//
// Created by gil on 19/12/18.
//

#ifndef EX3_OPENDATASERVER_H
#define EX3_OPENDATASERVER_H


#include "Command.h"

class OpenDataServer: public Command {
public:
    void execute(list<string> list) override;

};


#endif //EX3_OPENDATASERVER_H
