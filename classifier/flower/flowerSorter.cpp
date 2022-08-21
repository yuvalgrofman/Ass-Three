#include "flowerSorter.h"

bool FlowerSorter::compare(const Flower *flower1, const Flower *flower2) const {
    return distance.getDistance(flowerPoint, flower1->getData()) <=
                        distance.getDistance(flowerPoint, flower2->getData());
}

FlowerSorter::FlowerSorter(const FlowerPoint &flowerPoint, const Distance &distance):
                flowerPoint(flowerPoint), distance(distance) {}

void FlowerSorter::sortFlowerList(const Flower **array, const int size) const {
    if (size <= 1) {
        return;
    }

    int leftSize = size / 2;
    int rightSize = size - leftSize;
    const Flower **left = array;
    const Flower **right = array + leftSize;
    sortFlowerList(left, leftSize);
    sortFlowerList(right, rightSize);

    const Flower *arr[size];
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
