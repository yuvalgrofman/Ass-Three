#ifndef ASS_ONE_CLASSIFIER_H
#define ASS_ONE_CLASSIFIER_H

#include <string>
#include "distances/distance.h"
#include "vector"
#include "dataspace/dataSpaceCreator.h"
#include <iostream>

using namespace std;

/**
 * @brief The classifier class
 *
 * This class is responsible for classifying a data-point.
 */
class Classifier {
    private:
        const int k;
        const vector<Distance*>* distances;
        const DataSpace* dataSpace;
        vector<DataPoint*>* unclassifiedPoints;

    public:
        /**
         * Creates a file with the given name and predicts the classify type of the unclassified data.
         * according to the k-nearest neighbors algorithm using the given distance.
         * @param outputFile The name of the file to create.
         * @param distance given distance to use.
         */
        void predictFileByDist(const string &outputFile, Distance &distance) const;


        /**
         * Constructor.
         * @param k integer which represents the number of neighbors to use
         * @param distances vector of pointers to distance classes
         * @param classifiedData path to the file containing the classified data
         * @param unclassifiedData path to the file containing the unclassified data
         */
        Classifier(int k, vector<Distance*>* distances, const string& classifiedData, const string& unclassifiedData);

        /**
         * Classifies the unclassified data.
         * For each distance class, a file is created containing the
         * predicted classified types according to the distance class.
         */
        void classify();

        /**
         * Classifies the given data-point.
         * @param dataPoint - the given data point.
         * @param distance - the given distance metric.
         * @return the predicted classified type.
         */
        string classify(DataPoint& dataPoint, Distance& distance);

        /**
         * Destructor.
         */
        ~Classifier();
};


#endif //ASS_ONE_CLASSIFIER_H
