#ifndef ASS_ONE_SORT_FLOWER_LIST_H
#define ASS_ONE_SORT_FLOWER_LIST_H

#include "flower.h"
#include "classifier/distances/distance.h"

/**
 * @brief The FlowerSorter class
 *
 * This class is Responsible for comparing and sorting flower,
 * based on the distance to a specific flower point, with a specific distance function.
 */
class FlowerSorter {
private:
    const FlowerPoint& flowerPoint;
    const Distance& distance;

    /**
     * Compare two flowers, to see which of them should be before the other,
     * when sorting the flowers.
     * @param flower1 - the first flower.
     * @param flower2 - the second flower.
     * @return true if flower1 should be before flower2 when sorting, and false otherwise.
     */
    bool compare(const Flower* flower1, const Flower* flower2) const;

public:
    /**
     * Constructor.
     * @param flowerPoint - the flower point to compare the flowers by.
     * @param distance - the distance measurement to compare the flowers by.
     */
    FlowerSorter(const FlowerPoint& flowerPoint, const Distance& distance);

    /**
     * Sorts a flower array.
     * @param array - the array of flowers
     * @param size - the size of the array
     */
    void sortFlowerList(const Flower** array, const int size) const;
};


#endif //ASS_ONE_SORT_FLOWER_LIST_H
