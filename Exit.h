//
// Created by gil on 26/12/18.
//

#ifndef EX3_EXIT_H
#define EX3_EXIT_H


#include "Command.h"
#include "DataBase.h"

class Exit : public Command{
    DataBase* dataBase = DataBase ::getInstance();

};


#endif //EX3_EXIT_H
