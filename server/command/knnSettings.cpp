#include "knnSettings.h"

KnnSettings::KnnSettings(int userId) : userId(userId) {}

int KnnSettings::getK() {
    ifstream istream;
    istream.open("../server/data/train_user_" + to_string(userId) + ".csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    string line;
    getline(istream, line);

    return stoi(line);
}

Distance* KnnSettings::getDistance() {
    ifstream istream;
    istream.open("../server/data/train_user_" + to_string(userId) + ".csv");

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
    dio->read();

}