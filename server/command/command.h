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

using namespace std;

class Command {

    protected:
        DefaultIO* dio;
        int userId;
        string description;


        int getK() const;
        Distance* getDistance() const;
        void writeCSVFile(string filepath, string fileContent) const;

    public:
        Command(DefaultIO* dio, int userId, string description);
        virtual void execute() = 0;

        string getDescription() const;
};

#endif //ASS_TWO_COMMAND_H
