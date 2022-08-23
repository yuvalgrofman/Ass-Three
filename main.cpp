#include <iostream>
#include "server/server.h"
#include "server/IO/standardIO.h"
#include <sstream>

int main() {

    DefaultIO* server = new StandardIO();
    Server* s = new Server(server, 1);
    s->run();
    s->close();
}
