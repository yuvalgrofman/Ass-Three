#ifndef ASS_TWO_COMMAND_H
#define ASS_TWO_COMMAND_H

#include <fstream>
#include <string>
#include <sstream>
#include "server/IO/defaultIO.h"
#include "classifier/distances/distance.h"

using namespace std;

class Command {

    protected:
        string description;
        DefaultIO* dio;


        int getK();
        Distance* getDistance();
        void writeCSVFile(string filepath, string fileContent);

public:
    virtual void execute();

};

#endif //ASS_TWO_COMMAND_H
