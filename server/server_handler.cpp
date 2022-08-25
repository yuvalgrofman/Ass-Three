#include "server_handler.h"


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "serverThread.h"
#include <pthread.h>

Server_handler::Server_handler(SocketIO *io) {
    this->io = io;
}

void Server_handler::run() {
    while(true) {
        try {
            string s = io->read();
            int id = getNewId();
            int port = getNewPort();
            io->write(to_string(port));
            io->write(to_string(id));

            int input[2] = {port, id};

            pthread_t thread_id;

            pthread_create(&thread_id, NULL, serverThread, (void *)&port);
            pthread_join(thread_id, NULL);
        } catch (...) {
            // do nothing.
        }
    }
}

void Server_handler::close() {
    io->close();
}
