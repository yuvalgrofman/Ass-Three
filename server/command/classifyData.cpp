#include <vector>
#include "classifyData.h"
#include "classifier/classifier.h"

ClassifyData::ClassifyData(int userId) : userId(userId) {}

void ClassifyData::execute() {
    string classified = "../server/data/user_" + to_string(userId) + "_train.csv";
    string unclassified = "../server/data/user_" + to_string(userId) + "_test.csv";

    vector<Distance*> *dists = new vector<Distance*>();
    dists->push_back(getDistance());

    Classifier *c = new Classifier(getK(), dists,
                           classified,unclassified);

    c->predictFileByDist("../server/data/user_" + to_string(userId)
                        + "_prediction.csv", *getDistance());

    delete c;
    delete dists;
}