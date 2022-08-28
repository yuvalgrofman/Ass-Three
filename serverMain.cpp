#include "server/serverRunner.h"

/**
 * The main function for the server.
 * it creates a SeverRunner object, and runs it.
 * @return 0 (the default return value of the main function)
 */
int main() {
    ServerSocket* serverSocket = new ServerSocket();
    ServerRunner* runner = new ServerRunner(*serverSocket);
    runner->run();
    delete runner;
}
