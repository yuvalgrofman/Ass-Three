#include "recvData.h"

recvData::recvData(int userId) : userId(userId) {}

void recvData::execute() {
    string trainFileContents = dio->read();
    writeCSVFile("../server/data/train_user_" + to_string(userId) + ".csv", trainFileContents);
    dio->write("Upload complete.");


    string testFileContents = dio->read();
    writeCSVFile("../server/data/train_user_" + to_string(userId) + ".csv" ,testFileContents);
    dio->write("Upload complete.");
}