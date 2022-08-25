#ifndef ASS_THREE_SOCKETIO_H
#define ASS_THREE_SOCKETIO_H

#include "defaultIO.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <algorithm>

/**
 * @brief The SocketIO class
 *
 * This class is Responsible for communicating with the client via a socket.
 * It uses the TCP communication protocol.
 * It is an IO class, and thus it inherits from the DefaultIO class.
 */
class SocketIO : public DefaultIO {
    private:
        int client_sock;

    public:
        // const values for the socket communication.
        static const int BUFFER_SIZE = 4096;
        static const char END_OF_MESSAGE = ';';

        /**
         * Constructor.
         * @param client_sock - the socket of the client.
         */
        SocketIO(int client_sock);

        virtual string read() const override;
        virtual void write(string str) const override;
        void close() const override;
};


#endif //ASS_THREE_SOCKETIO_H