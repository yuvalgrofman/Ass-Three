#ifndef ASS_THREE_SERVERSOCKET_H
#define ASS_THREE_SERVERSOCKET_H

#include "IO/socketIO.h"

/**
 * @brief The ServerSocket class
 *
 * This class is responsible for accepting new clients and creating new servers
 * with the appropriate instance of DefaultIO and userId.
 */
class ServerSocket {
    private:
        int port;
        int sock;

    public:
        ServerSocket(int port = 5555);
        SocketIO* accept();
        void close();

};

#endif //ASS_THREE_SERVERSOCKET_H
