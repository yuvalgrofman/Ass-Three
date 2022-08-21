#ifndef ASS_TWO_SERVER_HANDLER_H
#define ASS_TWO_SERVER_HANDLER_H

#include "server.h"

class Server_handler {

    private:
        Server* server;

    public:
        Server_handler(int port = 5555);
        void connect();
        void run();
        void close();
        ~Server_handler();
};

#endif //ASS_TWO_SERVER_HANDLER_H
