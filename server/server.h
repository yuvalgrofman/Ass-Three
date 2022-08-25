#ifndef ASS_TWO_SERVER_H
#define ASS_TWO_SERVER_H

#include "server/IO/defaultIO.h"
#include "server/command/command.h"
#include "server/command/recvData.h"
#include "server/command/knnSettings.h"
#include "server/command/classifyData.h"
#include "server/command/displayData.h"
#include "server/command/uploadData.h"
#include "server/command/displayConfusionMatrix.h"
#include "server/command/close.h"
#include <map>
#include <algorithm>
#include <stdio.h>

map<int, Command*>* getCommands(DefaultIO* dio, int userId);

/**
 * Server is responsible for communication with a single client.
 * Therefore, the server receives in the constructor a IO to the user and
 * an integer which represents the userId.
 * The server_handler will be responsible for creating
 * new servers in different threads with the appropriate instance of DefaultIO and userId.
 */
class Server {

    private:
        DefaultIO* dio;
        int userId;

    public:
        Server(DefaultIO* dio, int userId);
        void run();
        void close();
};

#endif //ASS_TWO_SERVER_H
