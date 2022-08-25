#ifndef ASS_THREE_SERVERRUNNER_H
#define ASS_THREE_SERVERRUNNER_H

#include "serverSocket.h"
#include "vector"

class ServerRunner {
    private:
        int highestId;
        ServerSocket &serverSocket;

        public:
            ServerRunner(ServerSocket &serverSocket);
            void run();
};


#endif //ASS_THREE_SERVERRUNNER_H
