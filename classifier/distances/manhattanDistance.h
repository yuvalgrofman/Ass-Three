#ifndef ASS_ONE_MANHATTAN_DISTANCE
#define ASS_ONE_MANHATTAN_DISTANCE

#include "distance.h"

/**
 * @brief The ManhattanDistance class
 *
 * This class implements the Manhattan distance function.
 * The distance between two points is the sum of the differences.
 */
class ManhattanDistance : public Distance {
public:
    virtual double getDistance(const DataPoint& p1, const DataPoint& p2) const;
    virtual string getName() const;
};
#endif //ASS_ONE_MANHATTAN_DISTANCE