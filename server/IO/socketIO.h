#ifndef ASS_THREE_SOCKETIO_H
#define ASS_THREE_SOCKETIO_H

#include "defaultIO.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class SocketIO : DefaultIO {
    private:

        int port;
        int sock;
        int client_sock;

        void connect();

    public:
        static const int BUFFER_SIZE = 4096;

        SocketIO(int port = 5555);

        virtual string read() const override;
        virtual void write(string str) const override;
        void close() const;
};


#endif //ASS_THREE_SOCKETIO_H