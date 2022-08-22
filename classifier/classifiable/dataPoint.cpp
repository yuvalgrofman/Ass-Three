#include "dataPoint.h"

DataPoint::DataPoint(const double data[], int size) : data(data), size(size) {}

double DataPoint::getVariable(int index) const {
    return data[index];
}

int DataPoint::getNumberOfVariables() const {
    return size;
}

