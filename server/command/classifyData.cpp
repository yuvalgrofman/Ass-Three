#include <vector>
#include "classifyData.h"
#include "classifier/classifier.h"

ClassifyData::ClassifyData(DefaultIO* dio, int userId) : Command(dio, userId, "classify data") {}

void ClassifyData::execute() {
    string train = "../server/data/user_" + to_string(userId) + "_train.csv";
    string test = "../server/data/user_" + to_string(userId) + "_test.csv";
    string classified = "../server/data/classified.csv";

    vector<Distance*> *dists = new vector<Distance*>();
    dists->push_back(getDistance());

    Classifier *c = new Classifier(getK(),classified,train);

    c->predictFileByDist("../server/data/user_" + to_string(userId)
                        + "_train_prediction.csv", *getDistance());

    Classifier* c1 = new Classifier(getK(),classified, test);

    c1->predictFileByDist("../server/data/user_" + to_string(userId)
                         + "_test_prediction.csv", *getDistance());
    delete dists;
    delete c;
    delete c1;
}