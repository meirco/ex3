//
// Created by gil on 19/12/18.
//

//struct
//execute- get the list<string>
//open the server and the socket -- bind, listen, accept
//read the lines from the xml
//saperate with "," byh the XML format
//save the read lines in a data base that we can pull by o(1).


#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>

#include "OpenDataServer.h"

using namespace std;

struct ArgsStruct
{
    list<string> listOfArgs;
    int numOfArgs;
};

void* openServer(void* args){

    struct ArgsStruct* argsStruct = (struct ArgsStruct*) args;

//    ArgsStruct * argsStruct = new ArgsStruct();
//    argsStruct.listOfArgs = list1;
//    argsStruct.numOfArgs = argc;

    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    //sockfd = socket(domain, type, protocol)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5001;

    serv_addr.sin_family = AF_INET; //domain: AF_INET (IPv4 protocol)
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
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    bzero(buffer,256);
    n = read( newsockfd,buffer,255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Here is the message: %s\n",buffer);

    /* Write a response to the client */
    n = write(newsockfd,"I got your message",18);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

}

void OpenDataServer::execute(list<string> list1) {
    struct ArgsStruct* argsStruct = new ArgsStruct();
    argsStruct->listOfArgs =list1;
    argsStruct->numOfArgs = list1.size();
    pthread_t trid;
    pthread_create(&trid, nullptr, openServer, argsStruct);
}