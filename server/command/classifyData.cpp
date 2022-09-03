#include <vector>
#include "classifyData.h"
#include "classifier/classifier.h"

ClassifyData::ClassifyData(DefaultIO* dio, int userId) : Command(dio, userId, "classify data") {}

void ClassifyData::execute() {
    string train = "../server/data/user_" + to_string(userId) + "_train.csv";
    bool trainIsEmpty = false;
    ifstream trainContentStream(train);
    trainIsEmpty = trainContentStream.peek() == std::ifstream::traits_type::eof();

    string test = "../server/data/user_" + to_string(userId) + "_test.csv";
    bool testIsEmpty = false;
    ifstream testContentStream(train);
    testIsEmpty = testContentStream.peek() == std::ifstream::traits_type::eof();

    if (trainIsEmpty || testIsEmpty) {
        string s = "train or test files are empty.\nIn order to upload them press 1.\n";
        dio->write(s);

    } else {
        dio->write("Classifying data.\n");

        Classifier *c = new Classifier(getK(), train, test);

        Distance *d = getDistance();
        c->predictFileByDist("../server/data/user_" + to_string(userId)
                             + "_test_prediction.csv", *d);
        delete d;

        delete c;
    }
}