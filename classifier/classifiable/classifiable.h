#ifndef ASS_THREE_CLASSIFIABLE_H
#define ASS_THREE_CLASSIFIABLE_H

#include <string>
#include "dataPoint.h"
using namespace std;

/**
 * @brief The Classifiable class
 *
 * This class represents a Classifiable object which has
 * data parameters and a type classification.
 * The data parameters are stored in a DataPoint and the type is stored as a string.
 */
class Classifiable {
private:
    const DataPoint& dataPoint;
    const string type;

public:
    /**
     * Copy constructor.
     * @param classifiable - the classifiable to copy.
     */
    Classifiable(Classifiable const &classifiable);

    /**
     * Constructor.
     * @param dataPoint - the data point of the classifiable object.
     * @param type - the type of the classifiable object.
     */
    Classifiable(const DataPoint &dataPoint, string type);

    /**
     * @return the type of the classifiable object.
     */
    string getType() const;

    /**
     * @return the data point of the classifiable object.
     */
    const DataPoint& getData() const;

    /**
     * Default constructor.
     */
    Classifiable() = default;

    /**
     * Destructor.
     */
    ~Classifiable();
};


#endif //ASS_THREE_CLASSIFIABLE_H
