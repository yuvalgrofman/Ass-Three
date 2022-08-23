#ifndef ASS_ONE_DATA_SPACE_CREATOR_H
#define ASS_ONE_DATA_SPACE_CREATOR_H

#include "classifier/classifiable/classifiable.h"
#include "dataSpace.h"
#include "classifier/classifiable/dataReader.h"
#include <vector>

/**
 * @brief The DataSpaceCreator class
 *
 * This class is responsible for creating a data space.
 */
class DataSpaceCreator {
private:
    vector<const Classifiable*> classifiables;

    /**
     * Adds a classifiable to the collection.
     * @param classifiable - the classifiable to add.
     */
    void add(const Classifiable* classifiable);

    /**
     * Says the length of the list of classifiables.
     * @return the current amount of classifiables.
     */
    int length() const;

public:
    /**
     * Constructor.
     * @param reader - the reader to use for building the collection.
     */
    DataSpaceCreator(DataReader& reader);

    /**
     * Builds the data-space from the data this creator has.
     * @return a data-space with the data that was inputted to this creator.
     */
    DataSpace& makeDataSpace() const;
};

#endif // ASS_ONE_DATA_SPACE_CREATOR_H