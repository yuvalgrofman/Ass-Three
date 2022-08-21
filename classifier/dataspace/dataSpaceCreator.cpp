#include "dataSpaceCreator.h"

DataSpace& DataSpaceCreator::makeDataSpace() const {
    const Flower** data = new const Flower*[length()];

    for (int i = 0; i < length(); i++) {
        data[i] = flowers.at(i);
    }
    DataSpace* dataSpace = new DataSpace(data, length());
    return *dataSpace;
}

int DataSpaceCreator::length() const {
    return (int) flowers.size();
}

void DataSpaceCreator::add(const Flower* flower) {
    flowers.push_back(flower);
}

DataSpaceCreator::DataSpaceCreator(FlowerReader& reader) {
    Flower* ptr = reader.readFlower();
    while (ptr != nullptr) {
        add(ptr);
        ptr = reader.readFlower();
    }
}