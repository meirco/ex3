//
// Created by gil on 20/12/18.
//

#include <unistd.h>
#include <iostream>
#include "Sleep.h"

int Sleep::execute(vector<string> vector1) {
    sleep(stoi(vector1.at(1)));
    int count = vector1.size();
    cout << "sleep" + count;
    return count;
}
