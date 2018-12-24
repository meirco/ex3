//
// Created by meir on 22/12/18.
//

#include "DataBase.h"

using namespace std;


DataBase* DataBase :: instance = nullptr;

DataBase *DataBase::getInstance() {
    if(!instance) {
        instance = new DataBase;
    }
    return instance;
}


// set one variable with its path.
void DataBase:: setStringsForPath(string variable, string path) {
    this->varPath[variable] = path;

}
// set one variable with its value.
void DataBase:: setDoubleForVariable(string variable, double value) {
    this->strDoubleMap[variable] = value;
}

void DataBase::setXmlMap(string variable, double value) {
    this->xmlMap[variable] =value;
}

// the map getters.
 map<string, string> &DataBase::getVarPath()  {
    return varPath;
}

 map<string, double> &DataBase::getStrDoubleMap()  {
    return strDoubleMap;
}

map<string, double >& DataBase::getXmlMap() {
    return xmlMap;
}
/*
instrumentation/airspeed-indicator/indicated-speed-kt
instrumentation/altimeter/indicated-altitude-ft
instrumentation/altimeter/indicated-altitude-ft
instrumentation/attitude-indicator/indicated-pitch-deg
instrumentation/attitude-indicator/indicated-roll-deg
instrumentation/attitude-indicator/internal-pitch-deg
instrumentation/attitude-indicator/internal-roll-deg
instrumentation/encoder/indicated-altitude-ft
instrumentation/encoder/pressure-alt-ft
instrumentation/gps/indicated-altitude-ft
instrumentation/gps/indicated-ground-speed-kt
instrumentation/gps/indicated-vertical-speed
instrumentation/heading-indicator/indicated-heading-deg
instrumentation/magnetic-compass/indicated-heading-deg
instrumentation/slip-skid-ball/indicated-slip-skid
instrumentation/turn-indicator/indicated-turn-rate
instrumentation/vertical-speed-indicator/indicated-speed-fpm
controls/flight/aileron
controls/flight/elevator
controls/flight/rudder
controls/flight/flaps
controls/engines/engine/throttle
engines/engine/rpm
 * */
void DataBase::initializeXmlMap(){

    xmlMap.insert(pair<string, double >("instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    xmlMap.insert(pair<string, double >("instrumentation/altimeter/indicated-altitude-ft", 0));
    xmlMap.insert(pair<string, double >("instrumentation/altimeter/indicated-altitude-ft", 0));
    xmlMap.insert(pair<string, double >("instrumentation/attitude-indicator/indicated-pitch-deg", 0));
    xmlMap.insert(pair<string, double >("instrumentation/attitude-indicator/indicated-roll-deg", 0));
    xmlMap.insert(pair<string, double >("instrumentation/attitude-indicator/internal-pitch-deg", 0));
    xmlMap.insert(pair<string, double >("instrumentation/attitude-indicator/internal-roll-deg", 0));
    xmlMap.insert(pair<string, double >("instrumentation/encoder/indicated-altitude-ft", 0));
    xmlMap.insert(pair<string, double >("instrumentation/encoder/pressure-alt-ft", 0));
    xmlMap.insert(pair<string, double >("instrumentation/gps/indicated-altitude-ft", 0));
    xmlMap.insert(pair<string, double >("instrumentation/gps/indicated-ground-speed-kt", 0));
    xmlMap.insert(pair<string, double >("instrumentation/gps/indicated-vertical-speed", 0));
    xmlMap.insert(pair<string, double >("instrumentation/heading-indicator/indicated-heading-deg", 0));
    xmlMap.insert(pair<string, double >("instrumentation/magnetic-compass/indicated-heading-deg", 0));
    xmlMap.insert(pair<string, double >("instrumentation/slip-skid-ball/indicated-slip-skid", 0));
    xmlMap.insert(pair<string, double >("instrumentation/turn-indicator/indicated-turn-rate", 0));
    xmlMap.insert(pair<string, double >("instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0));
    xmlMap.insert(pair<string, double >("controls/flight/aileron", 0));
    xmlMap.insert(pair<string, double >("controls/flight/elevator", 0));
    xmlMap.insert(pair<string, double >("controls/flight/rudder", 0));
    xmlMap.insert(pair<string, double >("controls/flight/flaps", 0));
    xmlMap.insert(pair<string, double >("controls/engines/engine/throttle", 0));
    xmlMap.insert(pair<string, double >("engines/engine/rpm", 0));

//    int index = 0;
//    double value = xmlMap.at(lexeredList.at(index));
//    if(c != NULL) {
//        index += c->execute(lexeredList); // getting the specific line.
//
//    }



}



DataBase::DataBase() {}






