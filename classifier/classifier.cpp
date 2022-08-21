#include "classifier.h"


Classifier::Classifier(int k, vector<Distance*>* distances, const string& classifiedData,
                       const string& unclassifiedData) : k(k), distances(distances) {
    unclassifiedFLowers = new vector<FlowerPoint*>();

    FlowerReader &unClassifiedReader = *(new FlowerReader(unclassifiedData));
    FlowerPoint* ptr = unClassifiedReader.readFlowerPoint();

    while (ptr != nullptr) {
        unclassifiedFLowers->push_back(ptr);
        ptr = unClassifiedReader.readFlowerPoint();
    }

    delete &unClassifiedReader;

    FlowerReader &classifiedReader = *(new FlowerReader(classifiedData));
    DataSpaceCreator creator = DataSpaceCreator(classifiedReader);
    dataSpace = &creator.makeDataSpace();

    delete &classifiedReader;
}

void Classifier::classify() {
    for (Distance *distance : *distances) {
        predictFileByDist(distance->getName() + "_output.csv", *distance);
    }
}

void Classifier::predictFileByDist(const string &outputFile, Distance &distance) const {
    ofstream outfile;
    outfile.open(outputFile, ios::out);

    for (FlowerPoint *flower : *unclassifiedFLowers) {
        outfile << dataSpace->predict(k, *flower, distance) << endl;
    }

    outfile.close();
}

FlowerType Classifier::classify(FlowerPoint &flowerPoint, Distance &distance) {
    return dataSpace->predict(k, flowerPoint, distance);
}

Classifier::~Classifier() {
    delete dataSpace;
    for (FlowerPoint *flowerPoint : *unclassifiedFLowers) {
        delete flowerPoint;
    }
    delete unclassifiedFLowers;
}