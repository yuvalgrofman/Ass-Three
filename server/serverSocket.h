#ifndef ASS_THREE_SERVERSOCKET_H
#define ASS_THREE_SERVERSOCKET_H

#include "IO/socketIO.h"

class ServerSocket {
    private:
        int port;
        int sock;

    public:
        ServerSocket(int port= 5555);
        SocketIO* accept();
        void close();

};

#endif //ASS_THREE_SERVERSOCKET_H
