#ifndef ASS_ONE_DATA_SPACE_CREATOR_H
#define ASS_ONE_DATA_SPACE_CREATOR_H

#include "classifier/flower/flower.h"
#include "dataSpace.h"
#include "classifier/flower/flowerReader.h"
#include <vector>

/**
 * @brief The DataSpaceCreator class
 *
 * This class is responsible for creating a data space.
 */
class DataSpaceCreator {
private:
    vector<const Flower*> flowers;

    /**
     * Adds a flower to the collection.
     * @param flower - the flower to add.
     */
    void add(const Flower* flower);

    /**
     * Says the length of the list of flowers
     * @return the current amount of flowers.
     */
    int length() const;

public:
    /**
     * Constructor.
     * @param reader - the reader to use for building the collection.
     */
    DataSpaceCreator(FlowerReader& reader);

    /**
     * Builds the data-space from the flower data this creator has.
     * @return a data-space with the data that was inputted to this creator.
     */
    DataSpace& makeDataSpace() const;
};

#endif // ASS_ONE_DATA_SPACE_CREATOR_H