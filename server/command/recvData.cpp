#include "recvData.h"

RecvData::RecvData(DefaultIO* dio, int userId) : Command(dio, userId, "upload an unclassified csv data file") {}

void RecvData::execute() {
    string trainFileContents = dio->read();
    writeCSVFile("../server/data/user_" + to_string(userId) + "_train.csv", trainFileContents);
    dio->write("Upload complete.\n");

    string testFileContents = dio->read();
    writeCSVFile("../server/data/user_" + to_string(userId) + "_test.csv" ,testFileContents);
    dio->write("Upload complete.\n");

    string trainPredict = "../server/data/user_" + to_string(userId) + "_train_prediction.csv";
    writeCSVFile(trainPredict, "");
    string testPredict = "../server/data/user_" + to_string(userId) + "_test_prediction.csv";
    writeCSVFile(testPredict, "");
}