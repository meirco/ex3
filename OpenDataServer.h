//
// Created by gil on 19/12/18.
//

#ifndef EX3_OPENDATASERVER_H
#define EX3_OPENDATASERVER_H



#include "Command.h"
#include "DataBase.h"

using namespace std;

class OpenDataServer: public Command {
public:
    int execute(vector<string> vector1);
//    static void* ConnectServer(void* args);
    DataBase* dataBase = dataBase->getInstance();

};


#endif //EX3_OPENDATASERVER_H
