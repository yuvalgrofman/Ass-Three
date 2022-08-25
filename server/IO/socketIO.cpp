#include "socketIO.h"

SocketIO::SocketIO(int client_sock) : client_sock(client_sock) {}

string SocketIO::read() const {
    char buffer[BUFFER_SIZE];
    int read_bytes = recv(client_sock, buffer, BUFFER_SIZE, 0);
    if (read_bytes == 0) {
        // connection closed
        return "";
    } else if (read_bytes < 0) {
        perror("error receiving flower point");
    }

    string s = string(buffer);
    return s.substr(0, s.find(END_OF_MESSAGE));
}

void SocketIO::write(string str) const {
    str += END_OF_MESSAGE;
    int sent_bytes = send(client_sock, str.c_str(), str.length(), 0);
    if (sent_bytes < 0) {
        perror("error sending flower point");
    }
}

void SocketIO::close() const {
    ::close(client_sock);
}
