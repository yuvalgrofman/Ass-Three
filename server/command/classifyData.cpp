#include <vector>
#include "classifyData.h"
#include "classifier/classifier.h"

ClassifyData::ClassifyData(DefaultIO* dio, int userId) : Command(dio, userId, "classify data") {}

void ClassifyData::execute() {
    string train = "../server/data/user_" + to_string(userId) + "_train.csv";
    bool trainExists = false;

    ifstream trainContentStream(train);
    trainExists = trainContentStream ? true : false;
    string test = "../server/data/user_" + to_string(userId) + "_test.csv";

    bool testExists = false;
    ifstream testContentStream(train);
    testExists = testContentStream ? true : false;

    if (!trainExists || !testExists) {
        string s = "train of test files don't exist.\nIn order to upload them press 1.\n";
        dio->write(s);

    } else {
        dio->write("Classifying data.\n");

        Classifier *c = new Classifier(getK(), train, test);

        c->predictFileByDist("../server/data/user_" + to_string(userId)
                             + "_test_prediction.csv", *getDistance());

        delete c;
    }
}