#include "socketIO.h"

SocketIO::SocketIO(int client_sock) : client_sock(client_sock) {}

string SocketIO::read() const {
    char buffer[BUFFER_SIZE] = {0};
    int read_bytes = recv(client_sock, buffer, BUFFER_SIZE, 0);
    if (read_bytes == 0) {
        // connection closed
        return "";
    } else if (read_bytes < 0) {
        perror("error receiving message from client.\n");
    }

    buffer[BUFFER_SIZE - 1] = '\0';
    string s = string(buffer);
    return s.substr(0, s.find(END_OF_MESSAGE));
}

void SocketIO::write(string str) const {
    string s(str);
    if (s.length() < BUFFER_SIZE) {
        s.insert(str.length(), BUFFER_SIZE - str.length(), ';');
    }
    int sent_bytes = send(client_sock, s.c_str(), s.length(), 0);
    if (sent_bytes < 0) {
        perror("error sending message to client.\n");
    }
}

void SocketIO::close() const {
    ::close(client_sock);
}
