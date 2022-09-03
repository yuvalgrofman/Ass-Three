#ifndef ASS_THREE_SERVER_H
#define ASS_THREE_SERVER_H

#include "serverSocket.h"
#include "vector"
#include <dirent.h>
#include <string>

/**
 * Checks if a directory is empty
 * @param dir path to directory
 * @return true if empty, false otherwise
 */
bool dirIsEmpty(string dir);

/**
 * Checks if a directory exists
 * @param dir path to directory
 * @return true if exists, false otherwise
 */
bool dirExists(string dir);

/**
 * @brief The Server class
 *
 * This class is responsible for creating new servers in different threads
 * with the appropriate instance of DefaultIO and userId.
 */
class Server {
    private:
        int highestId;
        ServerSocket &serverSocket;

    public:
        static const string DATA_DIR;

        /**
         * Constructor.
         * @param serverSocket - the server socket to use
         */
        Server(ServerSocket &serverSocket);

        /**
         * Runs the server runner.
         */
        void run();
};


#endif //ASS_THREE_SERVER_H
