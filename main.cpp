#include <iostream>
#include "server/server.h"
#include "server/IO/standardIO.h"

int main() {
    DefaultIO* dio = new StandardIO();
    Server* s = new Server(dio, 1);
    s->run();
    s->close();
}
