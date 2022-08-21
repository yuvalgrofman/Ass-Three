#ifndef ASS_ONE_EUCLIDEAN_DISTANCE
#define ASS_ONE_EUCLIDEAN_DISTANCE

#include "classifier/distances/distance.h"
#include <cmath>

/**
 * @brief The EuclideanDistance class
 *
 * This class implements the Euclidean distance function.
 * The distance between two points is the square root of the sum of the squared differences.
 */
class EuclideanDistance : public Distance {
public:
    virtual double getDistance(const FlowerPoint& p1, const FlowerPoint& p2) const;
    virtual string getName() const;
};
#endif //ASS_ONE_EUCLIDEAN_DISTANCE