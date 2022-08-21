#include "euclideanDistance.h"

double EuclideanDistance::getDistance(const FlowerPoint& p1, const FlowerPoint& p2) const {
    return sqrt(std::pow(p1.getPetalLength() - p2.getPetalLength(), 2) +
                std::pow(p1.getSepalLength() - p2.getSepalLength(), 2) +
                std::pow(p1.getSepalWidth() - p2.getSepalWidth(), 2) +
                std::pow(p1.getWidth() - p2.getWidth(), 2));
}

string EuclideanDistance::getName() const {
    return "euclidean";
}