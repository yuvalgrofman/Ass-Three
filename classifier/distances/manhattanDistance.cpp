#include "manhattanDistance.h"
#include <cmath>


double ManhattanDistance::getDistance(const DataPoint& p1, const DataPoint& p2) const {
    if (p1.getNumberOfVariables() != p2.getNumberOfVariables()) {
        perror("Error: the number of variables in the two points is not equal");
    }

    int numberOfVariables = p1.getNumberOfVariables();
    double sumOfDifferences = 0;

    for (int i = 0; i < numberOfVariables; i++) {
        sumOfDifferences += abs(p1.getVariable(i) - p2.getVariable(i));
    }

    return sumOfDifferences;
}

string ManhattanDistance::getName() const {
    return "manhattan";
}