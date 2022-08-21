#include "flower.h"

Flower::Flower(const FlowerPoint& dataPoint, const FlowerType type): type(type), dataPoint(dataPoint) {}

Flower::Flower(Flower const &flower): type(flower.type), dataPoint(flower.dataPoint) {}

FlowerType Flower::getType() const {
    return type;
}

const FlowerPoint& Flower::getData() const {
    return dataPoint;
}

Flower::~Flower() {
    delete &dataPoint;
}