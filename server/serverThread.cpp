#include "serverThread.h"
#include "server.h"
#include "IO/socketIO.h"

void* serverThread(void *vargp) {
    Server *server = (Server *)vargp;

    server->run();
    server->close();

    delete server;
}
