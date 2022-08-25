#ifndef ASS_THREE_DATAPOINT_H
#define ASS_THREE_DATAPOINT_H

#include <vector>
using namespace std;

/**
 * @brief The DataPoint class
 *
 * This class represents a DataPoint object which has
 * a specific number of parameters.
 * the number of parameters is decided when creating the object.
 * The parameters are stored in an array of doubles.
 */
class DataPoint {
    private:
        const double *data;
        const int size;

    public:
        /**
         * Constructor.
         * @param data - the data of the data point.
         * @param size - the size of the data point.
         */
        DataPoint(const double data[], int size);

        /**
         * Get the value of the parameter at the given index.
         * @param index - the index of the wanted parameter.
         * @return the value of the parameter at the given index, from the data array,
         * or throw an exception if the index is out of bounds.
         */
        double getVariable(int index) const;

        /**
         * @return the number of parameters in the data point.
         */
        int getNumberOfVariables() const;

        /**
         * Destructor.
         */
        ~DataPoint();
};


#endif //ASS_THREE_DATAPOINT_H
