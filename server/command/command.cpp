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

    if (istream.peek() == std::ifstream::traits_type::eof()) {
        ofstream ostream("../server/data/user_" + to_string(userId) + "_config.csv");

        if (!ostream.is_open()) {
            //TODO: print error
        }

        ostream << "5\n";
        ostream << "EUC";
        ostream.close();

        return 5;
    }

    string line;
    getline(istream, line);
    istream.close();

    return stoi(line);
}

Distance* Command::getDistance() const {
    ifstream istream("../server/data/user_" + to_string(userId) + "_config.csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    if (istream.peek() == std::ifstream::traits_type::eof()) {
        ofstream ostream("../server/data/user_" + to_string(userId) + "_config.csv");

        if (!ostream.is_open()) {
            //TODO: print error
        }

        ostream << "5\n";
        ostream << "EUC";
        ostream.close();

        return new EuclideanDistance();
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

bool Command::isDataClassified() const {
    string testPredict = "../server/data/user_" + to_string(userId) + "_test_prediction.csv";
    ifstream testPredictStream(testPredict);
    char v = testPredictStream.peek();

    return !(testPredictStream.peek() == std::ifstream::traits_type::eof());
}

string Command::getDescription() const {
    return description;
}