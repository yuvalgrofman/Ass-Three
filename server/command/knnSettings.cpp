#include <algorithm>
#include "knnSettings.h"

KnnSettings::KnnSettings(int userId) : userId(userId) {}

int KnnSettings::getK() {
    ifstream istream;
    istream.open("../server/data/user_" + to_string(userId) + "_config.csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    string line;
    getline(istream, line);

    return stoi(line);
}

Distance* KnnSettings::getDistance() {
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

void KnnSettings::execute() {
    int k = getK();
    Distance* d = getDistance();

    dio->write("The current KNN parameters are: K = " + to_string(k) + ", distance metric = " + d->getName());
    string input = dio->read();

    if (input.compare("")) {
        bool validInput = false;

        string strk;
        string distance;

        do {
            stringstream ss(input);

            getline(ss, strk, ' ');
            getline(ss, distance);

            bool strkValid  = false;
            bool distanceValid = false;

            //checking if strk is valid
            if (!strk.empty() && std::all_of(strk.begin(), strk.end(), ::isdigit)) {
                int k = stoi(strk);
                strkValid = 0 < k && k < 11;
            }

            Distance* euc = new EuclideanDistance();
            Distance* man = new ManhattanDistance();
            Distance* cheb = new ChebyshevDistance();

            distanceValid = !distance.compare(euc->getName())
                         || !distance.compare(man->getName())
                         || !distance.compare(cheb->getName());

            delete euc;
            delete man;
            delete cheb;

            if (!strkValid && !distanceValid) {
                dio->write("Invalid value for K and Distance.");
            } else if (!strkValid) {
                dio->write("Invalid value for K.");
            } else if (!distanceValid) {
                dio->write("Invalid value for Distance.");
            }

            validInput = strkValid && distanceValid;
        } while (!validInput);

        string knnSettingContents = strk + "\n" + distance;
        writeCSVFile("../server/data/user_" + to_string(userId) + "_config.csv", knnSettingContents);
    }
}