#ifndef ASS_TWO_SERVER_H
#define ASS_TWO_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "classifier/flower/flower.h"
#include "classifier/classifier.h"
#include "classifier/distances/euclideanDistance.h"

class Server {

    private:
        int server_port;
        int server_socket;
        int client_sock;
        int commOverFlag;
        DataSpace* dataSpace;

    public:
        static const int BUFFER_SIZE = 4096;
        Server(int port);
        void connect();

        FlowerPoint& receiveFlowerPoint();
        void sendClassification(FlowerPoint& flower, int k, Distance* distance);
        void closeServer() const;
        int isCommOver();
        ~Server();
};

#endif //ASS_TWO_SERVER_H
