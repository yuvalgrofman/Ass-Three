#ifndef ASS_THREE_DATAPOINT_H
#define ASS_THREE_DATAPOINT_H

#include <vector>
using namespace std;

class DataPoint {
    private:
        const double *data;
        const int size;

    public:
        DataPoint(const double data[], int size);
        double getVariable(int index) const;
        int getNumberOfVariables() const;
        DataPoint(const vector<double> &data);
        ~DataPoint();
};


#endif //ASS_THREE_DATAPOINT_H
