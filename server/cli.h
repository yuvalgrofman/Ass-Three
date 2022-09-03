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
#include <cstdio>
#include <iostream>
#include <fstream>

map<int, Command*>* getCommands(DefaultIO* dio, int userId);

/**
 * CLI is responsible for communication with a single client.
 * Therefore, the server receives in the constructor an IO to communicate
 * with the client, and an integer which represents the userId of the client.
 * The Server will be responsible for creating new servers in different threads
 * with the appropriate instance of DefaultIO and userId.
 */
class CLI {

    private:
        DefaultIO* dio;
        int userId;
        const int NUM_OF_COMMANDS = 7;

    public:
        /**
         * Constructor.
         * @param dio - the IO to communicate with the client.
         * @param userId - the userId of the client.
         */

        CLI(DefaultIO* dio, int userId);
        /**
         * Runs the server.
         */
        void run();

        /**
         * Closes the server.
         */
        void close();

        ~CLI();
};

#endif //ASS_TWO_SERVER_H
