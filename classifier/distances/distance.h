#ifndef ASS_ONE_DISTANCE
#define ASS_ONE_DISTANCE

#include "classifier/flower/flowerPoint.h"
#include "string"

using namespace std;

/**
 * @brief The Distance class
 *
 * This class is an abstract class that defines the interface for a distance
 * function.
 */
class Distance {
    public:
        /**
         * @brief getDistance
         * @param p1 first point
         * @param p2 second point
         * @return the distance between the two points
         */
        virtual double getDistance(const FlowerPoint& p1, const FlowerPoint& p2) const = 0;

        /**
         * @brief getName
         * @return the name of the distance function
         */
        virtual string getName() const = 0;
};

#endif //ASS_ONE_DISTANCE