#ifndef ASS_THREE_CLASSIFIABLE_H
#define ASS_THREE_CLASSIFIABLE_H

#include <string>
#include "dataPoint.h"
using namespace std;

class Classifiable {
private:
    const DataPoint& dataPoint;
    const string type;

public:
    Classifiable(Classifiable const &classifiable);

    Classifiable(const DataPoint &dataPoint, string type);

    string getType() const;

    const DataPoint& getData() const;

    Classifiable() = default;

    ~Classifiable();
};


#endif //ASS_THREE_CLASSIFIABLE_H
