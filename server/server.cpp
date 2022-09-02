#include "server.h"
#include "serverThread.h"
#include "cli.h"

const string Server::DATA_DIR = "../server/data";

bool dirIsEmpty(string dirname) {
    int n = 0;
    struct dirent *d;
    DIR *dir = opendir(dirname.c_str());
    if (dir == NULL) //Not a directory or doesn't exist
        return true;
    while ((d = readdir(dir)) != NULL) {
        if(++n > 2)
            break;
    }

    closedir(dir);
    if (n <= 2) //Directory Empty
        return true;
    else
        return false;
}


Server::Server(ServerSocket &serverSocket) : serverSocket(serverSocket) {
    highestId = 0;
}

void Server::run() {
    while (true) {
        try {
            if (!serverSocket.hasTimedOut()) {
                SocketIO *socketIO = serverSocket.accept();
                pthread_t thread_id;
                highestId++;
                CLI *server = new CLI(socketIO, highestId);

                pthread_create(&thread_id, NULL, serverThread, (void *)server);
            } else {
                if (dirIsEmpty(DATA_DIR)) {
                    return;
                }
            }
        } catch (...) {
            break;
        }

    }
}