#include "recvData.h"

recvData::recvData(DefaultIO* dio, int userId) : Command(dio, userId) {
    description.assign("upload an unclassified csv data file");
}

void recvData::execute() {
    string trainFileContents = dio->read();
    writeCSVFile("../server/data/user_" + to_string(userId) + "_train.csv", trainFileContents);
    dio->write("Upload complete.");


    string testFileContents = dio->read();
    writeCSVFile("../server/data/user_" + to_string(userId) + "_test.csv" ,testFileContents);
    dio->write("Upload complete.");
}