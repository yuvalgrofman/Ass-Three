#ifndef ASS_THREE_DATAREADER_H
#define ASS_THREE_DATAREADER_H

#include "classifiable.h"
#include <fstream>

DataPoint* detectDataPoint(const string &line);
Classifiable* detectClassifiable(const string &line);

class DataReader {
    private:
        string file;
        fstream fin;

    public:
        DataReader(const string &filename);
        Classifiable* readClassifiable();
        DataPoint* readDataPoint();
};


#endif //ASS_THREE_DATAREADER_H
