#ifndef ASS_ONE_FLOWER_READER_H
#define ASS_ONE_FLOWER_READER_H

#include "flower.h"
#include <fstream>

/**
 * detect a flower point from a line of text.
 * @param line - the line of text to detect the flower point from.
 * @return a pointer to the flower point.
 */
FlowerPoint* detectFlowerPoint(string line);

/**
 * detect a flower from a line of text.
 * @param line - the line of text to detect the flower from.
 * @return a pointer to the flower.
 */
Flower* detectFlower(string line);

/**
 * @brief The FlowerReader class
 *
 * This class is responsible for reading flowers and flower-points from files.
 */
class FlowerReader {
    private:
        // The file stream to read from.
        string file;

        //the stream used to read the file
        fstream fin;

    public:
        /**
         * Constructor.
         * @param file the file to read from
         */
        FlowerReader(const string &filename);

        /**
         * Reads a flower from the file.
         * if the file is empty, it returns nullptr.
         * @return the flower
         */
        Flower* readFlower();

        /**
         * Reads a flower point from the file.
         * if the file is empty, it returns nullptr.
         * @return the flower point
         */
        FlowerPoint* readFlowerPoint();
};

#endif //ASS_ONE_FLOWER_READER_H
