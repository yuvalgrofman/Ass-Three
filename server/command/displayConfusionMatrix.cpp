#include "displayConfusionMatrix.h"
#include "classifier/classifier.h"
#include <map>

map<string, int>& DisplayConfusionMatrix::getClassificationOptions() const {
    ifstream istream = ifstream("../server/data/user_" + to_string(userId) + "_train.csv");

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
    string train = "../server/data/user_" + to_string(userId) + "_train.csv";
    bool trainIsEmpty = false;
    ifstream trainContentStream(train);
    trainIsEmpty = trainContentStream.peek() == std::ifstream::traits_type::eof();

    if (trainIsEmpty) {
        string s = "train file is empty.\nIn order to upload it "
                   "choose option 1 from the options screen.\n";
        dio->write(s);
    } else {
        dio->write("Sending data.\n");

        Classifier *c = new Classifier(getK(), train, train);

        Distance *d = getDistance();
        c->predictFileByDist("../server/data/user_" + to_string(userId)
                             + "_train_prediction.csv", *d);
        delete d;
        delete c;

        map<string, int> &types = getClassificationOptions();

        int numTypes = types.size();
        int results[numTypes][numTypes];
        for (int i = 0; i < numTypes; i++) {
            for (int j = 0; j < numTypes; j++) {
                results[i][j] = 0;
            }
        }

        string prediction = "../server/data/user_" + to_string(userId) + "_train_prediction.csv";

        ifstream predictionStream(prediction);
        ifstream trainStream(train);

        string predictionLine;
        string trainLine;
        getline(predictionStream, predictionLine);
        getline(trainStream, trainLine);

        while (!predictionStream.eof() && !trainStream.eof()) {
            trainLine = trainLine.substr(trainLine.find_last_of(',') + 1);

            int predictionIndex = types.at(predictionLine);

            int trainIndex = types.at(trainLine);

            results[trainIndex][predictionIndex]++;


            getline(predictionStream, predictionLine);
            getline(trainStream, trainLine);
        }

        predictionStream.close();
        trainStream.close();

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

        int maxLengthClassificationString = 0;
        map<string, int>::iterator itr;
        for (itr = types.begin(); itr != types.end(); itr++) {
            int length = itr->first.length();
            if (maxLengthClassificationString < length) {
                maxLengthClassificationString = length;
            }
        }

        for (itr = types.begin(); itr != types.end(); itr++) {
            int row = itr->second;


            string rowString = itr->first;
            int length = rowString.length();
            rowString = rowString.append(maxLengthClassificationString - length, ' ');

            for (int col = 0; col < numTypes; col++) {
                rowString += "\t" + to_string(results[row][col]);
            }
            dio->write(rowString);
        }

        writeCSVFile(prediction, "");

        Distance *dist = getDistance();
        dio->write("The current KNN parameters are: K = " + to_string(getK())
                   + ", distance metric = " + dist->getName());
        delete dist;

        delete &types;
    }
}