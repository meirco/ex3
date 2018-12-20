//
// Created by gil on 18/12/18.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

#include <list>
#include <string>

using namespace std;

class Command {
public:
    virtual void execute(list<string> list) =0;
};

//openDataServer
//connect
//var
//bind there is a note at the targil instructions page 5 at the end.
// =
//while
//if
//print
//sleep

// git clone https://github.com/meirco/ex3.git

#endif //EX3_COMMAND_H