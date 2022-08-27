#include <vector>
#include "classifyData.h"
#include "classifier/classifier.h"

ClassifyData::ClassifyData(DefaultIO* dio, int userId) : Command(dio, userId, "classify data") {}

void ClassifyData::execute() {
    string train = "../server/data/user_" + to_string(userId) + "_train.csv";
    string test = "../server/data/user_" + to_string(userId) + "_test.csv";

    Classifier *c = new Classifier(getK(), train, test);

    c->predictFileByDist("../server/data/user_" + to_string(userId)
                         + "_test_prediction.csv", *getDistance());

    delete c;
}