#include "chebyshevDistance.h"
#include <cmath>
#include <string>

using namespace std;


double ChebyshevDistance::getDistance(const DataPoint& p1, const DataPoint& p2) const {
    if (p1.getNumberOfVariables() != p2.getNumberOfVariables()) {
        perror("Error: the number of variables in the two points is not equal");
    }

    double maxDist = 0;
    int numberOfVariables = p1.getNumberOfVariables();
    for (int i = 0; i < numberOfVariables; i++) {
        double diff = abs(p1.getVariable(i) - p2.getVariable(i));
        if (diff > maxDist) {
            maxDist = diff;
        }
    }

   return maxDist;
}

string ChebyshevDistance::getName() const {
    return "chebyshev";
}