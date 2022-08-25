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
#include <algorithm>

class SocketIO : public DefaultIO {
    private:
        int client_sock;

    public:
        static const int BUFFER_SIZE = 4096;
        static const char END_OF_MESSAGE = ';';

        SocketIO(int client_sock);

        virtual string read() const override;
        virtual void write(string str) const override;
        void close() const override;
};


#endif //ASS_THREE_SOCKETIO_H