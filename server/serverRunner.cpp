#include "serverRunner.h"
#include "serverThread.h"
#include "server.h"

ServerRunner::ServerRunner(ServerSocket &serverSocket) : serverSocket(serverSocket) {
    highestId = 0;
}

void ServerRunner::run() {
    while (true) {
        try {
            SocketIO *socketIO = serverSocket.accept();
            pthread_t thread_id;
            highestId++;
            Server *server = new Server(socketIO, highestId);

            pthread_create(&thread_id, NULL, serverThread, (void *)server);
        } catch (...) {
            break;
        }

    }
}