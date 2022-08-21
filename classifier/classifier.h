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
 * This class is responsible for classifying a flower point as a certain flower.
 */
class Classifier {
    private:
        const int k;
        const vector<Distance*>* distances;
        const DataSpace* dataSpace;
        vector<FlowerPoint*>* unclassifiedFLowers;

        /**
         * Creates a file with the given name and predicts the flower type of the unclassified flowers,
         * according to the k-nearest neighbors algorithm using the given distance.
         * @param outputFile The name of the file to create.
         * @param distance given distance to use.
         */
        void predictFileByDist(const string &outputFile, Distance &distance) const;

    public:
        /**
         * Constructor.
         * @param k integer which represents the number of neighbors to use
         * @param distances vector of pointers to distance classes
         * @param classifiedData path to the file containing the classified flowers
         * @param unclassifiedData path to the file containing the unclassified flowers
         */
        Classifier(int k, vector<Distance*>* distances, const string& classifiedData, const string& unclassifiedData);

        /**
         * Classifies the unclassified flowers.
         * For each distance class, a file is created containing the predicted flower types according to the distance class.
         */
        void classify();

        /**
         * Classifies the given flower point.
         * @param flowerPoint  given flower point.
         * @param distance given distance metric.
         * @return  predicted flower type.
         */
        FlowerType classify(FlowerPoint& flowerPoint, Distance& distance);

        /**
         * Destructor.
         */
        ~Classifier();
};


#endif //ASS_ONE_CLASSIFIER_H
