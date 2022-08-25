#ifndef ASS_TWO_SERVER_HANDLER_H
#define ASS_TWO_SERVER_HANDLER_H

#include "server/IO/socketIO.h"

int getNewPort() {
    struct sockaddr_in sin;
    int sock, port = 5555;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        return -1;
    }

    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = 0;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_family = AF_INET;

    if (bind(socket, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)) == -1) {
        if (errno == EADDRINUSE)
            printf("Port in use");
        return -1;
    }

}

class Server_handler {

    private:
        SocketIO* io;

    public:
        Server_handler(SocketIO* io);
        void run();
        void close();
        ~Server_handler();
};

#endif //ASS_TWO_SERVER_HANDLER_H
