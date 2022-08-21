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

int Command::getK() {
    ifstream istream;
    istream.open("../server/data/user_" + to_string(userId) + "_config.csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    string line;
    getline(istream, line);

    return stoi(line);
}

Distance* Command::getDistance() {
    ifstream istream;
    istream.open("../server/data/user_" + to_string(userId) + "_config.csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    string line;
    getline(istream, line);
    getline(istream, line);

    Distance* euc = new EuclideanDistance();
    Distance* man = new ManhattanDistance();
    Distance* cheb = new ChebyshevDistance();

    Distance* d;

    if (!line.compare(euc->getName())) {
        d = new EuclideanDistance();

    } else if (!line.compare(man->getName())) {
        d = new ManhattanDistance();

    } else if (!line.compare(cheb->getName())) {
        d = new ChebyshevDistance();

    } else {
        //TODO: print error
    }

    delete euc;
    delete man;
    delete cheb;

    return d;
}