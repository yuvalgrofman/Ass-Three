#include "dataSorter.h"

bool DataSorter::compare(const Classifiable* clsf1, const Classifiable* clsf2) const {
    return distance.getDistance(referencePoint, clsf1->getData()) <=
           distance.getDistance(referencePoint, clsf1->getData());
}

DataSorter::DataSorter(const DataPoint& referencePoint, const Distance& distance) :
            referencePoint(referencePoint), distance(distance) {}

void DataSorter::sortClassifiableList(const Classifiable** array, const int size) const {
    if (size <= 1) {
        return;
    }

    int leftSize = size / 2;
    int rightSize = size - leftSize;
    const Classifiable **left = array;
    const Classifiable **right = array + leftSize;
    sortClassifiableList(left, leftSize);
    sortClassifiableList(right, rightSize);

    const Classifiable *arr[size];
    int leftIndex = 0;
    int rightIndex = 0;
    int index = 0;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (compare(left[leftIndex], right[rightIndex])) {
            arr[index] = left[leftIndex];
            leftIndex++;
        } else {
            arr[index] = right[rightIndex];
            rightIndex++;
        }
        index++;
    }
    while (leftIndex < leftSize) {
        arr[index] = left[leftIndex];
        leftIndex++;
        index++;
    }
    while (rightIndex < rightSize) {
        arr[index] = right[rightIndex];
        rightIndex++;
        index++;
    }

    for (int i = 0; i < size; i++) {
        array[i] = arr[i];
    }
}


