#include "classifiable.h"

Classifiable::Classifiable(const DataPoint &dataPoint, string type) : type(type), dataPoint(dataPoint) {}

Classifiable::Classifiable(Classifiable const &classifiable): type(classifiable.type),
            dataPoint(classifiable.dataPoint) {}

string Classifiable::getType() const {
    return type;
}

const DataPoint& Classifiable::getData() const {
    return dataPoint;
}

Classifiable::~Classifiable() {
    delete &dataPoint;
}
