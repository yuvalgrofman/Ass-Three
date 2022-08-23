#include "dataSpaceCreator.h"

DataSpace& DataSpaceCreator::makeDataSpace() const {
    const Classifiable **data = new const Classifiable*[length()];

    for (int i = 0; i < length(); i++) {
        data[i] = classifiables.at(i);
    }

    DataSpace* dataSpace = new DataSpace(data, length());
    return *dataSpace;
}

int DataSpaceCreator::length() const {
    return (int) classifiables.size();
}

void DataSpaceCreator::add(const Classifiable* classifiable) {
    classifiables.push_back(classifiable);
}

DataSpaceCreator::DataSpaceCreator(DataReader& reader) {
    Classifiable* ptr = reader.readClassifiable();
    while (ptr != nullptr) {
        add(ptr);
        ptr = reader.readClassifiable();
    }
}