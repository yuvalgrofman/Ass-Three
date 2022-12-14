#include "server.h"

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

bool dirExists(string dirname) {
    DIR *dir = opendir(dirname.c_str());
    bool flag = dir != NULL;
    free(dir);
    return flag;
}


Server::Server(ServerSocket &serverSocket) : serverSocket(serverSocket) {
    highestId = 0;
}

void Server::run() {
    if (!dirExists(DATA_DIR)) {
        mkdir(DATA_DIR.c_str(), 0777);
    }

    while (true) {
        try {
            if (!serverSocket.hasTimedOut()) {
                SocketIO *socketIO = serverSocket.accept();
                pthread_t thread_id;
                highestId++;
                CLI *server = new CLI(socketIO, highestId);

                pthread_create(&thread_id, NULL, serverThread, (void *)server);
                pthread_detach(thread_id);
            } else {
                if (dirIsEmpty(DATA_DIR)) {
                    rmdir(DATA_DIR.c_str());
                    return;
                }
            }
        } catch (...) {
            break;
        }
    }
}