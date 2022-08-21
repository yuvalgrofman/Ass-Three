#include "flowerPoint.h"

FlowerPoint::FlowerPoint(double width, double sepalLength, double sepalWidth, double petalLength) :
width(width), sepalLength(sepalLength), sepalWidth(sepalWidth), petalLength(petalLength) {}

double FlowerPoint::getPetalLength() const {
    return petalLength;
}

double FlowerPoint::getSepalLength() const {
    return sepalLength;
}

double FlowerPoint::getSepalWidth() const {
    return sepalWidth;
}

double FlowerPoint::getWidth() const {
    return width;
}