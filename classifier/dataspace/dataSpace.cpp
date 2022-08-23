#include "dataSpace.h"
#include <vector>
#include <map>
#include <iostream>
#include "classifier/classifiable/dataSorter.h"

using namespace std;

DataSpace::DataSpace(const Classifiable** data, const int numClassifiables):
                    numClassifiables(numClassifiables) {
    this->data = data;
}

DataSpace::~DataSpace() {
    for (int i = 0; i < numClassifiables; i++) {
        delete data[i];
    }
    delete[] data;
}

string DataSpace::predict(int k, const DataPoint& dataPoint, Distance& distance) const {
    const Classifiable *arr[numClassifiables];
    for (int i = 0; i < numClassifiables; i++) {
        arr[i] = data[i];
    }
    DataSorter sorter(dataPoint, distance);
    sorter.sortClassifiableList(arr, numClassifiables);

    map<string, int> classificationCount;
    for (int i = 0; i < k; i++) {
        string type = arr[i]->getType();
        if (classificationCount.find(type) == classificationCount.end()) {
            classificationCount.insert(pair<string, int>(type, 1));
        } else {
            classificationCount[type]++;
        }
    }

    string maxType = "";
    int maxCount = 0;
    for (map<string, int>::iterator it = classificationCount.begin();
                    it != classificationCount.end(); it++) {
        if (it->second > maxCount) {
            maxCount = it->second;
            maxType = it->first;
        }
    }

    return maxType;
}