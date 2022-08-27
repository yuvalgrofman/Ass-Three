#include <iostream>
#include "server/server.h"
#include "server/IO/standardIO.h"
#include "server/serverSocket.h"

int main() {

    ServerSocket* ss = new ServerSocket();
    DefaultIO* dio = ss->accept();
    Server* s = new Server(dio, 1);
    s->run();
    s->close();
    ss->close();
}
