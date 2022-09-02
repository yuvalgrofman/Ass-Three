#include "serverSocket.h"
#include <string.h>

ServerSocket::ServerSocket(int port) {
    this->port = port;

    this->sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("error creating socket");
    }

    int enableBind = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enableBind, sizeof(int)) < 0){
        perror("setsockopt(SO_REUSEADDR) failed");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(this->port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }

    this->maxFds = sock;

    FD_ZERO(&fdSet);
    FD_SET(sock, &fdSet);

    this->timeval.tv_sec = TIMEOUT_SECONDS;
    this->timeval.tv_usec = 0;
}

bool ServerSocket::hasTimedOut() {
    return select(maxFds + 1, &fdSet, NULL, NULL, &timeval) == 0;
}

SocketIO* ServerSocket::accept() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);

    int client_sock = ::accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }

    this->timeval.tv_sec = TIMEOUT_SECONDS;
    this->timeval.tv_usec = 0;
    return new SocketIO(client_sock);
}

void ServerSocket::close() {
    ::close(sock);
}