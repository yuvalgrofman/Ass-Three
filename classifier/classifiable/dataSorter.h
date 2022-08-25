#ifndef ASS_THREE_DATASORTER_H
#define ASS_THREE_DATASORTER_H

#include "classifiable.h"
#include "classifier/distances/distance.h"

/**
 * @brief The DataSorter class
 *
 * This class is Responsible for comparing and sorting classifiable objects,
 * based on the distance to a specific data point, with a specific distance function.
 */
class DataSorter {
    private:
        const DataPoint& referencePoint;
        const Distance& distance;

        /**
         * Compare two classifiable objects, to see which of them
         * should be before the other, when sorting the classifiable objects.
         * @param clsf1 - the first classifiable object.
         * @param clsf2 - the second classifiable object.
         * @return true if clsf1 should be before clsf2 when sorting, and false otherwise.
         */
        bool compare(const Classifiable* clsf1, const Classifiable* clsf2) const;

    public:
        /**
         * Constructor.
         * @param referencePoint - the reference point to compare the classifiable objects by.
         * @param distance - the distance measurement to compare the classifiable objects by.
         */
        DataSorter(const DataPoint& referencePoint, const Distance& distance);

        /**
         * Sorts a classifiable array.
         * @param array - the array of classifiable objects
         * @param size - the size of the array
         */
        void sortClassifiableList(const Classifiable** array, const int size) const;

};


#endif //ASS_THREE_DATASORTER_H
