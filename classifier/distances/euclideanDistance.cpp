#include "euclideanDistance.h"

double EuclideanDistance::getDistance(const DataPoint& p1, const DataPoint& p2) const {
    if (p1.getNumberOfVariables() != p2.getNumberOfVariables()) {
        perror("Error: the number of variables in the two points is not equal");
    }

    double sumOfSquaredDifferences = 0;
    int numberOfVariables = p1.getNumberOfVariables();
    for (int i = 0; i < numberOfVariables; i++) {
        sumOfSquaredDifferences += std::pow(p1.getVariable(i) - p2.getVariable(i), 2);
    }

    return sqrt(sumOfSquaredDifferences);
}

string EuclideanDistance::getName() const {
    return "euclidean";
}