#ifndef ASS_THREE_DATAREADER_H
#define ASS_THREE_DATAREADER_H

#include "classifiable.h"
#include <fstream>

/**
 * detect a data point from a line of text.
 * @param line - the line of text to detect the data point from.
 * @return a pointer to the data point.
 */
DataPoint* detectDataPoint(const string &line);

/**
 * detect a classifiable object from a line of text.
 * @param line - the line of text to detect the classifiable from.
 * @return a pointer to the classifiable object.
 */
Classifiable* detectClassifiable(const string &line);

/**
 * @brief The DataReader class
 *
 * This class is responsible for reading data-points,
 * and classifiable objects from files.
 */
class DataReader {
    private:
        // The file stream to read from.
        string file;

        // The stream used to read the file.
        fstream fin;

    public:
        /**
         * Constructor.
         * @param filename - the file to read from
         */
        DataReader(const string &filename);

        /**
         * Reads a classifiable object from the file.
         * if the file is empty, it returns nullptr.
         * @return a pointer to the classifiable object.
         */
        Classifiable* readClassifiable();

        /**
         * Reads a data point from the file.
         * if the file is empty, it returns nullptr.
         * @return a pointer to the data point.
         */
        DataPoint* readDataPoint();
};


#endif //ASS_THREE_DATAREADER_H
