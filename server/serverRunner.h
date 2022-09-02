#ifndef ASS_THREE_SERVERRUNNER_H
#define ASS_THREE_SERVERRUNNER_H

#include "serverSocket.h"
#include "vector"
#include <dirent.h>

bool dirIsEmpty(string dir);

/**
 * @brief The ServerRunner class
 *
 * This class is responsible for creating new servers in different threads
 * with the appropriate instance of DefaultIO and userId.
 */
class ServerRunner {
    private:
        int highestId;
        ServerSocket &serverSocket;

        public:
            /**
             * Constructor.
             * @param serverSocket - the server socket to use
             */
            ServerRunner(ServerSocket &serverSocket);

            /**
             * Runs the server runner.
             */
            void run();
};


#endif //ASS_THREE_SERVERRUNNER_H
