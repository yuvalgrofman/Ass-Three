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

        int maxFds;

        fd_set fdSet;
        struct timeval timeval;

    public:
        static const int TIMEOUT_SECONDS = 60;

        ServerSocket(int port = 5555);
        bool hasTimedOut();
        SocketIO* accept();
        void close();

};

#endif //ASS_THREE_SERVERSOCKET_H
