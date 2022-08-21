#include "dataSpace.h"
#include <vector>
#include <iostream>
#include "classifier/flower/flowerSorter.h"

using namespace std;

DataSpace::DataSpace(const Flower** data, const int numFlowers): numFlowers(numFlowers) {
    this->data = data;
}

DataSpace::~DataSpace() {
    for (int i = 0; i < numFlowers; i++) {
        delete data[i];
    }
    delete[] data;
}

FlowerType DataSpace::predict(int k, const FlowerPoint& flower, Distance& distance) const {
    const Flower *arr[numFlowers];
    for (int i = 0; i < numFlowers; i++) {
        arr[i] = data[i];
    }
    FlowerSorter sorter(flower, distance);
    sorter.sortFlowerList(arr, numFlowers);

    int closestNeighboursCount[NUM_FLOWER_TYPES];
    for (int i = 0; i < NUM_FLOWER_TYPES; i++) {
        closestNeighboursCount[i] = 0;
    }

    for (int i = 0; i < k; i++) {
        int a = arr[i]->getType();
        closestNeighboursCount[a]++;
    }

    int max = -1;
    FlowerType maxType;
    for (int i = 0; i < NUM_FLOWER_TYPES; i++) {
        if (closestNeighboursCount[i] > max) {
            max = closestNeighboursCount[i];
            maxType = static_cast<FlowerType>(i);
        }
    }
    return maxType;
}