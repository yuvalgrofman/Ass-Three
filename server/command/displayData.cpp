#include "displayData.h"

DisplayData::DisplayData(DefaultIO *dio, int userId) : Command(dio, userId, "display results") {}

void DisplayData::execute() {
    if (!isDataClassified()) {
        dio->write("The data hasn't been classified.\nTo classify the"
                   "data choose option 3 from the options screen.\n");
        return;
    } else {
        dio->write("Sending data.\n");
    }

    ifstream istream("../server/data/user_" + to_string(userId) + "_test_prediction.csv");

    string word;
    int lineNumber = 1;

    while(getline(istream, word)) {
        dio->write(to_string(lineNumber) + " " + word + "\n");
        lineNumber++;
    }

    dio->write("Done.\n");
}