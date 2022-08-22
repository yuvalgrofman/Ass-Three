#ifndef ASS_TWO_COMMAND_H
#define ASS_TWO_COMMAND_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "server/IO/defaultIO.h"
#include "classifier/distances/distance.h"
#include "classifier/distances/euclideanDistance.h"
#include "classifier/distances/manhattanDistance.h"
#include "classifier/distances/chebyshevDistance.h"
#include "server/command/command.h"

class Command {

    protected:
        string description;
        DefaultIO* dio;
        int userId;

        int getK() const;
        Distance* getDistance() const;
        void writeCSVFile(string filepath, string fileContent) const;

    public:
        Command(DefaultIO* dio, int userId);
        virtual void execute() = 0;
};

#endif //ASS_TWO_COMMAND_H
