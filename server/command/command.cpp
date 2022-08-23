#include <set>
#include <map>
#include "command.h"

Command::Command(DefaultIO *dio, int userId, string description) : dio(dio), userId(userId), description(description) {}

void Command::writeCSVFile(string filepath, string fileContent) const {
    ofstream ostream(filepath);

    if (!ostream.is_open()) {
        //TODO: print error
    }

    ostream << fileContent;
    ostream.close();
}

int Command::getK() const {
    ifstream istream("../server/data/user_" + to_string(userId) + "_config.csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    string line;
    getline(istream, line);

    return stoi(line);
}

Distance* Command::getDistance() const {
    ifstream istream("../server/data/user_" + to_string(userId) + "_config.csv");

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

map<string, int>& Command::getClassificationOptions() const {
    ifstream istream = ifstream("../server/data/user_" + to_string(userId) + "_test.csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    map<string, int> &options = *(new map<string, int>());

    string line;
    getline(istream, line);

    int index = 0;
    while (!line.empty()) {
        string type = line.substr(line.find_last_of(',') + 1);

        if (options.find(type) == options.end()) {
            options.insert({type, index});
            index++;
        }


        getline(istream, line);
    }

    return options;
}

string Command::getDescription() const {
    return description;
}