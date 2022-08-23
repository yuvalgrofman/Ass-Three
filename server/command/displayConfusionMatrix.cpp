#include "displayConfusionMatrix.h"
#include <map>

map<string, int>& DisplayConfusionMatrix::getClassificationOptions() const {
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

DisplayConfusionMatrix::DisplayConfusionMatrix(DefaultIO* dio, int userId) : Command(dio, userId,
 "display algorithm confusion matrix") {}

void DisplayConfusionMatrix::execute() {
    map<string, int> &types = getClassificationOptions();

    int numTypes = types.size();
    int results[numTypes][numTypes];
    for (int i = 0; i < numTypes; i++) {
        for (int j = 0; j < numTypes; j++) {
            results[i][j] = 0;
        }
    }

    string prediction = "../server/data/user_" + to_string(userId) + "_test_prediction.csv";
    string test = "../server/data/user_" + to_string(userId) + "_test.csv";

    ifstream predictionStream(prediction);
    ifstream testStream(test);

    if (!predictionStream.is_open() || !testStream.is_open()) {
        //TODO: print error
    }

    string predictionLine;
    string testLine;
    getline(predictionStream, predictionLine);
    getline(testStream, testLine);

    while (!predictionStream.eof() && !testStream.eof()) {
        testLine = testLine.substr(testLine.find(",") + 1);

        int predictionIndex = types.find(predictionLine)->second;

        int testIndex = types.find(testLine)->second;

        results[testIndex][predictionIndex]++;


        getline(predictionStream, predictionLine);
        getline(testStream, testLine);
    }

    predictionStream.close();
    testStream.close();

    for (int row = 0; row < numTypes; row++) {
        int numGussesInRow = 0;
        for (int col = 0; col < numTypes; col++) {
            numGussesInRow += results[row][col];
        }

        for (int col = 0; col < numTypes; col++) {
            results[row][col] = round((double(results[row][col]) / double(numGussesInRow)) * 100);
        }
    }

    dio->write("Confusion Matrix:");
    string lastLine = "\t";
    map<string, int>::iterator itr;
    for (itr = types.begin(); itr != types.end(); itr++) {
        lastLine += itr->first + " ";
        int row = itr->second;
        string rowString = itr->first;
        for (int col = 0; col < numTypes; col++) {
            rowString += to_string(results[row][col]) + "\t";
        }
        dio->write(rowString);
    }

    dio->write(lastLine);

    dio->write("The current KNN parameters are: K = " + to_string(getK())
               + ", distance metric = " + getDistance()->getName());

    delete &
types;
}