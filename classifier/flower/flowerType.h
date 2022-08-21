#ifndef ASS_ONE_FLOWER_TYPE_H
#define ASS_ONE_FLOWER_TYPE_H

#include <ostream>

/**
 * @brief The FlowerType enum.
 *
 * This enum is responsible for saving the possible types of flowers.
 */
enum FlowerType {
    SETOSA = 0,
    VIRGINICA = 1,
    VERSICOLOR = 2
};

// the number of flower types.
const int NUM_FLOWER_TYPES = 3;

/**
 * Operator<<, for adding a flower type to a stream.
 * @param os - the stream to add the type to.
 * @param type - the flower type to add to the stream.
 * @return the stream after the flower type was added to it.
 */
std::ostream& operator<<(std::ostream& os, const FlowerType type);

std::string FlowerTypeToString(FlowerType type);

#endif //ASS_ONE_FLOWER_TYPE_H
