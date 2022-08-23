#include "uploadData.h"

UploadData::UploadData(DefaultIO *dio, int userId) : Command(dio, userId, "download results") {}

void UploadData::execute() {
    ifstream istream;
    string buffer;

    string trainFileContent;
    string testFileContent;

    istream.open("../server/data/user_" + to_string(userId)
                                    + "_train_prediction.csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    while (getline(istream, buffer)) {
        trainFileContent += buffer;
    }

    dio->write(trainFileContent);

    istream.open("../server/data/user_" + to_string(userId)
                                    + "_train_prediction.csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    while (getline(istream, buffer)) {
        testFileContent += buffer;
    }

    dio->write(testFileContent);
}