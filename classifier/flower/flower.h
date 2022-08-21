#ifndef ASS_ONE_FLOWER_H
#define ASS_ONE_FLOWER_H

#include <string>
#include "flowerPoint.h"
#include "flowerType.h"

using namespace std;

/**
 * @brief The Flower class
 *
 * This class represents a Flower with 4 parameters and a type.
 * The parameters are stored in a FlowerPoint and the type is stored in a FlowerType.
 */
class Flower {
    private:
        const FlowerPoint& dataPoint;
        const FlowerType type;

    public:
        /**
         * Copy constructor.
         * @param flower flower to copy
         */
        Flower(Flower const &flower);

        /**
         * Constructor.
         * @param dataPoint data point of the flower
         * @param type type of the flower
         */
        Flower(const FlowerPoint &dataPoint, FlowerType type);

        /**
         * @return the type of the flower
         */
        FlowerType getType() const;

        /**
         * @return the data point of the flower
         */
        const FlowerPoint& getData() const;

        /**
         * Default constructor.
         */
        Flower() = default;

        /**
         * Destructor.
         */
        ~Flower();
};

#endif //ASS_ONE_FLOWER_H
