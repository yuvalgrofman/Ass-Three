#include "command.h"

void Command::writeCSVFile(string filepath, string fileContent) {
    ofstream ostream;
    ostream.open(filepath);

    if (!ostream.is_open()) {
        //TODO: print error
    }

    ostream << fileContent;
    ostream.close();
}