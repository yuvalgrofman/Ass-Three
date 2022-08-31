#include "client/clientSocket.h"
#include "client/client.h"

int main() {

    ClientSocket* dio = new ClientSocket();
    Client* c = new Client(dio);
    c->run();
    c->close();

    delete c;
    delete dio;
}