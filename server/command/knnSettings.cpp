#include <algorithm>
#include "knnSettings.h"

KnnSettings::KnnSettings(DefaultIO* dio, int userId) : Command(dio, userId, "algorithm settings") {}



void KnnSettings::execute() {
    int k = getK();
    Distance* d = getDistance();

    dio->write("The current KNN parameters are: K = " + to_string(k) + ", distance metric = " + d->getName() + "\n");
    string input = "";

    bool validInput = false;

    string strk;
    string distance;

    do {
        input = dio->read();

        if (!input.compare("NONE")) {
            dio->write("DONE\n");
            return;
        }

        stringstream ss(input);

        getline(ss, strk, ' ');
        getline(ss, distance);

        bool strkValid  = false;
        bool distanceValid = false;

        //checking if strk is valid
        if (!strk.empty() && std::all_of(strk.begin(), strk.end(), ::isdigit)) {
            int vk = stoi(strk);
            strkValid = 0 < vk && vk < 11;
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
    dio->write("DONE\n");
}