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

struct Args{
    int numOfTimesToReadDataPerSecond;
    int newsockfs;
};



void* ConnectServer(void* args){
    int  n;
    char buffer[1000];
    struct Args* args1 = (struct Args*) args;

    while(true) {

//        mtx.lock();

        bzero(buffer, 1000);
        n = read(args1->newsockfs, buffer, 999);


        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);


        /* Write a response to the client */
        n = write(args1->newsockfs, "I got your message", 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

//        mtx.unlock();

        usleep(1/(args1->numOfTimesToReadDataPerSecond)); // number of times to read the XML each second.
    }

    delete(args1);
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
    args1->numOfTimesToReadDataPerSecond=stoi(vector1[2]);
    args1->newsockfs = newsockfd;
//    pthread_t trid; //Declare the thread.
//    pthread_create(&trid, nullptr, ConnectServer, args1);
//    pthread_join(trid, nullptr);
    thread serverThred(ConnectServer, args1);
    serverThred.detach();

    return vector1.size(); //num of elements to move the index at the parser's list.
}