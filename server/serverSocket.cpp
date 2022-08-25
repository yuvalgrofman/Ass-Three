#include "serverSocket.h"

ServerSocket::ServerSocket(int port) {
    this->port = port;

    this->sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("error creating socket");
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
}

SocketIO* ServerSocket::accept() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);

    int client_sock = ::accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }

    return new SocketIO(client_sock);
}

void ServerSocket::close() {
    ::close(sock);
}