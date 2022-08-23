#include "classifier.h"

Classifier::Classifier(int k, vector<Distance*>* distances, const string& classifiedData,
                       const string& unclassifiedData) : k(k), distances(distances) {
    unclassifiedPoints = new vector<DataPoint*>();

    DataReader &unClassifiedReader = *(new DataReader(unclassifiedData));
    DataPoint* ptr = unClassifiedReader.readDataPoint();

    while (ptr != nullptr) {
        unclassifiedPoints->push_back(ptr);
        ptr = unClassifiedReader.readDataPoint();
    }

    delete &unClassifiedReader;

    DataReader &classifiedReader = *(new DataReader(classifiedData));
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

    for (DataPoint *point : *unclassifiedPoints) {
        outfile << dataSpace->predict(k, *point, distance) << endl;
    }

    outfile.close();
}

string Classifier::classify(DataPoint &dataPoint, Distance &distance) {
    return dataSpace->predict(k, dataPoint, distance);
}

Classifier::~Classifier() {
    delete dataSpace;
    for (DataPoint *point : *unclassifiedPoints) {
        delete point;
    }
    delete unclassifiedPoints;
}