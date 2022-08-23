#include "dataReader.h"
#include <sstream>
#include <iostream>

DataPoint* detectDataPoint(const string &line) {
    string word;

    if (line == "")
        return nullptr;

    stringstream streamLine(line);

    vector<double> data;

    while(getline(streamLine, word, ',')) {
        double value = 0;
        try {
            value = stod(word);
        } catch (...) {
            break;
        }
        data.push_back(stod(word));
    }

    double *arr;
    int size = data.size();
    arr = new double[size];
    for (int i = 0; i < size; i++) {
        arr[i] = data.at(i);
    }

    return new DataPoint(arr, size);
}

Classifiable* detectClassifiable(const string &line) {
    if (line == "")
        return nullptr;

    string type = line.substr(line.find_last_of(',') + 1);
    string data = line.substr(0, line.find_last_of(','));

    if (data.empty() || type.empty()){
        return nullptr;
    }

    DataPoint *dataPoint = detectDataPoint(data);
    if (dataPoint == nullptr) {
        return nullptr;
    }

    return new Classifiable(*dataPoint, type);
}

DataReader::DataReader(const string &filename) : file(filename) {
        fin.open(file, ios::in);
}

Classifiable* DataReader::readClassifiable() {
    string line;
    getline(fin, line);
    return detectClassifiable(line);
}

DataPoint* DataReader::readDataPoint() {
    string line;
    getline(fin, line);
    return detectDataPoint(line);
}