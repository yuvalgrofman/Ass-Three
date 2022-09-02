#include "serverThread.h"
#include "cli.h"
#include "IO/socketIO.h"

void* serverThread(void *arg) {
    CLI *server = (CLI *)arg;

    server->run();
    server->close();

    delete server;
}
