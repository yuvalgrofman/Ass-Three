#include "recvData.h"

recvData::recvData(int userId) : userId(userId) {}

void recvData::execute() {
    string trainFileContents = dio->read();
    writeCSVFile("../server/data/user_" + to_string(userId) + "_train.csv", trainFileContents);
    dio->write("Upload complete.");


    string testFileContents = dio->read();
    writeCSVFile("../server/data/user_" + to_string(userId) + "_test.csv" ,testFileContents);
    dio->write("Upload complete.");
}