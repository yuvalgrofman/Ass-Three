#include "dataPoint.h"

DataPoint::DataPoint(const double data[], int size) : data(data), size(size) {}

double DataPoint::getVariable(int index) const {
    if (index < 0 || index >= size) {
        throw "Index out of bounds";
    }
    return data[index];
}

int DataPoint::getNumberOfVariables() const {
    return size;
}

DataPoint::~DataPoint() {
    delete[] data;
}
