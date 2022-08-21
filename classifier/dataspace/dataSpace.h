#ifndef ASS_ONE_DATA_SPACE_H
#define ASS_ONE_DATA_SPACE_H

#include "classifier/flower/flower.h"
#include "classifier/distances/distance.h"

/**
 * @brief The DataSpace class
 *
 * This class represents a data space.
 * It contains a array of pointers to flowers and a integer which represents the number of flowers.
 */
class DataSpace {
    private:
        const int numFlowers;
        const Flower **data;

    public:
        /**
         * Constructor.
         * @param numFlowers number of flowers in the data space
         * @param data array of pointers to flowers
         */
        DataSpace(const Flower** data, const int numFlowers);

        /**
         * predicts the type of the flower-point based on the k nearest neighbors.
         * @param k integer which represents the number of neighbors to use
         * @param flowerPoint flower point to predict
         * @param distance distance class to use
         * @return the type of the flower-point
         */
        FlowerType predict(int k, const FlowerPoint& flowerPoint, Distance& distance) const;

        /**
         * Destructor.
         */
        ~DataSpace();
};

#endif //ASS_ONE_DATA_SPACE_H
