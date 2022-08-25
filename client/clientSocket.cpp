#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "clientSocket.h"

ClientSocket::ClientSocket(const std::string server_ip, const int port) : server_ip(server_ip), port_num(port),
                          sock(socket(AF_INET, SOCK_STREAM, 0)){
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(server_ip.c_str());
    sin.sin_port = htons(port_num);

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
}

void ClientSocket::write(const std::string str) const {
    string s = str + END_OF_MESSAGE;
    char const *data_addr = s.c_str();
    int data_len = s.length();
    int sent_bytes = send(sock, data_addr, data_len, 0);

    if (sent_bytes < 0) {
        perror("error sending data");
    }
}

string ClientSocket::read() const {
    char buffer[BUFFER_SIZE];
    int read_bytes = recv(sock, buffer, BUFFER_SIZE, 0);
    if (read_bytes == 0) {
        throw "connection is closed";
    } else if (read_bytes < 0) {
        throw "error";
    }
    string s = string(buffer);
    return s.substr(0, s.find(END_OF_MESSAGE));
}

void ClientSocket::closeConnection() const {
    close(sock);
}