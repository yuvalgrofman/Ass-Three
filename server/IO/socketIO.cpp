#include "socketIO.h"

SocketIO::SocketIO(int port) {
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

void SocketIO::accept() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);

    this->client_sock = ::accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }
}

string SocketIO::read() const {
    char buffer[BUFFER_SIZE];
    int read_bytes = recv(client_sock, buffer, BUFFER_SIZE, 0);
    if (read_bytes == 0) {
        // connection closed
        return "";
    } else if (read_bytes < 0) {
        perror("error receiving flower point");
    }
    return string(buffer);
}

void SocketIO::write(string str) const {
    int sent_bytes = send(client_sock, str.c_str(), str.length(), 0);
    if (sent_bytes < 0) {
        perror("error sending flower point");
    }
}

void SocketIO::close() const {
    ::close(sock);
}
