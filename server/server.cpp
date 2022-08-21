#include "server/server.h"

Server::Server(int server_port) {
    this->server_port = server_port;
    commOverFlag = 0;

    FlowerReader &classifiedReader = *(new FlowerReader("../server/data/flower_data.csv"));
    DataSpaceCreator creator = DataSpaceCreator(classifiedReader);
    dataSpace = &creator.makeDataSpace();

    delete &classifiedReader;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(server_socket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    if (listen(server_socket, 5) < 0) {
        perror("error listening to a socket");
    }
}

void Server::connect() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);

    this->client_sock = accept(server_socket,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }
}

FlowerPoint& Server::receiveFlowerPoint() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // connection is closed
    }
    else if (read_bytes < 0) {
        // error
    }
    else {

        int seenR = 0;
        for (int i = 0; i < BUFFER_SIZE; i++) {
            if (seenR) {
                buffer[i] = '\0';
            } else if (buffer[i] == '\r') {
                seenR = 1;
            }
        }

        string line(buffer);

        if (!line.compare("END\r")) {
            commOverFlag = 1;
            return *(new FlowerPoint(-1, -1, -1, -1));
        }

        commOverFlag = 0;
        return *(detectFlowerPoint(line));
    }
    return *(new FlowerPoint(-1, -1, -1, -1));
}

void Server::sendClassification(FlowerPoint &flower, int k, Distance* distance) {
    FlowerType type = dataSpace->predict(k, flower, *(distance));

    char buffer[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = '\0';
    }

    strcpy(buffer,  FlowerTypeToString(type).c_str());

    int sent_bytes = send(client_sock, buffer, BUFFER_SIZE, 0);

    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}

void Server::closeServer() const {
    close(server_socket);
}

int Server::isCommOver() {
    return commOverFlag;
}

Server::~Server() {
    delete dataSpace;
}