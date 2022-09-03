#include "uploadData.h"

UploadData::UploadData(DefaultIO *dio, int userId) : Command(dio, userId, "download results") {}

void UploadData::execute() {
    if (!isDataClassified()) {
        dio->write("The data hasn't been classified.\nTo classify the data "
                   "choose option 3 from the options screen.\n");
        return;
    } else {
        dio->write("Sending data.\n");
    }

    ifstream istream;
    string buffer;

    string testFileContent;

    istream.open("../server/data/user_" + to_string(userId)+ "_test_prediction.csv");

    if (!istream.is_open()) {
        //TODO: print error
    }

    while (getline(istream, buffer)) {
        testFileContent += buffer + "\n";
    }

    dio->write(testFileContent);
}