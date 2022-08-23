#include "dataPoint.h"

DataPoint::DataPoint(const double data[], int size) : data(data), size(size) {}

DataPoint::DataPoint(const vector<double> &data) : data(data.data()), size(data.size()) {}

double DataPoint::getVariable(int index) const {
    return data[index];
}

int DataPoint::getNumberOfVariables() const {
    return size;
}

DataPoint::~DataPoint() {
    delete[] data;
}
