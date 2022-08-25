#include "serverThread.h"
#include "server.h"
#include "IO/socketIO.h"

void* serverThread(void *vargp) {
    int *input = (int *)vargp;
    int port = input[0];
    int id = input[1];
    SocketIO *io = new SocketIO(port);
    Server server(io, id);

    server.run();
    server.close();

    delete io;
}