#include "serverThread.h"
#include "server.h"
#include "IO/socketIO.h"

void* serverThread(void *arg) {
    Server *server = (Server *)arg;

    server->run();
    server->close();

    delete server;
}
