#include "client/clientSocket.h"
#include "client/client.h"

/**
 * The main function for the client.
 * Creates a Client object, and runs it.
 * @return 0 (the default return value of the main function)
 */
int main() {

    ClientSocket* dio = new ClientSocket();
    Client* c = new Client(dio);
    c->run();
    c->close();

    delete c;
    delete dio;
}