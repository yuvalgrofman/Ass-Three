#ifndef ASS_ONE_DATA_SPACE_H
#define ASS_ONE_DATA_SPACE_H

#include "classifier/classifiable/classifiable.h"
#include "classifier/distances/distance.h"

/**
 * @brief The DataSpace class
 *
 * This class represents a data space.
 * It contains a array of pointers to classifiable objects and an
 * integer which represents the number of classifiable objects.
 */
class DataSpace {
    private:
        const int numClassifiables;
        const Classifiable **data;

    public:
        /**
         * Constructor.
         * @param numClassifiables - the number of classifiable objects in the data space.
         * @param data array of pointers to classifiable objects.
         */
        DataSpace(const Classifiable** data, const int numClassifiables);

        /**
         * predicts the type of the data-point based on the k nearest neighbors.
         * @param k integer which represents the number of neighbors to use.
         * @param dataPoint data point to predict.
         * @param distance distance class to use.
         * @return the predicted type of the data-point.
         */
        string predict(int k, const DataPoint& dataPoint, Distance& distance) const;

        /**
         * Destructor.
         */
        ~DataSpace();
};

#endif //ASS_ONE_DATA_SPACE_H
