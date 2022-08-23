#ifndef ASS_THREE_DATASORTER_H
#define ASS_THREE_DATASORTER_H


#include "classifiable.h"
#include "classifier/distances/distance.h"

class DataSorter {
    private:
        const DataPoint& referencePoint;
        const Distance& distance;

        bool compare(const Classifiable* clsf1, const Classifiable* clsf2) const;

    public:
        DataSorter(const DataPoint& referencePoint, const Distance& distance);

        void sortClassifiableList(const Classifiable** array, const int size) const;

};


#endif //ASS_THREE_DATASORTER_H
