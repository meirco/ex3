//
// Created by gil on 19/12/18.
//

//TODO - need to destroy the struct after the while's break
//TODO - need to get the vars from the xml.

//read the lines from the xml
//separate with "," byh the XML format
//save the read lines in a data base that we can pull by o(1).
//close the socket.

#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <mutex>
#include <thread>
#include "OpenDataServer.h"

using namespace std;

#define NUM_OF_ARGS 23

struct Args{
    int numOfTimesToReadDataPerSecond;
    int newsockfs;
};

void* ConnectServer(void* args) {
    int n;
    char buffer[1000], buffer2[1000];
    struct Args *args1 = (struct Args *) args;
    DataBase *dataBase = DataBase::getInstance();

    while (true) {

//        mtx.lock();

        bzero(buffer, 1000);
        n = read(args1->newsockfs, buffer, 999); //read line from simulator to socket.


        strcpy(buffer2 ,buffer); //backup for buffer.

        /* now we take the buffer, saperate to tokens and insert them to vector*/
        vector<double> lineArguments;
        char* copyString;
        copyString=strtok(buffer, ",");
        while (copyString != NULL) {
            lineArguments.push_back(stod(copyString));
            copyString = strtok(NULL, ",");
//            char* token = strtok(buffer, ",");
//            lineArguments.push_back(stod(token));
//
//            string(buffer).erase(0, pos + delimiter.length());
        }
        cout<<lineArguments.size()<<endl;




//        pch = strtok (buffer,",");
//        while (pch != NULL)
//        {
//
//            lineArguments.push_back(atof(pch));
//            pch = strtok (NULL, ",");
//        }
//        cout<< lineArguments.size()<< endl;
        char *str;

        for (int i = 0; i < NUM_OF_ARGS; ++i) { //max args = 23



            switch (i) {
                case 0:
                    str = strtok(buffer, ",");
                    dataBase->setXmlMap("instrumentation/airspeed-indicator/indicated-speed-kt", lineArguments.at(0));
                    break;
                case 1:
                    str = strtok(buffer, ",");
                    dataBase->setXmlMap("instrumentation/altimeter/indicated-altitude-ft",lineArguments.at(1));
                    str = strtok(NULL, ",");
                    break;
                case 2:
                    str = strtok(buffer, ",");
                    dataBase->setXmlMap("instrumentation/altimeter/indicated-altitude-ft",lineArguments.at(2));
                    str = strtok(NULL, ",");
                    break;
                case 3:
                    str = strtok(buffer, ",");
                    dataBase->setXmlMap("instrumentation/attitude-indicator/indicated-pitch-deg",lineArguments.at(3));
                    str = strtok(NULL, ",");
                    break;
                case 4:
                    str = strtok(buffer, ",");
                    dataBase->setXmlMap("instrumentation/attitude-indicator/indicated-roll-deg", lineArguments.at(4));
                    break;
                case 5:
                    dataBase->setXmlMap("instrumentation/attitude-indicator/internal-pitch-deg", atof(str));
                    break;
                case 6:
                    dataBase->setXmlMap("instrumentation/attitude-indicator/internal-roll-deg", atof(str));
                    break;
                case 7:
                    dataBase->setXmlMap("instrumentation/encoder/indicated-altitude-ft", atof(str));
                    break;
                case 8:
                    dataBase->setXmlMap("instrumentation/encoder/pressure-alt-ft", atof(str));
                    break;
                case 9:
                    dataBase->setXmlMap("instrumentation/gps/indicated-altitude-ft", atof(str));
                    break;
                case 10:
                    dataBase->setXmlMap("instrumentation/gps/indicated-ground-speed-kt", atof(str));
                    break;
                case 11:
                    dataBase->setXmlMap("instrumentation/gps/indicated-vertical-speed", atof(str));
                    break;
                case 12:
                    dataBase->setXmlMap("instrumentation/heading-indicator/indicated-heading-deg", atof(str));
                    break;
                case 13:
                    dataBase->setXmlMap("instrumentation/magnetic-compass/indicated-heading-deg", atof(str));
                    break;
                case 14:
                    dataBase->setXmlMap("instrumentation/slip-skid-ball/indicated-slip-skid", atof(str));
                    break;
                case 15:
                    dataBase->setXmlMap("instrumentation/turn-indicator/indicated-turn-rate", atof(str));
                    break;
                case 16:
                    dataBase->setXmlMap("instrumentation/vertical-speed-indicator/indicated-speed-fpm", atof(str));
                    break;
                case 17:
                    dataBase->setXmlMap("controls/flight/aileron", atof(str));
                    break;
                case 18:
                    dataBase->setXmlMap("controls/flight/elevator", atof(str));
                    break;
                case 19:
                    dataBase->setXmlMap("controls/flight/rudder", atof(str));
                    break;
                case 20:
                    dataBase->setXmlMap("controls/flight/flaps", atof(str));
                    break;
                case 21:
                    dataBase->setXmlMap("controls/engines/engine/throttle", atof(str));
                    break;
                case 22:
                    dataBase->setXmlMap("engines/engine/rpm", atof(str));
                    break;
            }
        }

        for(auto it = dataBase->getXmlMap().cbegin(); it != dataBase->getXmlMap().cend(); ++it)
        {
//            std::cout << it. << " " << it->second.first << " " << it->second.second << "\n";
            cout <<it->first<< it->second<<endl;
        }


        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer2);

        /* Write a response to the client */
        n = write(args1->newsockfs, "I got your message", 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

//        mtx.unlock();

        usleep(1 / (args1->numOfTimesToReadDataPerSecond)); // number of times to read the XML each second.
    }

    delete (args1);
    return nullptr;
}

int OpenDataServer::execute(vector<string> vector1) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = stoi(vector1[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    cout << "try to connect" << endl;
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
    cout << "Connected" << endl;
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    struct Args* args1 = new Args();
//    args1->portNumber = stoi(vector1[1]);
    args1->numOfTimesToReadDataPerSecond=stoi(vector1[2]);
    args1->newsockfs = newsockfd;
//    thread serverThread(ConnectServer, args1);
//    serverThread.detach();
    pthread_t trid; //Declare the thread.
    pthread_create(&trid, nullptr, ConnectServer, args1);
    pthread_join(trid, nullptr);

//    return vector1.size(); //num of elements to move the index at the parser's list.
}