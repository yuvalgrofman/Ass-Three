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

        /**
         * @return the k value that the user choose to use.
         */
        int getK() const;

        /**
         * @return the distance function that the user choose to use.
         */
        Distance* getDistance() const;

        /**
         * Writes a given string to a given file.
         * @param filepath - the path of the file to write to.
         * @param fileContent - the content of the file to write to.
         */
        void writeCSVFile(string filepath, string fileContent) const;

    public:
        /**
         * Constructor.
         * @param dio - the io object to use.
         * @param userId - the id of the user who run the command.
         * @param description - the description of the command.
         */
        Command(DefaultIO* dio, int userId, string description);

        /**
         * Execute this command.
         */
        virtual void execute() = 0;

        /**
         * Get the description of this command.
         * @return the description of this command.
         */
        string getDescription() const;
};

#endif //ASS_TWO_COMMAND_H
